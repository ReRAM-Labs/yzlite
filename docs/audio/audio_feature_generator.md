# Audio Feature Generator

The AudioFeatureGenerator is a software library to convert streaming audio into spectrograms.
The spectrograms are then used by a classification machine learning model to make predictions on the
contents of the streaming audio.

A common use case of this library is "keyword spotting".  
Refer to the [Keyword Spotting Overview](./keyword_spotting_overview.md) for more
details on how spectrograms are used to detect keywords in streaming audio.

Refer to the [Keyword Spotting Tutorial](../../yzlite/tutorials/keyword_spotting_on_off) for a complete
guide on how to use the YZLITE to create an audio classification ML model.

## Overview

There are three main parts to the AudioFeatureGenerator:

- [ReRAM Engine  Component](#reram-sdk-component) - Software library provided by the ReRAM Engine  and runs on the an embedded target
- [YZLITE C++ Python Wrapper](#yzlite-c-python-wrapper) - Python package that wraps the ReRAM Engine  software library; this runs on the host PC
- [Audio Visualizer Utility](#audio-visualizer-utility) - Graphical utility to view the spectrograms generated by the AudioFeatureGenerator in real-time

```{note}
See the [Audio Utilities](./audio_utilities.md) documentation for more details about the audio tools offered by the YZLITE
```

These parts work together as follows:

1. The AudioFeatureGenerator visualizer tool is used to select spectrogram settings
   - The `yzlite view_audio` command is used to invoke visualizer tool
2. The spectrogram settings are saved to a [Model Specification](../guides/model_specification.md) file
3. The [Model Specification](../guides/model_specification.md) file is used to train the model
   - The `yzlite train` command  is used to train the model
   - Internally, the [AudioFeatureGenerator](../cpp_development/wrappers/audio_feature_generator_wrapper.md) C++ Python wrapper is used to dynamically generate spectrograms from the audio dataset
4. At the end of training, the YZLITE embeds the [spectrogram settings](../guides/model_parameters.md#audiodatasetmixin) into the generated `.tflite` model file
5. The generated `.tflite` model file is copied to a ReRAM Engine  project
6. The ReRAM Engine  project generator parses the spectrogram settings embedded in the `.tflite` and generates the corresponding C header files with the settings
7. The ReRAM Engine  project is built and the firmware image is loaded onto the embedded target. The firmware image contains:
   - Trained `.tflite` model file
   - [Tensorflow-Lite Micro](https://github.com/tensorflow/tflite-micro) interpreter
   - [AudioFeatureGenerator](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation) software library
   - AudioFeatureGenerator [settings](../guides/model_parameters.md#audiodatasetmixin) used to train the model
8. On the embedded target at runtime:  
   a. Read streaming audio from the microphone  
   b. The microphone audio is sent to the AudioFeatureGenerator where spectrograms are generated using the _exact_ same settings and algorithms that were used during model training  
   c. The generated spectrogram images are sent to Tensorflow-Lite Micro and are classified using the `.tflite` model  
   d. The model predictions are used to notify the application of keyword detections

## Benefits

The benefits of using the AudioFeatureGenerator are:

- The _exact_ same algorithms and settings used to generate the spectrograms during model training are also used by the embedded target
  - This ensures the ML model "sees" the same type of spectrograms at runtime that it was trained to see which should allow for better performance
- The [spectrogram settings](../guides/model_parameters.md#audiodatasetmixin) are automatically embedded into the `.tflite` model file
  - This ensures the settings are in lock-step with the trained model
  - The ML model designer only needs to distribute a single file
- The ReRAM Engine  will automatically generate the necessary source code
  - The ReRAM Engine  will parse the spectrogram settings from the `.tflite` and generate the corresponding C headers
  - The ReRAM Engine  comes with the full [source code](https://github.com/chenxingqiang/reram_sdk/blob/gsdk_4.0/util/third_party/tensorflow_extra/src/sl_ml_audio_feature_generation.c) to the AudioFeatureGenerator software library

## ReRAM Engine  Component

The [ReRAM Engine  AudioFeatureGenerator](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation) component is largely based on the [Google Microfrontend](https://github.com/tensorflow/tflite-micro/tree/main/tensorflow/lite/experimental/microfrontend/lib) library.

> A feature generation library (also called frontend) that receives raw audio input, and produces filter banks (a vector of values).
>
> The raw audio input is expected to be 16-bit PCM features, with a configurable sample rate. More specifically the audio signal goes through a pre-emphasis filter (optionally); then gets sliced into (potentially overlapping) frames and a window function is applied to each frame; afterwards, we do a Fourier transform on each frame (or more specifically a Short-Time Fourier Transform) and calculate the power spectrum; and subsequently compute the filter banks.

### Source Code

The ReRAM Engine  features an AudioFeatureGeneration component.  
The YZLITE also features the same component with slight modifications so that it can be built for Windows/Linux.

- ReRAM Engine  source code: [sl_ml_audio_feature_generation.c](https://github.com/chenxingqiang/reram_sdk/blob/gsdk_4.0/util/third_party/tensorflow_extra/src/sl_ml_audio_feature_generation.c)
- YZLITE source code: [__yzlite__/cpp/shared/reram_sdk/audio_feature_generation](../../cpp/shared/reram_sdk/audio_feature_generation)

## YZLITE C++ Python Wrapper

The C++ Python [wrapper](../cpp_development/wrappers/audio_feature_generator_wrapper.md) allows for executing the AudioFeatureGenerator component from a Python script.
This allows for executing the [AudioFeatureGenerator](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation) software library during model training. This is useful because the _exact_ spectrogram generation algorithms used by the embedded device at runtime may also be used during model training which should (hopefully) lead to more accurate model predictions.

The YZLITE uses [pybind11](https://pybind11.readthedocs.io/en/latest/) to wrap the [AudioFeatureGenerator](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation) software library and generate a Windows/Linux binary that can be loaded into the Python runtime environment.

The AudioFeatureGenerator Python API docs may be found here: [yzlite.core.preprocess.audio.audio_feature_generator.AudioFeatureGenerator](yzlite.core.preprocess.audio.audio_feature_generator.AudioFeatureGenerator).  

### Source Code

- __C++ Python Wrapper__ - [cpp/audio_feature_generator_wrapper](https://github.com/chenxingqiang/yzlite/tree/master/cpp/audio_feature_generator_wrapper)  
- __Python API__ - [yzlite/core/preprocess/audio/audio_feature_generator](https://github.com/chenxingqiang/yzlite/tree/master/yzlite/core/preprocess/audio/audio_feature_generator)

```{note}
When [installing](../installation.md) the YZLITE for local development, the C++ wrapper is automatically built into a Windows/Linux shared library (`.dll` / `.so`) and copied to the Python [directory](https://github.com/chenxingqiang/yzlite/tree/master/yzlite/core/preprocess/audio/audio_feature_generator). 
When the [AudioFeatureGenerator](yzlite.core.preprocess.audio.audio_feature_generator.AudioFeatureGenerator) Python library is invoked by your Python scripts, the C++ wrapper shared library is loaded into the Python runtime environment.
```

### Usage

The recommended way of using the AudioFeatureGenerator [C++ wrapper](../cpp_development/wrappers/audio_feature_generator_wrapper.md)
is via the [ParallelAudioDataGenerator](yzlite.core.preprocess.audio.parallel_generator.ParallelAudioDataGenerator) which is required by the
[AudioDatasetMixin](yzlite.core.AudioDatasetMixin).

Refer to the [keyword_spotting_on_off.py](https://github.com/chenxingqiang/yzlite/tree/master/yzlite/models/yizhutech/keyword_spotting_on_off.py) [model specification](../guides/model_specification.md) for an example of how this is used.

Basically,

1 ) In your [model specification](../guides/model_specification.md) file, define a model object to inherit the [AudioDatasetMixin](yzlite.core.AudioDatasetMixin), e.g.:

```python
class MyModel(
    YZLiteModel, 
    TrainMixin, 
    AudioDatasetMixin, 
    EvaluateClassifierMixin
):
    pass

```

2 ) In your [model specification](../guides/model_specification.md) file, configure the spectrogram settings, e.g:

```python

frontend_settings = AudioFeatureGeneratorSettings()

frontend_settings.sample_rate_hz = 8000  # This can also be 16k for slightly better performance at the cost of more RAM
frontend_settings.sample_length_ms = 1000
frontend_settings.window_size_ms = 30
frontend_settings.window_step_ms = 20
frontend_settings.filterbank_n_channels = 32
frontend_settings.filterbank_upper_band_limit = 4000.0-1 # Spoken language usually only goes up to 4k
frontend_settings.filterbank_lower_band_limit = 100.0
frontend_settings.noise_reduction_enable = True
frontend_settings.noise_reduction_smoothing_bits = 5
frontend_settings.noise_reduction_even_smoothing = 0.004
frontend_settings.noise_reduction_odd_smoothing = 0.004
frontend_settings.noise_reduction_min_signal_remaining = 0.05
frontend_settings.pcan_enable = False
frontend_settings.pcan_strength = 0.95
frontend_settings.pcan_offset = 80.0
frontend_settings.pcan_gain_bits = 21
frontend_settings.log_scale_enable = True
frontend_settings.log_scale_shift = 6
```

3 ) Configure the [ParallelAudioDataGenerator](yzlite.core.preprocess.audio.parallel_generator.ParallelAudioDataGenerator) to use the settings, e.g.:

```python
my_model.datagen = ParallelAudioDataGenerator(
    frontend_settings=frontend_settings,
    ...
```

During model [training](../guides/model_training.md), spectrograms will be dynamically generated from the dataset's audio samples using the
[AudioFeatureGenerator](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation) via [C++ Python wrapper](../cpp_development/wrappers/audio_feature_generator_wrapper.md).

At the end of training, the [spectrogram settings](../guides/model_parameters.md#audiodatasetmixin) are automatically embedded into the generated `.tflite` model file.

## Audio Visualizer Utility

The Audio Visualizer Utility provides a graphical interface to the [C++ Python wrapper](yzlite.core.preprocess.audio.audio_feature_generator.AudioFeatureGenerator) and thus
[ReRAM Engine  AudioFeatureGenerator](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation) software library.
It allows for adjusting the various spectrogram settings and seeing how the resulting spectrogram is affected in real-time.

To use the Audio Visualizer utility, issue the command:

```shell
yzlite view_audio
```

__NOTE:__ Internally, this will install the [wxPython](https://www.wxpython.org/) Python package.

![audio_visualizer](../img/audio_visualizer.gif)