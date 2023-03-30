set(NAME "yzlite_reram_sdk_system_service")
add_library(${NAME})
add_library(yzlite::reram_sdk::system_service ALIAS ${NAME})


yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()

target_include_directories(${NAME} 
PUBLIC
    inc
)

target_sources(${NAME} 
PRIVATE 
    src/sl_system_init.c
    src/sl_system_process_action.c
    src/sl_system_kernel.c
)

target_link_libraries(${NAME}
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
    yzlite::reram_sdk::platform_common
)