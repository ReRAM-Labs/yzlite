
add_library(yzlite_cmsis_rtos2)
add_library(yzlite::cmsis_rtos2 ALIAS yzlite_cmsis_rtos2)

target_sources(yzlite_cmsis_rtos2
PRIVATE
    ${cmsis_SOURCE_DIR}/CMSIS/RTOS2/Source/os_systick.c
)
target_include_directories(yzlite_cmsis_rtos2
PUBLIC
    ${cmsis_SOURCE_DIR}/CMSIS/RTOS2/Include
)
target_link_libraries(yzlite_cmsis_rtos2
PRIVATE
    ${YZLITE_PLATFORM}
)