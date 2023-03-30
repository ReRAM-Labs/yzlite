import copy
import logging
import os
import re
import shutil
import sys
import time
from typing import List

import typer

from yzlite import YZLITE_ROOT_DIR
from yzlite import __version__ as yzlite_version
from yzlite import cli
from yzlite.utils.path import (create_tempdir, fullpath, get_user_setting,
                               recursive_listdir, remove_directory)
from yzlite.utils.shell_cmd import run_shell_cmd
from yzlite.utils.system import is_linux


@cli.build_cli.command('python_package')
def build_python_package_command(
    python_exe: str = typer.Option(None, '--python', '-p',
                                   help='Path to Python executable or Python command found on PATH. If omitted, use current Python'
                                   ),
    install: bool = typer.Option(True,
                                 help='Install the local repo into the venv, e.g.: pip install -e .'
                                 ),
    build: bool = typer.Option(True,
                               help='Build the YZLITE wheel'
                               ),
    utests: str = typer.Option('api',
                               help='''\b
Run the YZLITE unit tests against the built Python wheel in a new venv, BEFORE releasing to pypi.org. 
This should be a comma-separated list of unit tests to run. See "yzlite utest --help" for more details. 
Set as "none" to skip tests'''
                               ),
    release_test: bool = typer.Option(False,
                                      help='Release the built wheel to test.pypi.org'
                                      ),
    release_public: bool = typer.Option(False,
                                        help='Release the built wheel to pypi.org'
                                        ),
    release_utests: str = typer.Option('api',
                                       help='''\b
Run the YZLITE unit tests against the released package on pypi.org.
This should be a comma-separated list of unit tests to run. See "yzlite utest --help" for more details. 
Set as "none" to skip tests'''
                                       ),
    release_all: bool = typer.Option(False, '--all',
                                     help='''\b
Release for all supported Python versions.
~/.yzlite/user_settings.yaml must have a field python_paths: which contains list of Python executable paths, e.g.:
 python_paths:
  - C:/Python37/python.exe
  - C:/Python38/python.exe
  - C:/Python39/python.exe
'''
                                     ),
    pip_packages: str = typer.Option(None,
                                     help="""Force specific PIP packages during the unit tests. Each package should be delimited by a pipe character |
        \b
        e.g.: --pip-packages "tensorflow==2.4.*|tensorflow-probability==0.12.0"
        """
                                     ),
):
    """Build a YZLITE wheel for a specific Python version and optionally release to pypi.org

    \b
    To release the built wheel to https://test.pypi.org, add the --release-test option.
    To use this option, first update/create the file ~/.yzlite/user_settings.yaml,
    and add: 
        test_pypi_token: <token>
    where <token> is your test.pypi.org "API Token"
    \b
    Once released, the wheel may be installed via:
        pip install --extra-index-url https://test.pypi.org/simple yizhu-yzlite
    \b
    To release the built wheel to https://pypi.org, add the --release-public option.
    To use this option, first update/create the file ~/.yzlite/user_settings.yaml,
    and add:
          pypi_token: <token>
    where <token> is your pypi.org "API Token"
    \b
    Once released, the wheel may be installed via:
        pip install yizhu-yzlite

    NOTE: Before releasing, the __version__ in <yzlite repo>/yzlite/__init__.py must be incremented.

    This effectively runs the commands:
    \b
    if --install:
        export YZLITE_NO_BUILD_WRAPPERS=1
        git clone YZLITE_ROOT_DIR temp/yzlite/release/yzlite/python_<version>
        python temp/yzlite/release/yzlite/python_<version>/install_yzlite.py
    \b
    if --build:
        <venv python> setup.py bdist_wheel
    \b
    if --utests:
        rm -rf  temp/yzlite/python_venvs/tests/<python version>
        python -m venv temp/yzlite/python_venvs/tests/<python version>
        <venv python> install <built wheel>
        yzlite utest api
    \b
    if --release-test:
        twine upload --repository testpypi dist/*
        if --release-utests:
            <venv pip> install --extra-index-url https://test.pypi.org/simple yizhu-yzlite
            yzlite utest api
    \b
    if --release-public:
        twine upload dist/*
        if --release-utests:
            <venv pip> install yizhu-yzlite
            yzlite utest api

    HINT: Add the --all option to release for all Python versions at once
    """

    logger = cli.get_logger(verbose=True)

    if release_all or release_test or release_public:
        try:
            import twine
        except:
            raise RuntimeError(
                'Failed to import python package: twine, try running: pip install twine OR python ./install_yzlite.py --extras dev')

        retcode, dst_yzlite_origin_url = run_shell_cmd(
            ['git', 'config', '--get', 'remote.origin.url'], cwd=YZLITE_ROOT_DIR)
        if retcode != 0:
            cli.abort(
                msg=f'Failed to get remote.origin.url from {YZLITE_ROOT_DIR}, err: {dst_yzlite_origin_url}')

        public_yzlite_dir = get_user_setting('public_yzlite_dir')
        if public_yzlite_dir is None:
            cli.abort(msg='Must specify "public_yzlite_dir: <github yzlite repo dir>" in ~/.yzlite/user_settings.yaml which points to directory of the cloned yzlite repo on github')

        public_yzlite_dir = fullpath(public_yzlite_dir)
        current_yzlite_dir = fullpath(YZLITE_ROOT_DIR)
        if public_yzlite_dir != current_yzlite_dir:
            cli.abort(
                msg=f'~/.yzlite/user_settings.yaml:public_yzlite_dir={public_yzlite_dir}\n'
                f'does not match the current YZLITE_ROOT_DIR={current_yzlite_dir}\n'
                'You must only release the yizhu-yzlite package from the public github repo!'
            )

    if release_all:
        python_paths: List[str] = get_user_setting('python_paths')
        if not python_paths:
            cli.abort(msg='~/.yzlite/user_settings.yaml must have a field python_paths: which contains list of Python executable paths, e.g.:\n' +
                      'python_paths:\n' +
                      '  - C:/Python37/python.exe\n' +
                      '  - C:/Python38/python.exe\n' +
                      '  - C:/Python39/python.exe\n'
                      )

        for python_path in python_paths:  # pylint: disable=not-an-iterable
            cmd = copy.deepcopy(sys.argv)
            cmd.remove('--all')
            cmd.extend(['--python', python_path])
            retcode, _ = run_shell_cmd(cmd, outfile=logger, logger=logger)
            if retcode != 0:
                cli.abort(code=retcode,
                          msg=f'Failed to release wheel for {python_path}')

    #######################################
    # Determine the Python version

    if not python_exe:
        python_exe = sys.executable

    logger.info(f'Build YZLITE wheel using {python_exe} ...')

    retcode, retmsg = run_shell_cmd(
        [python_exe, '--version'], outfile=logger, logger=logger)
    if retcode != 0:
        cli.abort(
            msg=f'Failed to get Python version, err: {retmsg}\nEnsure the given Python executable is valid')

    match = re.match(r'.*\s(\d+).(\d+).(\d+)', retmsg.strip())
    if not match:
        cli.abort(msg=f'Failed to get Python version from {retmsg}')

    python_version_major = match.group(1)
    python_version_minor = match.group(2)
    python_version = f'{python_version_major}.{python_version_minor}'

    yzlite_release_dir = create_tempdir(
        f'release/yzlite/python_{python_version}')
    python_venv_dir = f'{yzlite_release_dir}/.venv'

    ##########################################
    # Clone YZLITE to tempdir and run install_yzlite.py

    if install:
        logger.info('#' * 100)

        logger.info(f'Cleaning {yzlite_release_dir} ...')
        remove_directory(yzlite_release_dir)

        logger.info(f'Cloning {YZLITE_ROOT_DIR} to {yzlite_release_dir}')

        retcode, retmsg = run_shell_cmd(
            ['git', 'clone', YZLITE_ROOT_DIR, yzlite_release_dir], outfile=logger, logger=logger)
        if retcode != 0:
            cli.abort(
                msg=f'Failed to clone {YZLITE_ROOT_DIR} to {yzlite_release_dir}, err: {retmsg}')

        logger.info('#' * 100)
        logger.info(f'Running {yzlite_release_dir}/install_yzlite.py')

        env = os.environ.copy()
        if 'PYTHONHOME' in env:
            del env['PYTHONHOME']
        env['PATH'] = os.path.dirname(python_exe) + os.pathsep + env['PATH']

        retcode, retmsg = run_shell_cmd(
            [python_exe, f'./install_yzlite.py'],
            env=env,
            cwd=yzlite_release_dir,
            outfile=logger,
            logger=logger,
        )
        if retcode != 0:
            cli.abort(msg=f'Failed to install the YZLITE, err: {retmsg}')

    if os.name == 'nt':
        python_venv_exe = f'{python_venv_dir}/Scripts/python.exe'
    else:
        python_venv_exe = f'{python_venv_dir}/bin/python3'

    if release_test:
        test_pypi_token = get_user_setting('test_pypi_token')
        if test_pypi_token is None:
            cli.abort(
                msg='When using the --release-test option, the file ~/.yzlite/user_settings.yaml must have the line: "test_pypi_token: <token>"'
                'which points the the test.pypi.org API token'
            )
        _check_pip_version(python_venv_exe, python_version,
                           use_test_pypi=True, logger=logger)

    if release_public:
        pypi_token = get_user_setting('pypi_token')
        if pypi_token is None:
            cli.abort(
                msg='When using the --release-public option, the file ~/.yzlite/user_settings.yaml must have the line: "pypi_token: <token>"'
                'which points the the pypi.org API token'
            )
        _check_pip_version(python_venv_exe, python_version,
                           use_test_pypi=False, logger=logger)

    #################################
    # Build the YZLITE wheel

    if build:
        logger.info('#' * 100)
        logger.info(
            f'Building the YZLITE Python wheel for Python {python_version} ...')

        remove_directory(f'{yzlite_release_dir}/dist')
        remove_directory(f'{yzlite_release_dir}/build')

        # That wrappers where already built in the above step
        env = os.environ.copy()
        env['YZLITE_NO_BUILD_WRAPPERS'] = '1'
        retcode, retmsg = run_shell_cmd(
            [python_venv_exe, f'{yzlite_release_dir}/setup.py', 'bdist_wheel'],
            outfile=logger,
            cwd=yzlite_release_dir,
            logger=logger,
            env=env
        )
        if retcode != 0:
            cli.abort(
                msg=f'Failed to build YZLITE Python wheel, err: {retmsg}')

    #################################
    # Get the path to the built wheel

    yzlite_version_regex = yzlite_version.replace('.', '\\.')
    wheel_paths = recursive_listdir(
        base_dir=f'{yzlite_release_dir}/dist',
        regex=f'.*/yizhu_yzlite-{yzlite_version_regex}-\\d+-cp{python_version_major}{python_version_minor}-.*' + '\\.whl'
    )
    if not wheel_paths:
        cli.abort(
            msg=f'Failed to find built .whl file in {yzlite_release_dir}/dist')

    wheel_path = wheel_paths[0].replace('\\', '/')

    if is_linux():
        # FIXME: This is a hack to enable the built wheel to
        # be uploaded to pypi.org.
        # Technically, the wheel should be built in Docker container
        # that allows for building actual "manylinux" wheels
        # More details here:
        # https://github.com/pypa/manylinux
        #
        # NOTE: The build scripts statically link most C libs
        #  and force GCC 2.17, see:
        # <yzlite repo>/cpp/shared/platforms/linux/CMakeLists.txt
        #
        # The built wheel has been verified to work on Google Colab
        # and AWS lambda Docker
        new_path = wheel_path.replace('linux_x86_64', 'manylinux2014_x86_64')
        shutil.copy(wheel_path, new_path)
        wheel_path = new_path

    logger.info('\n\n\n***')
    logger.info(f'Built wheel path: {wheel_path}' + '\n\n\n')

    ##########################################
    # Run the YZLITE unit tests
    _run_unit_tests(
        utests=utests,
        pip_args=[wheel_path],
        logger=logger,
        python_exe=python_exe,
        python_version=python_version,
        pip_packages=pip_packages
    )

    ################################
    # Upload wheel to https://test.pypi.org
    if release_test:
        logger.info('#' * 100)
        logger.info(f'Uploading {wheel_path} to https://test.pypi.org ...')
        retcode, retmsg = run_shell_cmd(
            [sys.executable, '-m', 'twine', 'upload', '--repository',
                'testpypi', '-u', '__token__', '-p', test_pypi_token, wheel_path],
            outfile=logger,
            logger=logger
        )
        if retcode != 0:
            cli.abort(
                msg=f'Failed to run upload to https://test.pypi.org, err: {retmsg}')

        _run_unit_tests(
            pip_args=['--extra-index-url', 'https://test.pypi.org/simple/',
                      f'yizhu-yzlite=={yzlite_version}'],
            logger=logger,
            python_exe=python_exe,
            python_version=python_version,
            pip_packages=pip_packages,
            retry=True,
            utests=release_utests
        )

    ################################
    # Upload wheel to https://pypi.org
    if release_public:
        logger.info('#' * 100)
        logger.info(f'Uploading {wheel_path} to https://pypi.org ...')
        retcode, retmsg = run_shell_cmd(
            [sys.executable, '-m', 'twine', 'upload', '-u',
                '__token__', '-p', pypi_token, wheel_path],
            outfile=logger,
            logger=logger
        )
        if retcode != 0:
            cli.abort(
                msg=f'Failed to run upload to https://pypi.org, err: {retmsg}')

        _run_unit_tests(
            pip_args=[f'yizhu-yzlite=={yzlite_version}'],
            logger=logger,
            python_exe=python_exe,
            python_version=python_version,
            pip_packages=pip_packages,
            retry=True,
            utests=release_utests
        )

    logger.info('Done')


