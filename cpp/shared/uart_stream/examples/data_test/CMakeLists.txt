

# To run this example, add the following to the file:
# <yzlite repo root>/user_options.cmake:
#
# yzlite_set(YZLITE_TARGET yzlite_uart_stream_data_test)
#
# And invoke the CMake target:
# yzlite_uart_stream_data_test_download
#
# This will download the firmware to the dev board
# Then, run the corresponding data_test.py script


add_executable(yzlite_uart_stream_data_test
    main.cc
)  
yzlite_add_exe_targets(yzlite_uart_stream_data_test)

target_link_libraries(yzlite_uart_stream_data_test
PRIVATE 
    ${YZLITE_PLATFORM}
    yzlite::uart_stream
)
