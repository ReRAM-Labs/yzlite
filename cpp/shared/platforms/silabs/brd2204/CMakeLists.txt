project(yzlite_platform_brd2204
        VERSION 1.0.0
        DESCRIPTION "YZTech's BRD2204 Dev board Platform"
)
export (PACKAGE ${PROJECT_NAME})
add_library(${PROJECT_NAME})


#############################################
# YZLITE Settings
yzlite_set(YZLITE_PLATFORM_NAME brd2204)
yzlite_set(YZLITE_PLATFORM_IS_EMBEDDED ON)

#############################################
# CMSIS Settings
yzlite_set(CMSIS_CORE cortex-m4)
yzlite_set(CMSIS_FPU OFF) # Disable the FPU so we can build in the NVM3 lib, the compiler will still generate FPU instructions when possible

#############################################
# ReRAM Engine Settings
yzlite_set(GECKO_SDK_BOARD_SERIES 1)
yzlite_set(GECKO_SDK_BOARD_TARGET ${PROJECT_NAME})
yzlite_set(GECKO_SDK_INCLUDE_EMLIB ON)
yzlite_set(GECKO_SDK_INCLUDE_IOSTREAM_SERVICE ON)

yzlite_set(SILABS_PART_NUMBER EFM32GG11B820F2048GL192)

# Default clock rate is 72MHz
yzlite_set(YZLITE_CPU_CLOCK 72000000 DEFAULT)
# Default stack size
yzlite_set(YZLITE_STACK_SIZE 5120 DEFAULT)



target_include_directories(${PROJECT_NAME}
PUBLIC
    config
    autogen
)

target_sources(${PROJECT_NAME}
PRIVATE
    start.c
)

add_library(${PROJECT_NAME}_autogen)
target_sources(${PROJECT_NAME}_autogen
PRIVATE
    autogen/sl_board_default_init.c
    autogen/sl_device_init_clocks.c
    autogen/sl_event_handler.c
    autogen/sl_iostream_handles.c
    autogen/sl_iostream_init_usart_instances.c
    autogen/sl_power_manager_handler.c
    autogen/sl_simple_led_instances.c
    autogen/sl_simple_button_instances.c
)
target_link_libraries(${PROJECT_NAME}_autogen
PRIVATE
    ${PROJECT_NAME}
    yzlite::reram_sdk::iostream_service
    yzlite::reram_sdk::device_init_service
    yzlite::reram_sdk::system_service
    yzlite::reram_sdk::power_manager_service
    yzlite::reram_sdk::hfxo_manager_service
    yzlite::reram_sdk::sleeptimer_service
    yzlite::reram_sdk::udelay_service
    yzlite::reram_sdk::ledrv
    yzlite::reram_sdk::button
    yzlite::reram_sdk::nvm3
    yzlite::reram_sdk::mic
    yzlite::reram_sdk::includes
)
target_compile_options(${PROJECT_NAME}_autogen
PRIVATE
    -Wno-implicit-function-declaration
)

set(GECKO_SDK_IO_STREAM_SERVICE_SOURCES
    sl_iostream_retarget_stdio.c
    sl_iostream_uart.c
    sl_iostream_usart.c
    sl_iostream_stdlib_config.c
)
yzlite_set(GECKO_SDK_IO_STREAM_SERVICE_SOURCES "${GECKO_SDK_IO_STREAM_SERVICE_SOURCES}")


target_link_libraries(${PROJECT_NAME}
PRIVATE
    yzlite::cpputils
    yzlite_platform_yizhu_simple_bootloader

PUBLIC
    yzlite::reram_sdk::clib_wrappers
    yzlite::platform::common
    yzlite::platform::yizhu_common
    yzlite::platform::fault_handler
    yzlite::cmsis
    ${PROJECT_NAME}_api
    yzlite::reram_sdk::iostream_service
    yzlite::reram_sdk::device_init_service
    yzlite::reram_sdk::system_service
    yzlite::reram_sdk::power_manager_service
    yzlite::reram_sdk::sleeptimer_service
    yzlite::reram_sdk::dmadrv
    yzlite::reram_sdk::ledrv
    yzlite::reram_sdk::nvm3
    yzlite::reram_sdk::button
    yzlite::reram_sdk::gpiointerrupt
    yzlite::reram_sdk::emlib
    yzlite::reram_sdk::platform_common
    yzlite::reram_sdk::platform_peripheral
    yzlite::reram_sdk::hardware_board
    yzlite::reram_sdk::device_efm32gg11b
    yzlite::reram_sdk::udelay_service
    yzlite::jlink_stream
)

set(LINKER_SCRIPT_PATH "${CMAKE_CURRENT_LIST_DIR}/autogen/linkerfile.ld" CACHE INTERNAL "")
target_link_options(${PROJECT_NAME}
PUBLIC
    -nostartfiles
    -Wl,-T${LINKER_SCRIPT_PATH}
    -Wl,-u_printf_float # Enable %f in printf()
    -Wl,-u_start
)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT_PATH})

target_compile_definitions(${PROJECT_NAME}
PUBLIC
    YZLITE_CPU_CLOCK=${YZLITE_CPU_CLOCK}
PRIVATE
    YZLITE_STACK_SIZE=${YZLITE_STACK_SIZE}
)

#############################################
# Create the YZLITE platform_api library
add_library(${PROJECT_NAME}_api STATIC)
target_sources(${PROJECT_NAME}_api
PRIVATE
    hardfault_handler.c
)
target_link_options(${PROJECT_NAME}_api
INTERFACE
    -Wl,--whole-archive ${CMAKE_CURRENT_BINARY_DIR}/lib${PROJECT_NAME}_api.a -Wl,--no-whole-archive
)

target_link_libraries(${PROJECT_NAME}_api
PRIVATE
    ${PROJECT_NAME}
)



###########################################################
# yzlite_platform_add_exe_targets
#
# Adds a target to download the application binary to the embedded device
#
macro(yzlite_platform_add_exe_targets exe_target)
  yzlite_commander_add_download_target(${exe_target})
  yzlite_commander_add_reset_target(${exe_target})
  yzlite_commander_add_download_run_target(${exe_target} ${ARGN})
endmacro()



#############################################
# Find necessary packages
find_package(yzlite_platform_common REQUIRED)
find_package(yzlite_platform_yizhu_common REQUIRED)
find_package(yzlite_cmsis REQUIRED)
find_package(yzlite_cpputils REQUIRED)
find_package(yzlite_commander REQUIRED)
find_package(yzlite_reram_sdk REQUIRED)
find_package(yzlite_jlink_stream REQUIRED)



