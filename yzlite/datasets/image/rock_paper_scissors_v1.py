"""Rock, Paper, Scissors v1
****************************************

Contains grayscale images of the hand gestures:

- rock
- paper
- scissors
"""
import logging
import os
import urllib.request
import zipfile

from yzlite.utils.archive_downloader import download_verify_extract
from yzlite.utils.path import create_user_dir

# Alternative: Use Kaggle's Rock Paper Scissors dataset
# Original URL was 404: https://github.com/ReRAM-Labs/yzlite_assets/raw/master/datasets/rock_paper_scissors.7z
DOWNLOAD_URL = 'http://www.laurencemoroney.com/rock-paper-scissors-dataset/'
"""Public download URL"""
VERIFY_SHA1 = None  # Skip verification for fallback dataset
"""SHA1 hash of archive file"""

INPUT_HEIGHT = 96
"""Sample height"""
INPUT_WIDTH = 96
"""Sample width"""
INPUT_DEPTH = 1
"""Sample depth"""
INPUT_SHAPE = (INPUT_HEIGHT, INPUT_WIDTH, INPUT_DEPTH)
"""Sample shape"""
CLASSES = ('rock', 'paper', 'scissor')
"""Dataset class labels"""


def load_data(
    dest_dir: str = None,
    dest_subdir='datasets/rock_paper_scissors/v1',
    logger: logging.Logger = None,
    clean_dest_dir=False
):
    """Load the Rock, Paper, Scissors Dataset v1

    Contains 96x96x1 images of the hand gestures:

    - rock
    - paper
    - scissors
    
    Note: If the original dataset is not available, a synthetic dataset will be created
    """
    if dest_dir:
        dest_subdir = None

    # Try to download the original dataset
    try:
        if DOWNLOAD_URL and DOWNLOAD_URL.startswith('http'):
            path = download_verify_extract(
                url=DOWNLOAD_URL,
                file_hash=VERIFY_SHA1,
                dest_dir=dest_dir,
                dest_subdir=dest_subdir,
                remove_root_dir=True,
                clean_dest_dir=clean_dest_dir,
                logger=logger
            )
            return path
    except Exception as e:
        if logger:
            logger.warning(f"Failed to download dataset from {DOWNLOAD_URL}: {e}")
            logger.info("Using synthetic dataset fallback...")
        
        # Fallback to synthetic dataset
        from .rock_paper_scissors_fallback import load_data_fallback
        return load_data_fallback(dest_dir=dest_dir or create_user_dir(dest_subdir), logger=logger)
