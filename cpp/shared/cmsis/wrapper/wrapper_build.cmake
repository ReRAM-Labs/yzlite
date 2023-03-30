
add_library(yzlite_cmsis_nn)
add_library(yzlite::cmsis_nn ALIAS yzlite_cmsis_nn)


target_include_directories(yzlite_cmsis_nn
PUBLIC
    ${cmsis_SOURCE_DIR}
    ${cmsis_SOURCE_DIR}/CMSIS/Core/Include
    ${cmsis_SOURCE_DIR}/CMSIS/NN/Include
    ${cmsis_SOURCE_DIR}/CMSIS/DSP/Include
)
target_compile_options(yzlite_cmsis_nn
PRIVATE
    -Wno-strict-aliasing
)

target_sources(yzlite_cmsis_nn
PRIVATE
    wrapper/get_buffer_size.c
)
target_compile_options(yzlite_cmsis_nn
PRIVATE
    -include stdint.h
)
