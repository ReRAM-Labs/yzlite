import pytest

from yzlite import YZLITE_DIR
from yzlite.utils.commander import query_platform
from yzlite.utils.test_helper import run_yzlite_command


def test_help():
    run_yzlite_command('fingerprint_reader', '--help')


def test_with_model_name():
    try:
        query_platform()
    except:
        pytest.skip('No embedded device connected')
        return
    run_yzlite_command('fingerprint_reader',
                       'fingerprint_signature_generator', '--test')
