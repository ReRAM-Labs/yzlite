
import logging
import pprint
from typing import Tuple, Union

import numpy as np
import tensorflow as tf

from yzlite.utils import gpu
from yzlite.utils.python import (DefaultDict, append_exception_msg,
                                 prepend_exception_msg)

from .model import (KerasModel, YZLiteModel, YZLiteModelEvent,
                    load_tflite_or_keras_model, load_yzlite_model)
from .summarize_model import summarize_model
from .tflite_model import TfliteModel
from .update_model_parameters import add_default_parameters
from .utils import get_yzlite_logger


def quantize_model(
    model: Union[YZLiteModel, str],
    keras_model: KerasModel = None,
    output: str = None,
    weights: str = None,
    build: bool = False,
    update_archive: bool = None,
    tflite_converter_override: dict = None,
    post_process: bool = False
) -> Union[str, TfliteModel]:
    """Generate a quantized .tflite model file

    This uses the Tensorflow `TfliteConverter <https://www.tensorflow.org/lite/convert>`_ internally.
    This will also add any metadata to the generated `.tflite` model file.

    .. seealso::
       * `Model Quantization Guide <https://github.com/ReRAM-Labs/yzlite/docs/guides/model_quantization.html>`_
       * `Model quantization API examples <https://github.com/ReRAM-Labs/yzlite/yzlite/examples/quantize_model.html>`_

    Args:
        model: :py:class:`yzlite.core.YZLiteModel` instance, name of YZLITE model, path to model archive (.yzlite.zip) or specification script (.py)
        keras_model: Optional, keras_model previously built from given yzlite_model

            * If none, then load keras model from YZLITE model archive's `.h5` file
            * If none and build=True, then build keras model rather that loading archive's `.h5`

        output: Optional, directory path or file path to generated `.tflite` file.

            * If `none` then generate in model log directory and update the model's archive.
            * If output='tflite_model', then return the :py:class:`yzlite.core.TfliteModel` object instead of `.tflite` file path

            NOTE: The model archive is NOT updated if this argument is supplied
        weights: Optional, path to model weights file. This is only used if no keras_model argument is given.
        build: If true and keras_model is None, then first build the keras model by training for 1 epoch..
            This is useful for visualizing the .tflite without fully training the model first
            NOTE: The model archive is NOT updated if this argument is supplied
        update_archive: Update the model archive `.yzlite.zip` with the generated `.tflite` file,.
            If None (default), then determine automatically if the model archive should be updated
        tflite_converter_override: Dictionary of zero or more :py:attr:`yzlite.core.TrainMixin.tflite_converter` settings
            used to override the :py:attr:`yzlite.core.TrainMixin.tflite_converter` in the model specification
            NOTE: The model archive is NOT updated if this argument is supplied
        post_process: This allows for post-processing the quantization results (e.g. uploading to a cloud) if supported by the given YZLiteModel

    Returns:
        The file path to the generated `.tflite` OR TfliteModel object if output='tflite_model'
    """

    if isinstance(model, YZLiteModel):
        yzlite_model = model

    elif isinstance(model, str):
        if model.endswith(('.tflite', '.h5')):
            raise ValueError(
                'Must provide name of YZLITE model '
                'or path model archive (.yzlite.zip) or specification script (.py)'
            )
        yzlite_model = load_yzlite_model(model)
    else:
        raise ValueError(
            'Must provide YZLiteModel instance, name of YZLITE model, or path to '
            'model archive (.yzlite.zip) or specification script (.py)'
        )

    logger = get_yzlite_logger()

    tflite_converter_settings = DefaultDict()
    if hasattr(yzlite_model, 'tflite_converter'):
        tflite_converter_settings.update(yzlite_model.tflite_converter)
    if tflite_converter_override:
        tflite_converter_settings.update(tflite_converter_override)

    if not tflite_converter_settings:
        raise ValueError(
            'YZLiteModel does not specify tflite_converter settings')

    yzlite_model.trigger_event(
        YZLiteModelEvent.QUANTIZE_STARTUP,
        build=build,
        keras_model=keras_model,
        tflite_converter_settings=tflite_converter_settings,
        post_process=post_process,
        logger=logger
    )

    logger.debug(
        f'Using tflite converter settings:\n{pprint.pformat(dict(tflite_converter_settings))}')

    gpu.initialize(logger=logger)

    if keras_model is None:
        if build:
            from .train_model import train_model

            built_yzlite_model = load_yzlite_model(
                yzlite_model.model_specification_path,
                reload=False
            )
            built_yzlite_model.enable_test_mode()
            results = train_model(
                model=built_yzlite_model,
                epochs=1,
                quantize=False,
                clean=None,
                create_archive=False,
                verbose=logger.verbose,
            )
            keras_model = results.keras_model

        else:
            keras_model = load_tflite_or_keras_model(
                yzlite_model,
                model_type='h5',
                weights=weights,
            )

    # Determine if we should update the model archive with the generated .tflite
    if update_archive is None:
        update_archive = False
        if not output and not build and not tflite_converter_override:
            update_archive = yzlite_model.check_archive_file_is_writable()

    # Determine the return value of this API
    if output:
        if output == 'tflite_model':
            retval = 'tflite_model'
        elif output.endswith('.tflite'):
            retval = output
        elif yzlite_model.test_mode_enabled:
            retval = f'{output}/{yzlite_model.name}.test.tflite'
        else:
            retval = f'{output}/{yzlite_model.name}.tflite'
    else:
        retval = yzlite_model.tflite_log_dir_path

    _update_absl_log_level('ERROR')

    # If we should generate an unquantized/float32 .tflite model
    # NOTE: Run this IF a "representative_dataset" converter setting was provided
    float32_tflite_path = None
    if output is None and tflite_converter_settings['generate_unquantized'] and tflite_converter_settings['representative_dataset'] is not None:
        float32_tflite_path = yzlite_model.unquantized_tflite_log_dir_path
        logger.info(f'Generating {float32_tflite_path}')
        float32_converter = tf.lite.TFLiteConverter.from_keras_model(
            keras_model)
        try:
            float32_tflite_flatbuffer = float32_converter.convert()
        except Exception as e:
            logger.debug(
                f'Failed to generated unquantized tflite model, err: {e}', exc_info=e)
            prepend_exception_msg(
                e, 'Failed to generated unquantized tflite model')
            raise
        finally:
            # The TfLiteConverter adds a StreamHandler to the root logger,
            # remove it so we don't double print everything to the console
            logger.root.handlers.clear()

        _save_flatbuffer_file(
            yzlite_model=yzlite_model,
            tflite_flatbuffer=float32_tflite_flatbuffer,
            logger=logger,
            output=float32_tflite_path,
            add_runtime_memory_size=False
        )

    converter = tf.lite.TFLiteConverter.from_keras_model(keras_model)
    _populate_converter_options(converter, tflite_converter_settings)

    try:
        yzlite_model.load_dataset(
            subset='validation', test=yzlite_model.test_mode_enabled)
    except Exception as e:
        prepend_exception_msg(e, 'Failed to load validation dataset')
        raise

    if tflite_converter_settings['representative_dataset'] == 'generate':
        converter.representative_dataset = create_representative_dataset_generator(
            yzlite_model,
            test=yzlite_model.test_mode_enabled,
            logger=logger
        )
    else:
        converter.representative_dataset = tflite_converter_settings['representative_dataset']

    logger.info(f'Generating {retval}')
    yzlite_model.trigger_event(
        YZLiteModelEvent.BEFORE_QUANTIZE,
        converter=converter,
        logger=logger
    )

    try:
        tflite_flatbuffer = converter.convert()
    except Exception as e:
        prepend_exception_msg(e, 'Failed to quantize model')
        if tflite_converter_settings['representative_dataset'] == 'generate':
            append_exception_msg(e,
                                 '\n\nYou may need to define a custom representative data generator\n'
                                 'e.g.: my_model.tflite_converter["representative_dataset"] = _my_data_generator_function\n'
                                 'See https://www.tensorflow.org/lite/performance/post_training_quantization\n'
                                 )
        raise
    finally:
        # The TfLiteConverter adds a StreamHandler to the root logger,
        # remove it so we don't double print everything to the console
        logger.root.handlers.clear()

    yzlite_model.trigger_event(
        YZLiteModelEvent.AFTER_QUANTIZE,
        tflite_flatbuffer=tflite_flatbuffer,
        logger=logger
    )

    yzlite_model.unload_dataset()
    _update_absl_log_level()

    retval, tflite_model = _save_flatbuffer_file(
        yzlite_model=yzlite_model,
        tflite_flatbuffer=tflite_flatbuffer,
        logger=logger,
        output=retval,
        add_runtime_memory_size=True
    )

    if update_archive:
        logger.info(f'Updating {yzlite_model.archive_path}')
        try:
            summary_path = f'{yzlite_model.log_dir}/{yzlite_model.name}.tflite.summary.txt'
            with open(summary_path, 'w') as fp:
                fp.write(summarize_model(tflite_model))
            yzlite_model.add_archive_file(summary_path)
        except:
            pass
        yzlite_model.add_archive_file('__yzlite_model_spec__')
        yzlite_model.add_archive_file(retval)
        if float32_tflite_path:
            yzlite_model.add_archive_file(float32_tflite_path)

    yzlite_model.trigger_event(
        YZLiteModelEvent.QUANTIZE_SHUTDOWN,
        tflite_model=tflite_model,
        logger=logger
    )

    return retval


