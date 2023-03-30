

import typer

from yzlite import cli


@cli.root_cli.command('quantize')
def quantize_model_command(
    model: str = typer.Argument(...,
                                help='''\b
One of the following:
- Name of YZLITE model
- Path to trained model's archive (.yzlite.zip)
- Path to YZLITE model's python script''',
                                metavar='<model>'
                                ),
    verbose: bool = typer.Option(False, '--verbose', '-v',
                                 help='Enable verbose console logs'
                                 ),
    output: str = typer.Option(None, '--output', '-o',
                               help='''\b
One of the following:
- Path to generated output .tflite file
- Directory where output .tflite is generated
- If omitted, .tflite is generated in the YZLITE model's log directory and the model archive is updated''',
                               metavar='<path>'
                               ),
    build: bool = typer.Option(False, '--build', '-b',
                               help='''\b
Build the Keras model rather than loading from a pre-trained .h5 file in the YZLITE model's archive.
This is useful if a .tflite needs to be generated to view its structure''',
                               ),
    weights: str = typer.Option(None, '--weights', '-w',
                                help='''\b
Optional, load weights from previous training session.
May be one of the following:
- If option omitted then quantize using output .h5 from training
- Absolute path to a generated weights .h5 file generated by Keras during training
- The keyword `best`; find the best weights in <model log dir>/train/weights
- Filename of .h5 in <model log dir>/train/weights
''',
                                metavar='<value>'
                                ),
    update_archive: bool = typer.Option(None,
                                        help='Update the model archive with the quantized model'
                                        ),
):
    """Quantize a model into a .tflite file

    \b
    The model is automatically quantized after training completes.
    This is useful if the yzlite_model.tflite_converter parameters
    are modified after the model is trained.
    \b
    For more details see:
    https://github.com/chenxingqiang/yzlite/docs/guides/model_quantization
    \b
    ----------
     Examples
    ----------
    \b
    # Quantize the previously trained model
    # and update its associated model archive audio_example1.yzlite.zip
    # with the generated .tflite model file
    yzlite quantize audio_example1
    \b
    # Generate a .tflite in the current directory from the given model archive
    yzlite quantize audio_example1.yzlite.zip --output .
    \b
    # Generate a .tflite from the given model python script
    # The .tflite is generated in the same directory as the Python script
    yzlite quantize my_model.py --build

    """

    # Import all required packages here instead of at top
    # to help improve the CLI's responsiveness
    from yzlite.core import load_yzlite_model, quantize_model, summarize_model

    logger = cli.get_logger(verbose=verbose)

    try:
        yzlite_model = load_yzlite_model(
            model,
            print_not_found_err=True
        )
    except Exception as e:
        cli.handle_exception('Failed to load model', e)

    try:
        tflite_path = quantize_model(
            yzlite_model,
            output=output,
            weights=weights,
            build=build,
            update_archive=update_archive
        )
    except Exception as e:
        cli.handle_exception('Failed to quantize model', e)

    if output:
        logger.info(f'Generated model at {tflite_path}')

    try:
        summary = summarize_model(
            yzlite_model,
            tflite=tflite_path,
        )
        logger.info(summary)
    except Exception as e:
        cli.print_warning(f'Failed to summarize model, err: {e}')
