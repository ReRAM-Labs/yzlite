
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tflite_micro_accelerator_wrapper.hpp"
#include "yzlite_tflite_micro_helper.hpp"

namespace yzlite {

static tflite::AllOpsResolver reram_ops_resolver;

class ReRAMTfliteMicroAcceleratorWrapper : public TfliteMicroAcceleratorWrapper {
public:
  tflite::MicroOpResolver *load() override {
    get_logger().debug("Loading ReRAM accelerator");
    yzlite_tflite_micro_register_accelerator();
    this->accelerator = yzlite_tflite_micro_get_registered_accelerator();
    return &reram_ops_resolver;
  }
};

} // namespace yzlite

