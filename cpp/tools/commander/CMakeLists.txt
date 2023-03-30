project(yzlite_commander
        VERSION 1.0.0
        DESCRIPTION "YZTech's Commander Utility"
)
export(PACKAGE ${PROJECT_NAME})


macro(yzlite_commander_add_download_target target)
  yzlite_load_python()
  yzlite_get(YZLITE_PLATFORM_NAME)
  yzlite_get(YZLITE_JLINK_DEVICE)

  if(YZLITE_JLINK_DEVICE)
    set(device_arg --device ${YZLITE_JLINK_DEVICE})
  endif()

  add_custom_target(${target}_download
    COMMAND ${PYTHON_EXECUTABLE} "${YZLITE_DIR}/utils/commander/commander.py" --platform ${YZLITE_PLATFORM_NAME} --path "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}.s37" --clear_end_of_flash ${device_arg}
    DEPENDS ${target}
    COMMENT "Downloading ${target}.s37 to ${YZLITE_PLATFORM_NAME}'s flash ..."
    USES_TERMINAL
  )

endmacro()


macro(yzlite_commander_add_reset_target target)
  yzlite_load_python()
  yzlite_get(YZLITE_PLATFORM_NAME)
  yzlite_get(YZLITE_JLINK_DEVICE)
  yzlite_get(YZLITE_JLINK_SERIAL_NUMBER)
  yzlite_get(YZLITE_DOWNLOAD_RUN_SERIAL_NUMBER)
  yzlite_get(YZLITE_DOWNLOAD_RUN_IP_ADDRESS)

  if(YZLITE_JLINK_DEVICE)
    set(device_arg --device ${YZLITE_JLINK_DEVICE})
  endif()

  if(YZLITE_DOWNLOAD_RUN_SERIAL_NUMBER)
    set(serial_number_arg --serial-number ${YZLITE_DOWNLOAD_RUN_SERIAL_NUMBER})
  elseif(YZLITE_JLINK_SERIAL_NUMBER)
    set(serial_number_arg --serial-number ${YZLITE_JLINK_SERIAL_NUMBER})
  endif()

  if(YZLITE_DOWNLOAD_RUN_IP_ADDRESS)
    set(ip_address_arg --ip-address ${YZLITE_DOWNLOAD_RUN_IP_ADDRESS})
  endif()

  add_custom_target(${target}_reset
    COMMAND ${PYTHON_EXECUTABLE} "${YZLITE_DIR}/utils/commander/commander.py" --platform ${YZLITE_PLATFORM_NAME} --reset ${device_arg} ${serial_number_arg} ${ip_address_arg}
    COMMENT "Resetting ${YZLITE_PLATFORM_NAME} ..."
    USES_TERMINAL
  )

endmacro()


