


###########################################################################
# CMSIS-Accelerated Kernels
#
yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(YZLITE_PLATFORM_IS_EMBEDDED)

find_package(yzlite_cmsis REQUIRED)
add_library(yzlite_tflite_micro_cmsis_kernels)
add_library(yzlite_tflite_micro_helium_kernels ALIAS yzlite_tflite_micro_cmsis_kernels)
add_library(yzlite::tflite_micro_cmsis_kernels ALIAS yzlite_tflite_micro_cmsis_kernels)

set(tflm_cmsis_kernel_sources
  tensorflow/lite/micro/kernels/cmsis_nn/add.cc
  tensorflow/lite/micro/kernels/cmsis_nn/conv.cc
  tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.cc
  tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.cc
  tensorflow/lite/micro/kernels/cmsis_nn/mul.cc
  tensorflow/lite/micro/kernels/cmsis_nn/pooling.cc
  tensorflow/lite/micro/kernels/cmsis_nn/softmax.cc
  tensorflow/lite/micro/kernels/cmsis_nn/svdf.cc
)

# If an accelerator was previously included
# then exclude the CMSIS kernels that are accelerated
yzlite_get(TFLITE_MICRO_EXCLUDED_REF_KERNELS)
if(TFLITE_MICRO_EXCLUDED_REF_KERNELS)
  yzlite_info("Excluded CMSIS kernels: ${TFLITE_MICRO_EXCLUDED_REF_KERNELS}" TAG yzlite_tflite_micro_cmsis_kernels)
  foreach(pat ${TFLITE_MICRO_EXCLUDED_REF_KERNELS})
    list(FILTER tflm_cmsis_kernel_sources EXCLUDE REGEX ".*/${pat}\.cc")
  endforeach()
endif()

yzlite_append(TFLITE_MICRO_EXCLUDED_REF_KERNELS
    add
    conv
    depthwise_conv
    fully_connected
    mul
    pooling
    softmax
    svdf
)
list(TRANSFORM tflm_cmsis_kernel_sources PREPEND ${Tensorflow_SOURCE_BASE_DIR}/)
target_sources(yzlite_tflite_micro_cmsis_kernels
PRIVATE
  ${tflm_cmsis_kernel_sources}
  kernels/cmsis_kernels_helper.cc
)

target_link_libraries(yzlite_tflite_micro_cmsis_kernels
PRIVATE
  yzlite::cmsis_nn
  yzlite::tflite_micro
)

endif() # YZLITE_PLATFORM_IS_EMBEDDED


