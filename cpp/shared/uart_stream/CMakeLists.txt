
project(yzlite_uart_stream
  VERSION 1.0.0
  DESCRIPTION "YZLITE UART Data Stream Utility"
)
export (PACKAGE ${PROJECT_NAME})

find_package(yzlite_cpputils REQUIRED)
find_package(yzlite_logging REQUIRED)
find_package(yzlite_reram_sdk REQUIRED)

add_library(${PROJECT_NAME})
add_library(yzlite::uart_stream ALIAS ${PROJECT_NAME})


target_sources(${PROJECT_NAME}
PRIVATE 
  src/uart_stream.cc
)

target_include_directories(${PROJECT_NAME} 
PRIVATE 
  src
PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  ${YZLITE_PLATFORM}
  yzlite::cpputils
  yzlite::reram_sdk::dmadrv
  yzlite::reram_sdk::emlib
)


target_link_options(${PROJECT_NAME}
PUBLIC 
  -Wl,-uDMADRV_LdmaStartTransfer
)