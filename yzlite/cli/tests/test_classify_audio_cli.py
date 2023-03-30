import pytest

from yzlite import YZLITE_DIR
from yzlite.utils.commander import query_platform
from yzlite.utils.test_helper import run_yzlite_command


def test_help():
    run_yzlite_command('classify_audio', '--help')


def test_pc_name():
    run_yzlite_command('classify_audio', 'tflite_micro_speech', '--test')


def test_pc_archive():
    archive_path = f'{YZLITE_DIR}/models/tflite_micro/tflite_micro_speech.yzlite.zip'
    run_yzlite_command('classify_audio', archive_path, '--test')


def test_device():
    try:
        query_platform()
    except:
        pytest.skip('No embedded device connected')
        return

    run_yzlite_command(
        'classify_audio', 'tflite_micro_speech', '--device', '--test')
