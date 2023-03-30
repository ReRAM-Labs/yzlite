project(yzlite_platform_linux
        VERSION 1.0.0
        DESCRIPTION "YZLITE Linux Platform"
)
export (PACKAGE ${PROJECT_NAME})
add_library(${PROJECT_NAME} INTERFACE)
add_library(yzlite::platform::linux ALIAS ${PROJECT_NAME})


yzlite_set(YZLITE_PLATFORM_NAME linux)
yzlite_set(YZLITE_PLATFORM_IS_EMBEDDED OFF)
# Default simulated clock rate is 80MHz
yzlite_set(YZLITE_CPU_CLOCK 80000000 DEFAULT)

# Just force these ReRAM Engine values
yzlite_set(GECKO_SDK_BOARD_TARGET ${YZLITE_PLATFORM})
yzlite_set(GECKO_SDK_BOARD_SERIES 2)

find_package(yzlite_platform_common REQUIRED)
find_package(yzlite_stacktrace REQUIRED)
find_package(yzlite_cpputils REQUIRED)
find_package(yzlite_libsoundio REQUIRED)
find_package(yzlite_reram_sdk_emulation REQUIRED)

yzlite_set(force_link_glibc_2_17_h_path "${CMAKE_CURRENT_LIST_DIR}/force_link_glibc_2.17.h")
function(yzlite_platform_linux_link_legacy_glibc)
    # Ensure we link against glibc 2.17 which is what Ubuntu 16
    # For more details, see: https://github.com/wheybags/glibc_version_header
    yzlite_get(force_link_glibc_2_17_h_path)
    yzlite_warn("Force linking to glibc 2.17 at ${force_link_glibc_2_17_h_path}")
    yzlite_append_global_cxx_flags("-include ${force_link_glibc_2_17_h_path}")
endfunction()


add_library(platform_linux_clib_override STATIC)
target_compile_features(platform_linux_clib_override  PUBLIC cxx_constexpr cxx_std_17)
target_sources(platform_linux_clib_override
PRIVATE
    start.cc
    clib_override.c
    sl_sleeptimer_linux.c
    microsecond_timer.c
    sl_system_init.c
)
target_compile_options(platform_linux_clib_override
PUBLIC
    -I $(CMAKE_CURRENT_LIST_DIR)
)
target_compile_definitions(platform_linux_clib_override
PRIVATE
    YZLITE_CPU_CLOCK=${YZLITE_CPU_CLOCK}
)
target_link_options(platform_linux_clib_override
PUBLIC
    -Wl,--wrap,main
    -Wl,--wrap,_assert
    -Wl,--wrap,__assert_fail
    -Wl,--wrap,__assert_perror_fail
    -Wl,--wrap,abort
    -Wl,--whole-archive ${CMAKE_CURRENT_BINARY_DIR}/libplatform_linux_clib_override.a -Wl,--no-whole-archive
)
target_link_libraries(platform_linux_clib_override
PUBLIC
    yzlite::platform::common
    yzlite::stacktrace
    yzlite::cpputils
    yzlite::libsoundio
    yzlite::reram_sdk::emulation
)

target_include_directories(${PROJECT_NAME}
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
INTERFACE
    yzlite::platform::common
    platform_linux_clib_override
    yzlite::reram_sdk::emulation
)

target_compile_definitions(${PROJECT_NAME}
INTERFACE
    __PROGRAM_START=_dummy # This is required to work-aroud build errors in cmsis_gcc.h
)