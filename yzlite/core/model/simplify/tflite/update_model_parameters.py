import os
import copy
from typing import Union

from yzlite.utils.path import fullpath
from yzlite.utils.hasher import generate_hash
from yzlite.utils.string_formatting import iso_time_str
from yzlite.core.tflite import TfliteModel
from yzlite.core.tflite.parameters import (
    TfliteModelParameters, TFLITE_METADATA_TAG)
from yzlite.core.yzlite import (YZLiteModel, load_yzlite_model)
from yzlite.core.utils import get_yzlite_logger


def update_model_parameters(
    model: Union[YZLiteModel, TfliteModel, str],
    params: dict = None,
    description: str = None,
    output: str = None,
    accelerator: str = None,
) -> Union[str, TfliteModel]:
    """Update the parameters of a previously trained model

    This updates the metadata of a previously trained `.tflite` model.
    The parameters are taken from either the given :py:class:`yzlite.core.YZLiteModel`'s python script
    or the given "params" dictionary and added to the `.tflite` model file.

    Args:
        model: Either the name of a model
            a :py:class:`yzlite.core.YZLiteModel` or :py:class:`yzlite.core.TfliteModel` instance or
            the path to a `.tflite` model file or `.yzlite` model archive
        params: Optional dictionary of parameters to add `.tflite`. If omitted then model argument must be a :py:class:`yzlite.core.YZLiteModel` instance or model name
        description: Optional description to add to `.tflite`
        output: Optional, directory path or file path to generated `.tflite` file.
            If none then generate in model log directory.
            If output='tflite_model', then return the :py:class:`yzlite.core.TfliteModel` object instead of `.tflite` file path
        accelerator: Optional hardware accelerator to use when determining the ``runtime_memory_size`` parameter.
            If None then default to the CMSIS kernels for calculating the required tensor arena size.

    Returns:
        The file path to the generated `.tflite` OR TfliteModel object if output=`tflite_model`
    """
    update_archive = False
    yzlite_model = None
    tflite_model = None
    tflite_path = None
    logger = get_yzlite_logger()

    if params and not isinstance(params, dict):
        raise Exception('params argument must be a dictionary')

    if isinstance(model, TfliteModel) or (isinstance(model, str)
                                          and model.endswith('.tflite')):
        if params is None:
            raise Exception(
                'Must provide "param" argument if "model" is a .tflite path or TfliteModel instance'
            )

        if isinstance(model, str):
            tflite_path = fullpath(model)
            tflite_model = TfliteModel.load_flatbuffer_file(tflite_path)
        else:
            tflite_model = model
            tflite_path = tflite_model.path
        # See if the .tflite already has parameters
        params_fb = tflite_model.get_metadata(TFLITE_METADATA_TAG)
        if params_fb is not None:
            model_parameters = TfliteModelParameters.deserialize(params_fb)
            if params:
                model_parameters.update(params)
        else:
            model_parameters = TfliteModelParameters(params)

    elif isinstance(model, YZLiteModel) or isinstance(model, str):
        if isinstance(model, YZLiteModel):
            yzlite_model = model
            if not output:
                update_archive = yzlite_model.check_archive_file_is_writable()
        elif model.endswith('.yzlite'):
            if params is None:
                raise Exception(
                    'Must provide "param" argument if "model" is a .yzlite path'
                )

            archive_path = model
            yzlite_model = load_yzlite_model(model, logger=logger)
            # Typically, the yzlite_model.tflite_archive_path is determined from the path of the yzlite_model.model_specification_path
            # However, in this special case, the model archive path is given
            # So we need to add a bit of hackery to ensure the yzlite_model.tflite_archive_path points to the correct location
            # by override the yzlite_model.model_specification_path
            yzlite_model._attributes._entries[
                'model_specification_path'].value = archive_path.replace(
                    '.yzlite', '.py')  # pylint: disable=protected-access
            yzlite_model.check_archive_file_is_writable(throw_exception=True)
            update_archive = True
        else:
            yzlite_model = load_yzlite_model(model)
            if not output:
                update_archive = yzlite_model.check_archive_file_is_writable()

        tflite_path = yzlite_model.tflite_archive_path
        tflite_model = TfliteModel.load_flatbuffer_file(tflite_path)
        description = yzlite_model.description
        yzlite_model.populate_model_parameters()
        model_parameters = yzlite_model.model_parameters

        # If additional parameters were given to this API
        # then add them to the model now
        if params:
            model_parameters.update(params)

    else:
        raise RuntimeError(
            'model argument must be model name, YZLiteModel or TfliteModel instance, or path to .tflite or .yzlite'
        )

    # Determine what the return value should be:
    #
    # If an output argument was supplied
    if output:
        # If we should just return the TfliteModel instance
        if output == 'tflite_model':
            retval = 'tflite_model'

        # If the path to a .tflite was given then just use that
        elif output.endswith('.tflite'):
            retval = output

        # Else we were given a directory

        # If the input was an YZLiteModel instance or name
        elif yzlite_model is not None:
            # The retval is the given output directory
            # plus the model name and .tflite extension
            if yzlite_model.test_mode_enabled:
                retval = f'{output}/{yzlite_model.name}.test.tflite'
            else:
                retval = f'{output}/{yzlite_model.name}.tflite'

        # Otherwise the retval is the given output directory
        # plus input .tflite filename
        else:
            retval_name = 'my_model.tflite' if tflite_path is None else os.path.basename(
                tflite_path)
            retval = f'{output}/{retval_name}'

    # Otherwise no output was given

    # If an YZLiteModel instance or name was given
    elif yzlite_model is not None:
        # Then update the model file in its log directory
        if yzlite_model.test_mode_enabled:
            retval = f'{yzlite_model.create_log_dir()}/{yzlite_model.name}.test.tflite'
        else:
            retval = f'{yzlite_model.create_log_dir()}/{yzlite_model.name}.tflite'

    # Else we just update the input .tflite file
    elif tflite_path is not None:
        retval = tflite_path

    else:
        raise RuntimeError('Failed to determine output path')

    # Add the model description if necessary
    if description:
        tflite_model.description = description

    # Add the default parameters to the model's metadata
    add_default_parameters(tflite_model,
                           model_parameters,
                           forced_params=params,
                           accelerator=accelerator)

    if retval == 'tflite_model':
        retval = tflite_model
    else:
        tflite_model.save(retval)

    if update_archive:
        logger.info(f'Updating {yzlite_model.archive_path}')
        yzlite_model.add_archive_file('__yzlite_model_spec__')
        yzlite_model.add_archive_file(retval)

    return retval


