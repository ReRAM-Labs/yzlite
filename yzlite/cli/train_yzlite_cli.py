
import typer

from yzlite import cli


@cli.root_cli.command('train')
def train_model_command(
    model: str = typer.Argument(...,
                                help='''\b
Name of YZLITE model OR path to model specification python script.
If YZLITE model name given, optionally append "-test" to execute a training "dryrun".
This ensures everything works by quickly training the model;
Dry-run training limits the number of epochs and dataset size.
All results are stored in a test directory and archive.
''',
                                metavar='<model>'
                                ),
    epochs: int = typer.Option(None, '-e', '--epochs',
                               help='Override the number of training epochs define by the YZLITE model',
                               metavar='<epochs>'
                               ),
    weights: str = typer.Option(None, '--weights', '-w',
                                help='''\b
Optional, load weights from previous training session.
May be one of the following:
- If option omitted then trained with initial weights
- Absolute path to a generated weights .h5 file generated by Keras during training
- The keyword 'best'; find the best weights from the previous training session
- Filename of .h5 in <model log dir>/train/weights''',
                                metavar='<weights>'
                                ),
    verbose: bool = typer.Option(False, '--verbose', '-v',
                                 help='Enable verbose console logs'
                                 ),
    resume: bool = typer.Option(False,
                                help='Resume the training from a previous training session using the last stored checkpoint weights'
                                ),
    resume_epoch: int = typer.Option(0,
                                     help='Specify the epoch to resume training',
                                     metavar='<epoch>'
                                     ),
    clean: bool = typer.Option(False,
                               help='Clean all previous training logs files, weights, and checkpoints'
                               ),
    show: bool = typer.Option(False,
                              help='Display the generated model training history diagram'
                              ),
    evaluate: bool = typer.Option(True,
                                  help='After training, evaluate the .h5 and .tflite models'
                                  ),
    test: bool = typer.Option(False,
                              help='Do a dryrun of training the model. This does the same thing as: yzlite train my_model-test'
                              ),
    post_process: bool = typer.Option(False, '--post',
                                      help='This allows for post-processing the training results (e.g. uploading to a cloud) if supported by the given YZLiteModel'
                                      )
):
    """Train an ML model

    \b
    This trains a model using the configuration specified in the given YZLITE model.
    \b
    All training results are stored <model log dir>/train.
    After training completes, an archive file is generated at:
      <YZLITE model directory>/<YZLITE model name>.yzlite.zip
    which contains:
    - YZLITE model specification python script
    - Keras model in .h5 format
    - Quantized .tflite model
    - Model summary
    - Training log
    \b
    For more details see:
    https://github.com/ReRAM-Labs/yzlite/docs/guides/model_training
    \b
    ----------
     Examples
    ----------
    \b
    # Execute model training dryrun
    yzlite train image_example1-test
    \b
    # Clean any previous training logs & checkpoints,
    # then train for 100 epochs
    yzlite train image_example1 --clean --epochs 100
    \b
    # Resume model from previous session at the last save checkpoint
    yzlite train image_example1 --resume
    \b
    # Resume model from previous session at epoch 43
    yzlite train image_example1 --resume-epoch 43
    \b
    # Do NOT evaluate the model after training
    yzlite train image_example1 --no-evaluate
    """
    # Import all required packages here instead of at top
    # to help improve the CLI's responsiveness
    from yzlite.core import (EvaluateAutoEncoderMixin, EvaluateClassifierMixin,
                             EvaluateMixin, evaluate_model, load_yzlite_model,
                             train_model)
    from yzlite.core.model.mixins.archive_mixin import ARCHIVE_EXTENSION
    from yzlite.utils.logger import ConsoleLoggerLevelContext

    logger = cli.get_logger(verbose=verbose)

    if model.endswith((ARCHIVE_EXTENSION, '.tflite', '.h5')):
        cli.abort(
            msg='Must provide name of an YZLITE model or the path to an model specification python script')

    if resume and resume_epoch == 0:
        # Resume from last available checkpoint
        resume_epoch = -1

    # Find the YZLITE Model file
    try:
        yzlite_model = load_yzlite_model(
            model,
            test=test,
            print_not_found_err=True
        )
    except Exception as e:
        cli.handle_exception('Failed to load model', e)

    if getattr(yzlite_model, 'tensorboard', {}):
        logger.info(
            f'HINT: View more training logs by running the command: yzlite tensorboard {model}')

    # Train the model
    try:
        train_model(
            yzlite_model,
            weights=weights,
            epochs=epochs,
            resume_epoch=resume_epoch,
            verbose=True,
            clean=clean,
            show=show,
            post_process=post_process
        )

        if evaluate and isinstance(yzlite_model, EvaluateMixin):
            try:
                logger.info('\n\n' + '-' * 80)
                logger.info('Evaluating the .h5 model ...')
                with ConsoleLoggerLevelContext(logger, 'ERROR'):
                    h5_eval_results = evaluate_model(
                        yzlite_model,
                        tflite=False,
                        verbose=True,
                        post_process=post_process
                    )
                logger.info(f'{h5_eval_results}')

                if yzlite_model.tflite_converter and \
                   (yzlite_model.eval_custom_function is not None or
                        isinstance(yzlite_model, (EvaluateClassifierMixin, EvaluateAutoEncoderMixin))):

                    logger.info('Evaluating the .tflite model ...')
                    with ConsoleLoggerLevelContext(logger, 'ERROR'):
                        tflite_eval_results = evaluate_model(
                            yzlite_model,
                            tflite=True,
                            verbose=True,
                            post_process=post_process
                        )
                    logger.info(f'{tflite_eval_results}')

            except Exception as e:
                logger.error('Error while evaluating model', exc_info=e)

    except Exception as e:
        cli.handle_exception('Failed to train model', e)
