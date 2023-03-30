project(yzlite_msgpack
        VERSION 1.0.0
        DESCRIPTION "Utility to serialize and de-serialize data using the msgpack format"
)
export (PACKAGE ${PROJECT_NAME})


add_library(${PROJECT_NAME})
add_library(yzlite::msgpack ALIAS ${PROJECT_NAME})

find_package(yzlite_str_util REQUIRED)
find_package(yzlite_dynamic_buffer REQUIRED)

target_sources(${PROJECT_NAME} 
PRIVATE 
    src/msgpack.c
    src/msgpack_deserialize.c 
    src/msgpack_serialize.c
    src/msgpack_buffered_writer.c
)

target_include_directories(${PROJECT_NAME}
PRIVATE 
    ./src
PUBLIC 
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
PRIVATE 
    yzlite::str_util
    yzlite::dynamic_buffer
)