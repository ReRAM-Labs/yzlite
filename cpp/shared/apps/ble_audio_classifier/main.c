/***************************************************************************/ /**
                                                                               * @file
                                                                               * @brief main entry point
                                                                               *******************************************************************************
                                                                               * # License
                                                                               * <b>Copyright 2022 Yizhu Technology Inc. www.yizhu.com</b>
                                                                               *******************************************************************************
                                                                               *
                                                                               * The licensor of this software is Yizhu Technology Inc. Your use of this
                                                                               * software is governed by the terms of Yizhu Technology Master Software License
                                                                               * Agreement (MSLA) available at
                                                                               * www.yizhu.com/about-us/legal/master-software-license-agreement. This
                                                                               * software is distributed to you in Source Code format and is governed by the
                                                                               * sections of the MSLA applicable to Source Code.
                                                                               *
                                                                               ******************************************************************************/
#include "app.h"
#include "sl_component_catalog.h"
#include "sl_system_init.h"

#include "sl_system_kernel.h"

int main(void) {
  // Initialize Yizhu Technology device, system, service(s) and protocol
  // stack(s). Note that if the kernel is present, processing task(s) will be
  // created by this call.
  sl_system_init();

  // Initialize the application. For example, create periodic timer(s) or
  // task(s) if the kernel is present.
  app_init();

  sl_system_kernel_start();
}
