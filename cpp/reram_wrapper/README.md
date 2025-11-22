# ReRAM Python Wrapper

This allows for running ReRAM-accelerated Tensorflow-Lite Micro (TFLM) kernels from a Python script with full simulation support.

This is useful as it allows for running `.tflite` model files with ReRAM simulation and determining values such as:  

- Required runtime memory (i.e. RAM)
- Energy consumption of ReRAM operations
- Performance with non-ideal effects (IR drop, sneak path, write/read variation)
- Impact of device faults
- Comparison between different ReRAM configurations

This wrapper is not used directly. Instead, it is loaded by the [TfliteMicro](yzlite.core.tflite_micro.TfliteMicro) Python package when specifying the `accelerator = reram`.

## Source Code

- [Python wrapper](../../cpp/reram_wrapper) - This makes the ReRAM-accelerated TFLM kernels accessible to Python
- [Python API](../../yzlite/core/tflite_micro) - Python package that loads the TFLM wrapper as well as this Python wrapper
- [ReRAM Simulator](../../reram_simulator_example.py) - Standalone ReRAM simulator implementation

## Features

### ReRAM Simulation
- Multi-level cell (MLC) simulation with configurable resistance levels
- Crossbar array with configurable dimensions
- ADC/DAC models with configurable resolution
- Non-ideal effects:
  - IR voltage drop
  - Sneak path currents
  - Write/read variation
  - Resistance drift

### Fault Injection
- Stuck-at faults (high/low resistance)
- Configurable fault rate
- Random fault distribution

### Performance Analysis
- Energy consumption tracking
- Latency measurement
- Cell utilization statistics
- Read/write operation counting

## Additional Links

- [Python API documentation](yzlite.core.tflite_micro.TfliteMicro)
- [C++ Development documentation](../../../../docs/cpp_development/index.md)
- [ReRAM Research Report](../../../../RERAM_SIMULATOR_RESEARCH.md)

## Building the Wrapper

### Pre-built

This wrapper comes pre-built when installing the YZLITE Python package, e.g.:

```shell
pip install yizhu-yzlite
```

### Automatic Build

This wrapper is automatically built when installing from source, e.g.:

```shell
git clone https://github.com/ReRAM-Labs/yzlite.git
cd yzlite
pip install -e .
```

### Manual build via YZLITE command

To manually build this wrapper, issue the YZLITE command:

```shell
yzlite build reram_wrapper
```

### Manual build via CMake

This wrapper can also be built via CMake using [Visual Studio Code](../../../../docs/cpp_development/vscode.md) or the [Command Line](../../../../docs/cpp_development/command_line.md).

To build the wrapper, the [build_options.cmake](../../../../docs/cpp_development/build_options.md) file needs to be modified.

Create the file `<yzlite repo root>/user_options.cmake` and add:

```
yzlite_set(YZLITE_TARGET yzlite_reram_wrapper)
```

```{note}
You must remove this option and clean the build directory before building the example applications
```

Then configure the CMake project using the Window/Linux GCC toolchain and build the target: `yzlite_reram_wrapper`.

## Usage Example

```python
from yzlite.core import TfliteMicro

# Load model with ReRAM accelerator
tflm_model = TfliteMicro.load_tflite_model(
    'my_model.tflite',
    accelerator='reram'  # Use ReRAM simulator
)

# Configure ReRAM parameters
tflm_model.accelerator.configure_crossbar(rows=256, cols=256, levels=8)
tflm_model.accelerator.set_adc_resolution(bits=4)
tflm_model.accelerator.set_non_ideal_effects_enabled(True)

# Run inference
results = tflm_model.profile()

# Get statistics
stats = tflm_model.accelerator.get_statistics()
print(f"Energy: {stats['energy_uj']} μJ")
print(f"Latency: {stats['latency_us']} μs")

# Test with faults
num_faults = tflm_model.accelerator.inject_faults(fault_rate=0.01)
results_with_faults = tflm_model.profile()
```

## Configuration Options

### Crossbar Configuration
```python
accelerator.configure_crossbar(
    rows=256,      # Number of rows
    cols=256,      # Number of columns  
    levels=8       # Resistance levels (MLC)
)
```

### ADC Configuration
```python
accelerator.set_adc_resolution(bits=4)  # 4-bit ADC
```

### Non-Ideal Effects
```python
accelerator.set_non_ideal_effects_enabled(True)
```
Enables:
- IR voltage drop
- Sneak path currents
- Write/read variation
- Resistance drift

### Fault Injection
```python
num_faults = accelerator.inject_faults(fault_rate=0.01)  # 1% fault rate
```

## Technical Details

### ReRAM Cell Model
- Resistance Range: 1kΩ (LRS) to 1MΩ (HRS)
- Multi-level: 2-16 levels configurable
- Write variation: ~10%
- Read noise: ~5%

### Crossbar Array
- Dimensions: Up to 1024x1024
- Operations: Matrix-vector multiplication
- IR drop modeling: Position-dependent
- Sneak path: Current leakage simulation

### ADC/DAC
- Resolution: 1-12 bits
- Quantization noise
- DNL/INL errors

## References

1. RAELLA: https://arxiv.org/abs/2304.07935
2. FARe: https://arxiv.org/abs/2401.10522
3. FPSA: https://arxiv.org/abs/1901.09904
4. RED: https://arxiv.org/abs/1907.02987

