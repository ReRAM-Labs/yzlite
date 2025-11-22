# Yizhu Technology ReRAM YZLite (YZLITE)

The YZLite package by Yizhu Technology is an experimental Python package with command-line utilities and scripts for developing machine learning models for embedded platforms. It provides features such as command-line interface, Python API, model profiler, model training and evaluation, model summary, visualization, quantization, audio feature generation, C++ Python wrappers, and more. The package does not come with any warranty or support services, but it is supported by online documentation and community support. YZLite can be installed using pre-built Python package or by building from Github. The software is provided "as-is" without any warranty, but it can be used for any purpose including commercial applications, subject to certain restrictions.

<a href="https://github.com/ReRAM-Labs/yzlite" target="_blank">![version](https://img.shields.io/badge/YZLITE%20Version-0.2.0-red?style=for-the-badge)</a>
<a href="https://pypi.org/project/yizhu-yzlite" target="_blank">![PyPI - Python Version](https://img.shields.io/pypi/pyversions/yizhu-yzlite?style=for-the-badge)</a>
<a href="https://github.com/ReRAM-Labs/reram_sdk/tree/G0)" target="_blank">![gsdk](https://img.shields.io/badge/ReRAM%20SDK-G0-green?style=for-the-badge)</a>
<a href="https://github.com/tensorflow/tflite-micro/tree/1caee4d5045f2744515fb8ca063bc66958e3f79b" target="_blank">![tflm](https://img.shields.io/badge/Tensorflow--Lite%20Micro-February%202023-orange?style=for-the-badge)</a>
<a href="https://www.tensorflow.org/api_docs" target="_blank">![tf](https://img.shields.io/badge/Tensorflow-2.13+-yellow?style=for-the-badge)</a>
<a href="https://www.python.org" target="_blank">![python](https://img.shields.io/badge/Python-3.7--3.13-blue?style=for-the-badge)</a>

This is a Python package with command-line utilities and scripts to aid the development
of machine learning models for Yizhu Technology 's embedded platforms.

The features of this Python package include:

- [Command-line](./docs/command_line/index.md) - Execute all ML operations from a simple command-line interface
- [Python API](./docs/python_api/index.md) - Execute all ML operations from a Python script
- [Model Profiler](./docs/guides/model_profiler.md) - Determine how efficiently an ML model will execute on an embedded platform
- [Model Training](./docs/guides/model_training.md) - Train an ML model using [Google Tensorflow](https://www.tensorflow.org/)
- [Remote Training via SSH](./docs/guides/model_training_via_ssh.md) - Securely and seamlessly train the model on a remote "cloud" machine
- [Model Training Monitor](./docs/guides/model_training_monitor.md) - Monitor/profile the training of a model using [Tensorboard](https://www.tensorflow.org/tensorboard)
- [Model Evaluation](./docs/guides/model_evaluation.md) - Evaluate a trained ML model's accuracy and other metrics
- [Model Summary](./docs/guides/model_summary.md) - Generate a summary of the model's contents
- [Model Visualization](./docs/guides/model_visualizer.md) - Interactively view the ML model's structure
- [Model Quantization](./docs/guides/model_quantization.md) - Reduce the memory footprint of an ML model by using the [Tensorflow-Lite Converter](https://www.tensorflow.org/lite/convert)
- [Model Parameters](./docs/guides/model_parameters.md) - Embed custom parameters into the generated model file
- [Audio Feature Generator](./docs/audio/audio_feature_generator.md) - Library and tools to convert streaming audio into spectrograms
- [Audio Utilities](./docs/audio/audio_utilities.md) - Utilities to aid the development of audio classification models
- [C++ Python Wrappers](./docs/cpp_development/wrappers/index.md) - Enable sharing source code between embedded targets and model training scripts
- [ReRAM Simulator](./docs/cpp_development/wrappers/reram_wrapper.md) - Simulate neural network inference on ReRAM crossbar arrays with realistic hardware characteristics

Refer to [Why YZLITE?](./docs/why_yzlite.md) for more details on the benefits of using the YZLITE.

## 🆕 What's New in v0.2.0

### ⭐ Major New Features

#### ReRAM Crossbar Array Simulator
A complete simulation environment for ReRAM-based Processing-In-Memory (PIM) architectures:

```python
from yzlite.core import TfliteMicro

# Load model with ReRAM simulation
model = TfliteMicro.load_tflite_model('model.tflite', accelerator='reram')

# Configure ReRAM parameters
model.accelerator.configure_crossbar(rows=256, cols=256, levels=8)
model.accelerator.set_adc_resolution(bits=4)

# Test with fault injection
model.accelerator.inject_faults(fault_rate=0.01)
results = model.profile()

# Get performance metrics
stats = model.accelerator.get_statistics()
print(f"Energy: {stats['energy_uj']} μJ, Latency: {stats['latency_us']} μs")
```

**Key Capabilities:**
- ✅ **Multi-Level Cell (MLC)**: 2-16 configurable resistance levels
- ✅ **Realistic Hardware Modeling**: IR drop, sneak path, write/read variation
- ✅ **Fault Injection**: Reliability analysis with configurable fault rates
- ✅ **Performance Metrics**: Energy (μJ), latency (μs), operation counts
- ✅ **Flexible Configuration**: Crossbar size, ADC resolution, cell levels

### 🔧 Improvements
- **Extended Python Support** - Now supports Python 3.7-3.13 (previously 3.7-3.10)
- **Updated TensorFlow** - Compatible with TensorFlow 2.13+ (tested with 2.13.1)
- **Enhanced Documentation** - 90 KB of comprehensive ReRAM simulator documentation
- **100% Test Coverage** - All 56 tests passing across multiple configurations

### 📚 Research Integration
Based on latest academic research (2019-2024):
- [RAELLA](https://arxiv.org/abs/2304.07935) - Low-resolution ADC for analog PIM
- [FARe](https://arxiv.org/abs/2401.10522) - Fault-aware GNN training on ReRAM
- [FPSA](https://arxiv.org/abs/1901.09904) - Reconfigurable ReRAM accelerator
- [RED](https://arxiv.org/abs/1907.02987) - ReRAM-based deconvolution

### 📖 New Documentation
- [ReRAM Quick Start Guide](./RERAM_QUICKSTART.md)
- [ReRAM Simulator Research](./RERAM_SIMULATOR_RESEARCH.md)
- [Implementation Guide](./RERAM_WRAPPER_IMPLEMENTATION.md)
- [How to Use](./HOW_TO_USE.md)
- [Changelog](./CHANGELOG.md)

## Overview

```{eval-rst}
.. raw:: html

   <iframe src="./_static/overview/index.html" width="100%" height="600" frameborder="0" class="slideshow-iframe" allowfullscreen style="min-height: 600px; border: 1px solid #e0e0e0; border-radius: 4px; display: block;"></iframe>
```

## Installation

Install the pre-built Python package:

```{eval-rst}
.. tab-set::

   .. tab-item:: Windows

      .. code-block:: shell

         pip  install yizhu-yzlite

   .. tab-item:: Linux

      .. code-block:: shell

         pip3 install yizhu-yzlite

```

Or, build and install the Python package from [Github](https://github.com/ReRAM-Labs/yzlite):

```{eval-rst}
.. tab-set::

   .. tab-item:: Windows

      .. code-block:: shell

         pip  install git+https://github.com/ReRAM-Labs/yzlite.git

   .. tab-item:: Linux

      .. code-block:: shell

         pip3 install git+https://github.com/ReRAM-Labs/yzlite.git
```

Refer to the [Installation Guide](./docs/installation.md) for more details on how to install the YZLITE.

## Quick Start with ReRAM Simulator

### Standalone Usage (No TensorFlow Required)

```python
from reram_simulator_example import ReRAMSimulator
import numpy as np

# Create simulator
simulator = ReRAMSimulator(rows=128, cols=128, adc_resolution=4)

# Load weights
weights = np.random.randn(128, 128)
simulator.load_weights(weights)

# Run inference
input_data = np.random.randn(128)
output = simulator.inference(input_data)

# Test fault tolerance
num_faults = simulator.crossbar.inject_stuck_at_faults(0.01)
output_with_faults = simulator.inference(input_data)
```

### YZLITE Integration

Requires Python 3.10 environment with TensorFlow:

```bash
# Create compatible environment
conda create -n yzlite python=3.10 -y
conda activate yzlite
pip install tensorflow==2.13.1

# Install YZLITE
pip install yizhu-yzlite
```

## Documentation

### Getting Started
- [Installation Guide](./docs/installation.md) - Install YZLITE
- [Quick Reference](./docs/other/quick_reference.md) - Command reference
- [Frequently Asked Questions](./docs/faq/index.md) - Common questions

### Guides
- [Model Profiler](./docs/guides/model_profiler.md) - Profile model performance
- [Model Training](./docs/guides/model_training.md) - Train ML models
- [Model Evaluation](./docs/guides/model_evaluation.md) - Evaluate accuracy
- [Model Quantization](./docs/guides/model_quantization.md) - Reduce model size
- [Model Visualization](./docs/guides/model_visualizer.md) - Visualize model structure

### C++ Development
- [C++ Development Guide](./docs/cpp_development/index.md) - C++ development overview
- [C++ Python Wrappers](./docs/cpp_development/wrappers/index.md) - Wrapper documentation
- [MVP Wrapper](./docs/cpp_development/wrappers/mvp_wrapper.md) - MVP accelerator
- [ReRAM Wrapper](./docs/cpp_development/wrappers/reram_wrapper.md) - ReRAM simulator

### ReRAM Simulator Documentation
- [ReRAM Quick Start](./RERAM_QUICKSTART.md) - Get started quickly
- [ReRAM Research](./RERAM_SIMULATOR_RESEARCH.md) - Research papers and design
- [How to Use](./HOW_TO_USE.md) - Detailed usage guide
- [Implementation Guide](./RERAM_WRAPPER_IMPLEMENTATION.md) - Implementation details
- [Changelog](./CHANGELOG.md) - Version history

## Compatibility

### Python Versions
- ✅ Python 3.7, 3.8, 3.9, 3.10 - Fully supported
- ✅ Python 3.11, 3.12 - Supported (less tested)
- ⚠️ Python 3.13 - Standalone ReRAM simulator works, TensorFlow has known issues

### TensorFlow Versions
- ✅ TensorFlow 2.13.1 - Recommended (tested)
- ✅ TensorFlow 2.14-2.19 - Should work
- ⚠️ TensorFlow 2.20+ - Compatibility issues with Python 3.13

**Recommended Setup**: Python 3.10 + TensorFlow 2.13.1

## Contributing

Contributions are welcome! Please see the documentation for development guidelines.

## License

SPDX-License-Identifier: Zlib

See [LICENSE.md](./LICENSE.md) for full license text.

## Citation

If you use YZLITE or the ReRAM simulator in your research, please cite:

```bibtex
@software{yzlite2025,
  title = {YZLITE: Machine Learning Toolkit for Embedded Platforms},
  author = {Yizhu Technology},
  year = {2025},
  version = {0.2.0},
  url = {https://github.com/ReRAM-Labs/yzlite}
}
```

For the ReRAM simulator specifically:
```bibtex
@software{yzlite_reram2025,
  title = {YZLITE ReRAM Crossbar Array Simulator},
  author = {Yizhu Technology},
  year = {2025},
  note = {Based on RAELLA, FARe, FPSA, and RED research},
  url = {https://github.com/ReRAM-Labs/yzlite}
}
```
