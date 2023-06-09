__NOTE:__ Refer to the [online documentation](https://github.com/ReRAM-Labs/yzlite) to properly view this file

# Utilities

The YZLITE Python package comes with various utility scripts.

The source code for these APIs may be found on Github at [https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/utils](https://github.com/ReRAM-Labs/yzlite/tree/master/yzlite/utils).

The following utilities are available:

<table class="autosummary longtable docutils align-default">
<colgroup>
<col style="width: 10%">
<col style="width: 90%">
</colgroup>
<tbody>
<tr class="row-odd"><td><p><a class="reference internal" href="audio_dataset_generator/index.html"><code class="xref py py-obj docutils literal notranslate"><span class="pre">yzlite.utils.audio_dataset_generator</span></code></a></p></td>
<td><p>Allows for generating a synthetic keyword audio datasets</p></td>
</tr>
</tbody>
</table>

<table class="autosummary longtable docutils align-default">
<colgroup>
<col style="width: 10%">
<col style="width: 90%">
</colgroup>
<tbody>
<tr class="row-odd"><td><p><a class="reference internal" href="uart_stream/index.html"><code class="xref py py-obj docutils literal notranslate"><span class="pre">yzlite.utils.uart_stream</span></code></a></p></td>
<td><p>Allows for streaming binary data between a Python script and embedded device via UART</p></td>
</tr>
</tbody>
</table>

<table class="autosummary longtable docutils align-default">
<colgroup>
<col style="width: 10%">
<col style="width: 90%">
</colgroup>
<tbody>
<tr class="row-odd"><td><p><a class="reference internal" href="jlink_stream/index.html"><code class="xref py py-obj docutils literal notranslate"><span class="pre">yzlite.utils.jlink_stream</span></code></a></p></td>
<td><p>Allows for transferring binary data between a Python script and a JLink-enabled embedded device via the debug interface</p></td>
</tr>
</tbody>
</table>

<table class="autosummary longtable docutils align-default">
<colgroup>
<col style="width: 10%">
<col style="width: 90%">
</colgroup>
<tbody>
<tr class="row-odd"><td><p><a class="reference internal" href="serial_reader/index.html"><code class="xref py py-obj docutils literal notranslate"><span class="pre">yzlite.utils.serial_reader</span></code></a></p></td>
<td><p>Allows for reading from a serial port (e.g. from the UART of an embedded device)</p></td>
</tr>
</tbody>
</table>

```{eval-rst}


.. autosummary::
   :toctree: archive_downloader
   :template: custom-module-template.rst

   yzlite.utils.archive_downloader

.. autosummary::
   :toctree: archive
   :template: custom-module-template.rst

   yzlite.utils.archive

.. autosummary::
   :toctree: bin2header
   :template: custom-module-template.rst

   yzlite.utils.bin2header

.. autosummary::
   :toctree: cmake
   :template: custom-module-template.rst

   yzlite.utils.cmake

.. autosummary::
   :toctree: gpu
   :template: custom-module-template.rst

   yzlite.utils.gpu

.. autosummary::
   :toctree: hasher
   :template: custom-module-template.rst

   yzlite.utils.hasher


.. autosummary::
   :toctree: logger
   :template: custom-module-template.rst

   yzlite.utils.logger

.. autosummary::
   :toctree: path
   :template: custom-module-template.rst

   yzlite.utils.path


.. autosummary::
   :toctree: python
   :template: custom-module-template.rst

   yzlite.utils.python


.. autosummary::
   :toctree: shell_cmd
   :template: custom-module-template.rst

   yzlite.utils.shell_cmd

.. autosummary::
   :toctree: string_formatting
   :template: custom-module-template.rst

   yzlite.utils.string_formatting

.. autosummary::
   :toctree: system
   :template: custom-module-template.rst

   yzlite.utils.system


.. autosummary::
   :toctree: signal_handler
   :template: custom-class-template.rst

   yzlite.utils.signal_handler.SignalHandler

.. autosummary::
   :toctree: process_pool
   :template: custom-class-template.rst

   yzlite.utils.process_pool.ProcessPool


```

```{toctree}
:maxdepth: 1
:hidden:

./archive_downloader
./archive
./bin2header
./cmake
./gpu
./hasher
./logger
./path
./python
./shell_cmd
./string_formatting
./system
./serial_reader/index
./signal_handler
./uart_stream/index
./jlink_stream/index
./process_pool
./process_pool_batch
./audio_dataset_generator/index
```
