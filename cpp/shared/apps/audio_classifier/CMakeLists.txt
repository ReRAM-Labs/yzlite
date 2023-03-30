

set(AUDIO_CLASSIFIER_SUPPORTED_PLATFORMS windows linux brd2204 brd2601 brd4166)
if(NOT ${YZLITE_PLATFORM_NAME} IN_LIST AUDIO_CLASSIFIER_SUPPORTED_PLATFORMS)
    yzlite_info(
        "Audio Classifier app NOT currently supported by platform: ${YZLITE_PLATFORM_NAME}"
        TAG yzlite_audio_classifier
    )
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
add_executable(yzlite_audio_classifier)


target_sources(yzlite_audio_classifier
PRIVATE
    main.c
    app.c
    audio_classifier.cc
    recognize_commands.cc
    audio_classifier_config.cc
    cli_opts.cc
)

target_link_libraries(yzlite_audio_classifier
PRIVATE
    yzlite::tflite_micro_model
    yzlite::tflite_model_parameters
    yzlite::reram_sdk::audio_feature_generation
    ${YZLITE_PLATFORM}
)


target_include_directories(yzlite_audio_classifier
PRIVATE
    .
)

yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    find_package(yzlite_cxxopts REQUIRED)
    target_link_libraries(yzlite_audio_classifier
    PRIVATE
        yzlite::cxxopts
    )
endif()


unset(_defines)
yzlite_get(VERBOSE)
if(VERBOSE)
    yzlite_info("Enabling verbose logs" TAG yzlite_audio_classifier)
    set(_defines ${_defines} VERBOSE=1)
endif()

yzlite_get(WINDOW_MS)
if(WINDOW_MS)
    yzlite_info("WINDOW_MS=${WINDOW_MS}" TAG yzlite_audio_classifier)
    set(_defines ${_defines} WINDOW_MS=${WINDOW_MS})
endif()

yzlite_get(THRESHOLD)
if(THRESHOLD)
    yzlite_info("THRESHOLD=${THRESHOLD}" TAG yzlite_audio_classifier)
    set(_defines ${_defines} THRESHOLD=${THRESHOLD})
endif()

yzlite_get(SUPPRESSION_MS)
if(SUPPRESSION_MS)
    yzlite_info("SUPPRESSION_MS=${SUPPRESSION_MS}" TAG yzlite_audio_classifier)
    set(_defines ${_defines} SUPPRESSION_MS=${SUPPRESSION_MS})
endif()

yzlite_get(COUNT)
if(COUNT)
    yzlite_info("COUNT=${COUNT}" TAG yzlite_audio_classifier)
    set(_defines ${_defines} COUNT=${COUNT})
endif()

yzlite_get(VOLUME_GAIN)
if(VOLUME_DB)
    yzlite_info("VOLUME_GAIN=${VOLUME_GAIN}" TAG yzlite_audio_classifier)
    set(_defines ${_defines} VOLUME_GAIN=${VOLUME_GAIN})
endif()

yzlite_get(LATENCY_MS)
if(LATENCY_MS)
    yzlite_info("LATENCY_MS=${LATENCY_MS}" TAG yzlite_audio_classifier)
    set(_defines ${_defines} LATENCY_MS=${LATENCY_MS})
endif()

if(_defines)
    target_compile_definitions(yzlite_audio_classifier
    PRIVATE
        ${_defines}
    )
endif()


#####################################################
# Convert the model .tflite to a C array

# Use the default model if one wasn't provided on the command-line
yzlite_get(AUDIO_CLASSIFIER_MODEL)
if(NOT AUDIO_CLASSIFIER_MODEL)
    set(AUDIO_CLASSIFIER_MODEL "keyword_spotting_on_off_v2")
endif()
yzlite_info("AUDIO_CLASSIFIER_MODEL=${AUDIO_CLASSIFIER_MODEL}" TAG yzlite_audio_classifier)

yzlite_add_tflite_model(yzlite_audio_classifier ${AUDIO_CLASSIFIER_MODEL})

# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_audio_classifier)



#####################################################
# Optional support for the Audio I/O

yzlite_get(AUDIO_CLASSIFIER_ENABLE_AUDIO_IO)
if(AUDIO_CLASSIFIER_ENABLE_AUDIO_IO)
    set(AUDIO_CLASSIFIER_AUDIO_IO_SUPPORTED_PLATFORMS brd2601)
    if(NOT ${YZLITE_PLATFORM_NAME} IN_LIST AUDIO_CLASSIFIER_AUDIO_IO_SUPPORTED_PLATFORMS)
        yzlite_info(
            "Audio Classifier: Audio I/O support in the is NOT currently supported by platform: ${YZLITE_PLATFORM_NAME}"
            TAG yzlite_audio_classifier
        )
        return()
    endif()

    yzlite_info("Audio Classifier: Enabling audio I/O" TAG yzlite_audio_classifier)

    find_package(yzlite_opus REQUIRED)
    find_package(yzlite_minimp3 REQUIRED)
    find_package(yzlite_voice_activity_detector REQUIRED)

    target_link_libraries(yzlite_audio_classifier
    PRIVATE
        yzlite_opus
        yzlite_minimp3
        yzlite_voice_activity_detector
    )

    target_sources(yzlite_audio_classifier
    PRIVATE
        audio_io.cc
    )

    target_compile_definitions(yzlite_audio_classifier
    PRIVATE
        AUDIO_IO_ENABLED=1
    )

endif()



