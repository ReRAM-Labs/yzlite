import os
import sys

yzlite_models_shared_dir = os.path.normpath(
    os.path.dirname(os.path.abspath(__file__)) + '/..')
if yzlite_models_shared_dir not in sys.path:
    sys.path.append(yzlite_models_shared_dir)
