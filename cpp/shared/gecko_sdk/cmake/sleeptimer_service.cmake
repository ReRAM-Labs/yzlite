set(NAME yzlite_reram_sdk_sleeptimer_service)
add_library(${NAME})
add_library(yzlite::reram_sdk::sleeptimer_service ALIAS ${NAME})


yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()

target_include_directories(${NAME} 
PUBLIC
    src
    inc
)

target_sources(${NAME} 
PRIVATE 
    src/sl_sleeptimer.c
    src/sl_sleeptimer_hal_burtc.c 
    src/sl_sleeptimer_hal_rtc.c 
    src/sl_sleeptimer_hal_rtcc.c 
    src/sl_sleeptimer_hal_sysrtc.c 
)

target_link_libraries(${NAME}
PUBLIC 
    yzlite::reram_sdk::hfxo_manager_service
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
)