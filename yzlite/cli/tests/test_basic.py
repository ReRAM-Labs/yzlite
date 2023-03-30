
import yzlite
from yzlite.utils.test_helper import run_yzlite_command


def test_version():
    retmsg = run_yzlite_command('--version')
    assert retmsg.strip() == yzlite.__version__


def test_help():
    run_yzlite_command('--help')
