
add_library(yzlite_platform_yizhu_simple_bootloader)

target_sources(yzlite_platform_yizhu_simple_bootloader
PRIVATE 
    simple_bootloader.c
)

target_link_libraries(yzlite_platform_yizhu_simple_bootloader
PRIVATE 
    ${YZLITE_PLATFORM}
)
