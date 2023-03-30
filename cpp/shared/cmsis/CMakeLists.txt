project(yzlite_cmsis
        VERSION 1.0.0
        DESCRIPTION "ARM CMSIS Project")
export (PACKAGE ${PROJECT_NAME})
add_library(${PROJECT_NAME} INTERFACE)
add_library(yzlite::cmsis ALIAS ${PROJECT_NAME})



yzlite_get(CMSIS_CORE)
yzlite_get(CMSIS_FPU)
yzlite_get(CMSIS_MARCH) # https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html
yzlite_get(CMSIS_DISABLE_FLOAT16)
yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)



CPMAddPackage(
    NAME cmsis
    URL  https://github.com/ARM-software/CMSIS_5/archive/ed78d6b78766d71cfe0431149f2f261d1c7277a1.zip
    URL_HASH SHA1=7f3cebce5149c191e2144af5d78498777a0f9545
    DOWNLOAD_ONLY ON
    CACHE_VERSION aug15_2022
)
set(cmsis_SOURCE_DIR ${cmsis_SOURCE_DIR} CACHE INTERNAL "")



if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    include("${CMAKE_CURRENT_LIST_DIR}/wrapper/wrapper_build.cmake")
    return()
endif()


if(NOT CMSIS_CORE)
    yzlite_error("Must define global variable CMSIS_CORE" TAG yzlite_cmsis)
endif()

set(CMSIS_SUPPORTED_CORES cortex-m3 cortex-m4 cortex-m33 cortex-m55)
if(NOT ${CMSIS_CORE} IN_LIST CMSIS_SUPPORTED_CORES)
    yzlite_error("CMSIS_CORE unsupported: ${CMSIS_CORE}\nCMSIS_SUPPORTED_CORES: ${CMSIS_SUPPORTED_CORES}" TAG yzlite_cmsis)
endif()


yzlite_append_global_cxx_flags("-mthumb -mno-thumb-interwork -flax-vector-conversions -I${cmsis_SOURCE_DIR}/CMSIS/Core/Include" ASM)


if(NOT CMSIS_FPU)
    yzlite_info("Using soft FPU" TAG yzlite_cmsis)
    yzlite_append_global_cxx_flags("-mfloat-abi=softfp" ASM)
    yzlite_remove_global_cxx_flags("-mfloat-abi=hard -mfpu=${CMSIS_FPU}" ASM)
else()
    yzlite_info("Using hw FPU=${CMSIS_FPU}" TAG yzlite_cmsis)
    yzlite_remove_global_cxx_flags("-mfloat-abi=softfp" ASM)
    yzlite_append_global_cxx_flags("-mfloat-abi=hard -mfpu=${CMSIS_FPU}" ASM)
endif()

if(CMSIS_DISABLE_FLOAT16)
    yzlite_remove_global_cxx_flags("-mfp16-format=ieee" ASM)
    yzlite_append_global_cxx_flags("-DDISABLEFLOAT16")
else()
    yzlite_info("Enabling float16" TAG yzlite_cmsis)
    yzlite_append_global_cxx_flags("-mfp16-format=ieee" ASM)
    yzlite_remove_global_cxx_flags("-DDISABLEFLOAT16" ASM)
endif()


if(CMSIS_MARCH)
    yzlite_info("Using -march=${CMSIS_MARCH}" TAG yzlite_cmsis)
    yzlite_remove_global_cxx_flags("-mcpu=${CMSIS_CORE} -mtune=${CMSIS_CORE}" ASM)
    yzlite_append_global_cxx_flags("-march=${CMSIS_MARCH}" ASM)
else()
    yzlite_info("Using -mcpu=${CMSIS_CORE}" TAG yzlite_cmsis)
    yzlite_append_global_cxx_flags("-mcpu=${CMSIS_CORE} -mtune=${CMSIS_CORE}" ASM)
    yzlite_remove_global_cxx_flags("-march=.*" WILDCARD ASM)
endif()



target_include_directories(${PROJECT_NAME}
INTERFACE
    ${cmsis_SOURCE_DIR}
)

include(${CMAKE_CURRENT_LIST_DIR}/cmsis_dsp.cmake)

if(YZLITE_PLATFORM_IS_EMBEDDED)
    include(${CMAKE_CURRENT_LIST_DIR}/cmsis_device.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/cmsis_nn.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/cmsis_rtos2.cmake)
endif()


