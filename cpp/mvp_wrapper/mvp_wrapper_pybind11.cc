

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "mvp_tflite_micro_accelerator.hpp"
#include "yzlite_tflite_micro_accelerator_recorder.hpp"

namespace py = pybind11;

static yzlite::MvpTfliteMicroAcceleratorWrapper mvp_accelerator;
extern "C" void sli_mvp_set_simulator_backend_enabled(bool);

namespace yzlite {
extern bool mvpv1_calculate_accelerator_cycles_only;
extern "C" const TfliteMicroAccelerator *yzlite_tflite_micro_get_accelerator();
} // namespace yzlite

PYBIND11_MODULE(MODULE_NAME, m) {

  /*************************************************************************************************
   * API version number of the wrapper
   *
   * Any other wrappers that link to this wrapper should check
   * this version to ensure compatibility
   */
  m.def("name", []() -> const char * {
    auto acc = yzlite::yzlite_tflite_micro_get_accelerator();
    return acc->name;
  });

  /*************************************************************************************************
   * API version number of the wrapper
   *
   * Any other wrappers that link to this wrapper should check
   * this version to ensure compatibility
   */
  m.def("api_version", []() -> int { return TFLITE_MICRO_API_VERSION; });

  /*************************************************************************************************
   * GIT hash of the YZLITE repo when the DLL was compiled
   *
   */
  m.def("git_hash", []() -> const char * { return YZLITE_GIT_HASH; });

  /*************************************************************************************************
   * Return the MvpTfliteMicroAcceleratorWrapper
   *
   */
  m.def("get_accelerator_wrapper",
        []() -> void * { return (void *)&mvp_accelerator; });

  /*************************************************************************************************
   * Enable/disabe the simulator backend.
   * This is used internally
   *
   */
  m.def("set_simulator_backend_enabled", [](bool enabled) -> void {
    sli_mvp_set_simulator_backend_enabled(enabled);
  });

  /*************************************************************************************************
   * Enable/disabe only calculating accelerator cycles during simulation
   * This is used internally
   *
   */
  m.def("set_calculate_accelerator_cycles_only_enabled",
        [](bool enabled) -> void {
          yzlite::mvpv1_calculate_accelerator_cycles_only = enabled;
        });

  /*************************************************************************************************
   * Enable recording hardware accelerator instructions
   *
   */
  m.def("enable_program_recorder", []() -> void {
    yzlite::TfliteMicroAcceleratorRecorder::instance()
        .set_program_recording_enabled();
  });

  /*************************************************************************************************
   * Enable recording hardware accelerator data
   *
   */
  m.def("enable_data_recorder", []() -> void {
    yzlite::TfliteMicroAcceleratorRecorder::instance()
        .set_data_recording_enabled();
  });
}