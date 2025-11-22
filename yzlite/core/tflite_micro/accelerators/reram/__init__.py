import importlib
from typing import Dict, Any

from yzlite.core.profiling_results import ProfilingModelResults
from yzlite.core.tflite_micro.tflite_micro_accelerator import \
    TfliteMicroAccelerator
from yzlite.core.utils import get_yzlite_logger


class ReRAMTfliteMicroAccelerator(TfliteMicroAccelerator):
    """
    ReRAM hardware simulator accelerator for TensorFlow Lite Micro
    
    This class allows for running .tflite models on the ReRAM hardware simulator
    and evaluating performance with realistic ReRAM characteristics including:
    - Multi-level cell (MLC) resistance states
    - Write/read variations
    - IR drop and sneak path effects
    - Fault injection
    - Energy and latency estimation
    """

    def __init__(self):
        # Import the ReRAM C++ python wrapper
        # For more details, see:
        # <yzlite root>/cpp/reram_wrapper
        try:
            _wrapper = importlib.import_module(
                'yzlite.core.tflite_micro.accelerators.reram._reram_wrapper')
        except (ImportError, ModuleNotFoundError) as e:
            raise ImportError(
                f'Failed to import the ReRAM wrapper C++ shared library, err: {e}\n'
                'This likely means you need to re-build the yzlite package or ReRAM wrapper package\n'
                'Try running: yzlite build reram_wrapper\n\n') from e

        super().__init__(_wrapper)
        
        # Default configuration
        self._simulator_enabled = True
        self._non_ideal_effects_enabled = True
        self._crossbar_config = {
            'rows': 256,
            'cols': 256,
            'levels': 8
        }
        self._adc_resolution = 4

    def set_simulator_backend_enabled(self, enabled: bool):
        """
        Enable/disable the ReRAM simulator backend
        
        Args:
            enabled: True to enable simulation, False to disable
        """
        self._simulator_enabled = enabled
        self._accelerator_wrapper.set_simulator_backend_enabled(enabled)
        get_yzlite_logger().debug(f"ReRAM simulator {'enabled' if enabled else 'disabled'}")

    def configure_crossbar(self, rows: int = 256, cols: int = 256, levels: int = 8):
        """
        Configure ReRAM crossbar array dimensions
        
        Args:
            rows: Number of rows in crossbar array
            cols: Number of columns in crossbar array
            levels: Number of resistance levels per cell (MLC)
        """
        self._crossbar_config = {'rows': rows, 'cols': cols, 'levels': levels}
        self._accelerator_wrapper.configure_crossbar(rows, cols, levels)
        get_yzlite_logger().debug(f"Configured ReRAM crossbar: {rows}x{cols} with {levels} levels")

    def set_adc_resolution(self, bits: int = 4):
        """
        Set ADC resolution for ReRAM readout
        
        Args:
            bits: ADC resolution in bits (typically 4-8)
        """
        self._adc_resolution = bits
        self._accelerator_wrapper.set_adc_resolution(bits)
        get_yzlite_logger().debug(f"Set ADC resolution to {bits} bits")

    def set_non_ideal_effects_enabled(self, enabled: bool):
        """
        Enable/disable non-ideal effects simulation
        
        Non-ideal effects include:
        - IR drop
        - Sneak path currents
        - Write/read variations
        - Resistance drift
        
        Args:
            enabled: True to enable non-ideal effects, False for ideal simulation
        """
        self._non_ideal_effects_enabled = enabled
        self._accelerator_wrapper.set_non_ideal_effects_enabled(enabled)
        get_yzlite_logger().debug(f"Non-ideal effects {'enabled' if enabled else 'disabled'}")

    def inject_faults(self, fault_rate: float = 0.01) -> int:
        """
        Inject stuck-at faults into ReRAM crossbar
        
        Args:
            fault_rate: Fraction of cells to fault (0.0-1.0)
            
        Returns:
            Number of faults injected
        """
        num_faults = self._accelerator_wrapper.inject_faults(fault_rate)
        get_yzlite_logger().info(f"Injected {num_faults} faults ({fault_rate*100:.2f}%)")
        return num_faults

    def get_statistics(self) -> Dict[str, Any]:
        """
        Get ReRAM simulator statistics
        
        Returns:
            Dictionary containing:
            - energy_uj: Energy consumption in microjoules
            - latency_us: Inference latency in microseconds
            - write_ops: Number of write operations
            - read_ops: Number of read operations
            - cell_utilization: Percentage of cells utilized
            - crossbar_rows: Crossbar row count
            - crossbar_cols: Crossbar column count
            - adc_resolution: ADC resolution in bits
            - injected_faults: Number of injected faults
        """
        return dict(self._accelerator_wrapper.get_statistics())

    def reset_simulator(self):
        """Reset ReRAM simulator state and statistics"""
        self._accelerator_wrapper.reset_simulator()
        get_yzlite_logger().debug("Reset ReRAM simulator")

    def estimate_profiling_results(
        self,
        results: ProfilingModelResults,
        **kwargs
    ):
        """
        Update the given ProfilingModelResults with estimated model metrics
        
        This estimates:
        - Energy consumption based on ReRAM operations
        - Latency based on ADC resolution and crossbar size
        - Layer-wise statistics
        
        Args:
            results: ProfilingModelResults object to update
            **kwargs: Additional parameters
        """
        # If no clock rate was given, default to 78MHz
        # (typical for embedded platforms)
        if results.cpu_clock_rate == 0:
            # pylint: disable=protected-access
            results._cpu_clock_rate = int(78e6)

        # Get ReRAM statistics
        stats = self.get_statistics()
        
        # Update results with ReRAM-specific metrics
        if hasattr(results, 'custom_stats'):
            results.custom_stats['reram_energy_uj'] = stats.get('energy_uj', 0)
            results.custom_stats['reram_latency_us'] = stats.get('latency_us', 0)
            results.custom_stats['reram_write_ops'] = stats.get('write_ops', 0)
            results.custom_stats['reram_read_ops'] = stats.get('read_ops', 0)
            results.custom_stats['reram_utilization'] = stats.get('cell_utilization', 0)
            
        get_yzlite_logger().debug(
            f"ReRAM profiling: {stats.get('energy_uj', 0):.2f} µJ, "
            f"{stats.get('latency_us', 0):.2f} µs"
        )

