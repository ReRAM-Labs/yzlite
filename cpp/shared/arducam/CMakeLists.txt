
project(yzlite_arducam
VERSION 1.0.0
DESCRIPTION "YZLITE ArduCAM Driver"
)
export (PACKAGE ${PROJECT_NAME})

add_library(${PROJECT_NAME})
add_library(yzlite::arducam ALIAS ${PROJECT_NAME})

find_package(yzlite_reram_sdk REQUIRED)



target_sources(${PROJECT_NAME}
PRIVATE 
    arducam/drivers/m2mp/arducam_m_2mp_driver.c
    arducam/drivers/m2mp/arducam.c
    arducam/drivers/m2mp/ov2640.c
)

target_include_directories(${PROJECT_NAME} 
PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    ${YZLITE_PLATFORM}
    yzlite::reram_sdk::includes
)
