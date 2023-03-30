project(yzlite_tflite_micro_mvp_kernels
  VERSION 1.0.0
  DESCRIPTION "YZTech's ReRAM Engine MVP Tensorflow accelerated kernels"
)
export(PACKAGE ${PROJECT_NAME})
add_library(${PROJECT_NAME})
add_library(yzlite::tflite_micro_mvp_kernels ALIAS ${PROJECT_NAME})

yzlite_info("Including ReRAM Engine MVP Tensorflow accelerated kernels")


# Find the common packages
find_package(yzlite_reram_sdk REQUIRED)
find_package(yzlite_cpputils REQUIRED)
find_package(yzlite_cmsis REQUIRED)

set(tflm_mvp_kernels_includes)
set(tflm_mvp_kernels_sources)
set(tflm_mvp_kernels_libraries)


# Configure the additional libraries to link against
# based on the build platform
yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)

# If we're building for an embedded platform
if(YZLITE_PLATFORM_IS_EMBEDDED)
  find_package(yzlite_cmsis REQUIRED)
  set(tflm_mvp_kernels_libraries yzlite::tflite_micro_cmsis_kernels)
  set(tflm_mvp_kernels_sources 
    mvp_driver/src/sl_mvp.cc 
    mvp_driver/src/sl_mvp_power.cc
  )

# Otherwise we're build for Window/Linux
else()
  yzlite_info("Using MVP simulator")
  yzlite_set(TFLITE_MICRO_SIMULATOR_ENABLED ON)

  # See if the GSDK MVP simulator source code package is 
  # externally available. Ignore the error if not.
  find_package(yzlite_sl_mvp_simulator QUIET)

  # If the MVP simulator was found externally
  # then link to the component
  if(yzlite_sl_mvp_simulator_FOUND)
    set(tflm_mvp_kernels_libraries yzlite::sl_mvp_simulator)
    target_compile_definitions(${PROJECT_NAME}
    PUBLIC
      SL_MVP_SIMULATOR_BUILD_FROM_SOURCE
    )

  # Otherwise we download and link to the pre-built static library
  else()
    execute_process(
      COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/mvp_driver/simulator/download_simulator_lib.py 
      RESULT_VARIABLE result 
      OUTPUT_VARIABLE output
    )
    list(GET output 0 sl_mvp_simulator_lib_dir)
    if(result) 
      if(output)
        list(GET output 1 _error_file_path)
        if(EXISTS "${_error_file_path}")
          file (STRINGS ${_error_file_path} _err_msg)
          string(REPLACE ";" "\n" _err_msg ${_err_msg})
        endif()
      endif()
      message(FATAL_ERROR "${_err_msg}\nFailed to download MVP simulator library, see: ${sl_mvp_simulator_lib_dir}/download.log\n\n")
    endif()

    string(REPLACE " " ";" _flag_list ${CMAKE_CXX_FLAGS})
    if("-fPIC" IN_LIST _flag_list)
      set(sl_mvp_simulator_lib_path "${sl_mvp_simulator_lib_dir}/sl_mvp_simulator.pic.a")
    else()
      set(sl_mvp_simulator_lib_path "${sl_mvp_simulator_lib_dir}/sl_mvp_simulator.a")
    endif()

    yzlite_info("Using pre-built GSDK MVP simulator at ${sl_mvp_simulator_lib_path}")
    find_package(yzlite_float16 REQUIRED)
    set(tflm_mvp_kernels_libraries ${sl_mvp_simulator_lib_path} yzlite::float16)
    list(APPEND tflm_mvp_kernels_includes "${sl_mvp_simulator_lib_dir}")
  endif()

endif()


list(APPEND tflm_mvp_kernels_sources
mvp_driver/src/sl_mvp_math.cc
mvp_driver/src/sl_mvp_util.cc
mvp_driver/src/sl_mvp_program_area.cc
mvp_driver/src/sl_mvp_ml_add.cc
mvp_driver/src/sl_mvp_ml_conv2d.cc
mvp_driver/src/sl_mvp_ml_fully_connected.cc
mvp_driver/src/sl_mvp_ml_pooling.cc
mvp_driver/src/sl_mvp_ml_depthwise_conv2d.cc 
mvp_driver/src/sl_mvp_ml_transpose_conv2d.cc 
mvp_driver/src/sli_mvp_ml_depthwise_conv2d.cc
mvp_driver/src/sli_mvp_ml_depthwise_conv2d_opt.cc
kernels/add.cc
kernels/conv.cc 
kernels/fully_connected.cc 
kernels/pooling.cc
kernels/depthwise_conv.cc
kernels/transpose_conv.cc
)
yzlite_append(TFLITE_MICRO_EXCLUDED_REF_KERNELS
  add
  conv 
  depthwise_conv
  fully_connected
  pooling
  transpose_conv
)


# Specify the MVP accelerator
# before we find the tflite micro component.
# This will cause tflite micro to use the MVP kernels
# NOTE: We must find the tflite micro component AFTER
#       we specify the TFLITE_MICRO_EXCLUDED_REF_KERNELS variable
yzlite_set(TFLITE_MICRO_ACCELERATOR mvp)
find_package(yzlite_tflite_micro REQUIRED)


target_sources(${PROJECT_NAME}
PRIVATE 
  tflite_micro_mvp_accelerator.cc
  ${tflm_mvp_kernels_sources}
)

target_include_directories(${PROJECT_NAME}
PUBLIC 
  mvp_driver/inc
  ${tflm_mvp_kernels_includes}
)

target_link_libraries(${PROJECT_NAME} 
PUBLIC 
  yzlite::tflite_micro
  yzlite::reram_sdk::includes
  yzlite::cmsis_nn
  ${tflm_mvp_kernels_libraries}
PRIVATE
  yzlite::cpputils
)
