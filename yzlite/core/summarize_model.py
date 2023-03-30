
import io
import logging
import os
from typing import Union

from yzlite.utils.path import fullpath
from yzlite.utils.python import append_exception_msg
from yzlite.utils.string_formatting import format_units

from .model import (KerasModel, YZLiteModel, YZLiteModelEvent,
                    load_tflite_or_keras_model, load_yzlite_model)
from .model.metrics import calculate_model_metrics
from .tflite_model import TfliteModel
from .utils import ArchiveFileNotFoundError, get_yzlite_logger


def summarize_model(
    model: Union[str, YZLiteModel, KerasModel, TfliteModel],
    tflite: bool = False,
    build: bool = False,
    test: bool = False,
    built_model: Union[KerasModel, TfliteModel] = None
) -> str:
    """Generate a summary of the given model
    and return the summary as a string

    .. seealso::
       * `Model Summary Guide <https://github.com/chenxingqiang/yzlite/docs/guides/model_summary.html>`_
       * `Model summary API examples <https://github.com/chenxingqiang/yzlite/yzlite/examples/summarize_model.html>`_


    Args:
        model: Either

            * a path to a `.tflite`, `.h5`, `.yzlite.zip`, `.py` file,
            * or a :py:class:`yzlite.core.YZLiteModel`, :py:class:`yzlite.core.KerasModel`,
            * or :py:class:`yzlite.core.TfliteModel` instance
        tflite: If true, the return the summary of the corresponding `.tflite model`.
            If true and model= :py:class:`yzlite.core.KerasModel`, this will quantize it into a `.tflite` model
        build: If true, then generate a `.h5` or `.tflite` by training the given :py:class:`yzlite.core.YZLiteModel` model for 1 epoch.
            This is useful for summarizing the :py:class:`yzlite.core.YZLiteModel` without fully training the model first
        test: If true and the model is the name of a YZLiteModel, then load the YZLiteModel in testing mode
        built_model: Optional, previously built :py:class:`yzlite.core.KerasModel` or
            :py:class:`yzlite.core.TfliteModel` associated with given :py:class:`yzlite.core.YZLiteModel`

    Returns:
        A summary of the given model as a string

    """
    yzlite_model = None
    yzlite_model_summary = None
    tflite_size = None

    logger = get_yzlite_logger()

    try:
        yzlite_model, built_model = _load_or_build_model(
            model,
            tflite=tflite,
            build=build,
            built_model=built_model,
            test=test,
            logger=logger
        )
    except ArchiveFileNotFoundError as e:
        append_exception_msg(e,
                             '\nAlternatively, add the --build option to summarize the model without training it first'
                             )
        raise

    if isinstance(built_model, TfliteModel):
        tflite_size = built_model.flatbuffer_size
        if yzlite_model is None:
            # If no YZLITE model was given (because we directly loaded a .tflite file)
            # then create a default model and attempt to load the common metadata entries
            yzlite_model = YZLiteModel()

        yzlite_model.deserialize_tflite_metadata(built_model)

    if yzlite_model is not None:
        yzlite_model_summary = yzlite_model.summary()

    model_metrics = calculate_model_metrics(built_model, logger=logger)

    summary = ''
    if isinstance(built_model, KerasModel):
        string_buffer = io.StringIO()

        def _writeln(s):
            string_buffer.write(s + '\n')
        built_model.summary(print_fn=_writeln)
        summary += string_buffer.getvalue()
    else:
        summary += built_model.summary()

    summary += '\n'
    summary += f'Total MACs: {format_units(model_metrics["total_macs"])}\n'
    summary += f'Total OPs: {format_units(model_metrics["total_ops"])}\n'

    if yzlite_model_summary is not None:
        summary += f'{yzlite_model_summary}\n'

    if tflite_size:
        summary += f'.tflite file size: {format_units(tflite_size, precision=1, add_space=False)}B\n'

    summary = summary.strip()

    summary_dict = dict(value=summary)
    if yzlite_model is not None:
        yzlite_model.trigger_event(
            YZLiteModelEvent.SUMMARIZE_MODEL,
            summary=summary,
            summary_dict=summary_dict,
            logger=logger
        )
    summary = summary_dict['value']

    return summary


def _load_or_build_model(
    model: Union[str, YZLiteModel, KerasModel, TfliteModel],
    built_model: Union[KerasModel, TfliteModel],
    test: bool,
    tflite: bool,
    build: bool,
    logger: logging.Logger
):
    """Load a previously trained .tflite/.h5 OR build the model now"""
    yzlite_model = None

    # If a YZLiteModel instance was given
    if isinstance(model, YZLiteModel):
        yzlite_model = model

    # Elif if a KerasModel instance was given
    elif isinstance(model, KerasModel):
        built_model = model

     # Elif if a KerasModel instance was given
    elif isinstance(model, TfliteModel):
        built_model = model

    elif not isinstance(model, str):
        raise Exception(
            'model argument must be a string or YZLiteModel,KerasModel,TfliteModel instance')

    # Else if the path to a .h5 or .tflite was given
    elif model.endswith(('.tflite', '.h5')):
        model_path = fullpath(model)
        if not os.path.exists(model_path):
            raise FileNotFoundError(f'Model not found: {model_path}')

        built_model = load_tflite_or_keras_model(model_path)

    # Else a YZLITE model name was given
    else:
        yzlite_model = load_yzlite_model(
            model,
            test=test,
            print_not_found_err=True
        )

    if build and yzlite_model is None:
        raise Exception('Must provide YZLiteModel with the build option')

    # If we have a YZLiteModel instance but no built model instance
    if yzlite_model is not None and built_model is None:
        # If we want to build keras or .tflite model from the .tflite
        # (i.e. if the model has not already been trained)
        if build:
            from .quantize_model import quantize_model
            from .train_model import train_model

            if tflite:
                built_model = quantize_model(
                    model=yzlite_model,
                    build=True,
                    output='tflite_model'
                )
            else:
                built_yzlite_model = load_yzlite_model(
                    yzlite_model.model_specification_path, test=True)
                results = train_model(
                    model=built_yzlite_model,
                    epochs=1,
                    quantize=False,
                    clean=None,
                    create_archive=False,
                    verbose=logger.verbose,
                )
                built_model = results.keras_model

        # Else if we need to load the .tflite from the YZLiteModel archive
        elif tflite:
            # If a .tflite path was given
            if isinstance(tflite, str):
                built_model = load_tflite_or_keras_model(
                    tflite,
                )
            # Else load the .tflite from the model archive
            else:
                built_model = load_tflite_or_keras_model(
                    yzlite_model,
                    model_type='tflite',
                )

        # Else load the .h5 from the YZLiteModel archive
        else:
            built_model = load_tflite_or_keras_model(
                yzlite_model,
                model_type='h5',
            )

    return yzlite_model, built_model
