# YZLITE CMake Utilities
#
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)


####################################################################
# Check if this util function has already been included
get_property(YZLITE_UTILITIES_INCLUDED GLOBAL "" PROPERTY YZLITE_UTILITIES_INCLUDED SET)
if (YZLITE_UTILITIES_INCLUDED)
  return()
endif()


####################################################################
# Define common global variables
#

# YZLITE_CPP_DIR = <yzlite root>/cpp
get_filename_component(YZLITE_CPP_DIR ${CMAKE_CURRENT_LIST_DIR}/../.. ABSOLUTE CACHE)
# YZLITE_DIR = <yzlite root>/yzlite
get_filename_component(YZLITE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../yzlite ABSOLUTE CACHE)
#  YZLITE_CPP_UTILS_DIR = <yzlite root>/cpp/tools/utils
set(YZLITE_CPP_UTILS_DIR "${YZLITE_CPP_DIR}/tools/utils" CACHE INTERNAL "YZLITE C++ build scripts directory")


####################################################################
# yzlite_get_log_level
#
# Get the current logging level
#
# output_var - Variable to hold log level
function(yzlite_get_log_level output_var)
  yzlite_get(YZLITE_CMAKE_LOG_LEVEL)
  set(_level ${YZLITE_CMAKE_LOG_LEVEL})

  if(NOT YZLITE_CMAKE_LOG_LEVEL)
    set(_level "info")
  endif()

  string(TOLOWER ${_level} _level)
  set(${output_var} ${_level} PARENT_SCOPE)
endfunction()


####################################################################
# yzlite_debug
#
# Print debug message
#
# msg - Debug message
# TAG - Optional tag to prepend to msg
function(yzlite_debug msg)
  cmake_parse_arguments(_PARSED "" "TAG" "" "${ARGN}")
  yzlite_get_log_level(_yzlite_log_level)
  set(_yzlite_log_levels debug)
  if(${_yzlite_log_level} IN_LIST _yzlite_log_levels)
    if(_PARSED_TAG)
      set(tag "[${_PARSED_TAG}]")
    endif()
    message(STATUS "[YZLITE]${tag} ${msg}")
  endif()
endfunction()


####################################################################
# yzlite_info
#
# Print info message
#
# msg - Info message
# TAG - Optional tag to prepend to msg
function(yzlite_info msg)
  cmake_parse_arguments(_PARSED "" "TAG" "" "${ARGN}")
  yzlite_get_log_level(_yzlite_log_level)
  set(_yzlite_log_levels debug info)
  if(${_yzlite_log_level} IN_LIST _yzlite_log_levels)
    if(_PARSED_TAG)
      set(tag "[${_PARSED_TAG}]")
    endif()
    message(STATUS "[YZLITE]${tag} ${msg}")
  endif()
endfunction()


####################################################################
# yzlite_warn
#
# Print warning message
#
# msg - Warning message
# TAG - Optional tag to prepend to msg
function(yzlite_warn msg)
  cmake_parse_arguments(_PARSED "" "TAG" "" "${ARGN}")
  yzlite_get_log_level(_yzlite_log_level)
  set(_yzlite_log_levels debug info warn warning)
  if(${_yzlite_log_level} IN_LIST _yzlite_log_levels)
    if(_PARSED_TAG)
      set(tag "[${_PARSED_TAG}]")
    endif()
    message(STATUS "[YZLITE]${tag} WARN: ${msg}")
  endif()
endfunction()


####################################################################
# yzlite_error
#
# Print error message
#
# msg - Error message
# TAG - Optional tag to prepend to msg
function(yzlite_error msg)
  cmake_parse_arguments(_PARSED "" "TAG" "" "${ARGN}")
  if(_PARSED_TAG)
    set(tag "[${_PARSED_TAG}]")
  endif()
  message(FATAL_ERROR "[YZLITE]${tag} ${msg}")
endfunction()


####################################################################
# yzlite_dump_cmake_variables
#
# Dump all CMake varaibles. Useful for debugging scripts
function(yzlite_dump_cmake_variables)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
            if (NOT MATCHED)
                continue()
            endif()
        endif()
        yzlite_info("${_variableName}=${${_variableName}}")
    endforeach()
endfunction()


####################################################################
# yzlite_set
#
# Set a global variable.
# NOTE: The updated variable is locally available after this is invoked.
#
# key - Name of variable
# value - Value of variable
# DEFAULT - If the "DEFAULT" keyword is provided as argument, then only set the variable if it hasn't already been defined
# ECHO - Optional, print key/value
function(yzlite_set key value)
  cmake_parse_arguments(YZLITE_ARGS "DEFAULT;ECHO" "" "" "${ARGN}")
  if (YZLITE_ARGS_DEFAULT)
    if(DEFINED ${key})
      set(${key} ${${key}} PARENT_SCOPE)
      return()
    endif()
  endif()

  set_property(GLOBAL PROPERTY ${key} "${value}")
  get_property(_value GLOBAL PROPERTY ${key})

  if(YZLITE_ARGS_ECHO)
    yzlite_info("${key}=${_value}")
  endif()
  set(${key} ${_value} PARENT_SCOPE)
endfunction()

####################################################################
# yzlite_get
#
# Get a global variable
#
# key - Name of variable
#
# Options:
# DEFAULT <value>  - Optional, value to set variable if it is not defined
# ECHO - Optional, print key/value
function(yzlite_get key)
  cmake_parse_arguments(YZLITE_ARGS "ECHO" "DEFAULT" "" "${ARGN}")

  unset(_value)
  get_property(_${key}_is_set GLOBAL PROPERTY ${key} SET)
  if(NOT _${key}_is_set)
    # First see if the variable is in the cache
    if(DEFINED CACHE{${key}})
      set_property(GLOBAL PROPERTY ${key} $CACHE{${key}})
      get_property(_value GLOBAL PROPERTY ${key})
    else()
      # Otherwise, see if a default was given
      if (DEFINED YZLITE_ARGS_DEFAULT)
        set_property(GLOBAL PROPERTY ${key} ${YZLITE_ARGS_DEFAULT})
        get_property(_value GLOBAL PROPERTY ${key})
      endif()
    endif()
  else()
    get_property(_value GLOBAL PROPERTY ${key})
  endif()

  if(DEFINED _value)
    if(YZLITE_ARGS_ECHO)
      yzlite_info("${key}=${_value}")
    endif()
    set(${key} ${_value} PARENT_SCOPE)
  endif()
