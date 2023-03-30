set(NAME yzlite_reram_sdk_hfxo_manager_service)
add_library(${NAME})
add_library(yzlite::reram_sdk::hfxo_manager_service ALIAS ${NAME})


yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()

target_include_directories(${NAME} 
PUBLIC
    inc
PRIVATE 
    src
)

target_sources(${NAME} 
PRIVATE 
    src/sl_hfxo_manager.c
    src/sl_hfxo_manager_hal_s2.c 
)

target_link_libraries(${NAME}
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
    yzlite::reram_sdk::sleeptimer_service
)