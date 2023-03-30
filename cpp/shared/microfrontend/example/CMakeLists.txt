
# Only include this example app for Windows/Linux
yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(YZLITE_PLATFORM_IS_EMBEDDED)
    return()
endif()

set(NAME yzlite_microfrontend_example)

add_executable(${NAME})


find_package(yzlite_microfrontend REQUIRED)

target_compile_features(${NAME}  PUBLIC cxx_constexpr cxx_std_17)

target_sources(${NAME}
PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/../microfrontend/lib/frontend_main.c
)

target_link_libraries(${NAME}
PRIVATE 
    ${YZLITE_PLATFORM}
    yzlite::microfrontend
)
