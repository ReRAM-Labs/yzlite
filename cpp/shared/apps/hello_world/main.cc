#include "sl_system_init.h"
#include <cstdio>

extern "C" int main(void) {
  sl_system_init();

  printf("Hello world!!\n");
  fflush(stdout);
  return 0;
}