def create_representative_dataset_generator(yzlite_model: YZLiteModel, logger: logging.Logger, test: bool = False):
    """Return a data generator function

    See https://www.tensorflow.org/lite/performance/post_training_quantization
    """
    logger.debug('Generating representative dataset using validation data')

    # Try to use the validation data if available, otherwise use the training data
    validation_data = yzlite_model.validation_data
    if validation_data is None:
        validation_data = yzlite_model.x

    def _representative_dataset_generator():
        for i, batch in enumerate(validation_data):
            batch_x, _, _ = tf.keras.utils.unpack_x_y_sample_weight(batch)
            if isinstance(batch_x, tf.Tensor):
                if batch_x.dtype != tf.float32:
                    batch_x = tf.cast(batch_x, dtype=tf.float32)

                # The TF-Lite converter expects 1 sample batches
                for x in batch_x:
                    yield [tf.expand_dims(x, axis=0)]

            else:
                # The TF-Lite converter expects the input to be a float32 data type
                if isinstance(batch_x, np.ndarray) and batch_x.dtype != np.float32:
                    batch_x = batch_x.astype(np.float32)

                elif isinstance(batch_x, (list, tuple)):
                    batch_x_norm = []
                    for batch_xi in batch_x:
                        if isinstance(batch_xi, np.ndarray) and batch_xi.dtype != np.float32:
                            batch_x_norm.append(batch_xi.astype(np.float32))
                        else:
                            batch_x_norm.append(batch_xi)
                    batch_x = batch_x_norm

                # The TF-Lite converter expects 1 sample batches
                for x in batch_x:
                    yield [np.expand_dims(x, axis=0)]

            # 100 batches should be enough
            # for the converter to determine the valid ranges
            # required for quantization
            if i > 100:
                break

    return _representative_dataset_generator


