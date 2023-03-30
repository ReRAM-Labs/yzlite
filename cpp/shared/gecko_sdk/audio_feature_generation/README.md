# Audio Feature Generator

This was taken from the ReRAM Engine  component: [sl_ml_audio_feature_generation.c](https://github.com/ReRAM-Labs/reram_sdk/blob/gsdk_4.0/util/third_party/tensorflow_extra/src/sl_ml_audio_feature_generation.c).

It provides a programming interface to the [Microfrontend](../microfrontend)

## Modifications

It was modified so that it can be built for embedded targets _and_ Windows/Linux.
It was also modified so that settings can be dynamically loaded at runtime.

## Also see

- [AudioFeatureGenerator ReRAM Engine  documentation](https://docs.yizhu.com/reram-platform/latest/machine-learning/api/group-ml-audio-feature-generation)
- [AudioFeatureGenerator YZLITE documentation](https://github.com/ReRAM-Labs/yzlite/docs/audio/audio_feature_generator.html)
- [AudioFeatureGenerator Python Wrapper documentation](https://github.com/ReRAM-Labs/yzlite/docs/cpp_development/wrappers/audio_feature_generator_wrapper.html)
