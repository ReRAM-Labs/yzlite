#include "tensorflow/lite/micro/debug_log.h"
#include "sl_iostream.h"
#include <string.h>

extern "C" void DebugLog(const char *s) {
  sl_iostream_write(sl_iostream_get_default(), s, strlen(s));
}
