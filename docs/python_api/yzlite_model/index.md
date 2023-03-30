# YZLITE Model

The [YZLiteModel](yzlite.core.YZLiteModel) is the root object used to create a [model specification](../../guides/model_specification.md).

The [model specification](../../guides/model_specification.md) should define an object that inherits [YZLiteModel](yzlite.core.YZLiteModel)
and any other required mixins. Once the object is defined and instantiated, the various properties should be populated.
After the model specification is finished, it may be invoked with one of the various [Model Operations](../operations/index.md).

## Example Usage

The following is a snippet from the [basic_example](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/examples/basic_example.html) reference model:

```python
import yzlite.core as yzlite_core

class MyModel(
    yzlite_core.YZLiteModel,    # We must inherit the YZLiteModel class
    yzlite_core.TrainMixin,   # We also inherit the TrainMixin since we want to train this model
    yzlite_core.DatasetMixin, # We also need the DatasetMixin mixin to provide the relevant dataset properties
    yzlite_core.EvaluateClassifierMixin,  # While not required, also inherit EvaluateClassifierMixin to help will generating evaluation for our classification model
):
    pass

my_model = MyModel()

my_model.version = 1
my_model.description = 'Basic model specification example'
my_model.classes = ['cat', 'dog', 'goat']
my_model.class_weights = 'balanced'
my_model.batch_size = 32
my_model.epochs = 100
my_model.validation_split = 0.2
...

if __name__ == '__main__':
    # Train the model
    # This does the same as issuing the command: yzlite train basic_example
    yzlite_core.train_model(my_model, clean=True)
    # Evaluate the model against the quantized .tflite (i.e. int8) model
    # This does the same as issuing the command: yzlite evaluate basic_example --tflite
    yzlite_core.evaluate_model(my_model, tflite=True)
    # Profile the model in the simulator
    # This does the same as issuing the command: yzlite profile basic_example
    yzlite_core.profile_model(my_model)

```

See the [reference models](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/index.html) for more examples.

Additional [Model Utilities](https://github.com/ReRAM-Labs/yzlite/docs/python_api/yzlite_model/utilities.html) are also available.

## API Reference

The following [YZLiteModel](yzlite.core.YZLiteModel) mixins are available:

```{eval-rst}
.. autosummary::
   :nosignatures:
   :toctree: model
   :template: custom-class-template.rst

   yzlite.core.YZLiteModel

.. autosummary::
   :nosignatures:
   :toctree: train_mixin
   :template: custom-class-template.rst

   yzlite.core.TrainMixin

.. autosummary::
   :nosignatures:
   :toctree: dataset_mixin
   :template: custom-class-template.rst

   yzlite.core.DatasetMixin

.. autosummary::
   :nosignatures:
   :toctree: audio_dataset_mixin
   :template: custom-class-template.rst

   yzlite.core.AudioDatasetMixin

.. autosummary::
   :nosignatures:
   :toctree: image_dataset_mixin
   :template: custom-class-template.rst

   yzlite.core.ImageDatasetMixin

.. autosummary::
   :nosignatures:
   :toctree: evaluate_mixin
   :template: custom-class-template.rst

   yzlite.core.EvaluateMixin

.. autosummary::
   :nosignatures:
   :toctree: evaluate_autoencoder_mixin
   :template: custom-class-template.rst

   yzlite.core.EvaluateAutoEncoderMixin

.. autosummary::
   :nosignatures:
   :toctree: evaluate_classifier_mixin
   :template: custom-class-template.rst

   yzlite.core.EvaluateClassifierMixin

.. autosummary::
   :nosignatures:
   :toctree: ssh_mixin
   :template: custom-class-template.rst

   yzlite.core.SshMixin

.. autosummary::
   :nosignatures:
   :toctree: weights_and_biases_mixin
   :template: custom-class-template.rst

   yzlite.core.WeightsAndBiasesMixin

.. autosummary::
   :nosignatures:
   :toctree: yzlite_dataset
   :template: custom-class-template.rst

   yzlite.core.YZLiteDataset

.. autosummary::
   :nosignatures:
   :toctree: model_event
   :template: custom-class-template.rst

   yzlite.core.YZLiteModelEvent

```

```{toctree}
:maxdepth: 2
:hidden:

./model
./train_mixin
./dataset_mixin
./image_dataset_mixin
./audio_dataset_mixin
./evaluate_mixin
./evaluate_classifier_mixin
./evaluate_autoencoder_mixin
./ssh_mixin
./weights_and_biases_mixin
./utilities
./yzlite_dataset
./model_event
```
