# Yizhu Technology ReRAM YZLite (YZLITE)

The YZLite package by Yizhu Technology is an experimental Python package with command-line utilities and scripts for developing machine learning models for embedded platforms. It provides features such as command-line interface, Python API, model profiler, model training and evaluation, model summary, visualization, quantization, audio feature generation, C++ Python wrappers, and more. The package does not come with any warranty or support services, but it is supported by online documentation and community support. YZLite can be installed using pre-built Python package or by building from Github. The software is provided "as-is" without any warranty, but it can be used for any purpose including commercial applications, subject to certain restrictions.

<a href="https://github.com/ReRAM-Labs/yzlite" target="_blank">![version](https://img.shields.io/badge/YZLITE%20Version-0.1.0-red?style=for-the-badge)</a>
<a href="https://pypi.org/project/yizhu-yzlite" target="_blank">![PyPI - Python Version](https://img.shields.io/pypi/pyversions/yizhu-yzlite?style=for-the-badge)</a>
<a href="https://github.com/ReRAM-Labs/reram_sdk/tree/G0)" target="_blank">![gsdk](https://img.shields.io/badge/ReRAM%20SDK-G0-green?style=for-the-badge)</a>
<a href="https://github.com/tensorflow/tflite-micro/tree/1caee4d5045f2744515fb8ca063bc66958e3f79b" target="_blank">![tflm](https://img.shields.io/badge/Tensorflow--Lite%20Micro-February%202023-orange?style=for-the-badge)</a>
<a href="https://www.tensorflow.org/api_docs" target="_blank">![tf](https://img.shields.io/badge/Tensorflow-2.11-yellow?style=for-the-badge)</a>

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

Refer to [Why YZLITE?](./docs/why_yzlite.md) for more details on the benefits of using the YZLITE.

## Overview

```{eval-rst}
.. raw:: html

   <iframe src="./_static/overview/index.html" height="100%" width="100%" frameborder="0" class="slideshow-iframe" allowfullscreen></iframe>
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

## Other Information

- [Frequently Asked Questions](./docs/faq/index.md)
- [Model Profiler Utility](./docs/guides/model_profiler_utility.md)
- [Quick Reference](./docs/other/quick_reference.md)
- [Settings File](./docs/other/settings_file.md)
- [Model Specification](./docs/guides/model_specification.md)
- [Model Archive File](./docs/guides/model_archive.md)
- [Model Search Path](./docs/guides/model_search_path.md)
- [Environment Variables](./docs/other/environment_variables.md)
- [C++ Development](./docs/cpp_development/index.md)
