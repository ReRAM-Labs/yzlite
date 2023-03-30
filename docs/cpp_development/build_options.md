# C++ Build Options

Custom CMake settings may be specified in the file:

```
<yzlite repo root>/user_options.cmake
```

__NOTE:__  You must create this file if it doesn't exist

This file is included at the very beginning of the CMake build script.
Any CMake variable may be include in the file.  
Some of the more common settings include:

## YZLITE_CMAKE_LOG_LEVEL

```
# Enable verbose YZLITE CMake log messages
yzlite_set(YZLITE_CMAKE_LOG_LEVEL debug)
```

## YZLITE_PLATFORM_NAME

Build for a supported embedded platform.

Refer to [Supported Hardware](../other/supported_hardware.md) for more details.

__NOTE:__ If this variable is not defined, then the host operating system (e.g. `windows` or `linux`) is automatically selected.

```shell
# Specify the embedded platform
yzlite_set(YZLITE_PLATFORM_NAME brd2601)
```

## TFLITE_MICRO_ACCELERATOR

Specify the Tensorflow-Lite Micro accelerated kernels to include in the build.

```shell
# Use the ReRAM Engine  MVP TFLM kernels
yzlite_set(TFLITE_MICRO_ACCELERATOR mvp)
```

## YZLITE_TARGET

Build for a specific target.  
By default, all applications are automatically included during the CMake configuration phase.
This option allows only include a specific package in the configuration.

__NOTE:__ The specified target must be found via `find_package()` or `yzlite_find_package()`.

```shell
# Only include the TFLM Python wrapper in the build
yzlite_set(YZLITE_TARGET yzlite_tflite_micro_wrapper)
```

## YZLITE_ENABLE_DEBUG_INFO_IN_RELEASE_BUILDS

This will add debug symbols to release builds.
This is useful for building fully optimized binaries but still allow for single-step debugging

```shell
yzlite_set(YZLITE_ENABLE_DEBUG_INFO_IN_RELEASE_BUILDS ON)
```

## YZLITE_ENABLE_OUTPUT_DISASSEMBLY

This will disassemble the output binary and generate a log file in the build directory.
This is useful for debugging the assembly instructions with the corresponding source code.

__NOTE:__ It is recommended to also enable `YZLITE_ENABLE_DEBUG_INFO_IN_RELEASE_BUILDS` for release builds.

```shell
yzlite_set(YZLITE_ENABLE_OUTPUT_DISASSEMBLY ON)
```

## MODEL_PROFILER_MODEL

```shell
# Specify the path to the .tflite model file to profile
# in the yzlite_model_profiler application
yzlite_set(MODEL_PROFILER_MODEL ~/my_models/my_model.tflite)
```

__HINT:__  
You can also specify the path to the `.yzlite.zip` model archive or just specify the YZLITE model name, e.g.:

```shell
# Specify the path to the model archive
yzlite_set(MODEL_PROFILER_MODEL ~/my_models/my_model.yzlite.zip)

# Specify the YZLITE model name
# NOTE: The model specification must be on the model search path, see:
#       https://github.com/ReRAM-Labs/yzlite/docs/guides/model_search_path.html
yzlite_set(MODEL_PROFILER_MODEL image_example1)
```

## AUDIO_CLASSIFIER_MODEL

```
# Specify the path to the .tflite model file to profile
# in the yzlite_audio_classifier application
yzlite_set(AUDIO_CLASSIFIER_MODEL ~/my_models/my_model.tflite)
```

__HINT:__  
You can also specify the path to the `.yzlite.zip` model archive or just specify the YZLITE model name, e.g.:

```shell
# Specify the path to the model archive
yzlite_set(AUDIO_CLASSIFIER_MODEL ~/my_models/my_model.yzlite.zip)

# Specify the YZLITE model name
# NOTE: The model specification must be on the model search path, see:
#       https://github.com/ReRAM-Labs/yzlite/docs/guides/model_search_path.html
yzlite_set(AUDIO_CLASSIFIER_MODEL image_example1)
```

## YZLITE_RUN_MODEL_FROM_RAM

In the [__yzlite__/cpp/shared/apps/model_profiler](../../cpp/shared/apps/model_profiler) app, load the `.tflite` model into RAM before
running inference. This causes all models weights and filters to
reside in RAM as well.

__NOTE:__ Bobcat only has 256K of RAM total. So the model
must be small enough to fit the model + TFLM working memory.

```shell
yzlite_set(YZLITE_RUN_MODEL_FROM_RAM ON)
```
