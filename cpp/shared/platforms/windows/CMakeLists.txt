project(yzlite_platform_windows
        VERSION 1.0.0
        DESCRIPTION "YZLITE Windows Platform"
)
export (PACKAGE ${PROJECT_NAME})
add_library(${PROJECT_NAME} INTERFACE)
add_library(yzlite::platform::windows ALIAS ${PROJECT_NAME})

yzlite_set(YZLITE_PLATFORM_NAME windows)
yzlite_set(YZLITE_PLATFORM_IS_EMBEDDED OFF)
# Default simulated clock rate is 80MHz
yzlite_set(YZLITE_CPU_CLOCK 80000000 DEFAULT)

# Just force these ReRAM Engine values
yzlite_set(GECKO_SDK_BOARD_TARGET ${YZLITE_PLATFORM})
yzlite_set(GECKO_SDK_BOARD_SERIES 2)



find_package(yzlite_platform_common REQUIRED)
find_package(yzlite_stacktrace REQUIRED)
find_package(yzlite_cpputils REQUIRED)
find_package(yzlite_reram_sdk_emulation REQUIRED)

add_library(platform_windows_clib_override STATIC)
target_compile_features(platform_windows_clib_override  PUBLIC cxx_constexpr cxx_std_17)
target_sources(platform_windows_clib_override
PRIVATE
    start.cc
    clib_override.c
    sl_sleeptimer_windows.c
    microsecond_timer.c
    sl_system_init.c
)
target_compile_options(platform_windows_clib_override
PUBLIC
    -I $(CMAKE_CURRENT_LIST_DIR)
)
target_compile_definitions(platform_windows_clib_override
PRIVATE
    YZLITE_CPU_CLOCK=${YZLITE_CPU_CLOCK}
)
target_link_options(platform_windows_clib_override
PUBLIC
    -Wl,--wrap,main
    -Wl,--wrap,_assert_func
    -Wl,--wrap,_assert
    -Wl,--wrap,abort
    -Wl,--wrap,_wassert
    -Wl,--whole-archive ${CMAKE_CURRENT_BINARY_DIR}/libplatform_windows_clib_override.a -Wl,--no-whole-archive
)
target_link_libraries(platform_windows_clib_override
PUBLIC
    yzlite::platform::common
    yzlite::stacktrace
    yzlite::cpputils
    yzlite::reram_sdk::emulation
)




target_include_directories(${PROJECT_NAME}
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
INTERFACE
    yzlite::platform::common
    platform_windows_clib_override
    yzlite::reram_sdk::emulation
)

target_compile_definitions(${PROJECT_NAME}
INTERFACE
    __PROGRAM_START=_dummy # This is required to work-aroud build errors in cmsis_gcc.h
)
