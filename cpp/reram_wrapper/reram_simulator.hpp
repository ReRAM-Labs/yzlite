#pragma once

#include <cmath>
#include <cstdint>
#include <random>
#include <vector>

namespace yzlite {
namespace reram {

/**
 * @brief ReRAM Cell Model
 * 
 * Simulates a single ReRAM cell with multi-level resistance states
 */
class ReRAMCell {
public:
  ReRAMCell(int levels = 8, float r_lrs = 1e3f, float r_hrs = 1e6f,
            float write_var = 0.1f, float read_noise = 0.05f)
      : levels_(levels), R_LRS_(r_lrs), R_HRS_(r_hrs),
        write_variation_(write_var), read_noise_(read_noise),
        current_level_(0), resistance_(r_hrs), is_faulty_(false),
        stuck_resistance_(0.0f) {
    updateResistance();
  }

  void write(int target_level) {
    if (is_faulty_)
      return; // Stuck-at fault

    current_level_ = std::max(0, std::min(target_level, levels_ - 1));

    // Add write variation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> dist(0.0f, write_variation_);
    float variation = dist(gen);
    float actual_level =
        current_level_ + variation * static_cast<float>(levels_);
    actual_level = std::max(0.0f, std::min(actual_level,
                                           static_cast<float>(levels_ - 1)));

    // Update resistance (logarithmic distribution)
    float log_r_lrs = std::log10(R_LRS_);
    float log_r_hrs = std::log10(R_HRS_);
    float log_r = log_r_lrs + (log_r_hrs - log_r_lrs) *
                                   (1.0f - actual_level / (levels_ - 1));
    resistance_ = std::pow(10.0f, log_r);
  }

  float read(float voltage = 0.2f) {
    float current = voltage / (is_faulty_ ? stuck_resistance_ : resistance_);

    // Add read noise
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> dist(0.0f, read_noise_ * std::abs(current));
    float noise = dist(gen);

    return current + noise;
  }

  void setStuckAtFault(bool high_resistance) {
    is_faulty_ = true;
    stuck_resistance_ = high_resistance ? R_HRS_ : R_LRS_;
  }

  bool isFaulty() const { return is_faulty_; }
  float getResistance() const {
    return is_faulty_ ? stuck_resistance_ : resistance_;
  }
  int getLevels() const { return levels_; }

private:
  void updateResistance() {
    float log_r_lrs = std::log10(R_LRS_);
    float log_r_hrs = std::log10(R_HRS_);
    float ratio = static_cast<float>(current_level_) / (levels_ - 1);
    float log_r = log_r_lrs + (log_r_hrs - log_r_lrs) * (1.0f - ratio);
    resistance_ = std::pow(10.0f, log_r);
  }

  int levels_;
  float R_LRS_;
  float R_HRS_;
  float write_variation_;
  float read_noise_;
  int current_level_;
  float resistance_;
  bool is_faulty_;
  float stuck_resistance_;
};

/**
 * @brief ReRAM Crossbar Array
 * 
 * Simulates a crossbar array with non-ideal effects
 */
class ReRAMCrossbar {
public:
  ReRAMCrossbar(int rows, int cols, int levels = 8,
                float wire_resistance = 10.0f)
      : rows_(rows), cols_(cols), wire_resistance_(wire_resistance) {
    cells_.resize(rows);
    for (int i = 0; i < rows; ++i) {
      cells_[i].resize(cols);
      for (int j = 0; j < cols; ++j) {
        cells_[i][j] = ReRAMCell(levels);
      }
    }
  }

  void programWeights(const std::vector<std::vector<float>> &weights) {
    // Normalize weights to [0, 1]
    float w_min = weights[0][0], w_max = weights[0][0];
    for (const auto &row : weights) {
      for (float w : row) {
        w_min = std::min(w_min, w);
        w_max = std::max(w_max, w);
      }
    }

    float range = w_max - w_min;
    if (range < 1e-6f)
      range = 1.0f;

    // Map to resistance levels
    for (int i = 0; i < rows_ && i < static_cast<int>(weights.size()); ++i) {
      for (int j = 0; j < cols_ && j < static_cast<int>(weights[i].size());
           ++j) {
        float normalized = (weights[i][j] - w_min) / range;
        int level = static_cast<int>(normalized * (cells_[i][j].getLevels() - 1));
        cells_[i][j].write(level);
      }
    }
  }