endfunction()

####################################################################
# yzlite_append
#
# Append a value to a global list variable
# NOTE:
# - Duplicates are automatically removed
# - The updated list is locally available after this is invoked
#
# key - Variable key
# value - Value(s) to append to list
function(yzlite_append key)
  get_property(_value GLOBAL PROPERTY ${key})
  list(APPEND _value "${ARGN}")
  list(REMOVE_DUPLICATES _value)
  set_property(GLOBAL PROPERTY ${key} "${_value}")
  set(${key} "${_value}" PARENT_SCOPE)
endfunction()


####################################################################
# yzlite_remove
#
# Remove item for list
# NOTE:
# - The updated list is locally available after this is invoked
#
# key - Variable key
# value - Value to remove from list
function(yzlite_remove key value)
  get_property(_list GLOBAL PROPERTY ${key})
  list(REMOVE_ITEM _list ${value})
  set_property(GLOBAL PROPERTY ${key} "${_list}")
  set(${key} ${_list} PARENT_SCOPE)
endfunction()


####################################################################
# yzlite_contains
#
# Return if the given list contains the given target
# NOTE: Comparsion is case-insensitive, the target can be a
# CMake list OR a comma-separated string
#
# key - Key of variable to searcch
# target - Target or list of targets to check
# result_variable - Variable to populate, ON if target found, OFF else
function(yzlite_contains key target result_variable)
  get_property(_list GLOBAL PROPERTY ${key})
  if(NOT _list OR NOT target)
    set(${result_variable} OFF PARENT_SCOPE)
    return()
  endif()
  string(REPLACE "," ";" _list ${_list})
  foreach(list_item ${_list})
    string(TOLOWER "${list_item}" list_item)
    foreach(target_item ${target})
      string(TOLOWER "${target_item}" target_item)
      #yzlite_info("list_item=${list_item} target_item=${target_item}")
      if("${target_item}" STREQUAL "${list_item}")
        set(${result_variable} ON PARENT_SCOPE)
        return()
      endif()
    endforeach()
  endforeach()
  set(${result_variable} OFF PARENT_SCOPE)
endfunction()


####################################################################
# yzlite_define
#
# Define a global variable
# NOTE: The updated variable is locally available after this is invoked.
#
# key - Name of variable
# description - Description of the variable
#
# Options:
# DEFAULT <value>  - Optional, value to set variable if it is not defined
function(yzlite_define key description)
  cmake_parse_arguments(YZLITE_ARGS "" "DEFAULT" "" "${ARGN}")

  define_property(GLOBAL PROPERTY ${key}
      BRIEF_DOCS  ${description}
      FULL_DOCS   ${description}
  )

  # First get the variable in-case it needs to be loaded from the cache
  yzlite_get(${key})

  # Check if the variable has been set
  get_property(${key}_is_set GLOBAL PROPERTY ${key} SET)
  if(NOT ${key}_is_set)
    # If not, set the variable with the default value if one was given
    if (DEFINED YZLITE_ARGS_DEFAULT)
      set_property(GLOBAL PROPERTY ${key} ${YZLITE_ARGS_DEFAULT})
      get_property(_value GLOBAL PROPERTY ${key})
      set(${key}_is_set ON)
    endif()
  else()
    get_property(_value GLOBAL PROPERTY ${key})
  endif()

  if(${key}_is_set)
    set(${key} ${_value} PARENT_SCOPE)
  endif()
endfunction()

####################################################################
# yzlite_copy
#
# Copy a file from the src to the dst
#
# src - Source file path
# dst - Destination path
function(yzlite_copy dst src)
  if(NOT EXISTS "${dst}" OR "${src}" IS_NEWER_THAN "${dst}")
    get_filename_component(dst_dir ${dst} DIRECTORY)
    get_filename_component(src_name ${src} NAME)
    file(COPY ${src} DESTINATION ${dst_dir})
    file(RENAME ${dst_dir}/${src_name} ${dst})
  endif()
endfunction()

####################################################################
# yzlite_git_hash
#
# Populate the git_hash variable with the shorthand
# git hash of the given directory
#
# directory - Directory to retrieve git hash from
# git_hash - Variable to populate with git hash
function(yzlite_git_hash directory git_hash)
  execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${directory}
    OUTPUT_VARIABLE _hash
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  set(${git_hash} ${_hash} PARENT_SCOPE)
endfunction()

####################################################################
# yzlite_git_version
#
# Populate the git_version variable with the shorthand
# git hash and date of the given directory.
#
# This runs the following command:
# git show -s --date=short --pretty='%h (%ad)'
#
# which has an output similar to:
# 3a3e27f9 (2022-06-06)
#
# directory - Directory to retrieve git hash from
# git_version - Variable to populate with git hash & version
function(yzlite_git_version directory git_version)
  set(_cmd_arg "--pretty=%h (%ad)")
  execute_process(
    COMMAND git show -s --date=short ${_cmd_arg}
    WORKING_DIRECTORY ${directory}
    OUTPUT_VARIABLE _hash
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  set(${git_version} ${_hash} PARENT_SCOPE)
endfunction()

####################################################################
# yzlite_update_module_path
#
# Update the CMAKE_MODULE_PATH to enable finding packages
# at the given directory via:
# find_package()
#
# NOTE: This will remove duplicates and also
#       update CMAKE_MODULE_PATH in the parent scope if necessary
#
# directory - Directory to append to search path
macro(yzlite_update_module_path directory)
  get_filename_component(abs_path ${directory} ABSOLUTE)
  yzlite_info("Appending module path: ${abs_path}")
  list(APPEND CMAKE_MODULE_PATH ${abs_path})
  list(REMOVE_DUPLICATES CMAKE_MODULE_PATH)
  # Also set the module paths in the parent scope if necessary
  get_directory_property(_has_parent PARENT_DIRECTORY)
  if(_has_parent)
    yzlite_set(YZLITE_CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} PARENT_SCOPE)
  endif()
  unset(_has_parent)
