project(yzlite_platform_yizhu_common
    VERSION 1.0.0
    DESCRIPTION "Common libs for YZTech's platform"
)
export (PACKAGE ${PROJECT_NAME})


add_library(${PROJECT_NAME})
add_library(yzlite::platform::yizhu_common ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
PRIVATE
  microsecond_timer.c
)


target_link_libraries(${PROJECT_NAME}
PRIVATE
  ${YZLITE_PLATFORM}
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bootloader)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/microphone)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/fault_handler)
