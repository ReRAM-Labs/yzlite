cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(yzlite
        VERSION 1.0.0
        DESCRIPTION "Yizhu Technology ReRAM YZLite"
        LANGUAGES C CXX ASM
)
export (PACKAGE yzlite)


# Cache the YZLITE binary build directory
set(YZLITE_BINARY_DIR ${PROJECT_BINARY_DIR} CACHE INTERNAL "YZLITE binary build directory")
# Include the YZLITE utilities script
include(${CMAKE_CURRENT_LIST_DIR}/cpp/tools/cmake/utilities.cmake)

# Update the CMake module path
# so that we can find other yzlite packages via: find_package()
yzlite_update_module_path("${CMAKE_CURRENT_LIST_DIR}/cpp/tools/cmake")

# Check if the yzlite is being used internally or externally
if("${CMAKE_SOURCE_DIR}" STREQUAL "${PROJECT_SOURCE_DIR}")
  yzlite_info("Building from yzlite root repository")

  # Update the CMake output directory so built executables
  # and DLL are store in the root of the build directory
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} CACHE INTERNAL "Build output directory")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} CACHE INTERNAL "Build output directory")
  set(CMAKE_FIND_PACKAGE_RESOLVE_SYMLINKS ON CACHE INTERNAL "")
  set(CMAKE_INSTALL_LIBDIR ${PROJECT_BINARY_DIR})

  if(NOT DEFINED CPM_SOURCE_CACHE)
      set(CPM_SOURCE_CACHE "${CMAKE_CURRENT_LIST_DIR}/cpp/shared" CACHE INTERNAL "CPM cache directory")
  endif()

else()  # else IF this is being built from an external CMake project

  if (DEFINED CACHE{CPM_SOURCE_CACHE})
    set(CPM_SOURCE_CACHE "${CMAKE_CURRENT_LIST_DIR}/cpp/shared") # Update the variable locally if it's already defined in cache
  else()
    set(CPM_SOURCE_CACHE "${CMAKE_CURRENT_LIST_DIR}/cpp/shared" CACHE INTERNAL "CPM Cache directory")
  endif()

endif() # IF is master project

if(NOT YZLITE_USER_OPTIONS)
  set(YZLITE_USER_OPTIONS ${CMAKE_CURRENT_LIST_DIR}/user_options.cmake)
endif()

if(EXISTS "${YZLITE_USER_OPTIONS}" AND NOT YZLITE_NO_USER_OPTIONS)
  yzlite_info("YZLITE_USER_OPTIONS=${YZLITE_USER_OPTIONS}")
  include("${YZLITE_USER_OPTIONS}")
endif()

if(YZLITE_ADDITIONAL_OPTIONS)
  yzlite_info("YZLITE_ADDITIONAL_OPTIONS=${YZLITE_ADDITIONAL_OPTIONS}")
  foreach(option_path IN LISTS YZLITE_ADDITIONAL_OPTIONS)
    include("${option_path}")
  endforeach()
endif()

# Set the default YZLITE Cmake log level
if(NOT DEFINED YZLITE_CMAKE_LOG_LEVEL)
  yzlite_set(YZLITE_CMAKE_LOG_LEVEL info)
  yzlite_debug("Default YZLITE_CMAKE_LOG_LEVEL=${YZLITE_CMAKE_LOG_LEVEL}")
endif()

# Include the Cmake Package Manager script
# NOTE: This must be included AFTER settting the
#        CPM_SOURCE_CACHE variable from above
include(${CMAKE_CURRENT_LIST_DIR}/cpp/tools/cmake/CPM.cmake)

###################################################
# Add the YZLITE platform package (if necessary)
yzlite_add_platform_package()


###################################################
# If no specific build target was given
# then automatically include all known packages
#
# HINT: To build a Python wrapper:
#
# Create the file <yzlite root>/user_options.cmake and add:
# yzlite_set(YZLITE_TARGET yzlite_audio_feature_generator_wrapper)
# yzlite_set(YZLITE_TARGET yzlite_tflite_micro_wrapper)
# or
# yzlite_set(YZLITE_TARGET yzlite_mvp_wrapper)
#
# OR:
# To the CMake build string, add:
# YZLITE_TARGET=yzlite_audio_feature_generator_wrapper
# YZLITE_TARGET=yzlite_tflite_micro_wrapper
# or
# YZLITE_TARGET=yzlite_mvp_wrapper

yzlite_get(YZLITE_TARGET)
if(NOT ("${YZLITE_TARGET}" STREQUAL "" OR "${YZLITE_TARGET}" STREQUAL "all"))
  yzlite_info("YZLITE_TARGET=${YZLITE_TARGET}")
  yzlite_find_package(${YZLITE_TARGET})

else()

  find_package(yzlite_hello_world)
  find_package(yzlite_model_profiler)
  find_package(yzlite_audio_classifier)
  find_package(yzlite_image_classifier)
  find_package(yzlite_fingerprint_authenticator)
  find_package(yzlite_ble_audio_classifier)

endif()

