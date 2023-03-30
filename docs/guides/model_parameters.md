# Model Parameters

This describes how custom parameters can be embedded into the generated `.tflite` model file.

```{note}
_Any_  `.tflite` model file will work with updating model parameters.  
i.e. The model file does _not_ need to be generated by the YZLITE to add additional parameters.
```

## Quick Reference

- Command-line: [yzlite update_params --help](../command_line/update_params.md)
- Python API: [update_model_parameters](yzlite.core.update_model_parameters)
- Python API examples: [update_params.ipynb](../../yzlite/examples/update_params.ipynb)

## Overview

The YZLITE allows for embedding custom parameters into a generated `.tflite` model file.

Model parameters are useful as they allow the model developer to embed the various processing settings used to train the model into the `.tflite` model file.
In this way, the `.tflite` file and the processing settings are an "atomic unit" and can easily be distributed with the
assurance that the `.tflite` model file and the processing settings are synchronized on the target device.

The basic flow for enabling model parameters is as follows:

1. Custom parameters are configured into Python dictionary using [YZLiteModel.model_parameters](yzlite.core.YZLiteModel.model_parameters) (this is typically done in a [model specification](./model_specification.md) script)
2. Python dictionary serialized using the [Google Flatbuffer](https://google.github.io/flatbuffers) schema: [dictionary.fbs](../python_api/tflite_model/dictionary.fbs)
3. Serialized parameters added to [metadata](https://github.com/tensorflow/tensorflow/blob/master/tensorflow/lite/schema/schema.fbs#L1244) section of the corresponding `.tflite` model file
4. At a later time, the parameters are retrieved from the `.tflite` model file's metadata section and de-serialized by either Python or the embedded device at runtime
5. The de-serialized parameters are used to configure the software to run the machine learning model

```{note}
Model parameters are __optional__. They are added as an additional entry to the "metadata" section of the `.tflite` model file. 
The core model structure and any other metadata entries in the `.tflite` model file are unchanged.
```

### Parameter Basics

Each model parameter is comprised of a:

- __key__ - The name of the parameter
- __type__ - The data type of the parameter
- __value__ - The value of the parameter

The supported Python types are:

- bool
- int
- float
- str
- List[str]
- List[int]
- List[float]
- bytes

### Viewing Parameters

Use the YZLITE's [model summary](./model_summary.md) feature to view the model parameters.
e.g.:

```shell
yzlite summarize audio_example1 --tflite
yzlite summarize ~/workspace/my_model.tflite
```

## General Parameters

The following parameters are added by the YZLITE by default:

- __name__    - The name of the model
- __version__  - The version number of the model as configured in the [model specification](./model_specification.md) script using [YZLiteModel.version](yzlite.core.YZLiteModel.version)
- __date__     - The date/time the `.tflite` model file was generated in ISO8601 format
- __hash__     - MD5 hash of the `.tflite` binary (excluding the `date` and `hash` parameters). This can be used as a unique ID for the `.tflite` model file
- __classes__  - List of strings for each class label the model supports. If the model is a classifier, the order of this list matches the model's output tensor
- __runtime_memory_size__ - The amount of RAM required by Tensorflow-Lite Micro's "tensor arena"

## Model Mixins

The following model mixins add parameters to the generated `.tflite`.  

```{note}
These parameters are used during model training, as such, they should also be used on the target device.
```

### AudioDatasetMixin

The [AudioDatasetMixin](yzlite.core.AudioDatasetMixin) adds the following parameters.  
__NOTE:__ The `fe.*` parameters are specified in the [AudioFeatureGeneratorSettings](yzlite.core.preprocess.audio.audio_feature_generator.AudioFeatureGeneratorSettings) and
used by the [AudioFeatureGenerator](yzlite.core.preprocess.audio.audio_feature_generator.AudioFeatureGenerator) during model training.  

See the [Audio Feature Generator](../audio/audio_feature_generator) guide for more details.

The `samplewise_norm.*` parameters are specified in [ParallelAudioDataGenerator](yzlite.core.preprocess.audio.parallel_generator.ParallelAudioDataGenerator).

- __fe.sample_rate_hz__                     - The sample rate of the audio in Hz
- __fe.sample_length_ms__                   - The length of an audio sample in milliseconds
- __fe.window_size_ms__                     - Length of desired time frames in ms
- __fe.window_step_ms__                     - Length of step size for the next frame in ms
- __fe.filterbank_n_channels__              - The number of filterbank channels to use.
- __fe.filterbank_upper_band_limit__        - The highest frequency included in the filterbanks
- __fe.filterbank_lower_band_limit__        - The lowest frequency included in the filterbanks
- __fe.noise_reduction_enable__             - Enable/disable noise reduction module
- __fe.noise_reduction_smoothing_bits__     - Scale up signal by 2^(smoothing_bits) before reduction
- __fe.noise_reduction_even_smoothing__     - Smoothing coefficient for even-numbered channels
- __fe.noise_reduction_odd_smoothing__      - Smoothing coefficient for odd-numbered channels
- __fe.noise_reduction_min_signal_remaining__ - Fraction of signal to preserve in smoothing
- __fe.pcan_enable__                        - Enable PCAN auto gain control
- __fe.pcan_strength__                      - Gain normalization exponent
- __fe.pcan_offset__                        - Positive value added in the normalization denominator
- __fe.pcan_gain_bits__                     - Number of fractional bits in the gain
- __fe.log_scale_enable__                   - Enable logarithmic scaling of filterbanks
- __fe.log_scale_shift__                    - Scale filterbanks by 2^(scale_shift)
- __fe.fft_length__                         - This is required FFT length which is the smallest power of 2 that is larger than the window size
- __fe.activity_detection_enable__          - Enable the activity detection block. This indicates when activity, such as a speech command, is detected in the audio stream
- __fe.activity_detection_alpha_a__         - The activity detection "fast filter" coefficient. The filter is a 1-real pole IIR filter: `computes out = (1-k)*in + k*out`
- __fe.activity_detection_alpha_b__         - The activity detection "slow filter" coefficient. The filter is a 1-real pole IIR filter: `computes out = (1-k)*in + k*out`
- __fe.activity_detection_arm_threshold__   - The threshold for when there should be considered possible activity in the audio stream
- __fe.activity_detection_trip_threshold__  - The threshold for when activity is considered detected in the audio stream
- __fe.dc_notch_filter_enable__             - Enable the DC notch filter. This will help negate any DC components in the audio signal
- __fe.dc_notch_filter_coefficient__        - The coefficient used by the DC notch filter, DC notch filter coefficient k in Q(16,15) format, `H(z) = (1 - z^-1)/(1 - k*z^-1)`
- __fe.quantize_dynamic_scale_enable__      - Enable dynamic quantization of the generated audio spectrogram. With this, the max spectrogram value is mapped to +127,
                                              and the max spectrogram minus `fe.quantize_dynamic_scale_range_db` is mapped to -128.
                                              Anything below max spectrogram minus `fe.quantize_dynamic_scale_range_db` is mapped to -128.
- __fe.quantize_dynamic_scale_range_db__    - The dynamic range in dB used by the dynamic quantization
- __samplewise_norm.rescale__               - Value to scale each element of the sample:  `norm_sample = sample * <scaler>`. The model input dtype should be a float32
- __samplewise_norm.mean_and_std__          - Normalize the sample by the mean and standard deviation: `norm_sample = (sample - mean(sample)) / std(sample)`. The model input dtype should be a float32

### ImageDatasetMixin

The [ImageDatasetMixin](yzlite.core.ImageDatasetMixin) adds the following parameters.  
The `samplewise_norm.*` parameters are specified in [ParallelImageDataGenerator](yzlite.core.preprocess.image.parallel_generator.ParallelImageDataGenerator).

- __samplewise_norm.rescale__ - Value to scale each element of the sample: `norm_img = img * <scaler>`
- __samplewise_norm.mean_and_std__ - Normalize the sample by the mean and standard deviation: `norm_img = (img - mean(img)) / std(img)`

## Custom Parameters

Custom, user-defined parameters may also be added to the generated `.tflite` model file.

### Add Via Model Script

The recommended approach is adding the parameters to the [model specification](./model_specification.md) script
using the [YZLiteModel.model_parameters](yzlite.core.YZLiteModel.model_parameters) property then either invoking the `update_params` command
or [update_model_parameters](yzlite.core.update_model_parameters) API.

For instance, the model specification script might have:

```python
# The minimum number of inference results to average when calculating the detection value
my_model.model_parameters['minimum_count'] = 3
# Set the volume (in dB) scaler (i.e. amplitude) to apply to the microphone data. If 0 or omitted, no scaler is applied
my_model.model_parameters['volume_db'] = 5.0
# This simulates the amount of time in milliseconds an audio loop takes.
my_model.model_parameters['latency_ms'] = 0
# Console logging level, set to 'debug' to enable verbose logging
my_model.model_parameters['log_level'] = 'info'
```

These parameters will be embedded into the generated `.tflite` model file.

```{note}
The parameters are added _any_ time the `.tflite` model file is generated.
This includes after the `train`, `quantize`, and `update_params` commands and APIs.
```

### Add Via Command/API

Alternatively, parameters can be added directly through the `update_params` command and [update_model_parameters](yzlite.core.update_model_parameters) API
_without_ modifying the [model specification](./model_specification.md) script.

For example,

```shell
yzlite update_params ~/workspace/my_model.tflite my_custom_params=43
```

```python
update_model_parameters('~/workspace/my_model.tflite', params={'my_custom_params': 43})
```

## Command

Updating model parameters from the command-line is done using the `update_params` operation.

For more details on the available command-line options, issue the command:

```shell
yzlite update_params --help
```

### Example 1: Update model specification

The most common use case of the `update_params` command is:

1. Fully [train](./model_training.md) a model
2. Later modify the [model specification](./model_specification.md) script with additional parameters
3. Run the `update_params` command to update the `.tflite` model file in the [model archive](./model_archive.md)

In this example, it's assumed that the [YZLiteModel.model_parameters](yzlite.core.YZLiteModel.model_parameters) in
the [tflite_micro_speech model](yzlite.models.tflite_micro.tflite_micro_speech) specification script have been modified _after_ the model has been trained.

```python
yzlite_model.model_parameters['average_window_duration_ms'] = 1000
yzlite_model.model_parameters['detection_threshold'] = 185
yzlite_model.model_parameters['suppression_ms'] = 1500
yzlite_model.model_parameters['minimum_count'] = 3
yzlite_model.model_parameters['volume_db'] = 5.0
yzlite_model.model_parameters['latency_ms'] = 0
yzlite_model.model_parameters['log_level'] = 'info'
```

```shell
yzlite update_params tflite_micro_speech
```

After this command completes, the `tflite_micro_speech.yzlite.zip` model archive is updated with a new `tflite_micro_speech.tflite` model file.  
Note that _only_ the parameters in the `.tflite`'s metadata section are modified. The model weights and layers are untouched.

### Example 2: Update with command-line

The `update_params` command also works with `.tflite` model files generated outside of the YZLITE.  
In this mode, model parameters can be supplied on the command-line, e.g.:

```shell
yzlite update_params ~/workspace/my_model.tflite volume=10.0 log_level=debug threshold=43
```

After this command completes, the `~/workspace/my_model.tflite` model file is updated with the given parameters.  
Note that _only_ the parameters in the `.tflite`'s metadata section are modified.
The model weights and layers are untouched.

### Example 3: Update with .json file

The `update_params` command also works with `.tflite` model files generated outside of the YZLITE.
In this mode, model parameters can be supplied via a JSON file, e.g.:

Given the file `model_parameters.json`:

```json
{
    "volume": 10.0,
    "log_level": "debug",
    "threshold": 43
}
```

and running the command:

```shell
yzlite update_params ~/workspace/my_model.tflite --params  ~/workspace/model_parameters.json
```

the `~/workspace/my_model.tflite` model file is updated with the given parameters.  
Note that _only_ the parameters in the `.tflite`'s metadata section are modified.
The model weights and layers are untouched.

## Python API

Updating model parameters is accessible via the [update_model_parameters](yzlite.core.update_model_parameters) API.

Examples using this API may be found in [update_params.ipynb](../../yzlite/examples/update_params.ipynb)