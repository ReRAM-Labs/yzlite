#pragma once
#include <cassert>
#include <complex>
#include <cstdio>
#include <functional>

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/core/api/error_reporter.h"
#include "tensorflow/lite/kernels/internal/types.h"
#include "tensorflow/lite/kernels/op_macros.h"
#include "tensorflow/lite/micro/compatibility.h"

#include "cpputils/helpers.hpp"
#include "float16.hpp"
#include "logging/logger.hpp"
#include "profiling/profiler.hpp"

#ifndef YZLITE_LOG_LEVEL
#define YZLITE_LOG_LEVEL 0
#endif

#if YZLITE_LOG_LEVEL <= 0
#define YZLITE_DEBUG(msg, ...) ::yzlite::get_logger().debug(msg, ##__VA_ARGS__)
#endif
#if YZLITE_LOG_LEVEL <= 1
#define YZLITE_INFO(msg, ...) ::yzlite::get_logger().info(msg, ##__VA_ARGS__)
#endif
#if YZLITE_LOG_LEVEL <= 2
#define YZLITE_WARN(msg, ...) ::yzlite::get_logger().warn(msg, ##__VA_ARGS__)
#endif
#if YZLITE_LOG_LEVEL <= 3
#define YZLITE_ERROR(msg, ...) ::yzlite::get_logger().error(msg, ##__VA_ARGS__)
#endif

#ifndef YZLITE_DEBUG
#define YZLITE_DEBUG(...)
#endif
#ifndef YZLITE_INFO
#define YZLITE_INFO(...)
#endif
#ifndef YZLITE_WARN
#define YZLITE_WARN(...)
#endif
#ifndef YZLITE_ERROR
#define YZLITE_ERROR(...)
#endif

#define ALLOCATE_PERSISTENT_BUFFER(type, count)                                \
  ::yzlite::allocate_persistent_buffer<type>(context, count)
#define ALLOCATE_SCRATCH_BUFFER(size_bytes, scratch_buffer_index)              \
  {                                                                            \
    const auto status = ::yzlite::allocate_scratch_buffer(                     \
        context, size_bytes, scratch_buffer_index);                            \
    if (status != kTfLiteOk)                                                   \
      return status;                                                           \
  }
#define GET_SCRATCH_BUFFER(type, scratch_buffer_index)                         \
  ::yzlite::get_scratch_buffer<type>(context, scratch_buffer_index)
#define ENSURE_POINTER_STATUS(ptr)                                             \
  if (ptr == nullptr) {                                                        \
    assert(ptr != nullptr);                                                    \
    return kTfLiteError;                                                       \
  }
#define YZLITE_KERNEL_UNSUPPORTED_MSG(fmt, ...)                                \
  ::yzlite::issue_unsupported_kernel_message(fmt, ##__VA_ARGS__);

namespace yzlite {

using Logger = logging::Logger;
using LogLevel = logging::Level;

typedef std::complex<float> cfloat_t;
typedef std::complex<float16_t> cfloat16_t;

struct TfliteMicroAccelerator {
  const char *name;
  void (*init)();
  void (*deinit)();
  int (*get_profiler_loop_count)();
  void (*start_profiler)(int loop_count);
  void (*stop_profiler)(int loop_count);
  void (*start_op_profiler)(int op_idx, profiling::Profiler *profiler);
  void (*stop_op_profiler)(int op_idx, profiling::Profiler *profiler);
  bool (*set_simulator_memory)(const char *region, void *base_address,
                               uint32_t length);
  bool (*invoke_simulator)(const std::function<bool()> &func);
};

extern bool model_profiler_enabled;
extern bool model_tensor_recorder_enabled;
extern bool model_error_reporter_enabled;
extern bool model_has_unsupported_layers;
extern const char *TFLITE_MICRO_VERSION;

extern "C" DLL_EXPORT void issue_unsupported_kernel_message(const char *fmt,
                                                            ...);
extern "C" DLL_EXPORT void
yzlite_tflite_micro_set_accelerator(const TfliteMicroAccelerator *accelerator);
extern "C" DLL_EXPORT const TfliteMicroAccelerator *
yzlite_tflite_micro_get_registered_accelerator();
extern "C" DLL_EXPORT void
yzlite_tflite_micro_get_current_layer_opcode_and_index(int *opcode, int *index);
extern "C" void yzlite_tflite_micro_register_accelerator();

Logger &get_logger();
bool set_log_level(LogLevel level);
TfLiteStatus allocate_scratch_buffer(TfLiteContext *ctx, unsigned size_bytes,
                                     int *scratch_buffer_index);
const void *get_metadata_from_tflite_flatbuffer(const void *tflite_flatbuffer,
                                                const char *tag,
                                                uint32_t *length = nullptr);
bool get_tflite_flatbuffer_from_end_of_flash(
    const uint8_t **tflite_flatbuffer, uint32_t *length = nullptr,
    const uint32_t *flash_end_addr = nullptr);

/*************************************************************************************************/
template <typename T>
T *allocate_persistent_buffer(TfLiteContext *ctx, unsigned count) {
  return reinterpret_cast<T *>(
      ctx->AllocatePersistentBuffer(ctx, sizeof(T) * count));
}

/*************************************************************************************************/
template <typename T>
T *get_scratch_buffer(TfLiteContext *ctx, int scratch_buffer_index) {
  return reinterpret_cast<T *>(
      ctx->GetScratchBuffer(ctx, scratch_buffer_index));
}

/*************************************************************************************************/
inline tflite::PaddingType runtime_padding_type(TfLitePadding padding) {
  switch (padding) {
  case TfLitePadding::kTfLitePaddingSame:
    return tflite::PaddingType::kSame;
  case TfLitePadding::kTfLitePaddingValid:
    return tflite::PaddingType::kValid;
  case TfLitePadding::kTfLitePaddingUnknown:
  default:
    return tflite::PaddingType::kNone;
  }
}

/*************************************************************************************************/
inline int div_round_up(const int numerator, const int denominator) {
  return (numerator + denominator - 1) / denominator;
}

/*************************************************************************************************/
inline int div_ceil(const int numerator, const int denominator,
                    int lower_limit = std::numeric_limits<int>::min()) {
  assert(denominator > 0);
  const std::div_t div = std::div(numerator, denominator);

  const int ceil = div.quot + (div.rem ? 1 : 0); // ceil

  return std::max(ceil, lower_limit);
}

/*************************************************************************************************/
inline int div_floor(const int numerator, const int denominator,
                     int upper_limit = std::numeric_limits<int>::max()) {
  assert(denominator > 0);
  const std::div_t div = std::div(numerator, denominator);

  const int floor = div.quot; // floor

  return std::min(floor, upper_limit);
}

bool verify_model_flatbuffer(const void *flatbuffer, int flatbuffer_length);

} // namespace yzlite
