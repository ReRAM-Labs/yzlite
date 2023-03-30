
set(NAME "yzlite_reram_sdk_button")
add_library(${NAME})
add_library(yzlite::reram_sdk::button ALIAS ${NAME})


yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()


target_include_directories(${NAME} 
PUBLIC
    inc
)

target_compile_options(${NAME}  
PRIVATE 
    -Wimplicit-fallthrough=0)

target_sources(${NAME}  
PRIVATE 
    src/sl_button.c 
    src/sl_simple_button.c
)

target_link_libraries(${NAME}  
PRIVATE
    ${GECKO_SDK_BOARD_TARGET}
)