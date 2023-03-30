import sys

import typer
from click.parser import OptionParser
from typer.core import TyperCommand

from yzlite import cli


class _VariableArgumentOptionParser(OptionParser):
    def parse_args(self, args):
        if len(args) >= 2:
            self.ctx.meta['vargs'] = args[1:]
            return super().parse_args(args[:1])
        else:
            return super().parse_args(args)


class _VariableArgumentParsingCommand(TyperCommand):
    def make_parser(self, ctx):
        """Creates the underlying option parser for this command."""
        parser = _VariableArgumentOptionParser(ctx)
        for param in self.get_params(ctx):
            param.add_to_parser(parser, ctx)
        return parser


@cli.root_cli.command("custom", cls=_VariableArgumentParsingCommand)
def custom_model_command(
    ctx: typer.Context,
    model: str = typer.Argument(...,
                                help='Name of YZLITE model OR path to model specification python script',
                                metavar='<model>'
                                )
):
    """Custom Model Operations

    This allows for running custom-defined model commands.
    The model operations are defined in the model specification file.

    ----------
     Examples
    ----------
    \b
    # Run the 'visualize' custom command provided by the 
    # siamese_contrastive example model
    yzlite custom siamese_contrastive visualize

    """

    # Import all required packages here instead of at top
    # to help improve the CLI's responsiveness
    from yzlite.core import load_yzlite_model

    # Find the YZLITE Model file
    try:
        yzlite_model = load_yzlite_model(
            model,
            print_not_found_err=True
        )
    except Exception as e:
        cli.handle_exception('Failed to load model', e)

    if len(yzlite_model.cli.registered_commands) == 0:
        cli.abort(
            msg=f'Model {yzlite_model.name} does not define any custom commands')

    # This works around an issue with yzlite_cli.py
    # modules that only have one command
    # It simply adds a hidden dummy command to the root CLI
    @yzlite_model.cli.command('_yzlite_workaround', hidden=True)
    def _yzlite_workaround():
        pass

    try:
        orig_argv = sys.argv
        sys.argv = ['yzlite'] + ctx.meta['vargs']
        yzlite_model.cli(prog_name=f'yzlite custom {yzlite_model.name}')
    except Exception as e:
        cli.handle_exception(
            f'Model {yzlite_model.name} custom command failed', e)
    finally:
        sys.argv = orig_argv