def add_default_parameters(tflite_model: TfliteModel,
                           model_parameters: TfliteModelParameters,
                           forced_params: dict = None,
                           accelerator: str = None,
                           add_runtime_memory_size=True):
    """Add the default parameters to the model's metadata"""

    model_parameters = copy.deepcopy(model_parameters)

    forced_params = forced_params or {}
    forced_runtime_memory_size = forced_params.get('runtime_memory_size', None)
    forced_date = forced_params.get('date', None)
    forced_hash = forced_params.get('hash', None)

    # We generate the .tflite flatbuffer twice
    # The first time, we generate with a null hash model parameter
    # and then calculate the hash of the flatbuffer (with the hash null)
    # We then update the calculated hash and re-generate the flatbuffer.
    calculated_hash = None
    for i in range(2):
        if i == 0:
            # Try to determine the RAM required by TFLM
            # and add it to the parameters
            if add_runtime_memory_size:
                if forced_runtime_memory_size is None:
                    try:
                        from yzlite.core.tflite_micro import TfliteMicro

                        tflm_model = TfliteMicro.load_tflite_model(
                            tflite_model,
                            accelerator=accelerator,
                            # Set the runtime buffer size to -1 so the optimal size is automatically found
                            runtime_buffer_size=-1
                        )
                        try:
                            model_parameters[
                                'runtime_memory_size'] = tflm_model.details.runtime_memory_size
                        finally:
                            TfliteMicro.unload_model(tflm_model)
                    except:
                        if 'runtime_memory_size' in model_parameters:
                            del model_parameters['runtime_memory_size']
                else:
                    model_parameters[
                        'runtime_memory_size'] = forced_runtime_memory_size
            else:
                if 'runtime_memory_size' in model_parameters:
                    del model_parameters['runtime_memory_size']

            # Ensure the model 'hash' and 'date' parameters are cleared
            # on the first pass
            # This ensures the generated hash is constant
            model_parameters['hash'] = ''
            model_parameters['date'] = ''
        else:
            model_parameters['hash'] = forced_hash or calculated_hash
            model_parameters['date'] = forced_date or iso_time_str()

        # Serialize the tflite_model_parameters into a flatbuffer
        serialized_model_parameters = model_parameters.serialize()
        # Add the params to the .tflite flatbuffer
        tflite_model.add_metadata(TFLITE_METADATA_TAG,
                                  serialized_model_parameters)

        # If this is the first pass, then calculate the hash
        # of the .tflite flatbuffer (including all the metadata)
        if i == 0:
            calculated_hash = generate_hash(tflite_model.flatbuffer_data)
