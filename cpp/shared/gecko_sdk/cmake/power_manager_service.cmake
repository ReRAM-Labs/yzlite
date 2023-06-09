set(NAME yzlite_reram_sdk_power_manager_service)
add_library(${NAME})
add_library(yzlite::reram_sdk::power_manager_service ALIAS ${NAME})


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
PRIVATE 
    src
)


if(${GECKO_SDK_BOARD_SERIES} STREQUAL 1)
    set(_hal_source src/sl_power_manager_hal_s0_s1.c)
elseif(${GECKO_SDK_BOARD_SERIES} STREQUAL 2)
    set(_hal_source src/sl_power_manager_hal_s2.c)
else()
    yzlite_error("GECKO_SDK_BOARD_SERIES=${GECKO_SDK_BOARD_SERIES} not supported")
endif()


target_sources(${NAME}
PRIVATE 
    src/sl_power_manager.c
    src/sl_power_manager_debug.c
    ${_hal_source}
)

target_compile_options(${NAME}
PRIVATE 
    -Wno-implicit-function-declaration
)


target_link_libraries(${NAME}
PRIVATE 
    ${GECKO_SDK_BOARD_TARGET}
    yzlite::reram_sdk::sleeptimer_service
)