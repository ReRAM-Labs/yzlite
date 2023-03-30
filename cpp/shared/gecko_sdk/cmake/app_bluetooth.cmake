set(NAME "yzlite_reram_sdk_app_bluetooth")
add_library(${NAME} INTERFACE)
add_library(yzlite::reram_sdk::app_bluetooth ALIAS ${NAME})


yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()


target_include_directories(${NAME}
INTERFACE
    common/gatt_service_device_information
    ../common/util/app_assert
)
