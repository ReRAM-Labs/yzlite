#pragma once
#include "em_device.h"

#define YZLITE_ADD_FAULT_HANDLER()                                             \
  {                                                                            \
    __ASM volatile("MRS R0, MSP");                                             \
    __ASM volatile("MRS R1, PSP");                                             \
    __ASM volatile("MOV R2, LR");                                              \
    __ASM volatile("B yzlite_fault_handler");                                  \
  }

extern void __NO_RETURN yzlite_fault_handler(uint32_t MSP, uint32_t PSP,
                                             uint32_t LR);
