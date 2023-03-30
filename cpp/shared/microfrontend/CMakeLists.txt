project(yzlite_microfrontend
        VERSION 1.0.0
        DESCRIPTION "YZTech's Microfrontend"
)
export(PACKAGE ${PROJECT_NAME})

add_library(${PROJECT_NAME})
add_library(yzlite::microfrontend ALIAS ${PROJECT_NAME})



target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)


set(sources
    microfrontend/lib/activity_detection.c
    microfrontend/lib/activity_detection_util.c
    microfrontend/lib/dc_notch_filter.c
    microfrontend/lib/dc_notch_filter_util.c
    microfrontend/lib/filterbank_util.c
    microfrontend/lib/filterbank.c
    microfrontend/lib/frontend_util.c
    microfrontend/lib/frontend.c
    microfrontend/lib/log_lut.c
    microfrontend/lib/log_scale.c
    microfrontend/lib/log_scale_util.c
    microfrontend/lib/noise_reduction_util.c
    microfrontend/lib/noise_reduction.c
    microfrontend/lib/pcan_gain_control_util.c
    microfrontend/lib/pcan_gain_control.c
    microfrontend/lib/window_util.c
    microfrontend/lib/window.c
)

find_package(yzlite_reram_sdk REQUIRED)

set(libs yzlite::reram_sdk::includes)

yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(YZLITE_PLATFORM_IS_EMBEDDED)
    find_package(yzlite_cmsis REQUIRED)
    list(APPEND libs yzlite::cmsis_dsp)
    list(APPEND sources
        microfrontend/sl_ml_fft.cc
    )
else()
    find_package(yzlite_kissfft REQUIRED)
    list(APPEND libs yzlite::kissfft)
    list(APPEND sources
        microfrontend/lib/fft_util.cc
        microfrontend/lib/fft.cc
    )

endif()

target_sources(${PROJECT_NAME}
PRIVATE
    ${sources}
)
target_link_libraries(${PROJECT_NAME}
PUBLIC
    ${libs}
)

##############################################
# If this is a non-embedded build
# then also build the microfrontend as a DLL
if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    add_library(microfrontend SHARED)
    set_target_properties(microfrontend PROPERTIES PREFIX "")

    target_compile_definitions(microfrontend
    PRIVATE
        MICROFRONTEND_DLL_EXPORT
    )

    target_sources(microfrontend
    PRIVATE
        ${sources}
    )

    target_link_libraries(microfrontend
    PUBLIC
        ${libs}
    )

    target_include_directories(microfrontend
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )

endif()


add_subdirectory(tests)
add_subdirectory(example)