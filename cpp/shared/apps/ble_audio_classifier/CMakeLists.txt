
# Currently, this app only supports the BRD2601 platform
# The bluetooth GSDK component must be enabled to build this app
yzlite_get(GECKO_SDK_ENABLE_BLUETOOTH)
if(NOT GECKO_SDK_ENABLE_BLUETOOTH OR NOT "${YZLITE_PLATFORM_NAME}" STREQUAL "brd2601")
    return()
endif()

# Find the necessary packages
find_package(yzlite_logging REQUIRED)
find_package(yzlite_profiling REQUIRED)
find_package(yzlite_tflite_micro_model REQUIRED)
find_package(yzlite_reram_sdk REQUIRED)
find_package(yzlite_reram_sdk_audio_feature_generation REQUIRED)


#####################################################
# Define the audio_classifier executable
add_executable(yzlite_ble_audio_classifier)


target_sources(yzlite_ble_audio_classifier
PRIVATE
    main.c
    app.c
    recognize_commands.cc
    ble_audio_classifier.cc
    ble_audio_classifier_config.cc
    bluetooth.c
    gatt_db.c
    sl_gatt_service_device_information.c
)

target_link_libraries(yzlite_ble_audio_classifier
PRIVATE
    yzlite::tflite_micro_model
    yzlite::tflite_model_parameters
    yzlite::reram_sdk::audio_feature_generation
    ${YZLITE_PLATFORM}
)


target_include_directories(yzlite_ble_audio_classifier
PRIVATE
    .
)

yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    find_package(yzlite_cxxopts REQUIRED)
    target_link_libraries(yzlite_ble_audio_classifier
    PRIVATE
        yzlite::cxxopts
    )
endif()


#####################################################
# Convert the model .tflite to a C array

# Use the default model if one wasn't provided on the command-line
yzlite_get(BLE_AUDIO_CLASSIFIER_MODEL)
if(NOT BLE_AUDIO_CLASSIFIER_MODEL)
    set(BLE_AUDIO_CLASSIFIER_MODEL "keyword_spotting_pacman_v2")
endif()
yzlite_info("BLE_AUDIO_CLASSIFIER_MODEL=${BLE_AUDIO_CLASSIFIER_MODEL}" TAG yzlite_ble_audio_classifier)

yzlite_add_tflite_model(yzlite_ble_audio_classifier ${BLE_AUDIO_CLASSIFIER_MODEL})

# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_ble_audio_classifier)
