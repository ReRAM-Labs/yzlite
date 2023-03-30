# UART Stream Data Test

This tests the various data input/output features of the [UartStream](https://github.com/ReRAM-Labs/yzlite/docs/python_api/utils/uart_stream/index.html) library.

This contains both a firmware application plus Python script.
Both work together to stream data across the UART.

See the source code for this example on Github: [cpp/shared/uart_stream/examples/data_test](https://github.com/ReRAM-Labs/yzlite/blob/master/cpp/shared/uart_stream/examples/data_test)

## Setup Steps

0 ) See the [YZLITE C++ Development Docs](https://github.com/ReRAM-Labs/yzlite/docs/cpp_development/index.html) for setting up your environment

__NOTE:__ The application needs to be built for [embedded](https://github.com/ReRAM-Labs/yzlite/docs/cpp_development/vscode.html#build-for-embedded)

1 ) Connect a supported development board (e.g. BRD2601B) to your PC

2 ) Create or modify the file:

```
<yzlite repo root>/user_options.cmake
```

and add the following:

```
yzlite_set(YZLITE_TARGET yzlite_uart_stream_data_test)
yzlite_set(YZLITE_PLATFORM_NAME brd2601) # Change this to your platform's name as necessary
```

3 ) Invoke the CMake target: `yzlite_uart_stream_data_test_download`

which will build the firmware application and program it to the development board.

4 ) Run the Python script (from the YZLITE Python virtual environment):

```
python data_test.py
```

This will stream and verify data transferred between the dev board and Python script
using the [UartStream](https://github.com/ReRAM-Labs/yzlite/docs/python_api/utils/uart_stream/index.html) library.