endmacro()


####################################################################
# yzlite_list_append
#
# Append one or more values to the given list.
# Duplicates will NOT be appended.
#
# list - Name of list variable to update in-place
# values - One or more values to append to list (automatically ignores duplicates)
# LIST_IS_STRING - Optional, use if the given list is a space-delimited string
function(yzlite_list_append list values)
  cmake_parse_arguments(PARSED "LIST_IS_STRING" "" "" "${ARGN}")

  string(REPLACE " " ";" _list "${${list}}")
  string(REPLACE " " ";" _values "${values}")

  foreach(new_value ${_values})
    set(_found OFF)

    foreach(existing_value ${_list})
      if(${new_value} STREQUAL ${existing_value})
        set(_found ON)
        break()
      endif()
    endforeach(existing_value)

    if(NOT _found)
      list(APPEND _list ${new_value})
    endif()

  endforeach(new_value)

  if(PARSED_LIST_IS_STRING)
    string(REPLACE ";" " " _list "${_list}")
    set(${list} "${_list}" PARENT_SCOPE)
  else()
    set(${list} ${_list} PARENT_SCOPE)
  endif()
endfunction()


####################################################################
# yzlite_list_remove
#
# Remove one or more values to the given list.
#
# list - Name of list variable to update in-place
# values - One or more values to remove from list
# LIST_IS_STRING - Optional, use if the given list is a space-delimited string
# WILDCARD - Optional, indicates the values to remove contain wildcards
function(yzlite_list_remove list values)
  cmake_parse_arguments(PARSED "LIST_IS_STRING;WILDCARD" "" "" "${ARGN}")

  string(REPLACE " " ";" _list "${${list}}")
  string(REPLACE " " ";" _values "${values}")

  foreach(new_value ${_values})
    if(NOT PARSED_WILDCARD)
      list(REMOVE_ITEM _list ${new_value})
    else()
      foreach(existing_value ${_list})
        if(existing_value MATCHES ${new_value})
          list(REMOVE_ITEM _list ${existing_value})
        endif()
      endforeach(existing_value)
    endif()
  endforeach(new_value)

  if(PARSED_LIST_IS_STRING)
    string(REPLACE ";" " " _list "${_list}")
    set(${list} "${_list}" PARENT_SCOPE)
  else()
    set(${list} ${_list} PARENT_SCOPE)
  endif()
endfunction()


