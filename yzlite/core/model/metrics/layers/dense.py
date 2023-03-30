from typing import Union

from yzlite.core import TfliteFullyConnectedLayer
from yzlite.core.tflite_model.tflite_schema import BuiltinOperator

from .layer import KerasLayer, Layer, TfliteLayer, flat_size


class Dense(Layer):

    def __init__(self):
        Layer.__init__(self, ('Dense', BuiltinOperator.FULLY_CONNECTED))

    def process(self, layer: Union[TfliteLayer, KerasLayer]):
        bias_ops = 0
        if isinstance(layer, TfliteFullyConnectedLayer):
            in_depth = layer.input_data.shape[-1]
            out_depth = layer.output_data.shape[-1]
            if layer.use_bias:
                bias_ops = layer.outputs[0].shape.flat_size
        else:
            in_depth = layer.input_shape[-1]
            out_depth = layer.output_shape[-1]
            if layer.use_bias:
                bias_ops = flat_size(layer.output_shape[1:])

        self.name = layer.name
        self.macs = in_depth * out_depth
        self.ops = self.macs * 2 + bias_ops


class DenseTransposeShared(Layer):

    def __init__(self):
        Layer.__init__(self, 'DenseTransposeShared')

    def process(self, layer: Union[TfliteLayer, KerasLayer]):
        bias_ops = 0
        if isinstance(layer, KerasLayer):
            in_depth = layer.input_shape[-1]
            out_depth = layer.output_shape[-1]
            if layer.use_bias:
                bias_ops = flat_size(layer.output_shape[1:])
        else:
            in_depth = layer.inputs[0][-1]
            out_depth = layer.outputs[0][-1]
            if layer.n_outputs > 2:
                bias_ops = layer.outputs[0].shape.flat_size

        self.name = layer.name
        self.macs = in_depth * out_depth
        self.ops = self.macs * 2 + bias_ops


Dense()
DenseTransposeShared()
