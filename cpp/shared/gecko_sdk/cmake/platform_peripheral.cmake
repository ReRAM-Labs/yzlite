set(NAME yzlite_reram_sdk_platform_peripheral)
add_library(${NAME})
add_library(yzlite::reram_sdk::platform_peripheral ALIAS ${NAME})


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
    src/peripheral_sysrtc.c 
)

target_link_libraries(${NAME}
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
)
