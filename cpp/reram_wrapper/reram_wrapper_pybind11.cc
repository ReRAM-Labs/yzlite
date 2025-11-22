


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "reram_tflite_micro_accelerator.hpp"
#include "reram_simulator.hpp"
#include "yzlite_tflite_micro_accelerator_recorder.hpp"

namespace py = pybind11;

static yzlite::ReRAMTfliteMicroAcceleratorWrapper reram_accelerator;

// ReRAM simulator global state
namespace reram_sim {
static bool simulator_enabled = true;
static bool non_ideal_effects_enabled = true;
static int crossbar_rows = 256;
static int crossbar_cols = 256;
static int resistance_levels = 8;
static int adc_resolution = 4;

// ReRAM simulator instance
static yzlite::reram::ReRAMCrossbar *crossbar = nullptr;
static yzlite::reram::ADCModel *adc = nullptr;
static yzlite::reram::Statistics stats;

void initialize() {
  if (crossbar == nullptr) {
    crossbar = new yzlite::reram::ReRAMCrossbar(crossbar_rows, crossbar_cols,
                                                 resistance_levels);
    adc = new yzlite::reram::ADCModel(adc_resolution);
  }
}

void cleanup() {
  if (crossbar != nullptr) {
    delete crossbar;
    crossbar = nullptr;
  }
  if (adc != nullptr) {
    delete adc;
    adc = nullptr;
  }
}

void reconfigure() {
  cleanup();
  initialize();
}

} // namespace reram_sim

namespace yzlite {
extern "C" const TfliteMicroAccelerator *yzlite_tflite_micro_get_accelerator();
} // namespace yzlite

PYBIND11_MODULE(MODULE_NAME, m) {
  m.doc() = "ReRAM Accelerator Python Wrapper for YZLITE TensorFlow Lite Micro";
  
  // Initialize ReRAM simulator on module load
  reram_sim::initialize();

  /*************************************************************************************************
   * Return the accelerator name
   *
   */
  m.def("name", []() -> const char * {
    return "ReRAM";
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
   * Return the ReRAMTfliteMicroAcceleratorWrapper
   *
   */
  m.def("get_accelerator_wrapper",
        []() -> void * { return (void *)&reram_accelerator; });

  /*************************************************************************************************
   * Enable/disable the simulator backend
   * This controls whether ReRAM simulation is enabled
   *
   */
  m.def("set_simulator_backend_enabled", [](bool enabled) -> void {
    reram_sim::simulator_enabled = enabled;
    yzlite::get_logger().debug("ReRAM simulator %s", 
                               enabled ? "enabled" : "disabled");
  });

  /*************************************************************************************************
   * Configure ReRAM crossbar dimensions
   *
   */
  m.def("configure_crossbar", [](int rows, int cols, int levels) -> void {
    reram_sim::crossbar_rows = rows;
    reram_sim::crossbar_cols = cols;
    reram_sim::resistance_levels = levels;
    reram_sim::reconfigure(); // Recreate crossbar with new dimensions
    yzlite::get_logger().debug("Configured ReRAM crossbar: %dx%d with %d levels", 
                               rows, cols, levels);
    reram_sim::stats.addWriteOp(); // Track configuration as write operation
  });

  /*************************************************************************************************
   * Set ADC resolution for ReRAM readout
   *
   */
  m.def("set_adc_resolution", [](int bits) -> void {
    reram_sim::adc_resolution = bits;
    if (reram_sim::adc != nullptr) {
      delete reram_sim::adc;
      reram_sim::adc = new yzlite::reram::ADCModel(bits);
    }
    yzlite::get_logger().debug("Set ReRAM ADC resolution to %d bits", bits);
  });

  /*************************************************************************************************
   * Enable/disable non-ideal effects simulation
   *
   */
  m.def("set_non_ideal_effects_enabled", [](bool enabled) -> void {
    reram_sim::non_ideal_effects_enabled = enabled;
    yzlite::get_logger().debug("Non-ideal effects %s", 
                               enabled ? "enabled" : "disabled");
  });

  /*************************************************************************************************
   * Inject faults into ReRAM crossbar
   *
   */
  m.def("inject_faults", [](float fault_rate) -> int {
    reram_sim::initialize();
    int num_faults = reram_sim::crossbar->injectStuckAtFaults(fault_rate);
    yzlite::get_logger().debug("Injected %d faults (%.2f%%)", 
                               num_faults, fault_rate * 100);
    return num_faults;
  });

  /*************************************************************************************************
   * Get ReRAM statistics (energy, latency, etc.)
   *
   */
  m.def("get_statistics", []() -> py::dict {
    py::dict stats_dict;
    stats_dict["energy_uj"] = reram_sim::stats.energy_uj;
    stats_dict["latency_us"] = reram_sim::stats.latency_us;
    stats_dict["write_ops"] = reram_sim::stats.write_ops;
    stats_dict["read_ops"] = reram_sim::stats.read_ops;
    stats_dict["cell_utilization"] = reram_sim::stats.cell_utilization;
    stats_dict["crossbar_rows"] = reram_sim::crossbar_rows;
    stats_dict["crossbar_cols"] = reram_sim::crossbar_cols;
    stats_dict["adc_resolution"] = reram_sim::adc_resolution;
    stats_dict["injected_faults"] = reram_sim::injected_faults;
    return stats_dict;
  });

  /*************************************************************************************************
   * Reset ReRAM simulator state
   *
   */
  m.def("reset_simulator", []() -> void {
    reram_sim::stats.reset();
    reram_sim::reconfigure(); // Recreate fresh crossbar
    yzlite::get_logger().debug("Reset ReRAM simulator");
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

