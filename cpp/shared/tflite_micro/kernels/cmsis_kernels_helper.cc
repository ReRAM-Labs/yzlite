#include "yzlite_tflite_micro_internal.hpp"

extern "C" void yzlite_tflite_micro_register_accelerator() {
  // This is just a placeholder since there is not specific accelerator to
  // register for this CMSIS kernels
  yzlite::yzlite_tflite_micro_set_accelerator(nullptr);
}