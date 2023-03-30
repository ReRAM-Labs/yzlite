import pytest

from yzlite.utils.commander import query_platform
from yzlite.utils.test_helper import run_yzlite_command


def test_commander_help():
    run_yzlite_command('commander', '--help')


def test_commander_device_info():
    try:
        query_platform()
    except:
        pytest.skip('No device connected')
        return

    try:
        run_yzlite_command('commander', 'device', 'info', '-d', 'efr32')
    except RuntimeError:
        run_yzlite_command('commander', 'device', 'info', '-d', 'efm32')
