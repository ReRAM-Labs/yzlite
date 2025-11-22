
import logging

import typer

from cpp.reram_wrapper import build_reram_wrapper
from yzlite import cli


@cli.build_cli.command('reram_wrapper')
def build_reram_wrapper_command(
    verbose: bool = typer.Option(False, '--verbose', '-v',
                                 help='Enable verbose console logs'
                                 ),
    clean: bool = typer.Option(True,
                               help='Clean the build directory before building'
                               ),
    use_user_options: bool = typer.Option(False, '--user', '-u',
                                          help='Use the <yzlite>/user_options.cmake file while building the wrapper. If omitted then this file is IGNORED'
                                          ),
    debug: bool = typer.Option(False, '--debug', '-d',
                               help='Build debug version of ReRAM wrapper')
):
    """Build the ReRAM simulator Tensorflow-Lite Micro Python wrapper

    \b
    This builds the ReRAM simulator Python wrapper:  
    https://github.com/ReRAM-Labs/yzlite/tree/master/cpp/reram_wrapper
    \b
    NOTE: The built wrapper library is copied to:
    https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/tflite_micro/accelerators/reram

    """

    logger = cli.get_logger(verbose=verbose)

    try:
        build_reram_wrapper(
            logger=logger,
            clean=clean,
            verbose=verbose,
            use_user_options=use_user_options,
            debug=debug
        )
    except Exception as e:
        cli.handle_exception('Failed to build reram_wrapper', e)

    logger.info('Done')

