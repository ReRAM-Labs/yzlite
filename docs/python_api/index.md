# API Reference

Once the YZLITE is [installed](../installation.md) into the Python environment, it may be imported into a python script using:

```python
import yzlite
```

Once the YZLITE is imported, it's various APIs may be accessed.

**API Overview**

The following provides a general overview of the YZLITE Python API:

| Name                                                                                                            | Description                                                                                                                  |
|-----------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| [Model Operations](https://github.com/ReRAM-Labs/yzlite/docs/python_api/operations/index.html)                    | Modeling operations such as profiling and training                                                                           |
| [YZLITE Model](https://github.com/ReRAM-Labs/yzlite/docs/python_api/yzlite_model/index.html)                          | Provides the root object of a [model specification](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_specification.html) |
| [Tensorflow-Lite Model](https://github.com/ReRAM-Labs/yzlite/docs/python_api/tflite_model/index.html)             | Enables reading/writing `.tflite` model flatbuffer                                                                           |
| [Tensorflow-Lite Micro Model](https://github.com/ReRAM-Labs/yzlite/docs/python_api/tflite_micro_model/index.html) | Enables running `.tflite` models in the [Tensorflow-Lite Micro](https://github.com/tensorflow/tflite-micro) interpreter      |
| [Keras Model](https://www.tensorflow.org/api_docs/python/tf/keras/Model)                                        | The model object used by [Tensorflow](https://www.tensorflow.org/overview) during model training                             |
| [Data Preprocessing](https://github.com/ReRAM-Labs/yzlite/docs/python_api/data_preprocessing/index.html)          | Dataset preprocessing utilities                                                                                              |
| [Utilities](https://github.com/ReRAM-Labs/yzlite/docs/python_api/utils/index.html)                                | Common utilities                                                                                                             |
| [Reference Models](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/index.html)                        | Pre-trained reference models                                                                                                 |
| [Reference Datasets](https://github.com/ReRAM-Labs/yzlite/docs/python_api/datasets/index.html)                    | Datasets used by reference models                                                                                            |

**Package Directory Structure**

The YZLITE Python package has the following structure:

| Name                                                                                                                   | Description                                                                                                                                                                                                                                                         |
|------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [yzlite](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite)                                                           | The root of the YZLITE package                                                                                                                                                                                                                                        |
| [yzlite.core](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core)                                                 | Core modeling utilities, see the [Model Operations](https://github.com/ReRAM-Labs/yzlite/docs/python_api/operations/index.html) docs for more details                                                                                                                 |
| [yzlite.core.model](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/model)                                     | Provides the root object of a [model specification](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_specification.html), more details in the [YZLITE Model](https://github.com/ReRAM-Labs/yzlite/docs/python_api/yzlite_model/index.html) docs                       |
| [yzlite.core.preprocess](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/preprocess)                           | Data pre-processing utilities, see the [Data Preprocessing](https://github.com/ReRAM-Labs/yzlite/docs/python_api/data_preprocessing/index.html) docs for more info                                                                                                    |
| [yzlite.core.tflite_model](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/tflite_model)                       | Enables reading/writing `.tflite` model flatbuffers, more details in the [TfliteModel](https://github.com/ReRAM-Labs/yzlite/docs/python_api/tflite_model/index.html) docs                                                                                             |
| [yzlite.core.tflite_model_parameters](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/tflite_model_parameters) | Enables read/writing custom parameters in a `.tflite` model flatbuffer                                                                                                                                                                                              |
| [yzlite.core.tflite_micro](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/tflite_micro)                       | Enables running `.tflite` models in the [Tensorflow-Lite Micro](https://github.com/tensorflow/tflite-micro) interpreter, more details in the [Tensorflow-Lite Micro Wrapper](https://github.com/ReRAM-Labs/yzlite/docs/python_api/tflite_micro_model/index.html) docs |
| [yzlite.core.keras](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/core/keras)                                     | Helper scripts for the [Keras API](https://www.tensorflow.org/api_docs/python/tf/keras)                                                                                                                                                                             |
| [yzlite.utils](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/utils)                                               | Common utility scripts, more details in the [utilities](https://github.com/ReRAM-Labs/yzlite/docs/python_api/utils/index.html) docs                                                                                                                                   |
| [yzlite.cli](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/cli)                                                   | YZLITE Command-Line Interface (CLI) scripts                                                                                                                                                                                                                           |
| [yzlite.models](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/models)                                             | Reference models, more details in the [Reference models](https://github.com/ReRAM-Labs/yzlite/docs/python_api/models/index.html) docs                                                                                                                                 |
| [yzlite.datasets](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/datasets)                                         | Reference datasets, more details in the [Reference datasets](https://github.com/ReRAM-Labs/yzlite/docs/python_api/datasets/index.html) docs                                                                                                                           |

```{eval-rst}
.. toctree::
   :maxdepth: 1
   :hidden:

   ./operations/index
   ./yzlite_model/index
   ./tflite_micro_model/index
   ./tflite_model/index
   ./keras_model
   ./data_preprocessing/index
   ./utils/index
```
