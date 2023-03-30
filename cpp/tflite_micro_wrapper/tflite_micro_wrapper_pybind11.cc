
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "cpputils/heap.hpp"
#include "logging/logger.hpp"
#include "stacktrace/stacktrace.h"
#include "yzlite_tflite_micro_helper.hpp"

namespace py = pybind11;

extern void init_tflite_micro_model(py::module &);

PYBIND11_MODULE(MODULE_NAME, m) {
  init_tflite_micro_model(m);

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
   * Set YZLITE logging level: debug, info, warn, error
   */
  m.def("set_log_level", [](const char *level) -> bool {
    auto &logger = yzlite::get_logger();
    if (!logger.level(level)) {
      return false;
    }

    return true;
  });
  /*************************************************************************************************
   * Return YZLITE logging level as a string
   */
  m.def("get_log_level", []() {
    const auto &logger = yzlite::get_logger();
    return logger.level_str();
  });

  /*************************************************************************************************
   * Set yzlite logger with callback
   * This allows for sending the YZLITE logs to a python logger
   */
  m.def("set_logger_callback",
        [](const std::function<void(const char *)> &callback) {
          auto &logger = yzlite::get_logger();
          logger.flags(logging::PrintLevel);
          logger.writer([callback](const char *msg, int length, void *arg) {
            callback(msg);
          });
        });

  /*************************************************************************************************
   * Initialize the wrapper
   */
  m.def("init", []() {
    // This allows for printing stack dumps on a segfault
    stacktrace_init();
    yzlite::get_logger().debug("TF-Lite Micro wrapper initialized");
  });
}

// This doesn't do anything other than work around a build error on Windows
extern "C" int main(int, char **) { return -1; }