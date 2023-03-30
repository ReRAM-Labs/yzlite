
# See: https://github.com/lieff/minimp3
CPMAddPackage(
    NAME minimp3 
    GITHUB_REPOSITORY lieff/minimp3
    GIT_TAG afb604c06bc8beb145fecd42c0ceb5bda8795144
    CACHE_VERSION nov30_2021
    DOWNLOAD_ONLY ON
)
export(PACKAGE yzlite_minimp3)
add_library(yzlite_minimp3 INTERFACE)
add_library(yzlite::minimp3 ALIAS yzlite_minimp3)

target_include_directories(yzlite_minimp3
INTERFACE 
    ${minimp3_SOURCE_DIR}
)

