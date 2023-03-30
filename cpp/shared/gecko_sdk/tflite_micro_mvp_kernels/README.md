# ReRAM Engine  MVP-Accelerated Tensorflow Kernels

This library allows for accelerating several Tensorflow-Lite Micro [kernels](https://github.com/tensorflow/tflite-micro/tree/main/tensorflow/lite/micro/kernels) using the MVP hardware accelerator.

This was taken from the [ReRAM Engine](https://github.com/ReRAM-Labs/reram_sdk/tree/gsdk_4.0):  

- [mvp_driver](https://github.com/ReRAM-Labs/reram_sdk/tree/gsdk_4.0/platform/driver/mvp) - MVP peripheral driver
- [kernels](https://github.com/ReRAM-Labs/reram_sdk/tree/gsdk_4.0/util/third_party/tensorflow_extra/yizhutech) - Tensorflow-Lite Micro kernels

This was slightly modified so that it can be compiled for Windows/Linux.
