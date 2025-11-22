
import os
import sys

__version__ = '0.2.7'

YZLITE_DIR = os.path.dirname(os.path.abspath(__file__)).replace('\\', '/')
YZLITE_ROOT_DIR = os.path.dirname(YZLITE_DIR).replace('\\', '/')


def disable_tensorflow():
    """Disable the Tensorflow Python package with a placeholder

    Tensorflow is very bloaty
    If we can get away without importing it we can save a lot of time
    and potentially diskspace if we remove it as a dependency

    This also disables matplotlib which can also be bloaty
    """
    sys.path.insert(0, f'{YZLITE_DIR}/core/keras/tensorflow_placeholder')


if os.environ.get('YZLITE_DISABLE_TF', '0') == '1':
    disable_tensorflow()
