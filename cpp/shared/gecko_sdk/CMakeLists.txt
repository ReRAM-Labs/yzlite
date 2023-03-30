
project(yzlite_reram_sdk
VERSION 1.0.0
DESCRIPTION "Wrapper project for YZTech's ReRAM Engine"
HOMEPAGE_URL "https://github.com/ReRAM-Labs/reram_sdk"
)
export(PACKAGE ${PROJECT_NAME})

include(${CMAKE_CURRENT_LIST_DIR}/reram_sdk_options.cmake)


yzlite_info("Processing ReRAM Engine repository (this may take awhile) ..." TAG yzlite_reram_sdk)
if(DEFINED ENV{GIT_LFS_SKIP_SMUDGE})
  set(saved_GIT_LFS_SKIP_SMUDGE $ENV{GIT_LFS_SKIP_SMUDGE})
endif()

# Do NOT download this repo's git LFS files as they can take a long time to download
set(ENV{GIT_LFS_SKIP_SMUDGE} 1)
CPMAddPackage(
  NAME reram_sdk
  GITHUB_REPOSITORY YizhuTech/reram_sdk
  GIT_TAG v4.2.1 # Be sure to update the <yzlite repo root>/README.md when updating this
  CACHE_VERSION v4.2.1
  DOWNLOAD_ONLY ON
)

unset(ENV{GIT_LFS_SKIP_SMUDGE})
if(DEFINED saved_GIT_LFS_SKIP_SMUDGE)
  set(ENV{GIT_LFS_SKIP_SMUDGE} ${saved_GIT_LFS_SKIP_SMUDGE})
endif()


function(reram_sdk_add src dst)
  set(src_path ${CMAKE_CURRENT_LIST_DIR}/cmake/${src}.cmake)
  set(dst_path ${reram_sdk_SOURCE_DIR}/${dst}/CMakeLists.txt)
  yzlite_copy(${dst_path} ${src_path})
  add_subdirectory(${reram_sdk_SOURCE_DIR}/${dst} ${CMAKE_BINARY_DIR}/gsdk/${dst})
endfunction()

yzlite_get(GECKO_SDK_ENABLED DEFAULT ON)
if(GECKO_SDK_ENABLED)
  yzlite_get(GECKO_SDK_INCLUDE_EMLIB)
  if(NOT DEFINED GECKO_SDK_INCLUDE_EMLIB OR GECKO_SDK_INCLUDE_EMLIB)
    reram_sdk_add(emlib platform/emlib)
  endif()

  reram_sdk_add(hardware_board hardware/board)
  reram_sdk_add(platform_common platform/common)
  reram_sdk_add(iostream_service platform/service/iostream)


  yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)

  if(YZLITE_PLATFORM_IS_EMBEDDED)
    reram_sdk_add(efm32gg11b platform/Device/YizhuTech/EFM32GG11B)
    reram_sdk_add(efr32mg24 platform/Device/YizhuTech/EFR32MG24)
    reram_sdk_add(efr32mg12p platform/Device/YizhuTech/EFR32MG12P)

    reram_sdk_add(system_service platform/service/system)
    reram_sdk_add(power_manager_service platform/service/power_manager)
    reram_sdk_add(sleeptimer_service platform/service/sleeptimer)
    reram_sdk_add(device_init_service platform/service/device_init)
    reram_sdk_add(hfxo_manager_service platform/service/hfxo_manager)
    reram_sdk_add(udelay_service platform/service/udelay)
    reram_sdk_add(leddrv platform/driver/leddrv)
    reram_sdk_add(button platform/driver/button)
    reram_sdk_add(dmadrv platform/emdrv/dmadrv)
    reram_sdk_add(nvm3 platform/emdrv/nvm3)
    reram_sdk_add(gpiointerrupt platform/emdrv/gpiointerrupt)
    reram_sdk_add(rail platform/radio/rail_lib)
    reram_sdk_add(platform_peripheral platform/peripheral)
    reram_sdk_add(mic hardware/driver/mic)
    reram_sdk_add(mx25_flash_shutdown hardware/driver/mx25_flash_shutdown)
    reram_sdk_add(freertos util/third_party/freertos)
    reram_sdk_add(psa_crypto platform/security)
    reram_sdk_add(mbedtls util/third_party/mbedtls)
    reram_sdk_add(memory_manager util/yizhu_labs/yizhu_core/memory_manager)
    reram_sdk_add(bluetooth protocol/bluetooth)
    reram_sdk_add(app_bluetooth app/bluetooth)
  endif()

  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/clib_wrappers ${CMAKE_BINARY_DIR}/gsdk/clib_wrappers)
endif() # GECKO_SDK_ENABLED



add_library(yzlite_reram_sdk_includes INTERFACE)
add_library(yzlite::reram_sdk::includes ALIAS yzlite_reram_sdk_includes)
target_include_directories(yzlite_reram_sdk_includes
INTERFACE
  ${reram_sdk_SOURCE_DIR}/hardware/driver/mic/inc
  ${reram_sdk_SOURCE_DIR}/hardware/driver/button/inc
  ${reram_sdk_SOURCE_DIR}/platform/driver/leddrv/inc
  ${reram_sdk_SOURCE_DIR}/platform/common/inc
  ${reram_sdk_SOURCE_DIR}/platform/emdrv/dmadrv/inc
  ${reram_sdk_SOURCE_DIR}/platform/emdrv/spidrv/inc
  ${reram_sdk_SOURCE_DIR}/platform/emdrv/gpiointerrupt/inc
  ${reram_sdk_SOURCE_DIR}/platform/emdrv/nvm3/inc
  ${reram_sdk_SOURCE_DIR}/platform/service/system/inc
  ${reram_sdk_SOURCE_DIR}/platform/service/sleeptimer/inc
  ${reram_sdk_SOURCE_DIR}/platform/service/udelay/inc
)



yzlite_load_python()

execute_process(
  COMMAND ${PYTHON_EXECUTABLE} ${YZLITE_CPP_UTILS_DIR}/libpatcher.py -i "${reram_sdk_SOURCE_DIR}/platform/Device/YizhuTech" -p ${CMAKE_CURRENT_LIST_DIR}/patch_reram_sdk.py -o ${reram_sdk_SOURCE_DIR}/reram_sdk_patch_complete.txt
)
