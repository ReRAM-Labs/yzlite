import logging

import numpy as np

from yzlite.utils.logger import get_logger as _get_logger


class ArchiveFileNotFoundError(FileNotFoundError):
    '''File not found in model archive exception'''


def get_yzlite_logger() -> logging.Logger:
    """Return the YZLITE logger
    If not logger has been previously set, then create a default logger
    """
    if 'logger' not in globals():
        logger = _get_logger('yzlite', console=True)
        set_yzlite_logger(logger)

    logger = globals()['logger']

    # Try to add TF logs to the YZLITE log file
    try:
        tf_logger = logging.getLogger('tensorflow')
        yzlite_file_handler = logger.file_handler
        if yzlite_file_handler:
            already_added = False
            for h in tf_logger.handlers:
                if h == yzlite_file_handler:
                    already_added = True
                    break

            if not already_added:
                tf_logger.addHandler(yzlite_file_handler)
    except:
        pass

    return logger


def set_yzlite_logger(logger: logging.Logger):
    """Set the YZLITE logger"""
    globals()['logger'] = logger


def convert_y_to_labels(y: np.ndarray) -> np.ndarray:
    """Convert a 1-hot encoded list of samples to a 1D list of class labels"""
    if len(y.shape) == 2 and y.shape[1] == 1:
        return np.squeeze(y, axis=1)

    labels = np.zeros(y.shape[0], dtype=int)
    for i in range(len(labels)):  # pylint: disable=consider-using-enumerate
        labels[i] = np.argmax(y[i])
    return labels
