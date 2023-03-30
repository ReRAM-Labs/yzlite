
# This app currently only supports embedded platforms
if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    return()
endif()


# Find the necessary packages
find_package(yzlite_logging REQUIRED)
find_package(yzlite_profiling REQUIRED)
find_package(yzlite_tflite_micro_model REQUIRED)
find_package(yzlite_arducam REQUIRED)



#####################################################
# Define the image_classifier executable
add_executable(yzlite_image_classifier)


target_sources(yzlite_image_classifier
PRIVATE
    main.cc
    app.cc
    image_classifier.cc
    recognize_commands.cc
)

target_link_libraries(yzlite_image_classifier
PRIVATE
    yzlite::tflite_micro_model
    yzlite::arducam
    ${YZLITE_PLATFORM}
)


target_include_directories(yzlite_image_classifier
PRIVATE
    .
)


#####################################################
# Convert the model .tflite to a C  array

# Use the default model if one wasn't provided on the command-line
yzlite_get(IMAGE_CLASSIFIER_MODEL)
if(NOT IMAGE_CLASSIFIER_MODEL)
    set(IMAGE_CLASSIFIER_MODEL "rock_paper_scissors")
endif()
yzlite_info("IMAGE_CLASSIFIER_MODEL=${IMAGE_CLASSIFIER_MODEL}" TAG yzlite_image_classifier)

yzlite_add_tflite_model(yzlite_image_classifier ${IMAGE_CLASSIFIER_MODEL})


# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_image_classifier)
