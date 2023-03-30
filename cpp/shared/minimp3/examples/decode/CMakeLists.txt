

find_package(yzlite_minimp3 REQUIRED)


# Define the hello_world executable
add_executable(yzlite_minimp3_example
    main.cc
)  

# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_minimp3_example)

target_link_libraries(yzlite_minimp3_example
PRIVATE 
    ${YZLITE_PLATFORM}
    yzlite::minimp3
)

