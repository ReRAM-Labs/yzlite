"""
TensorFlow Datasets Wrapper for YZLITE
直接使用 TFDS 替代所有 yzlite_assets 数据集
"""

import os
import logging
import numpy as np
from PIL import Image
from typing import Optional, Tuple
import tensorflow_datasets as tfds


def load_tfds_image_dataset(
    tfds_name: str,
    dest_dir: str,
    target_size: Tuple[int, int] = (96, 96),
    grayscale: bool = True,
    max_samples: int = None,
    logger: Optional[logging.Logger] = None
) -> str:
    """
    从 TensorFlow Datasets 加载图像数据集并转换为文件
    
    Args:
        tfds_name: TFDS 数据集名称
        dest_dir: 目标目录
        target_size: 目标图像大小
        grayscale: 是否转换为灰度
        max_samples: 最大样本数（None = 全部）
        logger: 日志记录器
        
    Returns:
        数据集路径
    """
    if logger:
        logger.info(f"Loading {tfds_name} from TensorFlow Datasets...")
    
    # 加载数据集
    ds_train = tfds.load(tfds_name, split='train', as_supervised=True)
    ds_test = tfds.load(tfds_name, split='test', as_supervised=True) if tfds.builder(tfds_name).info.splits.get('test') else None
    
    # 获取类别信息
    info = tfds.builder(tfds_name).info
    num_classes = info.features['label'].num_classes
    class_names = info.features['label'].names
    
    # 转换并保存
    for split_name, dataset in [('train', ds_train), ('test', ds_test)]:
        if dataset is None:
            continue
            
        split_dir = os.path.join(dest_dir, split_name)
        
        # 创建类别目录
        for class_name in class_names:
            class_dir = os.path.join(split_dir, class_name)
            os.makedirs(class_dir, exist_ok=True)
        
        # 保存图像
        for idx, (image, label) in enumerate(dataset):
            if max_samples and idx >= max_samples:
                break
                
            img_array = image.numpy()
            
            # 转换
            img = Image.fromarray(img_array)
            if grayscale:
                img = img.convert('L')
            img = img.resize(target_size)
            
            # 保存
            class_idx = label.numpy()
            class_name = class_names[class_idx]
            filename = os.path.join(split_dir, class_name, f'{class_name}_{idx:04d}.png')
            img.save(filename)
    
    if logger:
        logger.info(f"✓ Dataset saved to {dest_dir}")
    
    return dest_dir


def load_tfds_audio_dataset(
    tfds_name: str,
    dest_dir: str,
    max_samples: int = None,
    logger: Optional[logging.Logger] = None
) -> str:
    """
    从 TensorFlow Datasets 加载音频数据集
    
    Args:
        tfds_name: TFDS 数据集名称
        dest_dir: 目标目录
        max_samples: 最大样本数
        logger: 日志记录器
        
    Returns:
        数据集路径
    """
    import soundfile as sf
    
    if logger:
        logger.info(f"Loading {tfds_name} from TensorFlow Datasets...")
    
    # 加载数据集
    ds = tfds.load(tfds_name, split='train', as_supervised=True)
    
    # 获取类别信息
    info = tfds.builder(tfds_name).info
    class_names = info.features['label'].names if hasattr(info.features['label'], 'names') else []
    
    # 创建目录并保存
    for class_name in class_names:
        class_dir = os.path.join(dest_dir, class_name)
        os.makedirs(class_dir, exist_ok=True)
    
    # 保存音频文件
    for idx, (audio, label) in enumerate(ds):
        if max_samples and idx >= max_samples:
            break
            
        audio_data = audio.numpy()
        
        # 假设采样率 16kHz
        sample_rate = 16000
        
        # 保存
        if class_names:
            class_idx = label.numpy()
            class_name = class_names[class_idx]
            filename = os.path.join(dest_dir, class_name, f'{class_name}_{idx:04d}.wav')
        else:
            filename = os.path.join(dest_dir, f'audio_{idx:04d}.wav')
        
        sf.write(filename, audio_data, sample_rate)
    
    if logger:
        logger.info(f"✓ Dataset saved to {dest_dir}")
    
    return dest_dir


# 数据集映射表
TFDS_REPLACEMENTS = {
    'rock_paper_scissors': 'rock_paper_scissors',
    'speech_commands': 'speech_commands',
    'mnist': 'mnist',
    'fashion_mnist': 'fashion_mnist',
    'cifar10': 'cifar10',
    'cifar100': 'cifar100',
    'cats_vs_dogs': 'cats_vs_dogs',
}

