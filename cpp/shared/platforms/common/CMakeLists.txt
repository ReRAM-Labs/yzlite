project(yzlite_platform_common
        VERSION 1.0.0
        DESCRIPTION "YZLITE platform common library"
)
export(PACKAGE yzlite_platform_common)


add_library(${PROJECT_NAME} INTERFACE)
add_library(yzlite::platform::common ALIAS ${PROJECT_NAME})


target_include_directories(${PROJECT_NAME}
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