###########################################################
# yzlite_commander_add_download_run_target
#
# Run the given target's firmware application on an embedded device.
#
# target - CMake target name of the embedded executable
#
# Optional arguments:
# TIMEOUT <seconds> - Number of seconds to wait before timing out when using the download_run target
# COMPLETED_MSG <msg> - Console msg app prints to be considered complete
macro(yzlite_commander_add_download_run_target target)
  cmake_parse_arguments(DOWNLOAD_RUN_ARG "" "TIMEOUT;COMPLETED_MSG" "" ${ARGN})
  yzlite_load_python()
  yzlite_get(YZLITE_PLATFORM_NAME)
  yzlite_get(YZLITE_JLINK_DEVICE)
  yzlite_get(YZLITE_JLINK_SERIAL_NUMBER)
  yzlite_get(YZLITE_DOWNLOAD_RUN_SETUP_SCRIPT)
  yzlite_get(YZLITE_DOWNLOAD_RUN_SETUP_SCRIPT_ARGS)
  yzlite_get(YZLITE_DOWNLOAD_RUN_PORT)
  yzlite_get(YZLITE_DOWNLOAD_RUN_BAUD)
  yzlite_get(YZLITE_DOWNLOAD_RUN_SERIAL_NUMBER)
  yzlite_get(YZLITE_DOWNLOAD_RUN_IP_ADDRESS)
  yzlite_get(YZLITE_DOWNLOAD_RUN_TIMEOUT)
  yzlite_get(YZLITE_DOWNLOAD_RUN_RETRIES)
  yzlite_get(YZLITE_DOWNLOAD_RUN_SSH_HOSTNAME)
  yzlite_get(YZLITE_DOWNLOAD_RUN_NO_MASSERASE)
  yzlite_get(YZLITE_DOWNLOAD_RUN_START_MSG)
  yzlite_get(YZLITE_DOWNLOAD_RUN_COMPLETED_MSG)

  if(YZLITE_JLINK_DEVICE)
    set(device_arg --device ${YZLITE_JLINK_DEVICE})
  endif()

  if(YZLITE_DOWNLOAD_RUN_SETUP_SCRIPT)
    set(setup_script_arg --setup-script "${YZLITE_DOWNLOAD_RUN_SETUP_SCRIPT}")
  endif()

  if(YZLITE_DOWNLOAD_RUN_SETUP_SCRIPT_ARGS)
    set(setup_script_args_arg --setup-script-args "${YZLITE_DOWNLOAD_RUN_SETUP_SCRIPT_ARGS}")
  endif()

  if(YZLITE_DOWNLOAD_RUN_PORT)
    set(port_arg --port "${YZLITE_DOWNLOAD_RUN_PORT}")
  endif()

  if(YZLITE_DOWNLOAD_RUN_BAUD)
    set(baud_arg --baud ${YZLITE_DOWNLOAD_RUN_BAUD})
  endif()

  if(YZLITE_DOWNLOAD_RUN_SERIAL_NUMBER)
    set(serial_number_arg --serial-number ${YZLITE_DOWNLOAD_RUN_SERIAL_NUMBER})
  elseif(YZLITE_JLINK_SERIAL_NUMBER)
    set(serial_number_arg --serial-number ${YZLITE_JLINK_SERIAL_NUMBER})
  endif()

  if(YZLITE_DOWNLOAD_RUN_IP_ADDRESS)
    set(ip_address_arg --ip-address ${YZLITE_DOWNLOAD_RUN_IP_ADDRESS})
  endif()

  if(DOWNLOAD_RUN_ARG_TIMEOUT)
    set(timeout_arg --timeout ${DOWNLOAD_RUN_ARG_TIMEOUT})
  elseif(YZLITE_DOWNLOAD_RUN_TIMEOUT)
    set(timeout_arg --timeout ${YZLITE_DOWNLOAD_RUN_TIMEOUT})
  endif()

  if(YZLITE_DOWNLOAD_RUN_RETRIES)
    set(retries_arg --retries ${YZLITE_DOWNLOAD_RUN_RETRIES})
  endif()

  if(YZLITE_DOWNLOAD_RUN_SSH_HOSTNAME)
    set(host_arg --host "${YZLITE_DOWNLOAD_RUN_SSH_HOSTNAME}")
  endif()

   if(YZLITE_DOWNLOAD_RUN_START_MSG)
    set(start_msg_arg --start-msg "${YZLITE_DOWNLOAD_RUN_START_MSG}")
  endif()

  if(DOWNLOAD_RUN_ARG_COMPLETED_MSG)
    set(completed_msg_arg --completed-msg "${DOWNLOAD_RUN_ARG_COMPLETED_MSG}")
  elseif(YZLITE_DOWNLOAD_RUN_COMPLETED_MSG)
    set(completed_msg_arg --completed-msg "${YZLITE_DOWNLOAD_RUN_COMPLETED_MSG}")
  endif()



  if(NOT YZLITE_DOWNLOAD_RUN_NO_MASSERASE)
    set(masserase_arg --masserase)
  endif()

  add_custom_target(${target}_download_run
    COMMAND ${PYTHON_EXECUTABLE} -m yzlite build download_run "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target}.s37" --platform ${YZLITE_PLATFORM_NAME} ${masserase_arg} ${device_arg} ${setup_script_arg} ${setup_script_args_arg} ${port_arg} ${baud_arg} ${serial_number_arg} ${ip_address_arg} ${timeout_arg} ${retries_arg} ${host_arg} ${start_msg_arg} ${completed_msg_arg}
    DEPENDS ${target}
    COMMENT "Downloading and running ${target}.s37 on ${YZLITE_PLATFORM_NAME}'s ..."
    USES_TERMINAL
  )

endmacro()