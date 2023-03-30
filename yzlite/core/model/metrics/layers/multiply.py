from typing import Union

from yzlite.core.tflite_model.tflite_schema import BuiltinOperator

from .layer import KerasLayer, Layer, TfliteLayer, flat_size


class Multiply(Layer):

    def __init__(self):
        Layer.__init__(self, ('Multiply', BuiltinOperator.MUL))

    def process(self, layer: Union[TfliteLayer, KerasLayer]):
        self.name = layer.name
        self.macs = 0
        if isinstance(layer, KerasLayer):
            output_shape = layer.output_shape
        else:
            output_shape = layer.outputs[0].shape

        # This assumes element-wise multiplication with all tensors the same shape
        self.ops = flat_size(output_shape[1:])


Multiply()
