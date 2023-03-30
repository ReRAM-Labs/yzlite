# pylint: disable=import-outside-toplevel,unused-import
import copy
from typing import Union

from tensorflow.keras.layers import Layer as KerasLayer

from yzlite.core import TfliteLayer

from .layer import SUPPORTED_LAYERS, Layer


def parse_layer(model_layer: Union[TfliteLayer, KerasLayer]) -> Layer:
    if isinstance(model_layer, KerasLayer):
        opcode = model_layer.__class__.__name__
    else:
        opcode = model_layer.opcode

    for l in SUPPORTED_LAYERS:
        if opcode in l.opcodes:
            layer = copy.deepcopy(l)
            layer.process(model_layer)
            return layer

    return None


def load_layers():
    if len(SUPPORTED_LAYERS) > 0:
        return

    from . import (activation, add, conv, dense, depthwise_conv, ignored,
                   multiply, pad, pooling, quantize, reshape)
