
import os
from multiprocessing import current_process

# If we're in a subprocess, then disable the GPU and TF logging
# This is necessary for the parallel data generators
if current_process().name != 'MainProcess':
    # Disable the GPU and logging if this is a subprocess
    os.environ['CUDA_VISIBLE_DEVICES'] = '-1'
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'  # WARNING log level
else:
    # Otherwise set the log level to debug (we use redirect_stream() to redirect the log to the cli logger)
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '0'

# If it's not already specified, then  GPU uses threads dedicated to this device
# More details here:
# https://github.com/NVIDIA/DeepLearningExamples/issues/57
os.environ['TF_GPU_THREAD_MODE'] = os.environ.get(
    'TF_GPU_THREAD_MODE', 'gpu_private')


def main():
    """Entry point for the CLI"""

    # We want to minimize the amount of package that
    # get imported by subprocesses, so we manually import
    # these packages only if "main()" is actually being invoked
    import atexit
    import signal
    import threading

    from yzlite import cli
    from yzlite.utils.system import send_signal

    # Get the logger now so that we can redirect TF logs
    cli.get_logger(and_set_yzlite_logger=False)

    # Create the "Typer" CLI instances
    cli.create_cli()

    # This will send the CTRL+Break signal to any subprocesses after 5s of the program exiting.
    # This helps to ensure that the CLI does not hang due to processes not being cleaned up properly.
    t = threading.Timer(5, send_signal, kwargs=dict(
        sig=signal.SIGTERM, pid=-1))
    atexit.register(t.start)

    # Execute the command
    try:
        cli.root_cli()
    except Exception as e:
        cli.handle_exception('Exception while executing command', e)
