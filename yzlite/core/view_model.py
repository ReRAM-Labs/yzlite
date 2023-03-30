import http
import os
import time
from typing import Union

from yzlite.utils.network import find_listening_port
from yzlite.utils.path import create_tempdir, fullpath
from yzlite.utils.python import append_exception_msg

from .model import (KerasModel, YZLiteModel, load_tflite_or_keras_model,
                    load_yzlite_model)
from .quantize_model import quantize_model
from .tflite_model import TfliteModel
from .utils import ArchiveFileNotFoundError, get_yzlite_logger

DEFAULT_PORT = 8080
DEFAULT_HOST = 'localhost'


def view_model(
    model: Union[str, YZLiteModel, KerasModel, TfliteModel],
    host: str = None,
    port: int = None,
    test: bool = False,
    build: bool = False,
    tflite: bool = False,
    timeout: float = 7.0
):
    """View an interactive graph of the given model in a webbrowser

    .. seealso::
       * `Model Visualization Guide <https://github.com/chenxingqiang/yzlite/docs/guides/model_visualizer.html>`_
       * `Model visualization API examples <https://github.com/chenxingqiang/yzlite/yzlite/examples/view_model.html>`_

    Args:
        model: Either 

            * a path to a `.tflite`, `.h5`, `.yzlite.zip`, `.py` file,
            * or a :py:class:`yzlite.core.YZLiteModel`, :py:class:`yzlite.core.KerasModel`,
            * or :py:class:`yzlite.core.TfliteModel` instance
        host: Optional, host name of local HTTP server
        port: Optional, listening port of local HTTP server
        test: Optional, if true load previously generated test model
        build: Optional, if true, build the YZLITE model rather than loading previously trained model
        tflite: If true, view .tflite model otherwise view keras model
        timeout: Amount of time to wait before terminaing HTTP server
    """
    try:
        import netron
    except:
        raise RuntimeError(
            'Failed import netron Python package, try running: pip install netron OR pip install yizhu-yzlite[full]')

    # The default netron.server.ThreadedHTTPServer class that netron
    # uses inherits ThreadingMixIn which can hang.
    # Override this class to use http.server.ThreadingHTTPServer
    # which does not hang when it's shutdown
    netron.server.ThreadedHTTPServer = http.server.ThreadingHTTPServer
    netron.server._ThreadedHTTPServer = http.server.ThreadingHTTPServer

    logger = get_yzlite_logger()

    model_path = _load_or_build_model(
        model,
        tflite=tflite,
        build=build,
        test=test
    )
    logger.debug(f'Viewing model file: {model_path}')

    host = host or DEFAULT_HOST
    port = port or find_listening_port(default_port=DEFAULT_PORT)

    if os.getenv('YZLITE_UNIT_TEST'):
        # Just return if we're doing a unit test
        return

    netron.start(file=model_path, address=(host, port), browse=True)
    start_time = time.time()
    while time.time() - start_time < timeout:
        try:
            time.sleep(0.1)
        except KeyboardInterrupt:
            break

    netron.stop()


def _load_or_build_model(
    model: Union[str, YZLiteModel, KerasModel, TfliteModel],
    test: bool,
    build: bool,
    tflite: bool
):

    if isinstance(model, KerasModel):
        model_path = f'{create_tempdir("tmp_models")}/model.h5'
        model.save(model_path, save_format='tf')
        return model_path

    if isinstance(model, TfliteModel):
        model_path = f'{create_tempdir("tmp_models")}/model.tflite'
        model.save(model_path)
        return model_path

    if isinstance(model, YZLiteModel):
        yzlite_model = model

    elif isinstance(model, str):
        if model.endswith(('.tflite', '.h5')):
            model_path = fullpath(model)
            if not os.path.exists(model_path):
                raise FileNotFoundError(f'Model not found: {model_path}')
            return model_path

        else:
            yzlite_model = load_yzlite_model(
                model,
                test=test,
                print_not_found_err=True
            )
    else:
        raise ValueError('Invalid model argument')

    if build:
        if tflite:
            model_path = create_tempdir(
                "tmp_models") + f'/{yzlite_model.name}.tflite'
            quantize_model(
                model=yzlite_model,
                build=True,
                output=model_path
            )
            return model_path
        else:
            keras_model = load_tflite_or_keras_model(yzlite_model)
            model_path = f'{create_tempdir("tmp_models")}/model.h5'
            keras_model.save(model_path)
            return model_path

    else:
        try:
            if tflite:
                return yzlite_model.tflite_archive_path
            else:
                return yzlite_model.h5_archive_path
        except ArchiveFileNotFoundError as e:
            append_exception_msg(e,
                                 '\nAlternatively, add the --build option to view the model without training it first'
                                 )
            raise
