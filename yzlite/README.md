# YZLITE Python Package

This directory contains all of the YZLITE Python scripts.

This directory has the following structure:

```
/cli                            - Command line interface (CLI) commands. These commands are accessible via the yzlite command
/core                           - Core YZLITE Python packages
/core/model                     - YZLITE Model object and mixins
/core/preprocess                - Data preprocessing utilities
/core/tflite_micro              - Tensorflow-Lite Micro object. This uses the C++ Python wrapper to access the C++ library
/core/tflite_model              - Object to access a .tflite model file
/core/tflite_model_parameters   - Object to access custom parameters built into a .tflite model file
/utils                          - Various utility scripts
/datasets                       - Reference datasets
/models                         - Reference models
/examples                       - API usage examples
/tutorials                      - YZLITE tutorials
```

Refer to the [Python API Reference](https://github.com/ReRAM-Labs/yzlite/docs/python_api/python_api.html) for more details.