def _save_flatbuffer_file(
    yzlite_model: YZLiteModel,
    tflite_flatbuffer: bytes,
    output: str,
    logger: logging.Logger,
    add_runtime_memory_size: bool
) -> Tuple[Union[str, TfliteModel], TfliteModel]:
    """Save the given flatbuffer bytes to a .tflite with model parameters"""
    try:
        # Update the .tflite description and metadata fields before saving to the file
        tflite_model = TfliteModel(tflite_flatbuffer)

        # Add the model description
        tflite_model.description = yzlite_model.description

        # Serialize all the metadata including the model parameters
        # and add to the .tflite flatbuffer's "metadata" section
        metadata_list = yzlite_model.serialize_tflite_metadata()
        for tag, metadata in metadata_list:
            logger.debug(f'Adding metadata: {tag}')
            tflite_model.add_metadata(tag, metadata)

        # Add the default parameters to the model's metadata
        add_default_parameters(
            tflite_model,
            yzlite_model.model_parameters,
            add_runtime_memory_size=add_runtime_memory_size
        )

        if output == 'tflite_model':
            output = tflite_model
        else:
            tflite_model.save(output)
    except Exception as e:
        logger.debug(f'Failed to save .tflite model, err: {e}', exc_info=e)
        prepend_exception_msg(e, 'Failed to save .tflite model')
        raise

    return output, tflite_model


def _populate_converter_options(converter, tflite_converter_settings: dict):
    optimizations = tflite_converter_settings['optimizations']
    if optimizations:
        for i, opt in enumerate(optimizations):
            if isinstance(opt, str):
                optimizations[i] = tf.lite.Optimize[opt]
    converter.optimizations = optimizations

    supported_ops = tflite_converter_settings['supported_ops']
    if supported_ops:
        for i, opt in enumerate(supported_ops):
            if isinstance(opt, str):
                supported_ops[i] = tf.lite.OpsSet[opt]
    converter.target_spec.supported_ops = supported_ops

    inference_input_type = tflite_converter_settings['inference_input_type']
    inference_output_type = tflite_converter_settings['inference_output_type']

    converter.inference_input_type = _convert_dtype(inference_input_type)
    converter.inference_output_type = _convert_dtype(inference_output_type)

    for key, value in tflite_converter_settings.items():
        if key in (
            'optimizations',
            'supported_ops',
            'inference_input_type',
            'inference_output_type',
            'representative_dataset'
        ):
            continue

        if hasattr(converter, key):
            setattr(converter, key, value)


def _convert_dtype(dtype):
    if isinstance(dtype, str):
        return getattr(tf, dtype)

    if isinstance(dtype, tf.DType):
        return dtype

    if dtype in (np.uint8, np.dtype('uint8'), 'uint8'):
        return tf.uint8

    if dtype in (np.int8, np.dtype('int8'), 'int8'):
        return tf.int8

    if dtype in (np.int16, np.dtype('int16'), 'int16'):
        return tf.int16

    if dtype in (np.int32, np.dtype('int32'), 'int32'):
        return tf.int32

    if dtype in (np.float, np.float32, np.dtype('float32'), 'float32'):
        return tf.float32

    return dtype


def _update_absl_log_level(level=None):
    """The ABSL package prints a bunch of warnings while doing the conversion which may be ignore"""
    try:
        import absl.logging
        if level is not None:
            globals()['absl_log_level'] = absl.logging.get_verbosity()
            absl.logging.set_verbosity(getattr(absl.logging, level))

        else:
            absl.logging.set_verbosity(globals().get(
                'absl_log_level', absl.logging.get_verbosity()))
    except:
        pass
