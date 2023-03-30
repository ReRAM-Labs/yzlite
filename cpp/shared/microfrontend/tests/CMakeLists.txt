project(yzlite_microfrontend_tests
        VERSION 1.0.0
        DESCRIPTION "YZLITE Microfrontend Tests"
)
export(PACKAGE ${PROJECT_NAME})


add_executable(${PROJECT_NAME})


find_package(yzlite_microfrontend REQUIRED)
find_package(yzlite_gtest REQUIRED)

target_compile_features(${PROJECT_NAME}  PUBLIC cxx_constexpr cxx_std_17)

target_sources(${PROJECT_NAME}
PUBLIC 
    main.cc 
    fft_test.cc 
    filterbank_test.cc 
    frontend_test.cc 
    log_scale_test.cc 
    noise_reduction_test.cc 
    pcan_gain_control_test.cc 
    spectrogram_test.cc 
    window_test.cc
)

target_link_libraries( ${PROJECT_NAME}
PRIVATE 
    ${YZLITE_PLATFORM}
    yzlite::gtest
)

yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(YZLITE_PLATFORM_IS_EMBEDDED OR NOT HOST_OS_IS_WINDOWS)
    target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        yzlite::microfrontend
    )
else()
    target_link_libraries(${PROJECT_NAME}
    PRIVATE 
        microfrontend # Optional: link to the micrfrontend DLL instead of static library
    )
endif()

#####################################################
# Unit test

if(NOT YZLITE_EXCLUDE_TESTS)
    add_test(yzlite_microfrontend_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/yzlite_microfrontend_tests)
    set_tests_properties(yzlite_microfrontend_tests
        PROPERTIES
        FAIL_REGULAR_EXPRESSION ".*FAILED.*")
endif()