set(NAME "yzlite_reram_sdk_iostream_service")
add_library(${NAME})
add_library(yzlite::reram_sdk::iostream_service ALIAS ${NAME})

yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()

target_include_directories(${NAME} 
PUBLIC
    inc
)

yzlite_get(GECKO_SDK_IO_STREAM_SERVICE_SOURCES)
list(TRANSFORM GECKO_SDK_IO_STREAM_SERVICE_SOURCES PREPEND src/)
target_sources(${NAME} 
PRIVATE 
    src/sl_iostream.c
    ${GECKO_SDK_IO_STREAM_SERVICE_SOURCES}
)



target_link_libraries(${NAME}
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
    yzlite::reram_sdk::platform_common
)

target_link_options(${NAME}
PUBLIC 
    -Wl,-u_write
    -Wl,-u_read
    -Wl,-u_isatty
    -Wl,-u_lseek
    -Wl,-u_lseek
)