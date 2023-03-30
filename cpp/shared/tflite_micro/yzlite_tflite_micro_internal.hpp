
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/micro_allocator.h"
#include "tensorflow/lite/schema/schema_generated.h"

#include "logging/logger.hpp"
#include "profiling/profiler.hpp"

#include "yzlite_tflite_micro_helper.hpp"
#include "yzlite_tflite_micro_recorder.hpp"

#define SET_CURRENT_KERNEL(op_idx, op_code)                                    \
  yzlite::_current_kernel_index = op_idx;                                      \
  yzlite::_current_kernel_op_code = op_code;                                   \
  yzlite::_issued_unsupported_msg = false;
#define CLEAR_CURRENT_KERNEL()                                                 \
  yzlite::_current_kernel_index = -1;                                          \
  yzlite::_current_kernel_op_code = -1;

#ifdef TFLITE_MICRO_PROFILER_ENABLED

#define ALLOCATE_PROFILERS(subgraph_idx, operators_size)                       \
  FREE_PROFILERS();                                                            \
  yzlite::allocate_profilers(subgraph_idx, operators_size);

#define REGISTER_PROFILER(subgraph_idx, op_idx, op_type, context,              \
                          node_and_registration)                               \
  yzlite::register_profiler(subgraph_idx, op_idx,                              \
                            (tflite::BuiltinOperator)op_type, context,         \
                            node_and_registration);                            \
  allocator_->ResetTempAllocations();

#define FREE_PROFILERS() yzlite::free_profilers();

#define START_INFERENCE_PROFILER(subgraph_idx)                                 \
  if (subgraph_idx == 0) {                                                     \
    if (yzlite::_inference_profiler != nullptr)                                \
      yzlite::_inference_profiler->start();                                    \
    if (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)   \
      yzlite::yzlite_tflite_micro_get_registered_accelerator()                 \
          ->start_profiler(-1);                                                \
  }

#define STOP_INFERENCE_PROFILER(subgraph_idx)                                  \
  if (subgraph_idx == 0) {                                                     \
    if (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)   \
      yzlite::yzlite_tflite_micro_get_registered_accelerator()->stop_profiler( \
          -1);                                                                 \
    if (yzlite::_inference_profiler != nullptr)                                \
      yzlite::_inference_profiler->stop();                                     \
  }

#define START_OP_PROFILER(subgraph_idx, op_idx, op_code)                       \
  SET_CURRENT_KERNEL(op_idx, op_code)                                          \
  if (subgraph_idx == 0) {                                                     \
    if (yzlite::_kernel_profilers != nullptr)                                  \
      yzlite::_kernel_profilers[op_idx]->start();                              \
    if (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)   \
      yzlite::yzlite_tflite_micro_get_registered_accelerator()                 \
          ->start_op_profiler(op_idx, (yzlite::_kernel_profilers != nullptr)   \
                                          ? yzlite::_kernel_profilers[op_idx]  \
                                          : nullptr);                          \
  }

#define STOP_OP_PROFILER(subgraph_idx, op_idx)                                 \
  CLEAR_CURRENT_KERNEL()                                                       \
  if (subgraph_idx == 0) {                                                     \
    if (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)   \
      yzlite::yzlite_tflite_micro_get_registered_accelerator()                 \
          ->stop_op_profiler(op_idx, (yzlite::_kernel_profilers != nullptr)    \
                                         ? yzlite::_kernel_profilers[op_idx]   \
                                         : nullptr);                           \
    if (yzlite::_kernel_profilers != nullptr)                                  \
      yzlite::_kernel_profilers[op_idx]->stop();                               \
  }

#else // TFLITE_MICRO_PROFILER_ENABLED

#define ALLOCATE_PROFILERS(...)
#define REGISTER_PROFILER(...)
#define FREE_PROFILERS(...)
#define START_INFERENCE_PROFILER(...)
#define STOP_INFERENCE_PROFILER(...)
#define START_OP_PROFILER(subgraph_idx, op_idx, op_code)                       \
  SET_CURRENT_KERNEL(op_idx, op_code)
#define STOP_OP_PROFILER(subgraph_idx, op_idx) CLEAR_CURRENT_KERNEL()

#endif // TFLITE_MICRO_PROFILER_ENABLED

#ifdef TFLITE_MICRO_ACCELERATOR_PROFILER_ENABLED

#undef START_INFERENCE_PROFILER
#undef STOP_INFERENCE_PROFILER

#define START_INFERENCE_PROFILER(subgraph_idx)                                 \
  const int _accelerator_loop_count =                                          \
      (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)    \
          ? yzlite::yzlite_tflite_micro_get_registered_accelerator()           \
                ->get_profiler_loop_count()                                    \
          : 1;                                                                 \
  for (int _accelerator_loop = 0; _accelerator_loop < _accelerator_loop_count; \
       ++_accelerator_loop) {                                                  \
    if (_accelerator_loop == 0)                                                \
      if (yzlite::_inference_profiler != nullptr)                              \
        yzlite::_inference_profiler->start();                                  \
    if (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)   \
      yzlite::yzlite_tflite_micro_get_registered_accelerator()                 \
          ->start_profiler(_accelerator_loop);

#define STOP_INFERENCE_PROFILER(subgraph_idx)                                  \
  if (yzlite::yzlite_tflite_micro_get_registered_accelerator() != nullptr)     \
    yzlite::yzlite_tflite_micro_get_registered_accelerator()->stop_profiler(   \
        _accelerator_loop);                                                    \
  if (_accelerator_loop == 0)                                                  \
    if (yzlite::_inference_profiler != nullptr)                                \
      yzlite::_inference_profiler->stop();                                     \
  }

#endif // TFLITE_MICRO_ACCELERATOR_PROFILER_ENABLED

#define INVOKE_PROCESSING_CALLBACK()                                           \
  if (yzlite::_processing_callback != nullptr)                                 \
  yzlite::_processing_callback(yzlite::_processing_callback_arg)

namespace yzlite {

extern profiling::Profiler *_inference_profiler;
extern profiling::Profiler **_kernel_profilers;
extern int _current_kernel_index;
extern int _current_kernel_op_code;
extern bool _issued_unsupported_msg;
extern void (*_processing_callback)(void *);
extern void *_processing_callback_arg;

void allocate_profilers(int subgraph_index, int op_count);

void register_profiler(
    int subgraph_idx, int op_idx, tflite::BuiltinOperator op_type,
    const TfLiteContext *context,
    const tflite::NodeAndRegistration &node_and_registration);

void free_profilers();

bool calculate_op_metrics(
    const TfLiteContext *context,
    const tflite::NodeAndRegistration &node_and_registration,
    profiling::Metrics &metrics);

const char *to_str(tflite::BuiltinOperator op_type);
const char *op_to_str(int op_idx, tflite::BuiltinOperator op_type);

} // namespace yzlite