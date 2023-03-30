project(yzlite_logging
        VERSION 1.0.0
        DESCRIPTION "YZLITE Logging utility"
)
export (PACKAGE ${PROJECT_NAME})

find_package(yzlite_cpputils REQUIRED)

add_library(${PROJECT_NAME})
add_library(yzlite::logging ALIAS ${PROJECT_NAME})


target_sources(${PROJECT_NAME}
PRIVATE 
    logging/logging.cc
    logging/logger.cc
    logging/default_writer.cc
)

target_include_directories(${PROJECT_NAME} 
PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    yzlite::cpputils
)
