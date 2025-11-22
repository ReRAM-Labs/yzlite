"""Rock, Paper, Scissors v1
****************************************

Contains grayscale images of the hand gestures:

- rock
- paper
- scissors

Uses TensorFlow Datasets for reliable access.
"""
import logging
import os
import tensorflow_datasets as tfds

DOWNLOAD_URL = None  # Using TensorFlow Datasets instead
"""Public download URL"""
VERIFY_SHA1 = None
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
    """Load the Rock, Paper, Scissors Dataset v1 using TensorFlow Datasets

    Contains 96x96x1 images of the hand gestures:

    - rock
    - paper
    - scissors
    
    Uses TensorFlow Datasets for reliable access to the rock_paper_scissors dataset.
    """
    from yzlite.utils.path import create_user_dir
    import numpy as np
    from PIL import Image
    
    if dest_dir is None:
        dest_dir = create_user_dir(dest_subdir)
    
    os.makedirs(dest_dir, exist_ok=True)
    
    if logger:
        logger.info(f"Loading Rock Paper Scissors dataset using TensorFlow Datasets...")
    
    # Load using TensorFlow Datasets
    try:
        # Download the dataset
        ds_train = tfds.load('rock_paper_scissors', split='train', as_supervised=True)
        ds_test = tfds.load('rock_paper_scissors', split='test', as_supervised=True)
        
        # Convert to image files
        for split_name, dataset in [('train', ds_train), ('test', ds_test)]:
            split_dir = os.path.join(dest_dir, split_name)
            
            for class_name in CLASSES:
                class_dir = os.path.join(split_dir, class_name)
                os.makedirs(class_dir, exist_ok=True)
            
            # Save images
            for idx, (image, label) in enumerate(dataset.take(500)):  # Limit samples
                img_array = image.numpy()
                
                # Convert to grayscale and resize to 96x96
                img = Image.fromarray(img_array)
                img = img.convert('L').resize((96, 96))
                
                # Get class name
                class_idx = label.numpy()
                class_name = CLASSES[class_idx] if class_idx < len(CLASSES) else 'unknown'
                
                # Save
                filename = os.path.join(split_dir, class_name, f'{class_name}_{idx:04d}.png')
                img.save(filename)
        
        if logger:
            logger.info(f"✓ Dataset loaded to {dest_dir}")
        
        return dest_dir
        
    except Exception as e:
        # If tfds fails, use synthetic fallback
        if logger:
            logger.warning(f"TensorFlow Datasets failed: {e}, using synthetic data")
        
        from .rock_paper_scissors_fallback import load_data_fallback
        return load_data_fallback(dest_dir=dest_dir, logger=logger)
