__NOTE:__ Refer to the [online documentation](https://github.com/ReRAM-Labs/yzlite) to properly view this file

# Tensorflow-Lite Model

This allows for accessing [.tflite](https://www.tensorflow.org/lite/models/convert) model files.
A `.tflite` uses a binary format called a [flatbuffer](https://google.github.io/flatbuffers/).
The flatbuffer "schema" used by a `.tflite` model is defined in [schema.fbs](https://github.com/tensorflow/tensorflow/blob/master/tensorflow/lite/schema/schema.fbs).

## Example Usage

Example usage of this package is as follows:

```python
# Import the TfliteModel class
from yzlite.core import TfliteModel

# Load the .tflite
tflite_model = TfliteModel.load_flatbuffer_file(tflite_path)

# Generate a summary of the .tflite
summary = tflite_model.summary()

# Print the summary to the console
print(summary)
```

See the [TfliteModel API examples](https://github.com/ReRAM-Labs/yzlite/yzlite/examples/tflite_model.html) for more examples.

## API Reference

```{eval-rst}
.. autosummary::
   :toctree: model
   :template: custom-class-template.rst

   yzlite.core.TfliteModel

.. autosummary::
   :toctree: layer
   :template: custom-class-template.rst

   yzlite.core.TfliteLayer

.. autosummary::
   :toctree: add_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteAddLayer

.. autosummary::
   :toctree: conv2d_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteConv2dLayer

.. autosummary::
   :toctree: conv2d_layer_options
   :template: custom-class-template.rst

   yzlite.core.TfliteConv2DLayerOptions

.. autosummary::
   :toctree: conv_params
   :template: custom-class-template.rst

   yzlite.core.TfliteConvParams

.. autosummary::
   :toctree: transpose_conv_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteTransposeConvLayer

.. autosummary::
   :toctree: transpose_conv_layer_options
   :template: custom-class-template.rst

   yzlite.core.TfliteTransposeConvLayerOptions

.. autosummary::
   :toctree: transpose_conv_params
   :template: custom-class-template.rst

   yzlite.core.TfliteTransposeConvParams

.. autosummary::
   :toctree: fully_connected_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteFullyConnectedLayer

.. autosummary::
   :toctree: fully_connected_layer_options
   :template: custom-class-template.rst

   yzlite.core.TfliteFullyConnectedLayerOptions

.. autosummary::
   :toctree: fully_connected_params
   :template: custom-class-template.rst

   yzlite.core.TfliteFullyConnectedParams

.. autosummary::
   :toctree: depthwise_conv2d_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteDepthwiseConv2dLayer

.. autosummary::
   :toctree: depthwise_conv2d_layer_options
   :template: custom-class-template.rst

   yzlite.core.TfliteDepthwiseConv2DLayerOptions

.. autosummary::
   :toctree: depthwise_conv_params
   :template: custom-class-template.rst

   yzlite.core.TfliteDepthwiseConvParams

.. autosummary::
   :toctree: pooling2d_layer
   :template: custom-class-template.rst

   yzlite.core.TflitePooling2dLayer

.. autosummary::
   :toctree: pooling2d_layer_options
   :template: custom-class-template.rst

   yzlite.core.TflitePool2DLayerOptions

.. autosummary::
   :toctree: pooling_params
   :template: custom-class-template.rst

   yzlite.core.TflitePoolParams

.. autosummary::
   :toctree: reshape_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteReshapeLayer

.. autosummary::
   :toctree: quantize_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteQuantizeLayer

.. autosummary::
   :toctree: dequantize_layer
   :template: custom-class-template.rst

   yzlite.core.TfliteDequantizeLayer

.. autosummary::
   :toctree: tensor
   :template: custom-class-template.rst

   yzlite.core.TfliteTensor

.. autosummary::
   :toctree: shape
   :template: custom-class-template.rst

   yzlite.core.TfliteShape

.. autosummary::
   :toctree: quantization
   :template: custom-class-template.rst

   yzlite.core.TfliteQuantization

.. autosummary::
   :toctree: activation
   :template: custom-class-template.rst

   yzlite.core.TfliteActivation

.. autosummary::
   :toctree: padding
   :template: custom-class-template.rst

   yzlite.core.TflitePadding

.. autosummary::
   :toctree: parameters
   :template: custom-class-template.rst

   yzlite.core.TfliteModelParameters
```

```{toctree}
:maxdepth: 1
:hidden:

./model
./parameters
./dictionary.fbs.md
./layer
./add_layer
./conv2d_layer
./conv2d_layer_options
./conv_params
./transpose_conv_layer
./transpose_conv_layer_options
./transpose_conv_params
./fully_connected_layer
./fully_connected_layer_options
./fully_connected_params
./depthwise_conv2d_layer
./depthwise_conv2d_layer_options
./depthwise_conv_params
./pooling2d_layer
./pooling2d_layer_options
./pooling_params
./reshape_layer
./quantize_layer
./dequantize_layer
./tensor
./shape
./quantization
./activation
./padding
```