def _run_unit_tests(
    utests: str,
    logger: logging.Logger,
    python_version: str,
    python_exe: str,
    pip_args: List[str],
    pip_packages: str,
    retry: bool = False,
):
    logger.info('#' * 100)
    if not utests:
        logger.info(
            'NOT running unit tests, but still checking that the package was properly built ...')

    logger.info('Installing built wheel in virtual environment ...')
    python_test_venv_dir = create_tempdir(
        f'release/python_venvs/tests/{python_version}')
    logger.info(f'Cleaning {python_test_venv_dir} ...')
    remove_directory(python_test_venv_dir)
    os.makedirs(python_test_venv_dir, exist_ok=True)

    logger.info(
        f'Creating Python v{python_version} virtual environment at {python_test_venv_dir}')
    retcode, retmsg = run_shell_cmd(
        [python_exe, '-m', 'venv', python_test_venv_dir], outfile=logger, logger=logger)
    if retcode != 0:
        cli.abort(msg=f'Failed to create Python venv, err: {retmsg}')

    if os.name == 'nt':
        python_venv_exe = f'{python_test_venv_dir}/Scripts/python.exe'
    else:
        python_venv_exe = f'{python_test_venv_dir}/bin/python3'

    logger.info('#' * 100)
    pip_cmd = [python_venv_exe, '-m', 'pip', 'install', '--force-reinstall']
    pip_cmd.extend(pip_args)
    cmd_str = ' '.join(pip_cmd)
    logger.info(f'Run {pip_cmd}')
    for i in range(3):
        retcode, retmsg = run_shell_cmd(pip_cmd, outfile=logger, logger=logger)
        if retcode != 0:
            if i < 2 and retry:
                time.sleep(3)
                continue
            cli.abort(msg=f'PIP cmd failed, err: {retmsg}')
        break

    if pip_packages:
        logger.info('#' * 100)
        logger.info(f'Forcing PIP versions: {pip_packages}')
        cmd = [python_venv_exe, '-m', 'pip', 'install']
        for pkg in pip_packages.split('|'):
            cmd.append(pkg)
        retcode, retmsg = run_shell_cmd(cmd, outfile=logger, logger=logger)
        if retcode != 0:
            cli.abort(msg=f'Failed to force Tensorflow version, err: {retmsg}')

    if os.name == 'nt':
        yzlite_exe = f'{python_test_venv_dir}/Scripts/yzlite.exe'
    else:
        yzlite_exe = f'{python_test_venv_dir}/bin/yzlite'

    retcode, retmsg = run_shell_cmd(
        [yzlite_exe, '--help'], outfile=logger, logger=logger)
    if retcode != 0:
        cmd_str = f'{yzlite_exe} --help'
        cli.abort(
            msg=f'Failed to run simple yzlite cmd: {cmd_str}, err: {retmsg}')

    if utests:
        if utests.lower() in ('0', 'none', 'off', 'no'):
            utests = None

    if utests:
        logger.info('#' * 100)
        logger.info('Running YZLITE unit tests ...')
        retcode, retmsg = run_shell_cmd(
            [yzlite_exe, 'utest', utests], outfile=logger, cwd=python_test_venv_dir, logger=logger)
        if retcode != 0:
            cli.abort(msg=f'Failed to run YZLITE unit tests, err: {retmsg}')


def _check_pip_version(venv_python_exe, python_version, use_test_pypi, logger):
    logger.info('Checking if package version already exists on server ...')
    cmd = [venv_python_exe, '-m', 'pip', 'install']
    if use_test_pypi:
        cmd.extend(['-i', 'https://test.pypi.org/simple/'])
    cmd.append('yizhu-yzlite==')

    _, retmsg = run_shell_cmd(cmd, logger=logger)

    start_index = retmsg.find('(from versions:')
    if start_index == -1:
        return
    retmsg = retmsg[start_index + len('(from versions:'):].strip()
    end_index = retmsg.find(')')
    if end_index == -1:
        return
    retmsg = retmsg[:end_index]

    server_name = 'https://test.pypi.org' if use_test_pypi else 'https://pypi.org'
    available_versions = [x.strip() for x in retmsg.split(',')]
    logger.info(
        f'YZLITE versions for Python v{python_version} found on {server_name}: {available_versions}')

    for v in available_versions:
        if v == yzlite_version:
            cli.abort(
                msg=f'YZLITE version: {yzlite_version} for Python v{python_version} is already available on {server_name}\n'
                'Must update __version__ in <yzlite repo>/yzlite/__init__.py'
            )
