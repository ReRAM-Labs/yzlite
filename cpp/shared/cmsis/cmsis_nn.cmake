add_library(yzlite_cmsis_nn INTERFACE)
add_library(yzlite::cmsis_nn ALIAS yzlite_cmsis_nn)


set(CMSIS_PATH ${cmsis_SOURCE_DIR})
add_subdirectory(${cmsis_SOURCE_DIR}/CMSIS/NN/Source)


target_link_libraries(yzlite_cmsis_nn
INTERFACE
  cmsis-nn
  yzlite::cmsis_dsp
)

target_include_directories(yzlite_cmsis_nn
INTERFACE
  ${cmsis_SOURCE_DIR}/CMSIS/NN
)

target_compile_definitions(yzlite_cmsis_nn
INTERFACE
  CMSIS_NN=1
)