
import time

import typer

from yzlite import cli


@cli.root_cli.command('profile')
def profile_model_command(
    model: str = typer.Argument(...,
                                help='''\b
One of the following:
- Name of previously trained YZLITE model
- Path to .tflite model file
- Path to .yzlite.zip model archive file''',
                                metavar='<model>'
                                ),
    accelerator: str = typer.Option(None, '--accelerator', '-a',
                                    help='''\b
Name of accelerator for which to compile then profile model.
If omitted, then profile using the reference kernels''',
                                    metavar='<name>'
                                    ),
    build: bool = typer.Option(False,
                               help='''Build and quantize before profiling the model rather
than loading from a pre-trained .tflite file in the YZLITE model's archive'''
                               ),
    verbose: bool = typer.Option(False, '--verbose', '-v',
                                 help='Enable verbose console logs'
                                 ),
    use_device: bool = typer.Option(False, '-d', '--device',
                                    help='''\b
Profile model on embedded device instead of simulator.
If this option is provided, then the device must be locally connected'''
                                    ),
    port: str = typer.Option(None,
                             help='''\b
Serial COM port of the embedded device.
This is only used with the --device option.
If omitted, then attempt to automatically determine the serial COM port''',
                             metavar='<port>'
                             ),
    output: str = typer.Option(None, '-o', '--output',
                               help='Generate profiling report in given output directory',
                               metavar='<output>'
                               ),
    no_format_units: bool = typer.Option(False, '--no-format',
                                         help='By default, the number units will be formatted for easier reading. Use this option to return the unformatted values'
                                         ),
    estimates: bool = typer.Option(False,
                                   help='If profiling in the simulator, this will estimate additional metrics such as CPU cycles and energy. Disabling this option can reduce profiling time'
                                   ),
    post_process: bool = typer.Option(False, '--post',
                                      help='This allows for post-processing the profiling results (e.g. uploading to a cloud) if supported by the given YZLiteModel'
                                      )
):
    """Profile a model to determine how efficiently is may run on hardware

    \b
    This will profile a YZLITE model or .tflite model file
    in a simulator or on a locally connected, embedded device.
    \b
    NOTE: *Any* .tflite model file supported by Tensorflow-Lite Micro will
    work with this command (i.e. The .tflite does NOT need to be generated by the YZLITE).
    \b
    For more details see:
    https://github.com/ReRAM-Labs/yzlite/docs/guides/model_profiler
    \b
    ----------
     Examples
    ----------
    \b
    # Profile the YZLITE model in the MVP accelerator simulator
    yzlite profile image_example1 --accelerator MVP --estimates
    \b
    # Profile a .tflite without any hardware acceleration
    yzlite profile ~/workspace/some_model.tflite --estimates
    \b
    # Profile the model on the connected development board
    # using the MVP accelerator
    yzlite profile audio_example1 --accelerator MVP --device

    """

    # Import all required packages here instead of at top
    # to help improve the CLI's responsiveness
    from yzlite.core import profile_model

    start_time = time.time()
    logger = cli.get_logger(verbose=verbose)

    accelerator = cli.parse_accelerator_option(accelerator)

    if not estimates and not use_device:
        logger.info(
            'HINT: Add the --estimates option to generate energy and CPU cycle estimates')

    if not verbose:
        saved_console_level = logger.console_level
        logger.console_level = 'WARNING'

    try:
        profiling_report = profile_model(
            model,
            accelerator=accelerator,
            use_device=use_device,
            port=port,
            build=build,
            return_estimates=estimates,
            post_process=post_process
        )
    except Exception as e:
        cli.handle_exception('Failed to profile model', e)

    if not verbose:
        logger.console_level = saved_console_level

    if output:
        logger.info(f'Generating profiling report at {output}')
        profiling_report.generate_report(
            output_dir=output,
            format_units=not no_format_units
        )
    else:
        cli.print_info(
            '\n' + profiling_report.to_string(format_units=not no_format_units))

    cli.print_info(f'Profiling time: {time.time()-start_time:3f} seconds')