  std::vector<float> matrixVectorMultiply(const std::vector<float> &input,
                                           bool apply_ir_drop = true,
                                           bool apply_sneak_path = true) {
    std::vector<float> output(rows_, 0.0f);

    // Simulate voltage inputs
    std::vector<float> voltages(cols_);
    for (int j = 0; j < cols_; ++j) {
      voltages[j] = (j < static_cast<int>(input.size())) ? input[j] * 0.2f : 0.0f;
    }

    // Accumulate currents for each row
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        float current = cells_[i][j].read(voltages[j]);
        output[i] += current;
      }
    }

    // Apply non-ideal effects
    if (apply_ir_drop) {
      applyIRDrop(output);
    }

    if (apply_sneak_path) {
      applySneakPath(output);
    }

    return output;
  }

  int injectStuckAtFaults(float fault_rate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    std::uniform_int_distribution<int> bool_dist(0, 1);

    int num_faults = 0;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (dist(gen) < fault_rate && !cells_[i][j].isFaulty()) {
          bool high_resistance = bool_dist(gen) == 1;
          cells_[i][j].setStuckAtFault(high_resistance);
          num_faults++;
        }
      }
    }
    return num_faults;
  }

  int getRows() const { return rows_; }
  int getCols() const { return cols_; }

private:
  void applyIRDrop(std::vector<float> &currents) {
    const float v_supply = 3.3f;
    for (int i = 0; i < static_cast<int>(currents.size()); ++i) {
      float voltage_drop = currents[i] * wire_resistance_ * (i + 1);
      float reduction = std::max(0.0f, 1.0f - voltage_drop / v_supply);
      currents[i] *= reduction;
    }
  }

  void applySneakPath(std::vector<float> &currents) {
    float total_current = 0.0f;
    for (float c : currents) {
      total_current += c;
    }
    float leakage_ratio = 0.01f; // 1% leakage
    float leakage_per_row =
        leakage_ratio * total_current / static_cast<float>(currents.size());

    for (auto &c : currents) {
      c += leakage_per_row;
    }
  }

  int rows_;
  int cols_;
  float wire_resistance_;
  std::vector<std::vector<ReRAMCell>> cells_;
};

/**
 * @brief ADC Model
 * 
 * Simulates analog-to-digital conversion
 */
class ADCModel {
public:
  ADCModel(int resolution = 4, float v_ref = 3.3f)
      : resolution_(resolution), v_ref_(v_ref) {
    levels_ = 1 << resolution; // 2^resolution
    lsb_ = v_ref / static_cast<float>(levels_);
  }

  std::vector<int> convert(const std::vector<float> &analog_values) {
    std::vector<int> digital(analog_values.size());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> dnl_dist(0.0f, 0.5f);

    for (size_t i = 0; i < analog_values.size(); ++i) {
      // Convert current to voltage (assume transimpedance amplifier)
      float voltage = analog_values[i] * 1e6f; // 1MΩ transimpedance

      // Quantize
      int quant = static_cast<int>(std::round(voltage / lsb_));
      quant = std::max(0, std::min(quant, levels_ - 1));

      // Add DNL/INL error
      float dnl_error = dnl_dist(gen);
      quant = std::max(0, std::min(static_cast<int>(quant + dnl_error),
                                   levels_ - 1));

      digital[i] = quant;
    }

    return digital;
  }

private:
  int resolution_;
  int levels_;
  float v_ref_;
  float lsb_;
};

/**
 * @brief Statistics tracking
 */
struct Statistics {
  double energy_uj = 0.0;
  double latency_us = 0.0;
  int write_ops = 0;
  int read_ops = 0;
  double cell_utilization = 0.0;

  void reset() {
    energy_uj = 0.0;
    latency_us = 0.0;
    write_ops = 0;
    read_ops = 0;
    cell_utilization = 0.0;
  }

  void addWriteOp() {
    write_ops++;
    energy_uj += 10.0; // 10 uJ per write (example)
    latency_us += 1.0; // 1 us per write (example)
  }

  void addReadOp() {
    read_ops++;
    energy_uj += 0.1; // 0.1 uJ per read (example)
    latency_us += 0.01; // 0.01 us per read (example)
  }
};

} // namespace reram
} // namespace yzlite

