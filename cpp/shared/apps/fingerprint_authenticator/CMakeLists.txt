
# This app currently only supports embedded platforms
if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    return()
endif()


# Find the necessary packages
find_package(yzlite_logging REQUIRED)
find_package(yzlite_profiling REQUIRED)
find_package(yzlite_tflite_micro_model REQUIRED)
find_package(yzlite_fingerprint_reader REQUIRED)



#####################################################
# Define the fingerprint_authenticator executable
add_executable(yzlite_fingerprint_authenticator)


target_sources(yzlite_fingerprint_authenticator
PRIVATE
    main.cc
    app_controller.cc
    fingerprint_authenticator.cc
    data_preprocessor.cc
    fingerprint_vault.c
)

target_link_libraries(yzlite_fingerprint_authenticator
PRIVATE
    yzlite::tflite_micro_model
    yzlite::fingerprint_reader
    ${YZLITE_PLATFORM}
)


target_include_directories(yzlite_fingerprint_authenticator
PRIVATE
    .
)


#####################################################
# Convert the model .tflite to a C header file

# Use the default model if one wasn't provided on the command-line
yzlite_get(FINGERPRINT_AUTHENTICATOR_MODEL)
if(NOT FINGERPRINT_AUTHENTICATOR_MODEL)
    set(FINGERPRINT_AUTHENTICATOR_MODEL "fingerprint_signature_generator")
endif()
yzlite_info("FINGERPRINT_AUTHENTICATOR_MODEL=${FINGERPRINT_AUTHENTICATOR_MODEL}" TAG yzlite_fingerprint_authenticator)

yzlite_add_tflite_model(yzlite_fingerprint_authenticator ${FINGERPRINT_AUTHENTICATOR_MODEL})


# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_fingerprint_authenticator)
