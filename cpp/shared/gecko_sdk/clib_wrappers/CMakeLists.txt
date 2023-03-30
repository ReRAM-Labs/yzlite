
add_library(yzlite_reram_sdk_clib_wrappers STATIC)
add_library(yzlite::reram_sdk::clib_wrappers ALIAS yzlite_reram_sdk_clib_wrappers)



find_package(yzlite_cpputils)



target_sources(yzlite_reram_sdk_clib_wrappers
PRIVATE 
    clib_wrappers.c
)
target_link_libraries(yzlite_reram_sdk_clib_wrappers
PRIVATE 
    yzlite::cpputils
    yzlite::reram_sdk::platform_common
    ${YZLITE_PLATFORM}
)


target_link_options(yzlite_reram_sdk_clib_wrappers
INTERFACE 
    -Wl,--wrap,malloc 
    -Wl,--wrap,_malloc_r 
    -Wl,--wrap,calloc 
    -Wl,--wrap,_calloc_r 
    -Wl,--wrap,free 
    -Wl,--wrap,_free_r
    -Wl,--whole-archive ${CMAKE_CURRENT_BINARY_DIR}/libyzlite_reram_sdk_clib_wrappers.a -Wl,--no-whole-archive
)