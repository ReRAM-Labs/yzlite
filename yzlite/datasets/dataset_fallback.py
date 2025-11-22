"""
通用数据集 Fallback 系统
使用 TensorFlow Datasets 作为备用数据源
"""

import os
import logging
import numpy as np
from typing import Optional

def get_tfds_dataset(dataset_name: str, dest_dir: str, logger: Optional[logging.Logger] = None):
    """
    使用 TensorFlow Datasets 作为 fallback
    
    Args:
        dataset_name: TFDS 数据集名称
        dest_dir: 目标目录
        logger: 日志记录器
        
    Returns:
        数据集路径
    """
    try:
        import tensorflow_datasets as tfds
        
        if logger:
            logger.info(f"Using TensorFlow Datasets fallback for {dataset_name}")
        
        # 下载数据集到指定目录
        dataset = tfds.load(
            dataset_name,
            data_dir=dest_dir,
            download=True,
            as_supervised=True
        )
        
        return os.path.join(dest_dir, dataset_name)
        
    except Exception as e:
        if logger:
            logger.warning(f"TensorFlow Datasets fallback failed: {e}")
        return None


def create_synthetic_audio_dataset(dest_dir: str, num_samples: int = 1000):
    """
    创建合成音频数据集
    
    Args:
        dest_dir: 目标目录
        num_samples: 每个类别的样本数
        
    Returns:
        数据集路径
    """
    import soundfile as sf
    
    classes = ['yes', 'no', 'up', 'down', 'left', 'right', 'on', 'off', 'stop', 'go']
    sample_rate = 16000
    duration = 1  # 1 second
    
    for class_name in classes:
        class_dir = os.path.join(dest_dir, class_name)
        os.makedirs(class_dir, exist_ok=True)
        
        for i in range(num_samples):
            # Generate synthetic audio
            t = np.linspace(0, duration, sample_rate)
            
            # Different frequency for each class
            freq = 200 + classes.index(class_name) * 100
            signal = np.sin(2 * np.pi * freq * t)
            
            # Add noise
            noise = np.random.normal(0, 0.1, signal.shape)
            signal = signal + noise
            
            # Save as WAV
            filename = os.path.join(class_dir, f'{class_name}_{i:04d}.wav')
            sf.write(filename, signal, sample_rate)
    
    print(f"✓ Created synthetic audio dataset with {num_samples} samples per class")
    return dest_dir


def create_synthetic_timeseries_dataset(dest_dir: str, num_samples: int = 500):
    """
    创建合成时间序列数据集（用于异常检测等）
    
    Args:
        dest_dir: 目标目录
        num_samples: 样本数
        
    Returns:
        数据集路径
    """
    import json
    
    # 创建正常和异常数据
    normal_dir = os.path.join(dest_dir, 'normal')
    anomaly_dir = os.path.join(dest_dir, 'anomaly')
    os.makedirs(normal_dir, exist_ok=True)
    os.makedirs(anomaly_dir, exist_ok=True)
    
    # 正常数据：规则的正弦波
    for i in range(num_samples):
        t = np.linspace(0, 4*np.pi, 100)
        signal = np.sin(t) + np.random.normal(0, 0.1, t.shape)
        
        filename = os.path.join(normal_dir, f'normal_{i:04d}.npy')
        np.save(filename, signal)
    
    # 异常数据：不规则波形
    for i in range(num_samples // 4):
        t = np.linspace(0, 4*np.pi, 100)
        signal = np.sin(t) + np.sin(3*t) + np.random.normal(0, 0.3, t.shape)
        
        filename = os.path.join(anomaly_dir, f'anomaly_{i:04d}.npy')
        np.save(filename, signal)
    
    print(f"✓ Created synthetic timeseries dataset")
    print(f"  Normal samples: {num_samples}")
    print(f"  Anomaly samples: {num_samples // 4}")
    
    return dest_dir


# 数据集映射：将 YZLITE 数据集映射到 TensorFlow Datasets
TFDS_DATASET_MAP = {
    'rock_paper_scissors': 'rock_paper_scissors',
    'speech_commands': 'speech_commands',
    'mnist': 'mnist',
    'cifar10': 'cifar10',
    'cifar100': 'cifar100',
}


def get_dataset_with_fallback(
    original_url: str,
    original_hash: str,
    dest_dir: str,
    dataset_type: str = 'image',
    logger: Optional[logging.Logger] = None
) -> str:
    """
    通用数据集下载函数，带多层 fallback
    
    Args:
        original_url: 原始 URL
        original_hash: 原始文件哈希
        dest_dir: 目标目录
        dataset_type: 数据集类型 ('image', 'audio', 'timeseries')
        logger: 日志记录器
        
    Returns:
        数据集路径
    """
    from yzlite.utils.archive_downloader import download_verify_extract
    
    # Level 1: 尝试原始 URL
    try:
        return download_verify_extract(
            url=original_url,
            file_hash=original_hash,
            dest_dir=dest_dir,
            logger=logger
        )
    except Exception as e:
        if logger:
            logger.warning(f"Original URL failed: {e}")
    
    # Level 2: 尝试 TensorFlow Datasets
    for yzlite_name, tfds_name in TFDS_DATASET_MAP.items():
        if yzlite_name in original_url:
            result = get_tfds_dataset(tfds_name, dest_dir, logger)
            if result:
                return result
    
    # Level 3: 创建合成数据集
    if logger:
        logger.info(f"Using synthetic {dataset_type} dataset as fallback")
    
    if dataset_type == 'image':
        from yzlite.datasets.image.rock_paper_scissors_fallback import create_synthetic_dataset
        return create_synthetic_dataset(dest_dir)
    elif dataset_type == 'audio':
        return create_synthetic_audio_dataset(dest_dir)
    elif dataset_type == 'timeseries':
        return create_synthetic_timeseries_dataset(dest_dir)
    else:
        raise ValueError(f"Unsupported dataset type: {dataset_type}")

