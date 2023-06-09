

import numpy as np
import tensorflow as tf
from tensorflow.keras.layers import (Activation, AveragePooling2D,
                                     BatchNormalization, Conv2D, Dense,
                                     Flatten, Input)
from tensorflow.keras.models import Model
from tensorflow.keras.regularizers import l2

# define model


def ResNet10V1(
    input_shape: tuple = (32, 32, 3),  # default size for cifar10
    num_classes: int = 10,  # default class number for cifar10
    num_filters: int = 16  # this should be 64 for an official resnet model
) -> Model:
    """ResNetv1-10 

    .. seealso::
       * https://arxiv.org/pdf/1512.03385.pdf
       * https://keras.io/api/applications/resnet/
       * https://github.com/ReRAM-Labs/platform_ml_models/blob/master/eembc/CIFAR10_ResNetv1/resnet_v1_eembc.py
    """

    # Input layer, change kernel size to 7x7 and strides to 2 for an official resnet
    inputs = Input(shape=input_shape)
    x = Conv2D(num_filters,
               kernel_size=3,
               strides=1,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(inputs)
    x = BatchNormalization()(x)
    x = Activation('relu')(x)
    # x = MaxPooling2D(pool_size=(2, 2))(x) # uncomment this for official resnet model

    # First stack

    # Weight layers
    y = Conv2D(num_filters,
               kernel_size=3,
               strides=1,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(x)
    y = BatchNormalization()(y)
    y = Activation('relu')(y)
    y = Conv2D(num_filters,
               kernel_size=3,
               strides=1,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(y)
    y = BatchNormalization()(y)

    # Overall residual, connect weight layer and identity paths
    x = tf.keras.layers.add([x, y])
    x = Activation('relu')(x)

    # Second stack

    # Weight layers
    num_filters = 32  # Filters need to be double for each stack
    y = Conv2D(num_filters,
               kernel_size=3,
               strides=2,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(x)
    y = BatchNormalization()(y)
    y = Activation('relu')(y)
    y = Conv2D(num_filters,
               kernel_size=3,
               strides=1,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(y)
    y = BatchNormalization()(y)

    # Adjust for change in dimension due to stride in identity
    x = Conv2D(num_filters,
               kernel_size=1,
               strides=2,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(x)

    # Overall residual, connect weight layer and identity paths
    x = tf.keras.layers.add([x, y])
    x = Activation('relu')(x)

    # Third stack

    # Weight layers
    num_filters = 64
    y = Conv2D(num_filters,
               kernel_size=3,
               strides=2,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(x)
    y = BatchNormalization()(y)
    y = Activation('relu')(y)
    y = Conv2D(num_filters,
               kernel_size=3,
               strides=1,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(y)
    y = BatchNormalization()(y)

    # Adjust for change in dimension due to stride in identity
    x = Conv2D(num_filters,
               kernel_size=1,
               strides=2,
               padding='same',
               kernel_initializer='he_normal',
               kernel_regularizer=l2(1e-4))(x)

    # Overall residual, connect weight layer and identity paths
    x = tf.keras.layers.add([x, y])
    x = Activation('relu')(x)

    # Fourth stack.
    # While the paper uses four stacks, for cifar10 that leads to a large increase in complexity for minor benefits
    # Uncomments to use it

#    # Weight layers
#    num_filters = 128
#    y = Conv2D(num_filters,
#                  kernel_size=3,
#                  strides=2,
#                  padding='same',
#                  kernel_initializer='he_normal',
#                  kernel_regularizer=l2(1e-4))(x)
#    y = BatchNormalization()(y)
#    y = Activation('relu')(y)
#    y = Conv2D(num_filters,
#                  kernel_size=3,
#                  strides=1,
#                  padding='same',
#                  kernel_initializer='he_normal',
#                  kernel_regularizer=l2(1e-4))(y)
#    y = BatchNormalization()(y)
#
#    # Adjust for change in dimension due to stride in identity
#    x = Conv2D(num_filters,
#                  kernel_size=1,
#                  strides=2,
#                  padding='same',
#                  kernel_initializer='he_normal',
#                  kernel_regularizer=l2(1e-4))(x)
#
#    # Overall residual, connect weight layer and identity paths
#    x = tf.keras.layers.add([x, y])
#    x = Activation('relu')(x)

    # Final classification layer.
    pool_size = int(np.amin(x.shape[1:3]))
    x = AveragePooling2D(pool_size=pool_size)(x)
    y = Flatten()(x)
    outputs = Dense(num_classes,
                    activation='softmax',
                    kernel_initializer='he_normal')(y)

    # Instantiate model.
    model = Model(inputs=inputs, outputs=outputs)
    return model
