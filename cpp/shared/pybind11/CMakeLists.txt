project(yzlite_pybind11
        VERSION 1.0.0
        DESCRIPTION "YZLITE Pybind11"
)
export(PACKAGE ${PROJECT_NAME})

yzlite_load_python()


# Let pybind re-find python
# The cached variable: PYTHON_EXECUTABLE
# should already be defined so pybind11 should just use that
set(Python_FOUND OFF)
set(Python3_FOUND OFF)
set(Python3_FOUND OFF)


CPMAddPackage(
    NAME pybind11
    GITHUB_REPOSITORY pybind/pybind11
    GIT_TAG v2.6.2
    CACHE_VERSION v2.6.2
    OPTIONS 
        "MSVC OFF"
)


add_library(yzlite_pybind11_helper INTERFACE)
add_library(yzlite::pybind11_helper ALIAS yzlite_pybind11_helper)

target_sources(yzlite_pybind11_helper
INTERFACE
  pybind11_helper.hpp
)
target_include_directories(yzlite_pybind11_helper
INTERFACE
  .
  ${PYTHON_INCLUDE_DIRS}
)

target_link_libraries(yzlite_pybind11_helper
INTERFACE 
  pybind11_headers
  ${PYTHON_LIBRARIES}
  yzlite_tflite_micro # NOTE: These must be manually included into the build
  yzlite_tflite_micro_model
)
