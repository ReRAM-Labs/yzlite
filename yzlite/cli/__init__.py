import typer

from .utils import (AdditionalArgumentParsingCommand,
                    VariableArgumentOptionParser,
                    VariableArgumentParsingCommand, abort, create_cli,
                    get_logger, handle_exception, parse_accelerator_option,
                    print_did_you_mean_error, print_error, print_info,
                    print_warning)

# This is set at the beginning of main()
root_cli: typer.Typer = None
# YZLITE build command group, this is set at the beginning of main()
build_cli: typer.Typer = None


def is_command_active() -> bool:
    """Return if a CLI command is currently active"""
    return root_cli is not None
