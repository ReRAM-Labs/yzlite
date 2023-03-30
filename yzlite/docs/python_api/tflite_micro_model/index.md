__NOTE:__ Refer to the [online documentation](https://github.com/ReRAM-Labs/yzlite) to properly view this file

# Tensorflow-Lite Micro Model

This package allows for executing a quantized `.tflite` model file in the [Tensorflow-Lite Micro](https://github.com/tensorflow/tflite-micro) interpreter.

## Example Usage

Example usage of this package is as follows:

```python
from yzlite.core.tflite_micro import TfliteMicro

# Profile the model in the TFLM interpreter
profiling_results = TfliteMicro.profile_model(tflite_path)

print(profiling_results)
```

See the [TfliteMicroModel API examples](https://github.com/ReRAM-Labs/yzlite/yzlite/examples/tflite_micro_model.html) for more examples.

## API Reference

```{eval-rst}
.. autosummary::
   :toctree: model
   :template: custom-class-template.rst

   yzlite.core.tflite_micro.TfliteMicroModel

.. autosummary::
   :toctree: model_details
   :template: custom-class-template.rst

   yzlite.core.tflite_micro.TfliteMicroModelDetails

.. autosummary::
   :toctree: wrapper
   :template: custom-class-template.rst

   yzlite.core.tflite_micro.TfliteMicro

.. autosummary::
   :toctree: profiled_layer_result
   :template: custom-class-template.rst

   yzlite.core.tflite_micro.TfliteMicroProfiledLayerResult


.. autosummary::
   :toctree: layer_error
   :template: custom-class-template.rst

   yzlite.core.tflite_micro.TfliteMicroLayerError

.. autosummary::
   :toctree: accelerator
   :template: custom-class-template.rst

   yzlite.core.tflite_micro.tflite_micro_accelerator.TfliteMicroAccelerator

```

```{toctree}
:maxdepth: 1
:hidden:

./model
./model_details
./wrapper
./accelerator
./layer_error
./profiled_layer_result
```
