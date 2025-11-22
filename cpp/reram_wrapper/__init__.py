"""YZLITE ReRAM Wrapper

This wrapper integrates ReRAM simulation with TensorFlow Lite Micro
"""

import logging

from yzlite import YZLITE_ROOT_DIR
from yzlite.utils.cmake import build_yzlite_target

__version__ = '0.1.0'


def build_reram_wrapper(
    clean: bool = True,
    verbose: bool = False,
    logger: logging.Logger = None,
    use_user_options=False,
    debug: bool = False,
):
    """Build the ReRAM simulator Python wrapper for the current OS/Python environment"""
    logger = logger or logging.getLogger()

    build_yzlite_target(
        target='yzlite_reram_wrapper',
        build_subdir='reram_wrap',
        source_dir=YZLITE_ROOT_DIR,
        clean=clean,
        verbose=verbose,
        debug=debug,
        logger=logger,
        use_user_options=use_user_options,
    )

