project(yzlite_reram_sdk_emulation
        VERSION 1.0.0
        DESCRIPTION "YZLITE Silabs ReRAM Engine API emulation library"
)
export(PACKAGE yzlite_reram_sdk_emulation)
add_library(${PROJECT_NAME})
add_library(yzlite::reram_sdk::emulation ALIAS ${PROJECT_NAME})



find_package(yzlite_reram_sdk REQUIRED)



target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)


target_sources(${PROJECT_NAME}
PRIVATE
    sl_simple_led_instances.c
    sl_led.c
    em_cmu.c
)

yzlite_get(YZLITE_CPU_CLOCK)
target_compile_definitions(${PROJECT_NAME}
PRIVATE
    YZLITE_CPU_CLOCK=${YZLITE_CPU_CLOCK}
)


target_link_libraries(${PROJECT_NAME}
PUBLIC
    yzlite::reram_sdk::includes
PRIVATE
    ${YZLITE_PLATFORM}
)
