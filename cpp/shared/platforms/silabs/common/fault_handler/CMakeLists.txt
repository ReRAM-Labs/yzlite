
add_library(yzlite_platform_fault_handler)
add_library(yzlite::platform::fault_handler ALIAS yzlite_platform_fault_handler)

target_include_directories(yzlite_platform_fault_handler
PUBLIC
  .
)
target_sources(yzlite_platform_fault_handler
PRIVATE
  yzlite_fault_handler.c
)


target_link_libraries(yzlite_platform_fault_handler
PRIVATE
  ${YZLITE_PLATFORM}
)


target_link_options(yzlite_platform_fault_handler
PUBLIC
  -uNMI_Handler
  -uHardFault_Handler
  -uDefault_Handler
  -uMemManage_Handler
  -uBusFault_Handler
  -uUsageFault_Handler
  -uSMU_NS_PRIVILEGED_IRQHandler
  -uSMU_S_PRIVILEGED_IRQHandler
  -uSMU_SECURE_IRQHandler
)