####################################################################
# yzlite_append_global_cxx_defines
#
# Append to the global C/C++ build defines (i.e. CMAKE_C_FLAGS and CMAKE_CXX_FLAGS).
# The defines will be made available to ALL C/C++ source files
#
# NOTE: -D is automatically prepended to the defines.
#       See yzlite_append_global_cxx_flags() to append flags
#
# defines - List of define to append
function(yzlite_append_global_cxx_defines)
  set(_defines "${ARGN}")
  list(TRANSFORM _defines PREPEND "-D")
  set(_prev_CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
  set(_prev_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

  yzlite_list_append(CMAKE_C_FLAGS ${_defines} LIST_IS_STRING)
  yzlite_list_append(CMAKE_CXX_FLAGS ${_defines} LIST_IS_STRING)

  if(NOT "${_prev_CMAKE_C_FLAGS}" STREQUAL "${CMAKE_C_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
  if(NOT "${_prev_CMAKE_CXX_FLAGS}" STREQUAL "${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
endfunction()

####################################################################
# yzlite_append_global_cxx_flags
#
# Append to the global C/C++ build flags (i.e. CMAKE_C_FLAGS and CMAKE_CXX_FLAGS).
# The flags will be made available to ALL C/C++ source files
#
# NOTE: This helps to ensure no duplicate flags are added
#
# flags - Flags to append
# ASM - Optional, also append flags to CMAKE_ASM_FLAGS
function(yzlite_append_global_cxx_flags flags)
  cmake_parse_arguments(PARSED "ASM" "" "" "${ARGN}")
  set(_prev_CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
  set(_prev_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
  set(_prev_CMAKE_ASM_FLAGS ${CMAKE_ASM_FLAGS})

  yzlite_list_append(CMAKE_C_FLAGS ${flags} LIST_IS_STRING)
  yzlite_list_append(CMAKE_CXX_FLAGS ${flags} LIST_IS_STRING)
  if(PARSED_ASM)
    yzlite_list_append(CMAKE_ASM_FLAGS ${flags} LIST_IS_STRING)
  endif()

  if(NOT "${_prev_CMAKE_C_FLAGS}" STREQUAL "${CMAKE_C_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
  if(NOT "${_prev_CMAKE_CXX_FLAGS}" STREQUAL "${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
  if(NOT "${_prev_CMAKE_ASM_FLAGS}" STREQUAL "${CMAKE_ASM_FLAGS}")
    set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
endfunction()

####################################################################
# yzlite_remove_global_cxx_flags
#
# Remove from the global C/C++ build flags (i.e. CMAKE_C_FLAGS and CMAKE_CXX_FLAGS).
# The flags will be removed for ALL C/C++ source files
#
# flags - Flags to remove
# WILDCARD - Optional, indicates the flags contain wildcards
# ASM - Optional, also remove from CMAKE_ASM_FLAGS
function(yzlite_remove_global_cxx_flags flags)
  set(_prev_CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
  set(_prev_CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
  set(_prev_CMAKE_ASM_FLAGS ${CMAKE_ASM_FLAGS})
  cmake_parse_arguments(PARSED "WILDCARD;ASM" "" "" "${ARGN}")

  if(PARSED_WILDCARD)
    yzlite_list_remove(CMAKE_C_FLAGS ${flags} LIST_IS_STRING WILDCARD)
    yzlite_list_remove(CMAKE_CXX_FLAGS ${flags} LIST_IS_STRING WILDCARD)
    if(PARSED_ASM)
      yzlite_list_remove(CMAKE_ASM_FLAGS ${flags} LIST_IS_STRING WILDCARD)
    endif()
  else()
    yzlite_list_remove(CMAKE_C_FLAGS ${flags} LIST_IS_STRING)
    yzlite_list_remove(CMAKE_CXX_FLAGS ${flags} LIST_IS_STRING)
    if(PARSED_ASM)
      yzlite_list_remove(CMAKE_ASM_FLAGS ${flags} LIST_IS_STRING)
    endif()
  endif()

  if(NOT "${_prev_CMAKE_C_FLAGS}" STREQUAL "${CMAKE_C_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
  if(NOT "${_prev_CMAKE_CXX_FLAGS}" STREQUAL "${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
  if(NOT "${_prev_CMAKE_ASM_FLAGS}" STREQUAL "${CMAKE_ASM_FLAGS}")
    set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
endfunction()


####################################################################
# yzlite_append_global_linker_flags
#
# Append to the global C/C++ linker build flags (i.e. CMAKE_EXE_LINKER_FLAGS).
# The flags will be made available to ALL C/C++ source files
#
# flags - Flags to append
function(yzlite_append_global_linker_flags flags)
  set(_prev_CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS})

  yzlite_list_append(CMAKE_EXE_LINKER_FLAGS ${flags} LIST_IS_STRING)

  if(NOT "${_prev_CMAKE_EXE_LINKER_FLAGS}" STREQUAL "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}" CACHE INTERNAL "" FORCE)
  endif()
endfunction()


####################################################################
# yzlite_discover_host_os
#
# Discover the current host OS and populate cache variables:
# HOST_OS = windows/linux/osx
# HOST_OS_IS_WINDOWS = ON/unset
# HOST_OS_IS_LINUX = ON/unset
# HOST_OS_IS_OSX = ON/unset
function(yzlite_discover_host_os)
  if(CMAKE_HOST_SYSTEM_NAME STREQUAL Windows)
    set(HOST_OS "windows" CACHE INTERNAL "Host operating system")
    set(HOST_OS_IS_WINDOWS ON CACHE INTERNAL "Host operating system is Windows")
  elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Linux)
    set(HOST_OS "linux" CACHE INTERNAL "Host operating system")
    set(HOST_OS_IS_LINUX ON CACHE INTERNAL "Host operating system is Linux")
  elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL Darwin)
    set(HOST_OS "osx" CACHE INTERNAL "Host operating system")
    set(HOST_OS_IS_OSX ON CACHE INTERNAL "Host operating system is OSX")
  else()
    yzlite_error("Unknown operating system ${CMAKE_HOST_SYSTEM_NAME}")
  endif()
endfunction()


####################################################################
# yzlite_add_package_directory
#
# This is used by the Find<package>.cmake
# scripts to include packages within the YZLITE wrapper's directory
#
# Arguments:
# package_name - The name of the package
# package_path - Package to package relative to YZLITE_CPP_DIR
#                OR absolute path which is treated as an external project
#
# Options:
# INCLUDE_IN_ALL - If given, then include this directory in the ALL build target
macro(yzlite_add_package_directory package_name package_path)
  cmake_parse_arguments(YZLITE_ARGS "INCLUDE_IN_ALL" "" "" "${ARGN}")

  get_property(${package_name}_FOUND GLOBAL PROPERTY ${package_name}_FOUND)
  if(NOT ${package_name}_FOUND)
    set(_saved_CPM_SOURCE_CACHE ${CPM_SOURCE_CACHE})
    set(CPM_SOURCE_CACHE ${YZLITE_CPP_DIR}/shared)

    if(IS_ABSOLUTE ${package_path})
      if(EXISTS "${package_path}/CMakeLists.txt")
        get_filename_component(_path ${package_path} ABSOLUTE)
        yzlite_debug("Adding ${package_name} -> ${_path}")
        set_property(GLOBAL PROPERTY ${package_name}_FOUND ON)
        set(${package_name}_FOUND ON)
        if(YZLITE_ARGS_INCLUDE_IN_ALL)
          add_subdirectory(${_path} ${YZLITE_BINARY_DIR}/external/${package_name})
        else()
          add_subdirectory(${_path} ${YZLITE_BINARY_DIR}/external/${package_name} EXCLUDE_FROM_ALL)
        endif()
      else()
        yzlite_error("Package does NOT exist or does not contain a CMakeLists.txt: ${package_name} -> ${package_path}")
      endif()
    else()
      if(EXISTS "${YZLITE_CPP_DIR}/${package_path}/CMakeLists.txt")
        yzlite_debug("Adding ${package_name} -> ${YZLITE_CPP_DIR}/${package_path}")
        set_property(GLOBAL PROPERTY ${package_name}_FOUND ON)
        set(${package_name}_FOUND ON)
        if(YZLITE_ARGS_INCLUDE_IN_ALL)
          add_subdirectory(${YZLITE_CPP_DIR}/${package_path} ${YZLITE_BINARY_DIR}/${package_path})
        else()
          add_subdirectory(${YZLITE_CPP_DIR}/${package_path} ${YZLITE_BINARY_DIR}/${package_path} EXCLUDE_FROM_ALL)
        endif()
      else()
        yzlite_error("YZLITE Package does NOT exist or does not contain a CMakeLists.txt: ${package_name} -> ${YZLITE_CPP_DIR}/${package_path}")
      endif()
    endif()

    set(CPM_SOURCE_CACHE ${_saved_CPM_SOURCE_CACHE})
  endif()

endmacro()


####################################################################
# yzlite_add_platform_package
#
# If necessary, set the cached variable:
# YZLITE_PLATFORM
# with the current host's OS.
# If YZLITE_PLATFORM was specified on the command-line then use that platform
#
# Then find and add the platform package to the build
macro(yzlite_add_platform_package)
  if("${TOOLCHAIN_PREFIX}" MATCHES ".*mingw32.*")
    if(YZLITE_PLATFORM_NAME AND NOT "${YZLITE_PLATFORM_NAME}" MATCHES ".*windows.*")
      yzlite_warn("\n\n\n   *** Using Windows toolchain but YZLITE_PLATFORM_NAME=${YZLITE_PLATFORM_NAME}. Forcing Windows platform\n\n")
      yzlite_set(YZLITE_PLATFORM_NAME OFF)
      set(YZLITE_PLATFORM OFF)
    endif()
  elseif("${TOOLCHAIN_PREFIX}" MATCHES ".*linux.*")
    if(YZLITE_PLATFORM_NAME AND NOT "${YZLITE_PLATFORM_NAME}" MATCHES ".*linux.*")
      yzlite_warn("\n\n\n    *** Using Linux toolchain but YZLITE_PLATFORM_NAME=${YZLITE_PLATFORM_NAME}. Forcing Linux platform\n\n")
      yzlite_set(YZLITE_PLATFORM_NAME OFF)
      set(YZLITE_PLATFORM OFF)
    endif()
  elseif("${TOOLCHAIN_PREFIX}" MATCHES ".*arm.*")
    if(NOT YZLITE_PLATFORM_NAME)
      yzlite_error("\nMust specify YZLITE_PLATFORM_NAME when using the ARM toolchain\n \
i.e. Create the file: <yzlite repo root>/user_options.cmake\n \
and add:\n \
# Set the name of your target embedded platform:\n \
yzlite_set(YZLITE_PLATFORM_NAME brd2601)\n \
")
    endif()
  endif()


  if(YZLITE_PLATFORM AND YZLITE_PLATFORM_NAME)
    if(NOT "${YZLITE_PLATFORM}" MATCHES ".*${YZLITE_PLATFORM_NAME}.*")
      yzlite_warn("YZLITE_PLATFORM=${YZLITE_PLATFORM} and YZLITE_PLATFORM_NAME=${YZLITE_PLATFORM_NAME}. Resetting YZLITE_PLATFORM")
      set(YZLITE_PLATFORM OFF)
    endif()
  endif()

  # If a platform target has NOT been specified
  if(NOT YZLITE_PLATFORM)
    # IF the platform name HAS been specified
    if(YZLITE_PLATFORM_NAME)
      yzlite_debug("Searching for platform: ${YZLITE_PLATFORM_NAME}")
      yzlite_find_package("^.*_platform_${YZLITE_PLATFORM_NAME}$" REQUIRED FIND_ONLY TARGET_VARIABLE YZLITE_PLATFORM)
    else()
      # Otherwise, use the current host's platform
      # And update the global variable
      set(YZLITE_PLATFORM "yzlite_platform_${HOST_OS}")
    endif()
    yzlite_debug("YZLITE_PLATFORM=${YZLITE_PLATFORM}")
  endif()

  set(YZLITE_PLATFORM ${YZLITE_PLATFORM} CACHE INTERNAL "YZLITE platform target")

  # Find and add the platform package to the build
  yzlite_get(${YZLITE_PLATFORM}_ADDED)
  if(NOT ${YZLITE_PLATFORM}_ADDED)
    yzlite_set(${YZLITE_PLATFORM}_ADDED ON)

    # Find the platform package
    find_package(${YZLITE_PLATFORM} REQUIRED)

    # Ensure the platform defines: YZLITE_PLATFORM_NAME
    yzlite_get(YZLITE_PLATFORM_NAME)
    if(NOT YZLITE_PLATFORM_NAME)
      yzlite_error("Your platform must specify: yzlite_set(YZLITE_PLATFORM_NAME <name>)")
    endif()
    yzlite_info("YZLITE_PLATFORM_NAME=${YZLITE_PLATFORM_NAME}")

    yzlite_get(YZLITE_PLATFORM_IS_EMBEDDED)
    if(NOT DEFINED YZLITE_PLATFORM_IS_EMBEDDED)
      # If the platform doesn't specify whether it's embedded or not
      # then default to it being embedded
      yzlite_set(YZLITE_PLATFORM_IS_EMBEDDED ON)
      yzlite_debug("Defaulting to YZLITE_PLATFORM_IS_EMBEDDED: ON")
    else()
      yzlite_debug("YZLITE_PLATFORM_IS_EMBEDDED: ${YZLITE_PLATFORM_IS_EMBEDDED}")
    endif()
    yzlite_get(YZLITE_CPU_CLOCK)
    if(NOT YZLITE_CPU_CLOCK)
      yzlite_error("Platform must specify YZLITE_CPU_CLOCK variable")
    endif()
    yzlite_info("YZLITE_CPU_CLOCK=${YZLITE_CPU_CLOCK}Hz")

    if(YZLITE_PLATFORM_IS_EMBEDDED AND NOT ${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
      yzlite_error("YZLITE_PLATFORM_NAME=${YZLITE_PLATFORM_NAME} but NOT using ARM toolchain, you probably need to switch toolchains or comment out YZLITE_PLATFORM_NAME in user_options.cmake. You likely need to clean your build directory as well")
    endif()
    set(YZLITE_PREVIOUS_PLATFORM_NAME ${YZLITE_PLATFORM_NAME} CACHE STRING "Name of last built platform")

    # Load any platform-specific settings
    if(COMMAND yzlite_platform_load_options)
      yzlite_debug("Loading platform options")
      yzlite_platform_load_options()
    endif()

  endif()

endmacro()


####################################################################
# yzlite_find_package
#
# Use a Python script to search the YZLITE and CMAKE_MODULE_PATH for a CMakeLists.txt
# that has the line:
# project(<name>)
# add_executable(<name>)
# add_library(<name>)
#
# OR a file named: Find<name>.txt
#
# Then try to include the resolved target name with find_package()
# otherwise manually include the subdirectory:
# add_subdirectory(<found dir>)
#
# NOTE: <name> can be a CMake target or a regex for a target
#
# Arguments:
# name - CMake package name or target which can optionally be a regex
#
# Optional arguments:
# REQUIRED - Throw an error if package isn't found
# QUIET - Don't print any message if package isn't found
# TARGET_VARIABLE <var> - Variable to hold found target
# FIND_ONLY - Only find the package, do NOT add it
#
macro(yzlite_find_package name)
  cmake_parse_arguments(_ARGS "REQUIRED;QUIET;FIND_ONLY" "TARGET_VARIABLE" "" "${ARGN}")

  # First try to find the package using the normal method
  find_package(${name} QUIET)

  if(NOT ${name}_FOUND)
    # Else try to find the package using a Python script
    yzlite_load_python()
    yzlite_get(YZLITE_TARGET_PATH)
    yzlite_get(YZLITE_PACKAGE_PATHS)
    execute_process(
      COMMAND ${PYTHON_EXECUTABLE} ${YZLITE_CPP_UTILS_DIR}/find_package_with_target.py "${name}" --paths "${CMAKE_MODULE_PATH};${YZLITE_PACKAGE_PATHS}"
      RESULT_VARIABLE result
      OUTPUT_VARIABLE target_and_dir
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(result)
      if(_ARGS_REQUIRED)
        yzlite_error("Failed to find package in YZLITE with target: ${name} Search paths: ${CMAKE_MODULE_PATH}")
      elseif(NOT _ARGS_QUIET)
        yzlite_warn("Failed to find package in YZLITE with target: ${name} Search paths: ${CMAKE_MODULE_PATH}")
      endif()
    else()
      list(GET target_and_dir 0 target)
      list(GET target_and_dir 1 package_dir)

      if(NOT _ARGS_FIND_ONLY)
        yzlite_debug("Including ${target} -> ${package_dir}")

        # Try to find the package one more time using the resolved target
        find_package(${target} QUIET)

        # Otherwise, manually include the package
        if(NOT ${target}_FOUND)
          add_subdirectory(${package_dir} ${YZLITE_BINARY_DIR}/external)
          set(${target}_FOUND ON)
        endif()
      endif()

      if(_ARGS_TARGET_VARIABLE)
        set(${_ARGS_TARGET_VARIABLE} ${target})
      endif()

    endif()
  endif()
endmacro()


####################################################################
# yzlite_add_exe_targets
#
# Add additional targets to executable
# For instance, this may add targets to generated
# embedded binary files from the application output file.
# This might also add targets for downloading the app binary
# to an embedded device.
#
# This should be called by each application's CMakeLists.txt
# See cpp/hello_world/CMakieLists.txt
#
# exe_target - Executable CMake target
macro(yzlite_add_exe_targets exe_target)
  if(COMMAND yzlite_toolchain_add_exe_targets)
    yzlite_toolchain_add_exe_targets(${exe_target})
  endif()

  if(COMMAND yzlite_platform_add_exe_targets)
    yzlite_platform_add_exe_targets(${exe_target})
  endif()
endmacro()


####################################################################
# yzlite_load_python
#
# Find the path to the Python executable.
#
macro(yzlite_load_python)
  get_property(PYTHON_EXECUTABLE_in_cache CACHE PYTHON_EXECUTABLE PROPERTY TYPE)

  if(NOT PYTHON_EXECUTABLE_in_cache)

    yzlite_get(YZLITE_PYTHON_VENV_DIR)
    if(NOT YZLITE_PYTHON_VENV_DIR)
      get_filename_component(YZLITE_PYTHON_VENV_DIR ${YZLITE_DIR}/../.venv ABSOLUTE)
      yzlite_debug("Using local YZLITE_PYTHON_VENV_DIR=${YZLITE_PYTHON_VENV_DIR}")
    else()
      yzlite_debug("Using command-line YZLITE_PYTHON_VENV_DIR=${YZLITE_PYTHON_VENV_DIR}")
    endif()

    if(EXISTS "${YZLITE_PYTHON_VENV_DIR}")
      # Ensure we find the Python in the virtual environment if one exists
      set(Python3_FIND_VIRTUALENV ONLY)
      set(Python3_FIND_STRATEGY LOCATION)
      set(Python3_FIND_REGISTRY NEVER)
      set(Python3_ROOT_DIR "${YZLITE_PYTHON_VENV_DIR}")
      set(ENV{VIRTUAL_ENV} "${YZLITE_PYTHON_VENV_DIR}")
      unset(Python3_FOUND) # Ensure Python is found again
      unset(Python3_Interpreter_FOUND)
      unset(Python3_EXECUTABLE)
    elseif(NOT YZLITE_ALLOW_EXTERNAL_PYTHON_EXECUTABLE)
      yzlite_warn("Directory not found: YZLITE_PYTHON_VENV_DIR=${YZLITE_PYTHON_VENV_DIR}")
    endif()

    find_package(Python3 REQUIRED)

    yzlite_debug("Python executable: ${Python3_EXECUTABLE}")
    yzlite_get(YZLITE_ALLOW_EXTERNAL_PYTHON_EXECUTABLE)
    string(TOLOWER "${Python3_EXECUTABLE}" Python3_EXECUTABLE_lower)
    string(TOLOWER "${YZLITE_PYTHON_VENV_DIR}" YZLITE_PYTHON_VENV_DIR_lower)
    if(NOT YZLITE_ALLOW_EXTERNAL_PYTHON_EXECUTABLE AND NOT "${Python3_EXECUTABLE_lower}" MATCHES "^${YZLITE_PYTHON_VENV_DIR_lower}/.*")
      # If the the compiler hasn't been set yet then we're likely in the toolchain.cmake
      # in this case, just issue a warning
      if(NOT CMAKE_C_COMPILER)
        yzlite_warn("\n\nFailed to find the Python executable in ${YZLITE_PYTHON_VENV_DIR} (Python3_EXECUTABLE=${Python3_EXECUTABLE})\nBe sure to first run:\npython ${yzlite_root_dir}/install_yzlite.py\nOr set the CMake variable: YZLITE_ALLOW_EXTERNAL_PYTHON_EXECUTABLE=ON  (not recommended)\n\n")
      else()
        yzlite_error("\n\nFailed to find the Python executable in ${YZLITE_PYTHON_VENV_DIR} (Python3_EXECUTABLE=${Python3_EXECUTABLE})\nBe sure to first run:\npython ${yzlite_root_dir}/install_yzlite.py\nOr set the CMake variable: YZLITE_ALLOW_EXTERNAL_PYTHON_EXECUTABLE=ON  (not recommended)\n\n")
      endif()
    endif()

    set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE} CACHE INTERNAL "Python executable path")

  endif()
endmacro()


####################################################################
# yzlite_get_recursive_properties
#
# Recursively retrieve all properties for the given target
#
# target - CMake target to retrieve all properties
# output_list - List variable to hold results
function(yzlite_get_recursive_properties property target output_list)
  list(LENGTH target target_count)

  if("${target_count}" STREQUAL "1")
    get_target_property(target_libs ${target} INTERFACE_LINK_LIBRARIES)
  else()
    set(target_libs ${target})
  endif()

  set(properties "")
  foreach(target_lib ${target_libs})
    if (TARGET ${target_lib})
      get_property(is_set TARGET ${target_lib} PROPERTY ${property} SET)
      if(is_set)
        get_target_property(props ${target_lib} ${property})
      endif()
      yzlite_get_recursive_properties(${property} ${target_lib} link_properties)
      list(APPEND properties ${props} ${link_properties})
    endif()
  endforeach()

  list(REMOVE_DUPLICATES properties)
  set(${output_list} ${properties} PARENT_SCOPE)
endfunction()


####################################################################
# yzlite_add_interface_compile_properties
#
# Recursively retrieve all INFERFACE_COMPILE_ properties for the given src_target
# and add them to the dst_target.
#
# dst_target - Target to add src_target's properties
# src_target - Target or list of targets to recursively retrieve
#              INTERFACE_INCLUDE_DIRECTORIES and INFERFACE_COMPILE_ properties
#
# Options:
# PRIVATE, PUBLIC, INTERFACE - One required, specify visiblity of properties on dst_target
function(yzlite_add_interface_compile_properties dst_target)
  cmake_parse_arguments(ARGS "PRIVATE;PUBLIC;INTERFACE" "" "" "${ARGN}")

  if(ARGS_PRIVATE)
    set(VISIBLITY PRIVATE)
  elseif(ARGS_PUBLIC)
    set(VISIBLITY PUBLIC)
  elseif(ARGS_INTERFACE)
    set(VISIBLITY INTERFACE)
  else()
    yzlite_error("Must specify visibility: PRIVATE, PUBLIC, or INTERFACE")
  endif()

  set(src_target ${ARGS_UNPARSED_ARGUMENTS})

  yzlite_get_recursive_properties(INTERFACE_INCLUDE_DIRECTORIES "${src_target}" _interface_props)
  target_include_directories(${dst_target}
  ${VISIBLITY}
    ${_interface_props}
  )

  yzlite_get_recursive_properties(INTERFACE_COMPILE_DEFINITIONS "${src_target}" _interface_props)
  target_compile_definitions(${dst_target}
  ${VISIBLITY}
    ${_interface_props}
  )

  yzlite_get_recursive_properties(INTERFACE_COMPILE_FEATURES "${src_target}" _interface_props)
  target_compile_features(${dst_target}
  ${VISIBLITY}
    ${_interface_props}
  )

  yzlite_get_recursive_properties(INTERFACE_COMPILE_OPTIONS "${src_target}" _interface_props)
  target_compile_options(${dst_target}
  ${VISIBLITY}
    ${_interface_props}
  )

endfunction()


####################################################################
# yzlite_bundle_static_library
#
# Combine all the static libraries required by ${tgt_name} into
# a single static library ${bundled_tgt_name}
#
# Adapted from:
# https://cristianadam.eu/20190501/bundling-together-static-libraries-with-cmake/
#
# tgt_name - Name of CMake target to gather all static libraries
# bundled_tgt_name - Name of generated static library
#
# Options:
# INTERPROCEDURAL_OPTIMIZATION - Enable interprocedural optimization
# EXCLUDED - List of CMake targets to exclude from bundling
function(yzlite_bundle_static_library tgt_name bundled_tgt_name)
  cmake_parse_arguments(ARGS "INTERPROCEDURAL_OPTIMIZATION" "" "EXCLUDED" "${ARGN}")
  list(APPEND static_libs ${tgt_name})

  function(_recursively_collect_dependencies input_target)
    set(_input_link_libraries LINK_LIBRARIES)
    get_target_property(_input_type ${input_target} TYPE)
    if (${_input_type} STREQUAL "INTERFACE_LIBRARY")
      set(_input_link_libraries INTERFACE_LINK_LIBRARIES)
    endif()
    get_target_property(public_dependencies ${input_target} ${_input_link_libraries})
    foreach(dependency IN LISTS public_dependencies)
      if(TARGET ${dependency})
        get_target_property(alias ${dependency} ALIASED_TARGET)
        if (TARGET ${alias})
          set(dependency ${alias})
        endif()
        get_target_property(_type ${dependency} TYPE)
        if (${_type} STREQUAL "STATIC_LIBRARY")
          list(APPEND static_libs ${dependency})
        endif()

        get_property(library_already_added
          GLOBAL PROPERTY _${tgt_name}_static_bundle_${dependency})
        if (NOT library_already_added)
          set_property(GLOBAL PROPERTY _${tgt_name}_static_bundle_${dependency} ON)
          _recursively_collect_dependencies(${dependency})
        endif()
      endif()
    endforeach()
    set(static_libs ${static_libs} PARENT_SCOPE)
  endfunction()

  _recursively_collect_dependencies(${tgt_name})

  list(REMOVE_DUPLICATES static_libs)
  list(REMOVE_ITEM static_libs ${ARGS_EXCLUDED})
  yzlite_info("Bundling: ${static_libs}")
  set(tgt_location ${CMAKE_CURRENT_BINARY_DIR})

  set(bundled_tgt_full_name
    ${tgt_location}/${CMAKE_STATIC_LIBRARY_PREFIX}${bundled_tgt_name}${CMAKE_STATIC_LIBRARY_SUFFIX})

  if (CMAKE_CXX_COMPILER_ID MATCHES "^(Clang|GNU)$")
    file(WRITE ${tgt_location}/${bundled_tgt_name}.ar.in
      "CREATE ${bundled_tgt_full_name}\n" )

    foreach(tgt IN LISTS static_libs)
      file(APPEND ${tgt_location}/${bundled_tgt_name}.ar.in
        "ADDLIB $<TARGET_FILE:${tgt}>\n")
    endforeach()

    file(APPEND ${tgt_location}/${bundled_tgt_name}.ar.in "SAVE\n")
    file(APPEND ${tgt_location}/${bundled_tgt_name}.ar.in "END\n")

    file(GENERATE
      OUTPUT ${tgt_location}/${bundled_tgt_name}.ar
      INPUT ${tgt_location}/${bundled_tgt_name}.ar.in)

    set(ar_tool ${CMAKE_AR})
    if (ARGS_INTERPROCEDURAL_OPTIMIZATION)
      set(ar_tool ${CMAKE_CXX_COMPILER_AR})
    endif()

    add_custom_command(
      COMMAND ${ar_tool} -M < ${tgt_location}/${bundled_tgt_name}.ar
      OUTPUT ${bundled_tgt_full_name}
      COMMENT "Bundling ${bundled_tgt_name}"
      VERBATIM)
  elseif(MSVC)
    find_program(lib_tool lib)

    foreach(tgt IN LISTS static_libs)
      list(APPEND static_libs_full_names $<TARGET_FILE:${tgt}>)
    endforeach()

    add_custom_command(
      COMMAND ${lib_tool} /NOLOGO /OUT:${bundled_tgt_full_name} ${static_libs_full_names}
      OUTPUT ${bundled_tgt_full_name}
      COMMENT "Bundling ${tgt_name} into ${bundled_tgt_name}"
      VERBATIM)
  else()
    yzlite_error("Unsupported compiler")
  endif()

  add_custom_target(${bundled_tgt_name}_generate ALL DEPENDS ${bundled_tgt_full_name})
  add_dependencies(${bundled_tgt_name}_generate ${tgt_name})

  add_library(${bundled_tgt_name} STATIC IMPORTED)
  set_target_properties(${bundled_tgt_name}
    PROPERTIES
      IMPORTED_LOCATION ${bundled_tgt_full_name}
      INTERFACE_INCLUDE_DIRECTORIES $<TARGET_PROPERTY:${tgt_name},INTERFACE_INCLUDE_DIRECTORIES>)
  add_dependencies(${bundled_tgt_name} ${bundled_tgt_name}_generate)

endfunction()

####################################################################
# yzlite_add_tflite_model
#
# Add a .tflite to the given build target.
#
# This does the following:
# 1. Convert given .tflite to C array
# 2. Generate new .c file with .tflite C array
# 3. Append generated .c file as source to build target
#
# The built application can then access the .tflite model
# using the C variables:
# extern "C" const uint8_t sl_tflite_model_array[];
# extern "C" const uint32_t sl_tflite_model_len;
#
# target - CMake build target
# tflite_path - File path to .tflite or YZLITE model name
# MEMORY_SECTION - Optional, specify which memory section the model will be placed
function(yzlite_add_tflite_model target tflite_path)
  cmake_parse_arguments(_PARSED "" "MEMORY_SECTION" "" "${ARGN}")
  yzlite_load_python()

  set(_generated_model_output_path "${YZLITE_BINARY_DIR}/${target}_generated_model.tflite.c")
  if(NOT EXISTS ${_generated_model_output_path})
      file(WRITE ${_generated_model_output_path})
  endif()

  yzlite_get(TFLITE_MICRO_ACCELERATOR)
  if(TFLITE_MICRO_ACCELERATOR)
    set(_accelerator_arg --accelerator ${TFLITE_MICRO_ACCELERATOR})
  endif()

  if(_PARSED_MEMORY_SECTION)
    set(_generate_model_memory_section_arg --memory-section ${_PARSED_MEMORY_SECTION})
  endif()

  add_custom_target(${target}_generate_model
      COMMAND ${PYTHON_EXECUTABLE} ${YZLITE_CPP_UTILS_DIR}/generate_model_header.py "${tflite_path}" --name "sl_tflite_model_array" --length_name "sl_tflite_model_len" --output "${_generated_model_output_path}" ${_accelerator_arg} ${_generate_model_memory_section_arg}
      COMMENT "Generating ${target}_generated_model.tflite.c from ${tflite_path}"
      BYPRODUCTS ${_generated_model_output_path}
  )
  add_dependencies(${target} ${target}_generate_model)

  target_sources(${target}
  PRIVATE
      ${_generated_model_output_path}
  )

endfunction()


####################################################################
# yzlite_add_tflite_model_op_resolver_header
#
# Generates a C++ header that defines a TFLM OpResolver which
# only includes the TFLM kernels used by the given header.
# This can *greatly* reduce the app's flash space.

# This will generate the C++ header:
# <target>_generated_model_op_resolver.hpp
#
# Include this header in your application which will define the variable:
# tflite::MicroMutableOpResolver op_resolver
#
# The op_resolver should be given to the TFLM interpreter during instantiation.
#
# target - CMake build target
# tflite_path - File path to .tflite or YZLITE model name
#
macro(yzlite_add_tflite_model_op_resolver_header target tflite_path)

  yzlite_load_python()

  set(_generated_op_resolver_output_path "${YZLITE_BINARY_DIR}/${target}_generated_model_op_resolver.hpp")
  if(NOT EXISTS ${_generated_op_resolver_output_path})
      file(WRITE ${_generated_op_resolver_output_path})
  endif()

  add_custom_target(${target}_generate_op_resolver_header
      COMMAND ${PYTHON_EXECUTABLE} ${YZLITE_CPP_UTILS_DIR}/generate_model_op_resolver_header.py "${tflite_path}" --name "MyOpResolver" --output "${_generated_op_resolver_output_path}"
      COMMENT "Generating ${target}_yzlite_model_profiler_generated_model_op_resolver.hpp from ${tflite_path}"
      BYPRODUCTS ${_generated_op_resolver_output_path}
  )
  add_dependencies(${target} ${target}_generate_op_resolver_header)

  target_sources(${target}
  PRIVATE
      ${_generated_op_resolver_output_path}
  )
  target_include_directories(${target}
  PRIVATE
    "${YZLITE_BINARY_DIR}"
  )
  unset(_generated_op_resolver_output_path)

endmacro()



# Discover the current host OS
yzlite_discover_host_os()


set_property(GLOBAL PROPERTY YZLITE_UTILITIES_INCLUDED ON)
