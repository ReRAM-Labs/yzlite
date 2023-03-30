import os
import tempfile
import time
from contextlib import redirect_stdout

import pytest
import typer

from yzlite import cli


@cli.root_cli.command('utest')
def utest_command(
    test_type: str = typer.Argument(None,
                                    help='''\b
Comma separated list of unit test types, options are:
- all - Run all the tests, default if omitted
- cli - Run CLI tests
- api - Run API tests
- model - Run reference model basic tests
- model-full - Run reference model full tests
- cpp - Build C++ applications tests
- studio - Simplicity Studio project generation/building tests
'''
                                    ),
    test_arg: str = typer.Argument(None,
                                   help='Argument for specific test(s) to run. Refer to the pytests -k option for more details: https://docs.pytest.org/en/latest/example/markers.html#using-k-expr-to-select-tests-based-on-their-name'
                                   ),
    verbose: bool = typer.Option(False, '--verbose', '-v',
                                 help='Enable verbose console logs'
                                 ),
    list_only: bool = typer.Option(False, '--list', '-l',
                                   help='Only list the available unit tests'
                                   ),
    clear_cache: bool = typer.Option(False,
                                     help='Clear the YZLITE cache directory before running tests'
                                     ),
    unique_temp_dir: bool = typer.Option(False,
                                         help='Use a unique path for the tmp directory'
                                         ),
):
    """Run the all unit tests"""

    # Import all required packages here instead of at top
    # to help improve the CLI's responsiveness
    from yzlite import YZLITE_DIR, YZLITE_ROOT_DIR
    from yzlite.utils.path import clean_directory, create_tempdir
    from yzlite.utils.python import as_list
    from yzlite.utils.test_helper import get_logger, pytest_results_dir

    all_types = {'all', 'cli', 'api', 'model', 'model-full', 'cpp', 'studio'}
    test_type = test_type or 'all'
    test_type = set(test_type.split(','))
    cpp_tests_dir = f'{YZLITE_ROOT_DIR}/cpp/tools/tests'

    if not test_type.issubset(all_types):
        cli.abort(
            msg=f'Unsupported test type: {",".join(test_type)}. Supported types are: {",".join(all_types)}')

    test_dirs = []
    if test_type & {'all', 'cli'}:
        test_dirs.append('cli/tests')

    if test_type & {'all', 'api'}:
        test_dirs.append('core/tflite_micro/tests')
        test_dirs.append('core/tflite_model/tests')
        test_dirs.append('core/tflite_model_parameters/tests')
        test_dirs.append('core/preprocess/audio/audio_feature_generator/tests')

    if test_type & {'all', 'model', 'model-full'}:
        if not (test_type & {'model-full'}):
            os.environ['YZLITE_UTEST_BASIC_MODEL_PARAMS'] = '1'
        test_dirs.append('models/tests')

    if test_type & {'all', 'cpp'}:
        if os.path.exists(cpp_tests_dir):
            test_dirs.append('../cpp/tools/tests/test_build_apps.py')
            test_dirs.append('../cpp/tools/tests/test_build_cli.py')
        elif (test_type & {'cpp'}):
            cli.abort(
                msg=f'{cpp_tests_dir} does not exist. Did you clone the YZLITE git repo?')

    if test_type & {'all', 'studio'}:
        if os.path.exists(cpp_tests_dir):
            test_dirs.append('../cpp/tools/tests/test_simplicity_studio.py')
        elif (test_type & {'studio'}):
            cli.abort(
                msg=f'{cpp_tests_dir} does not exist. Did you clone the YZLITE git repo?')

    test_dirs = as_list(test_dirs)

    clean_directory(pytest_results_dir)
    logger = get_logger('utest_cli', console=True)
    logger.set_terminator('')
    logger.info(f'Generating logs at: {pytest_results_dir}\n')

    if unique_temp_dir:
        from yzlite.utils import path
        path.TEMP_BASE_DIR = f'{tempfile.gettempdir()}/yzlite/{int(time.time())}'
        logger.warning(f'Setting temp dir as {path.TEMP_BASE_DIR}')

    if clear_cache:
        utest_cache_dir = create_tempdir('utest_cache')
        clean_directory(utest_cache_dir)
        os.environ['YZLITE_CACHE_DIR'] = utest_cache_dir
        logger.warning(
            f'Setting YZLITE_CACHE_DIR="{os.environ["YZLITE_CACHE_DIR"]}"\n')
    else:
        logger.warning(
            'NOT clearing YZLITE cache, using existing cache at ~/.yzlite\n')

    os.environ['CUDA_VISIBLE_DEVICES'] = '-1'  # Disable the GPU as well
    cli.print_info('Disabling usage of the GPU, e.g.: CUDA_VISIBLE_DEVICES=-1')

    cmd = []
    cmd.append(f'--rootdir={YZLITE_ROOT_DIR}')
    cmd.append(f'--html-report={pytest_results_dir}/report.html')
    cmd.append('--color=yes')
    cmd.extend(['-o', 'log_cli=true'])
    if verbose:
        cmd.append('-v')
        cmd.append('--log-cli-level=DEBUG')
    cmd.append('--show-capture=all')
    cmd.extend(['-W', 'ignore::DeprecationWarning'])
    if list_only:
        cmd.append('--collect-only')
    if test_arg is not None:
        cmd.extend(['-k', test_arg])

    for d in test_dirs:
        cmd.append(f'{YZLITE_DIR}/{d}')

    logger.info('Executing: pytest ' + " ".join(cmd) + '\n')
    with redirect_stdout(logger):
        retcode = pytest.main(cmd)

    logger.info(f'\n\nFor more details, see: {pytest_results_dir}\n')
    cli.abort(code=retcode)
