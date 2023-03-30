
# Bring in the required Keras classes
import functools

from tensorflow.keras.layers import (Activation, AveragePooling2D,
                                     BatchNormalization, Conv2D, Dense,
                                     Flatten)
from tensorflow.keras.models import Sequential
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.utils import to_categorical

from yzlite.core.keras import ImageDataGenerator
from yzlite.core.model import (EvaluateClassifierMixin, ImageDatasetMixin,
                               TrainMixin, YZLiteModel)
from yzlite.datasets.image import cifar10


# Instantiate the YZLiteModel object with the following 'mixins':
# - TrainMixin            - Provides classifier model training operations and settings
# - ImageDatasetMixin     - Provides image data generation operations and settings
# - EvaluateClassifierMixin         - Provides classifier evaluation operations and settings
# @yzlite_model # NOTE: This tag is required for this model be discoverable
class MyModel(
    YZLiteModel,
    TrainMixin,
    ImageDatasetMixin,
    EvaluateClassifierMixin
):
    pass


yzlite_model = MyModel()


#################################################
# General Settings
#
yzlite_model.version = 1
yzlite_model.description = 'Model used for unit tests'


#################################################
# Training Settings
yzlite_model.epochs = 5
yzlite_model.batch_size = 3
yzlite_model.optimizer = 'adam'
yzlite_model.metrics = ['accuracy']
yzlite_model.loss = 'categorical_crossentropy'

#################################################
# Training callback Settings

# Generate a training weights .h5 whenever the
# val_accuracy improves
yzlite_model.checkpoint['monitor'] = 'val_accuracy'


#################################################
# TF-Lite converter settings
yzlite_model.tflite_converter['optimizations'] = ['DEFAULT']
yzlite_model.tflite_converter['supported_ops'] = ['TFLITE_BUILTINS_INT8']
# can also be float32
yzlite_model.tflite_converter['inference_input_type'] = 'int8'
yzlite_model.tflite_converter['inference_output_type'] = 'int8'
# generate a representative dataset from the validation data
yzlite_model.tflite_converter['representative_dataset'] = 'generate'


#################################################
# Image Dataset Settings

# The directory of the training data
def my_dataset_loader(model):
    (x_train, y_train), (x_test, y_test) = cifar10.load_data()
    # Convert for training
    x_train = x_train.astype('float32')[:64]
    x_test = x_test.astype('float32')[:64]

    y_train = y_train[:64]
    y_test = y_test[:64]

    # Scale to INT8 range (simple non-adaptive)
    x_train = (x_train-128)/128
    x_test = (x_test-128)/128

    y_train = to_categorical(y_train, len(model.classes))
    y_test = to_categorical(y_test, len(model.classes))

    return x_train, y_train, x_test, y_test


yzlite_model.dataset = functools.partial(my_dataset_loader, yzlite_model)

# The classification type
yzlite_model.class_mode = 'categorical'
# The class labels found in your training dataset directory
yzlite_model.classes = ['airplane', 'automobile', 'bird',
                        'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']
# The input shape to the model. The dataset samples will be resized if necessary
yzlite_model.input_shape = (32, 32, 3)


#################################################
# ImageDataGenerator Settings

yzlite_model.datagen = ImageDataGenerator(
    validation_split=0.1,
)


#################################################
# Build the ML Model
def my_model_builder(model: MyModel):
    keras_model = Sequential(name=yzlite_model.name)

    keras_model.add(Conv2D(8, strides=(2, 2),
                           kernel_size=3, use_bias=True, padding='same',
                           activation='relu', input_shape=model.input_shape))
    keras_model.add(Flatten())
    keras_model.add(Dense(model.n_classes, use_bias=True))
    keras_model.add(Activation('softmax'))

    keras_model.compile(
        loss=model.loss,
        optimizer=model.optimizer,
        metrics=model.metrics
    )

    return keras_model


yzlite_model.build_model_function = my_model_builder
