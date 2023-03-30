# Model Specification

## Overview

The model specification is a standard Python script that defines everything needed to create, train, and evaluate a machine learning model.  

This includes:  

- Model version and description
- Model architecture/layout defined using the [Keras API](https://keras.io/api)
- Dataset and any augmentation settings
- Classification labels (e.g. `yes`, `no`)
- Training batch size, epochs, optimizer, loss metrics
- Keras training [callbacks](https://www.tensorflow.org/api_docs/python/tf/keras/callbacks)
- Tensorflow-Lite [Converter](https://www.tensorflow.org/lite/convert) settings for [quantizing](./model_quantization.md) the model
- Additional [parameters](./model_parameters.md) to include in the `.tflite` model file's metadata

### Model Name

The filename of the model specification script is the name given to the model.

So a model specification script with the file path:  `~/workspace/my_model_v1.py`
would have a model name: `my_model_v1`

```{note}
The model specification script's name must only contain alphanumeric or underscore characters
```

### Discoverable Models

The [list_yzlite_models](yzlite.core.list_yzlite_models) API returns all [YZLiteModel](yzlite.core.YZLiteModel) models found on the
[Model Search Path](./model_search_path.md). To make this API efficient, it only parses the text of the Python
scripts found on the model search path for the delimiter `@yzlite_model` (as opposed to loading each model as a Python module).

Thus, to make your model discoverable by this API, add `@yzlite_model` to your model specification script.

## YZLiteModel Class Instance

The core of the model specification script is the [YZLiteModel](yzlite.core.YZLiteModel) class instance.  
This is a Python class that contains all of the model settings and properties.
Additional properties are added to the [YZLiteModel](yzlite.core.YZLiteModel) by inheriting additional model "mixins".

For example, the following might be added to the top of model specification script:

```python
# Define a new MyModel class which inherits the 
# YZLiteModel and several mixins
# NOTE: The name of the custom class can by anything
# @yzlite_model
class MyModel(
    YZLiteModel, 
    TrainMixin, 
    DatasetMixin, 
    EvaluateClassifierMixin
):
    """My Model's class object"""

# Instantiate the MyModel class
my_model = MyModel()
```

Here we define our model's class object: `MyModel`.

At a minimum, this class must inherit [YZLiteModel](yzlite.core.YZLiteModel).

However, to use this model for training or evaluation, it should also inherit others "mixins" such as:  

- [TrainMixin](yzlite.core.TrainMixin) - Enables model training, see [Model Training](./model_training.md)
- [DatasetMixin](yzlite.core.DatasetMixin) - Provides the various properties for configuring the training dataset, see [Data Preprocessing](../python_api/data_preprocessing/index.md)
- [EvaluateClassifierMixin](yzlite.core.EvaluateClassifierMixin) - Optionals, enables automatic classifier model evaluation, see [Model Evaluation](./model_evaluation.md)
- [ImageDatasetMixin](yzlite.core.ImageDatasetMixin) - Optional, helper mixin for using image datasets. Alternatively, you can just use the [yzlite.core.DatasetMixin](yzlite.core.DatasetMixin)
- [AudioDatasetMixin](yzlite.core.AudioDatasetMixin) - Optional, helper mixin for using audio datasets. Alternatively, you can just use the [yzlite.core.DatasetMixin](yzlite.core.DatasetMixin)

The rest of the model specification script populates the various parameters of the model instance, e.g.:

```python
# General Settings
my_model.version = 1
my_model.description = 'My model is great!'

# Training Basic Settings
my_model.epochs = 100
my_model.batch_size = 64 
my_model.optimizer = 'adam'
...

# Dataset Settings
my_model.dataset = speech_commands_v2
my_model.class_mode = 'categorical'
my_model.classes = ['up', 'down', 'left', 'right']
...
```

## Specification Sections

After the model class instantiation, a typical model specification script contains the following sections:

### Model Layout

The actual machine learning model is defined using the [Keras API](https://keras.io/api).
The model is defined in a function that builds a [KerasModel](yzlite.core.KerasModel).
The model specification then sets the model property [TrainMixin.build_model_function](yzlite.core.TrainMixin.build_model_function)
to reference the function. At model training time, the model building function is invoked and the built
[KerasModel](yzlite.core.KerasModel) is trained using Tensorflow.

For example, a model specification script might have:

```python
def my_model_builder(my_model: MyModel):
    keras_model = Sequential(name=my_model.name)

    keras_model = Sequential()
    keras_model.add(InputLayer(my_model.input_shape))
    keras_model.add(Conv2D(
        filters=8,
        kernel_size=(10, 8),
        use_bias=True,
        padding="same",
        strides=(2,2))
    )
    keras_model.add(Activation('relu'))
    keras_model.add(Flatten())
    keras_model.add(Dense(units=my_model.n_classes))

    keras_model.compile(
        loss=my_model.loss, 
        optimizer=my_model.optimizer, 
        metrics=my_model.metrics
    )
    return keras_model

# Set the model property to reference the model build function
my_model.build_model_function = my_model_builder
```

#### Note about hardcoding model layer parameters

While not required, the `my_model` argument to the building function
should be used over hardcoded values, e.g.:

```python
# Good:
# Dynamically determine the number of dense unit based
# on the number of classes specified in the model properties
keras_model.add(Dense(units=my_model.n_classes))

# Bad:
# Hardcoding dense units
# If the number of classes changes, 
# then training will likely fail
keras_model.add(Dense(units=5))
```

```{seealso}
- [TrainMixin.build_model_function](yzlite.core.TrainMixin.build_model_function)
- [Keras API](https://keras.io/api)
```

### General Settings

This section contains basic information about the model such as its version and description, e.g.:

```python
my_model.version = 1
my_model.description = 'My model is great!'
```

```{seealso}
- [YZLiteModel.version](yzlite.core.YZLiteModel.version)
- [YZLiteModel.description](yzlite.core.YZLiteModel.description)
- [YZLiteModel.log_dir](yzlite.core.YZLiteModel.log_dir)
```

### Basic Training Settings

This section contains basic training settings such as the number of epochs and batch size, e.g.:

```python
my_model.epochs = 100
my_model.batch_size = 64 
my_model.optimizer = 'adam'
```

Also see:  

- [TrainMixin](yzlite.core.TrainMixin)
- [TrainMixin.epochs](yzlite.core.TrainMixin.epochs)
- [TrainMixin.batch_size](yzlite.core.TrainMixin.batch_size)
- [TrainMixin.optimizer](yzlite.core.TrainMixin.optimizer)
- [TrainMixin.metrics](yzlite.core.TrainMixin.metrics)
- [TrainMixin.loss](yzlite.core.TrainMixin.loss)

### Training Keras Callback Settings

Tensorflow/Keras supports various [callbacks](https://www.tensorflow.org/api_docs/python/tf/keras/callbacks) while training.  
The YZLITE provides properties for some of the more common callbacks, e.g.:

```python
# https://keras.io/api/callbacks/reduce_lr_on_plateau/
my_model.reduce_lr_on_plateau['monitor'] = 'accuracy'
my_model.reduce_lr_on_plateau['factor'] =  0.25
my_model.reduce_lr_on_plateau['patience'] = 25
```

```{seealso}
- [Model Training](./model_training.md)
- [TrainMixin](yzlite.core.TrainMixin)
- [TrainMixin.train_callbacks](yzlite.core.TrainMixin.train_callbacks)
- [TrainMixin.lr_schedule](yzlite.core.TrainMixin.lr_schedule)
- [TrainMixin.reduce_lr_on_plateau](yzlite.core.TrainMixin.reduce_lr_on_plateau)
- [TrainMixin.tensorboard](yzlite.core.TrainMixin.tensorboard)
- [TrainMixin.checkpoint](yzlite.core.TrainMixin.checkpoint)
- [TrainMixin.early_stopping](yzlite.core.TrainMixin.early_stopping)
```

### Tensorflow-Lite Converter Settings

At the end of training, a quantized `.tflite` model file is generated.
This is the file that is programmed into the embedded device and executed by [Tensorflow-Lite Micro](https://github.com/tensorflow/tflite-micro).

The `.tflite` is generated by the Tensorflow-Lite [Converter](https://www.tensorflow.org/lite/convert).
The settings for the converter are defined in the model specification script using the model property: [TrainMixin.tflite_converter](yzlite.core.TrainMixin.tflite_converter).

For example, the model specification script might have:

```python
my_model.tflite_converter['optimizations'] = [tf.lite.Optimize.DEFAULT]
my_model.tflite_converter['supported_ops'] = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
my_model.tflite_converter['inference_input_type'] = tf.int8
my_model.tflite_converter['inference_output_type'] = tf.int8
my_model.tflite_converter['representative_dataset'] = 'generate'
```

These settings are used at the end of training to generate the `.tflite`.  
See [Model Quantization](./model_quantization.md) for more details.

```{seealso}
- [Model Quantization](./model_quantization.md)
- [TrainMixin.tflite_converter](yzlite.core.TrainMixin.tflite_converter)
- [TFLiteConverter](https://www.tensorflow.org/api_docs/python/tf/lite/TFLiteConverter)
- [Post-training Quantization](https://www.tensorflow.org/lite/performance/post_training_quantization)
```

### Basic Dataset Settings

Basic dataset settings includes information such as the dataset directory, the "class mode", the class labels, input shape, etc. These settings are strongly dependent on the type of machine learning model that is being trained and/or evaluated.

At a minimum, the [DatasetMixin](yzlite.core.DatasetMixin) should be inherited by the model specification's [YZLiteModel](yzlite.core.YZLiteModel) class. This mixin is generic and its properties directly map to the parameters required by
[KerasModel.fit()](https://www.tensorflow.org/api_docs/python/tf/keras/Model#fit) (the Tensorflow function that actually trains the model)

Alternatively, the YZLITE features other dataset mixins that are specific to the dataset type:

- [AudioDatasetMixin](yzlite.core.AudioDatasetMixin) - Used for audio datasets (i.e. the samples in the dataset are audio files)
- [ImageDatasetMixin](yzlite.core.ImageDatasetMixin) - Used for image datasets (i.e. the samples in the dataset are images)

These are useful as they manage some of the details required to process these types of datasets (whereas the [DatasetMixin](yzlite.core.DatasetMixin) is generic and all details must be handled manually).

For example, an audio-based model specification script might have:

```python
yzlite_model.dataset = speech_commands_v2
yzlite_model.class_mode = 'categorical'
yzlite_model.classes = ['up', 'down', 'left', 'right']
```

Alternatively, an image-based model specification script might have:

```python
yzlite_model.dataset = rock_paper_scissors_v1
yzlite_model.class_mode = 'categorical'
yzlite_model.classes = ['rock', 'paper', 'scissors']
yzlite_model.input_shape = (96, 96, 1)
```

```{seealso}
- [DatasetMixin](yzlite.core.DatasetMixin)
- [AudioDatasetMixin](yzlite.core.AudioDatasetMixin)
- [ImageDatasetMixin](yzlite.core.ImageDatasetMixin)
```

### Dataset Augmentation Settings

The [AudioDatasetMixin](yzlite.core.AudioDatasetMixin) and [ImageDatasetMixin](yzlite.core.ImageDatasetMixin) mixins
are useful because they allow for augmenting the dataset during training (which is useful as it effectively increases the size of the dataset which can lead to a more robust model).

These settings are configured in the [AudioDatasetMixin.datagen](yzlite.core.AudioDatasetMixin.datagen) and [ImageDatasetMixin.datagen](yzlite.core.ImageDatasetMixin.datagen) properties.

For example, an audio-based model specification script might have:

```python
yzlite_model.datagen = ParallelAudioDataGenerator(
    unknown_class_percentage=3.0,
    silence_class_percentage=0.2,
    offset_range=(0.0,1.0),
    trim_threshold_db=20,
    noise_colors=None,
    bg_noise_range=(0.0,0.3),
    bg_noise_dir='_background_noise_'
)
```

Alternatively, an image-based model specification script might have:

```python
my_model.datagen = ParallelImageDataGenerator(
    rotation_range=35,
    contrast_range=(0.50, 1.70),
    noise=['gauss', 'poisson', 's&p'],
    horizontal_flip=True,
    vertical_flip=True,
)
```

```{seealso}
- [AudioDatasetMixin](yzlite.core.AudioDatasetMixin)
- [ImageDatasetMixin](yzlite.core.ImageDatasetMixin)
- [ParallelAudioDataGenerator](yzlite.core.preprocess.audio.parallel_generator.ParallelAudioDataGenerator)
- [ParallelImageDataGenerator](yzlite.core.preprocess.image.parallel_generator.ParallelImageDataGenerator)
```

### Tensorflow Dataset API

Alternatively, you may use the [Tensorflow Dataset API](https://www.tensorflow.org/api_docs/python/tf/data/Dataset).
In this case, only the [DatasetMixin](yzlite.core.DatasetMixin) is required.
Note the YZLITE provides additional APIs to aid the creation of the Tensorflow datasets, see [Tensorflow Dataset Utilities](https://github.com/ReRAM-Labs/yzlite/docs/python_api/data_preprocessing/utilities.html#tensorflow-dataset).

The YZLITE comes with reference models using the [Tensorflow Dataset API](https://www.tensorflow.org/api_docs/python/tf/data/Dataset):

- [basic_tf_dataset_example](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/examples/basic_tf_dataset_example.html)
- [image_tf_dataset](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/examples/image_tf_dataset.html)
- [audio_tf_dataset](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/examples/audio_tf_dataset.html)

### Evaluation Settings

While an important aspect of the model specification script is configuring
the training settings, it can also be used for configuring the model evaluation settings.

[Model evaluation](./model_evaluation.md) is enabled by inheriting one of the following mixins:

- [EvaluateClassifierMixin](yzlite.core.EvaluateClassifierMixin) - Evaluate a classification model
- [EvaluateAutoEncoderMixin](yzlite.core.EvaluateAutoEncoderMixin) - Evaluate an auto-encoder model

```{seealso}
- [Model evaluation](./model_evaluation.md)
- [EvaluateClassifierMixin](yzlite.core.EvaluateClassifierMixin)
- [EvaluateAutoEncoderMixin](yzlite.core.EvaluateAutoEncoderMixin)
```

### Additional Parameters

Additional parameters can also be added to the model specification.  
[Model Parameters](./model_parameters.md) are user-defined and are added to the "metadata" section
of the generated `.tflite` model file.

For example, a model specification script might have:

```python
# Set the volume (in dB) scaler (i.e. amplitude) to apply to the microphone data. If 0 or omitted, no scaler is applied
yzlite_model.model_parameters['volume_db'] = 5.0
# This simulates the amount of time in milliseconds an audio loop takes. This helps to provide a better idea of how well the given model will execute on an embedded device
yzlite_model.model_parameters['latency_ms'] = 0
# Console logging level, set to 'debug' to enable verbose logging
yzlite_model.model_parameters['log_level'] = 'info'
```

```{seealso}
- [Model Parameters](./model_parameters.md) 
- [YZLiteModel.model_parameters](yzlite.core.YZLiteModel.model_parameters)
```

## Examples

See the [reference models](../python_api/models/index.md) for complete model specification scripts:

- [yizhutech.keyword_spotting_on_off](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/yizhutech/keyword_spotting_on_off.py)
- [examples.image_example1](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/examples/image_example1.py)
- [examples.audio_example1](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/examples/audio_example1.py)
- [examples.conv1d_example](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/examples/conv1d_example.py)
- [examples.siamese_contrastive](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/examples/siamese_contrastive.py)
- [tflite_micro.tflite_micro_speech](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/tflite_micro/tflite_micro_speech.py)
- [tflite_micro.tflite_micro_magic_wand](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/tflite_micro/tflite_micro_magic_wand.py)
- [tinyml.anomaly_detection](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/tinyml/anomaly_detection.py)
- [tinyml.image_classification](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/tinyml/image_classification.py)
- [tinyml.keyword_spotting](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/tinyml/keyword_spotting.py)
- [tinyml.visual_wake_words](https://github.com/ReRAM-Labs/yzlite/blob/master/yzlite/models/tinyml/visual_wake_words.py)
