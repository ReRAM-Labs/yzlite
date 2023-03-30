
import os
from typing import Union

from .model import YZLiteModel, load_yzlite_model
from .tflite_micro import TfliteMicro
from .tflite_model import TfliteModel
from .utils import get_yzlite_logger


def compile_model(
    model: Union[YZLiteModel, TfliteModel, str],
    accelerator: str,
    output: str = None,
    update_archive: bool = None,
) -> Union[str, TfliteModel]:
    """Compile the given quantized .tflite model for the specified accelerator

    Returns:
        The file path to the compiled `.tflite` OR TfliteModel object if output='tflite_model'
    """

    yzlite_model = None

    if isinstance(model, TfliteModel):
        tflite_model = model

    elif isinstance(model, YZLiteModel):
        yzlite_model = model
        tflite_model = TfliteModel.load_flatbuffer_file(
            model.tflite_archive_path)

    elif isinstance(model, str):
        if model.endswith('.tflite'):
            tflite_model = TfliteModel.load_flatbuffer_file(model)
        elif model.endswith('.h5'):
            raise ValueError(
                'Must provide path to quantized .tflite model file'
            )
        else:
            yzlite_model = load_yzlite_model(model)
            tflite_model = TfliteModel.load_flatbuffer_file(
                yzlite_model.tflite_archive_path)

    else:
        raise ValueError(
            'Must provide path to .tflite, TfliteModel instance, YZLiteModel instance, name of YZLITE model, or path to '
            'model archive (.yzlite.zip) or specification script (.py)'
        )

    if not TfliteMicro.accelerator_is_supported(accelerator):
        raise ValueError(
            f'Unknown accelerator: {accelerator}, supported accelerators are: {", ".join(TfliteMicro.get_supported_accelerators())}')

    accelerator = TfliteMicro.normalize_accelerator_name(accelerator).lower()

    logger = get_yzlite_logger()

    tflm_accelerator = TfliteMicro.get_accelerator(accelerator)
    if not tflm_accelerator.supports_model_compilation:
        raise RuntimeError(
            f'Accelerator {accelerator} does not support compilation')

    compiled_tflite_model = tflm_accelerator.compile_model(
        tflite_model,
        logger=logger
    )

    # Determine if we should update the model archive with the generated .tflite
    if update_archive is None:
        update_archive = False
        if not output and yzlite_model is not None:
            update_archive = yzlite_model.check_archive_file_is_writable()
    if update_archive and yzlite_model is None:
        raise ValueError('Must provide YZLiteModel if updating archive')

    tflite_path = tflite_model.path or 'my_model.tflite'
    model_name = os.path.basename(tflite_path)[:-len('.tflite')]

    # Determine the return value of this API
    if output:
        if output == 'tflite_model':
            retval = 'tflite_model'
        elif output.endswith('.tflite'):
            retval = output
        else:
            retval = f'{output}/{model_name}.{accelerator}.tflite'
    elif yzlite_model is not None:
        retval = f'{yzlite_model.log_dir}/{yzlite_model.name}.{accelerator}.tflite'
    else:
        retval = f'{tflite_path[:-len(".tflite")]}.{accelerator}.tflite'

    if retval == 'tflite_model':
        retval = compiled_tflite_model
    else:
        logger.info(f'Saving {retval}')
        compiled_tflite_model.save(retval)
        if update_archive:
            logger.info(f'Updating {yzlite_model.archive_path}')
            yzlite_model.add_archive_file(retval)

    return retval
