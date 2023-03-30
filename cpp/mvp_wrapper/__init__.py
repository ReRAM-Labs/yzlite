import logging

from yzlite import YZLITE_ROOT_DIR
from yzlite.utils.cmake import build_yzlite_target


def build_mvp_wrapper(
    clean: bool = True,
    verbose: bool = False,
    logger: logging.Logger = None,
    use_user_options=False,
    debug: bool = False,
):
    """Build the MVP kernels + simulator Python wrapper for the current OS/Python environment"""
    logger = logger or logging.getLogger()

    build_yzlite_target(
        target='yzlite_mvp_wrapper',
        build_subdir='mvp_wrap',
        source_dir=YZLITE_ROOT_DIR,
        clean=clean,
        verbose=verbose,
        debug=debug,
        logger=logger,
        use_user_options=use_user_options,
    )
