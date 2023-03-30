project(yzlite_reram_sdk_audio_feature_generation
    VERSION 1.0.0
    DESCRIPTION "YZLITE audio feature generation library used by ReRAM Engine"
)
export(PACKAGE ${PROJECT_NAME})
add_library(${PROJECT_NAME})
add_library(yzlite::reram_sdk::audio_feature_generation ALIAS ${PROJECT_NAME})

find_package(yzlite_microfrontend REQUIRED)
find_package(yzlite_cpputils REQUIRED)
find_package(yzlite_tflite_micro REQUIRED)
find_package(yzlite_tflite_model_parameters REQUIRED)
find_package(yzlite_jlink_stream REQUIRED)
find_package(yzlite_libsoundio REQUIRED)


yzlite_get(GECKO_SDK_BOARD_TARGET)
if(NOT GECKO_SDK_BOARD_TARGET)
    yzlite_error("Must specify GECKO_SDK_BOARD_TARGET global property")
endif()


target_include_directories(${PROJECT_NAME} 
PUBLIC
    .
)

target_sources(${PROJECT_NAME}  
PRIVATE 
    sl_ml_audio_feature_generation.c
    sl_ml_audio_feature_generation_init.c 
    sl_ml_audio_feature_generation_config.cc
)

target_link_libraries(${PROJECT_NAME}  
PRIVATE
    ${GECKO_SDK_BOARD_TARGET}
    yzlite::microfrontend
    yzlite::cpputils
    yzlite::tflite_micro
    yzlite::tflite_model_parameters
)

yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(YZLITE_PLATFORM_IS_EMBEDDED)
    target_link_libraries(${PROJECT_NAME}  
    PRIVATE
        yzlite::jlink_stream
        yzlite::sl_mic
    )

    target_sources(${PROJECT_NAME}  
    PRIVATE 
        data_dumper_arm.cc
    )

else()
    target_link_libraries(${PROJECT_NAME}  
    PRIVATE
        yzlite::libsoundio
    )

    target_sources(${PROJECT_NAME}  
    PRIVATE 
        data_dumper_pc.cc
    )
endif()