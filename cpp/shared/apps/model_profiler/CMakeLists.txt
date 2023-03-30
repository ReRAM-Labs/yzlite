
yzlite_set(TFLITE_MICRO_PROFILER_ENABLED ON)


# Find the necessary packages
find_package(yzlite_logging REQUIRED)
find_package(yzlite_profiling REQUIRED)
find_package(yzlite_tflite_micro_model REQUIRED)



#####################################################
# Define the model_profiler executable
add_executable(yzlite_model_profiler)


target_sources(yzlite_model_profiler
PRIVATE
    main.cc
)

target_link_libraries(yzlite_model_profiler
PRIVATE
    yzlite::tflite_micro_model
    ${YZLITE_PLATFORM}
)

target_include_directories(yzlite_model_profiler
PRIVATE
    .
)

yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
if(NOT YZLITE_PLATFORM_IS_EMBEDDED)
    find_package(yzlite_cxxopts REQUIRED)
    target_link_libraries(yzlite_model_profiler
    PRIVATE
        yzlite::cxxopts
    )
    target_sources(yzlite_model_profiler
    PRIVATE
        cli_opts.cc
    )

endif()

yzlite_get(YZLITE_RUN_MODEL_FROM_RAM)
if(YZLITE_RUN_MODEL_FROM_RAM)
    yzlite_info("Loading .tflite flatbuffer into RAM" TAG yzlite_model_profiler)
    target_compile_definitions(yzlite_model_profiler
    PUBLIC
        YZLITE_RUN_MODEL_FROM_RAM
    )
endif()



yzlite_get(YZLITE_RUNTIME_MEMORY_SIZE)
if(DEFINED YZLITE_RUNTIME_MEMORY_SIZE)
    set(MODEL_PROFILER_RUNTIME_MEMORY_SIZE ${YZLITE_RUNTIME_MEMORY_SIZE})
endif()
yzlite_get(MODEL_PROFILER_RUNTIME_MEMORY_SIZE)
yzlite_get(MODEL_PROFILER_RUNTIME_MEMORY_SECTION)
if(DEFINED MODEL_PROFILER_RUNTIME_MEMORY_SIZE)
    yzlite_info("MODEL_PROFILER_RUNTIME_MEMORY_SIZE=${MODEL_PROFILER_RUNTIME_MEMORY_SIZE} bytes" TAG yzlite_model_profiler)
    target_compile_definitions(yzlite_model_profiler
    PRIVATE
        MODEL_PROFILER_RUNTIME_MEMORY_SIZE=${MODEL_PROFILER_RUNTIME_MEMORY_SIZE}
    )

    if(MODEL_PROFILER_RUNTIME_MEMORY_SECTION)
        yzlite_info("MODEL_PROFILER_RUNTIME_MEMORY_SECTION=${MODEL_PROFILER_RUNTIME_MEMORY_SECTION}" TAG yzlite_model_profiler)
        target_compile_definitions(yzlite_model_profiler
        PRIVATE
            MODEL_PROFILER_RUNTIME_MEMORY_SECTION=\"${MODEL_PROFILER_RUNTIME_MEMORY_SECTION}\"
        )
    endif()
elseif(MODEL_PROFILER_RUNTIME_MEMORY_SECTION)
    yzlite_warn("MODEL_PROFILER_RUNTIME_MEMORY_SECTION is not used if MODEL_PROFILER_RUNTIME_MEMORY_SIZE is not defined" TAG yzlite_model_profiler)
endif()


#####################################################
# Convert the model .tflite to a C array

# Use the default model if one wasn't provided on the command-line

yzlite_get(MODEL_PROFILER_MODEL)
if(NOT MODEL_PROFILER_MODEL)
    # Support legacy variable name
    yzlite_get(MODEL)
    if(MODEL)
        set(MODEL_PROFILER_MODEL ${MODEL})
    endif()
endif()

if(NOT MODEL_PROFILER_MODEL)
    set(MODEL_PROFILER_MODEL "image_classification")
endif()
yzlite_info("MODEL_PROFILER_MODEL=${MODEL_PROFILER_MODEL}" TAG yzlite_model_profiler)


yzlite_get(MODEL_PROFILER_MODEL_MEMORY_SECTION)
if(MODEL_PROFILER_MODEL_MEMORY_SECTION)
    set(memory_section_arg MEMORY_SECTION ${MODEL_PROFILER_MODEL_MEMORY_SECTION})
    yzlite_info("MODEL_PROFILER_MODEL_MEMORY_SECTION=${MODEL_PROFILER_MODEL_MEMORY_SECTION}" TAG yzlite_model_profiler)
endif()
yzlite_add_tflite_model(yzlite_model_profiler "${MODEL_PROFILER_MODEL}" ${memory_section_arg})


yzlite_get(MODEL_PROFILER_GENERATE_OP_RESOLVER_HEADER)
if(MODEL_PROFILER_GENERATE_OP_RESOLVER_HEADER)
    yzlite_info("Generating OpResolver from ${MODEL_PROFILER_MODEL}" TAG yzlite_model_profiler)
    yzlite_add_tflite_model_op_resolver_header(yzlite_model_profiler ${MODEL_PROFILER_MODEL})
endif()


# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_model_profiler)
