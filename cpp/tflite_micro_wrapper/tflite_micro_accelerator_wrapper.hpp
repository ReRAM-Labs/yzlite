
#include "tensorflow/lite/micro/micro_op_resolver.h"
#include "yzlite_tflite_micro_helper.hpp"

namespace yzlite {

class TfliteMicroAcceleratorWrapper {
public:
  const TfliteMicroAccelerator *accelerator = nullptr;

  // Register the accelerator and return its op resolver
  virtual tflite::MicroOpResolver *load() = 0;
};

} // namespace yzlite