import pytest

from yzlite import YZLITE_DIR
from yzlite.utils.commander import query_platform
from yzlite.utils.path import create_tempdir, remove_directory
from yzlite.utils.test_helper import run_yzlite_command
from yzlite.utils.test_helper.data import IMAGE_EXAMPLE1_TFLITE_PATH


def test_profile_help():
    run_yzlite_command('profile', '--help')


def test_profile_model_name():
    run_yzlite_command('profile', 'image_example1')


def test_profile_model_name_mvp():
    run_yzlite_command('profile', 'image_example1', '--accelerator', 'mvp')


def test_profile_archive_path():
    path = f'{YZLITE_DIR}/models/examples/image_example1.yzlite.zip'
    run_yzlite_command('profile', path)


def test_profile_tflite_path():
    run_yzlite_command('profile', IMAGE_EXAMPLE1_TFLITE_PATH)


def test_profile_build():
    run_yzlite_command('profile', 'image_example1', '--build')


def test_profile_output():
    out_dir = create_tempdir('tests/profile_output')
    remove_directory(out_dir)
    run_yzlite_command('profile', 'image_example1', '--output', out_dir)
    remove_directory(out_dir)


def test_profile_noformat():
    run_yzlite_command('profile', 'image_example1', '--no-format')


def test_profile_device():
    try:
        query_platform()
    except:
        pytest.skip('No device connected')
        return

    run_yzlite_command('profile', 'image_example1', '--device')
