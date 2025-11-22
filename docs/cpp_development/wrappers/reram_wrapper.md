# ReRAM Python Wrapper

This wrapper allows for running TensorFlow Lite Micro models with ReRAM crossbar array simulation.

## Overview

The ReRAM wrapper provides a comprehensive simulation environment for evaluating neural network inference on ReRAM (Resistive Random Access Memory) based Processing-In-Memory (PIM) architectures.

## Features

### ReRAM Simulation
- **Multi-Level Cell (MLC)**: Configurable resistance levels (2-16 levels)
- **Crossbar Array**: Configurable dimensions (up to 1024x1024)
- **ADC/DAC Models**: 1-12 bit resolution
- **Non-Ideal Effects**:
  - IR voltage drop
  - Sneak path currents
  - Write/read variation (10%)
  - Resistance drift

### Performance Analysis
- Energy consumption tracking (μJ)
- Latency measurement (μs)
- Read/write operation counting
- Cell utilization statistics

### Fault Injection
- Stuck-at faults (high/low resistance)
- Configurable fault rate (0-100%)
- Random fault distribution
- Reliability analysis

## Source Code

- [C++ Wrapper](../../cpp/reram_wrapper) - ReRAM simulator C++ implementation
- [Python API](../../yzlite/core/tflite_micro/accelerators/reram) - Python accelerator interface

## Building

### Pre-built
The wrapper comes pre-built when installing the YZLITE Python package:

```shell
pip install yizhu-yzlite
```

### Automatic Build
Automatically built when installing from source:

```shell
git clone https://github.com/ReRAM-Labs/yzlite.git
cd yzlite
pip install -e .
```

### Manual Build
To manually build this wrapper:

```shell
yzlite build reram_wrapper
```

## Usage

### Basic Usage

```python
from yzlite.core import TfliteMicro

# Load model with ReRAM accelerator
model = TfliteMicro.load_tflite_model(
    'my_model.tflite',
    accelerator='reram'
)

# Configure ReRAM parameters
model.accelerator.configure_crossbar(rows=256, cols=256, levels=8)
model.accelerator.set_adc_resolution(bits=4)
model.accelerator.set_non_ideal_effects_enabled(True)

# Run inference and profiling
results = model.profile()

# Get statistics
stats = model.accelerator.get_statistics()
print(f"Energy: {stats['energy_uj']} μJ")
print(f"Latency: {stats['latency_us']} μs")
```

### Fault Injection Testing

```python
# Normal inference
normal_results = model.profile()

# Inject faults (1%)
num_faults = model.accelerator.inject_faults(fault_rate=0.01)
print(f"Injected {num_faults} faults")

# Test with faults
faulty_results = model.profile()

# Compare accuracy
accuracy_drop = normal_results.accuracy - faulty_results.accuracy
print(f"Accuracy drop: {accuracy_drop*100:.2f}%")
```

### Configuration Options

#### Crossbar Configuration
```python
accelerator.configure_crossbar(
    rows=256,      # Number of rows
    cols=256,      # Number of columns
    levels=8       # Resistance levels (MLC)
)
```

#### ADC Configuration
```python
accelerator.set_adc_resolution(bits=4)  # 4-bit ADC
```

#### Non-Ideal Effects
```python
accelerator.set_non_ideal_effects_enabled(True)
```

Enables:
- IR voltage drop
- Sneak path currents
- Write/read variation
- Resistance drift

## Technical Details

### ReRAM Cell Model
- **Resistance Range**: 1kΩ (LRS) to 1MΩ (HRS)
- **Multi-Level**: 2-16 levels configurable
- **Write Variation**: ~10%
- **Read Noise**: ~5%

### Crossbar Array
- **Dimensions**: Up to 1024x1024
- **Operations**: Matrix-vector multiplication
- **IR Drop**: Position-dependent modeling
- **Sneak Path**: Current leakage simulation

### ADC/DAC
- **Resolution**: 1-12 bits
- **Quantization Noise**: Gaussian distribution
- **DNL/INL Errors**: ±0.5 LSB

## References

### Research Papers
1. **RAELLA** (2023): Low-resolution ADC for analog PIM  
   https://arxiv.org/abs/2304.07935

2. **FARe** (2024): Fault-aware GNN training on ReRAM  
   https://arxiv.org/abs/2401.10522

3. **FPSA** (2019): Reconfigurable ReRAM accelerator architecture  
   https://arxiv.org/abs/1901.09904

4. **RED** (2019): ReRAM-based deconvolution accelerator  
   https://arxiv.org/abs/1907.02987

### Documentation
- [ReRAM Research Report](../../../RERAM_SIMULATOR_RESEARCH.md)
- [Quick Start Guide](../../../RERAM_QUICKSTART.md)
- [Implementation Details](../../../RERAM_WRAPPER_IMPLEMENTATION.md)

## See Also

- [MVP Wrapper](./mvp_wrapper.md) - MVP hardware accelerator wrapper
- [TFLite Micro Wrapper](./tflite_micro_wrapper.md) - Base TFLite Micro wrapper
- [Audio Feature Generator Wrapper](./audio_feature_generator_wrapper.md)

