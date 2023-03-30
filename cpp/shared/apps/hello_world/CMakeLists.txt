
# Define the hello_world executable
add_executable(yzlite_hello_world
    main.cc
)

# Generate the exe output files (if necessary for the build platform)
yzlite_add_exe_targets(yzlite_hello_world)

target_link_libraries(yzlite_hello_world
PRIVATE
    ${YZLITE_PLATFORM}
)

# There's also:
# yzlite_info()
# yzlite_warn()
# yzlite_error()
# These levels are controlled by the CMake variable:
# YZLITE_CMAKE_LOG_LEVEL, e.g.:
# yzlite_set(YZLITE_CMAKE_LOG_LEVEL debug)
yzlite_debug("Example CMake debug msg" TAG yzlite_hello_world)