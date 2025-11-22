"""Rock Paper Scissors Dataset - Fallback implementation

Since the original yzlite_assets repository is not available,
this provides a fallback using TensorFlow Datasets or synthetic data.
"""

import os
import numpy as np
from PIL import Image


def create_synthetic_dataset(dest_dir, num_samples_per_class=100):
    """Create a synthetic Rock Paper Scissors dataset for testing
    
    Args:
        dest_dir: Destination directory
        num_samples_per_class: Number of samples per class
        
    Returns:
        Path to dataset directory
    """
    classes = ['rock', 'paper', 'scissor']
    
    for class_name in classes:
        class_dir = os.path.join(dest_dir, class_name)
        os.makedirs(class_dir, exist_ok=True)
        
        for i in range(num_samples_per_class):
            # Create synthetic grayscale image (96x96)
            # Use different patterns for each class
            if class_name == 'rock':
                # Circular pattern
                img = np.ones((96, 96), dtype=np.uint8) * 128
                center = (48, 48)
                for y in range(96):
                    for x in range(96):
                        dist = np.sqrt((x - center[0])**2 + (y - center[1])**2)
                        if dist < 30:
                            img[y, x] = 200
            elif class_name == 'paper':
                # Rectangle pattern  
                img = np.ones((96, 96), dtype=np.uint8) * 128
                img[20:76, 20:76] = 200
            else:  # scissor
                # X pattern
                img = np.ones((96, 96), dtype=np.uint8) * 128
                for i in range(96):
                    img[i, i] = 200
                    img[i, 95-i] = 200
            
            # Add noise
            noise = np.random.randint(-20, 20, (96, 96), dtype=np.int16)
            img = np.clip(img.astype(np.int16) + noise, 0, 255).astype(np.uint8)
            
            # Save image
            img_path = os.path.join(class_dir, f'{class_name}_{i:04d}.png')
            Image.fromarray(img).save(img_path)
    
    print(f"✓ Created synthetic dataset with {num_samples_per_class} samples per class")
    print(f"  Path: {dest_dir}")
    print(f"  Classes: {classes}")
    
    return dest_dir


def load_data_fallback(dest_dir=None, logger=None):
    """Load Rock Paper Scissors dataset with fallback to synthetic data
    
    Args:
        dest_dir: Destination directory
        logger: Logger instance
        
    Returns:
        Path to dataset directory
    """
    if dest_dir is None:
        from yzlite.utils.path import create_user_dir
        dest_dir = create_user_dir('datasets/rock_paper_scissors/v1_synthetic')
    
    # Check if dataset already exists
    if os.path.exists(dest_dir) and os.listdir(dest_dir):
        if logger:
            logger.info(f"Using existing dataset at {dest_dir}")
        return dest_dir
    
    # Create synthetic dataset
    if logger:
        logger.warning("Original dataset URL not available, using synthetic data")
        logger.info(f"Creating synthetic Rock Paper Scissors dataset...")
    
    return create_synthetic_dataset(dest_dir, num_samples_per_class=500)

