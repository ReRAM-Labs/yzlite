set(NAME "yzlite_reram_sdk_device_init_service")
add_library(${NAME})
add_library(yzlite::reram_sdk::device_init_service ALIAS ${NAME})



yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()
yzlite_get(GECKO_SDK_BOARD_SERIES)
if(NOT GECKO_SDK_BOARD_SERIES)
    yzlite_error("Must specify GECKO_SDK_BOARD_SERIES global property")
endif()

target_include_directories(${NAME} 
PUBLIC
    inc
)


yzlite_get(GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES)
if(NOT GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES)
    set(GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES sl_device_init_nvic.c)

    if(${GECKO_SDK_BOARD_SERIES} STREQUAL 1)
        list(APPEND GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES
            sl_device_init_dcdc_s1.c 
            sl_device_init_emu_s1.c 
            sl_device_init_hfxo_s1.c 
            sl_device_init_lfxo_s1.c 
            sl_device_init_hfrco.c 
        )

    elseif(${GECKO_SDK_BOARD_SERIES} STREQUAL 2)
        list(APPEND GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES
            sl_device_init_dcdc_s2.c 
            sl_device_init_emu_s2.c 
            sl_device_init_hfxo_s2.c 
            sl_device_init_hfrco.c 
            sl_device_init_lfxo_s2.c 
            sl_device_init_dpll_s2.c 
            sl_device_init_nvic.c
        )
    else()
        yzlite_error("GECKO_SDK_BOARD_SERIES=${GECKO_SDK_BOARD_SERIES} not supported")
    endif()

endif() # NOT GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES


list(TRANSFORM GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES PREPEND src/)
target_sources(${NAME} 
PRIVATE 
    ${GECKO_SDK_DEVICE_INIT_SERVICE_SOURCES}
)

target_link_libraries(${NAME}
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
    yzlite::reram_sdk::platform_common
)