/***************************************************************************/ /**
                                                                               * @file
                                                                               * @brief Yizhu Technology Audio Feature Generator for Machine Learning
                                                                               *******************************************************************************
                                                                               * # License
                                                                               * <b>Copyright 2021 Yizhu Technology Inc. www.yizhu.com</b>
                                                                               *******************************************************************************
                                                                               *
                                                                               * SPDX-License-Identifier: Zlib
                                                                               *
                                                                               * The licensor of this software is Yizhu Technology Inc.
                                                                               *
                                                                               * This software is provided 'as-is', without any express or implied
                                                                               * warranty. In no event will the authors be held liable for any damages
                                                                               * arising from the use of this software.
                                                                               *
                                                                               * Permission is granted to anyone to use this software for any purpose,
                                                                               * including commercial applications, and to alter it and redistribute it
                                                                               * freely, subject to the following restrictions:
                                                                               *
                                                                               * 1. The origin of this software must not be misrepresented; you must not
                                                                               *    claim that you wrote the original software. If you use this software
                                                                               *    in a product, an acknowledgment in the product documentation would be
                                                                               *    appreciated but is not required.
                                                                               * 2. Altered source versions must be plainly marked as such, and must not be
                                                                               *    misrepresented as being the original software.
                                                                               * 3. This notice may not be removed or altered from any source distribution.
                                                                               *
                                                                               ******************************************************************************/

#ifndef SL_ML_AUDIO_FEATURE_GENERATION_H
#define SL_ML_AUDIO_FEATURE_GENERATION_H

#include "sl_component_catalog.h"
#include "sl_status.h"
#include <stddef.h>
#include <stdint.h>

#include "tensorflow/lite/c/common.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
  * @addtogroup ml_audio_feature_generation Audio Feature Generator
  * The audio feature generator extracts mel-filterbank features
  * from an audio signal to use with machine learning audio classification
  * applications using a microphone as an audio source.
  *
  * @details
  * ## Feature Generation
  *
  * The Mel scale replicates the behavior of the human ear, which has a higher
  * resolution for lower frequencies and is less discriminative of the higher
  * frequencies. To create a mel filterbank, a number of filters are applied
  * to the signal, where the pass-band of the lower channel filters is narrow
  * and increases towards higher frequencies.

  * The audio signal is split into short overlapping segments using
  * a window function (Hamming). The Fast Fourier Transform (FFT) is applied
  * to each segment to retrieve the frequency spectrum and then the power
  spectrum
  * of the segment. The filterbank is created by applying a series of mel-scaled
  * filters to the output. Finally, the log is applied to the output to increase
  * the sensitivity between the lower channels.
  *
  *              Audio Signal
  *                   │
  *           ┌───────▼───────┐
  *           │   Windowing   │
  *           └───────┬───────┘
  *                   │
  *           ┌───────▼───────┐
  *           │      FFT      │
  *           └───────┬───────┘
  *                   │
  *           ┌───────▼───────┐
  *           │  Mel Filters  │
  *           └───────┬───────┘
  *                   │
  *           ┌───────▼───────┐
  *           │      Log      │
  *           └───────┬───────┘
  *                   │
  *                   ▼
  *        Log-scaled Mel Filterbank
  *
  *
  * The feature array is generated by stacking filterbanks of sequential
  segments
  * together to form a spectrogram. The array is sorted such that the first
  element
  * is the first channel of the oldest filterbank.
  *
  * ##  Usage
  * sl_ml_audio_feature_generation_init() initializes the frontend for feature
  generation
  * based on the configuration in sl_ml_audio_feature_generation_config.h. It
  also
  * initializes and starts the microphone in streaming mode, which places the
  audio
  * samples into a ring-buffer.
  *
  * If used together with the Flatbuffer Converter Tool and a compatible
  TensorFlow Lite
  * model, the configuration is pulled from the TensorFlow Lite model by
  default. Set the
  * configuration option `SL_ML_AUDIO_FEATURE_GENERATION_MANUAL_CONFIG_ENABLE`
  to override
  * this behavior and use manually-configured options from the configuration
  header.
  *
  * The features are generated when
  sl_ml_audio_feature_generation_update_features()
  * is called. The feature generator then updates the features for as many
  * new segments of audio as possible, starting from the last time the function
  * was called up until the current time. The new features are appended to the
  * feature buffer, replacing the oldest features such that the feature array
  * always contains the most up to date features.
  *
  * Note that if the audio buffer is not large enough to hold all audio samples
  * required to generate features between calls to
  * sl_ml_audio_feature_generation_update_features(), audio data will simply be
  * overwritten. The generator will not return an error. The audio buffer must
  * therefore be configured to be large enough to store all new sampled data
  * between updating features.

  * To retrieve the generated features, either
  * sl_ml_audio_feature_generation_get_features_raw(),
  * sl_ml_audio_feature_generation_get_features_quantized(), or
  * sl_ml_audio_feature_generation_fill_tensor() must be called.
  *
  *
  * ### Example
  *
  * When used with TensorFlow Lite Micro, the audio feature generator can be
  used to fill
  * a tensor directly by using sl_ml_audio_feature_generation_fill_tensor().
  However,
  * the model has to be trained using the same feature generator configurations
  as
  * used for inference, configured in sl_ml_audio_feature_generation_config.h.
  *
  * ```
  * #include "sl_tflite_micro_init.h"
  * #include "sl_ml_audio_feature_generation.h"
  *
  * void main(void)
  * {
  *   sl_ml_audio_feature_generation_init();
  *
  *   while(1){
  *     sl_ml_audio_feature_generation_update_features();
  *
  *     if(do_inference){
  *
  sl_ml_audio_feature_generation_fill_tensor(sl_tflite_micro_get_input_tensor());
  *       sl_tflite_micro_get_interpreter()->Invoke();
  *     }
  *
  *     ...
  *
  *   }
  * }
  *
  * ```
  *
  * Note that updating features and retrieving them can be performed
  independently.
  * Updating features should be done often enough to avoid overwriting the audio
  buffer
  * while retrieving them only needs to be done prior to inference.
  * @{
  ******************************************************************************/

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Set up the microphone as an audio source for feature generation and
                                                                               *    initialize the frontend for feature generation.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_FAIL
                                                                               ******************************************************************************/
sl_status_t sl_ml_audio_feature_generation_init();

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Initialize microfrontend according to the configuration in
                                                                               *    sl_ml_audio_feature_generation_config.h.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_FAIL
                                                                               ******************************************************************************/
sl_status_t sl_ml_audio_feature_generation_frontend_init();

/***************************************************************************/ /**
                                                                               *  Write one chunk of audio samples into the audio buffer.
                                                                               *
                                                                               *  @param[in] new_samples
                                                                               *    New audio samples to copy
                                                                               *
                                                                               *  @param[in] num_samples
                                                                               *    Number of audio samples in new_samples, must be equal to
                                                                               *    SL_AUDIO_FRONTEND_AUDIO_BUFFER_CHUNK_SIZE
                                                                               *
                                                                               *  @note Chunk size is determined by SL_AUDIO_FRONTEND_AUDIO_BUFFER_CHUNK_SIZE
                                                                               *
                                                                               *  @return
                                                                               *    SL_STATUS_OK success
                                                                               *    SL_STATUS_INVALID_PARAMETER num_samples is not equal to chunk size
                                                                               *
                                                                               ******************************************************************************/
sl_status_t sli_ml_audio_feature_generation_audio_buffer_write_chunk(
    const int16_t *new_samples, size_t num_samples);

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *  Update the feature buffer with the missing feature slices since the last call
                                                                               *  to this function.
                                                                               *
                                                                               *  To retrieve the features, call sl_ml_audio_feature_generation_get_features_raw or
                                                                               *  sl_ml_audio_feature_generation_fill_tensor.
                                                                               *
                                                                               * @note
                                                                               *  This function needs to be called often enough to ensure that the audio
                                                                               *  buffer isn't overwritten.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_EMPTY No new slices were calculated
                                                                               ******************************************************************************/
sl_status_t sl_ml_audio_feature_generation_update_features();

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Retrieve the features as type uint16 and copy them to the provided buffer.
                                                                               *
                                                                               * @param[out] buffer
                                                                               *    Pointer to the buffer to store the feature data
                                                                               *
                                                                               * @param[in] num_elements
                                                                               *    The number of elements corresponding to the size of the buffer; If this is
                                                                               *    not large enough to store the entire feature buffer the function will return
                                                                               *    with an error.
                                                                               *
                                                                               * @note
                                                                               *    This function overwrites the entire buffer.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_INVALID_PARAMETER num_elements too small
                                                                               ******************************************************************************/
sl_status_t
sl_ml_audio_feature_generation_get_features_raw(uint16_t *buffer,
                                                size_t num_elements);

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Retrieve the features as type float32 and copy them to the provided buffer.
                                                                               *
                                                                               * @param[out] buffer
                                                                               *    Pointer to the buffer to store the feature data
                                                                               *
                                                                               * @param[in] num_elements
                                                                               *    The number of elements corresponding to the size of the buffer; If this is
                                                                               *    not large enough to store the entire feature buffer the function will return
                                                                               *    with an error.
                                                                               *
                                                                               * @note
                                                                               *    This function overwrites the entire buffer.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_INVALID_PARAMETER num_elements too small
                                                                               ******************************************************************************/
sl_status_t
sl_ml_audio_feature_generation_get_features_raw_float32(float *buffer,
                                                        size_t num_elements);

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Retrieve the features quantized to signed integer numbers in the range
                                                                               *    -128 to 127 (int8) and copy them to the provided buffer.
                                                                               *
                                                                               *    @ref range_min and @ref range_max set the valid range of which values are
                                                                               *    quantized from.
                                                                               *
                                                                               * @param[out] buffer
                                                                               *    Pointer to the buffer to store the feature data
                                                                               *
                                                                               * @param[in] num_elements
                                                                               *    The number of elements corresponding to the size of the buffer, if this is
                                                                               *    not large enough to store the entire feature buffer the function will return
                                                                               *    with an error.
                                                                               *
                                                                               * @param[in] range_min
                                                                               *    Determines the lower point of the range to quantize features from
                                                                               *
                                                                               * @param[in] range_max
                                                                               *    Determines the largest point of the range to quantize features from
                                                                               *
                                                                               * @note
                                                                               *    This function overwrites the entire buffer.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_INVALID_PARAMETER invalid input parameters
                                                                               ******************************************************************************/
sl_status_t sli_ml_audio_feature_generation_get_features_quantized(
    int8_t *buffer, size_t num_elements, uint16_t range_min,
    uint16_t range_max);

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Fill a TensorFlow tensor with feature data of type int8.
                                                                               *
                                                                               *    This converts the uint16 spectrograms to int8 using dynamic scaling.
                                                                               *    With this, the max spectrogram value is mapped to +127, and the max spectrogram minus <dynamic_range>
                                                                               *    is mapped to -128. Anything below max spectrogram minus <dynamic_range> is mapped to -128.
                                                                               *
                                                                               *    The following scaling algorithm is used:
                                                                               *
                                                                               *    maxval = max(uint16_features_data)
                                                                               *    minval = max(maxval - dynamic_range, 0)
                                                                               *
                                                                               *    FOR i IN range(num_elements):
                                                                               *      value = uint16_features_data[i] - minval
                                                                               *      value *= 255
                                                                               *      value /= (maxval - minval)
                                                                               *      value -= 128
                                                                               *      value = min(max(value, -128), 127)
                                                                               *      buffer[i] = (int8_t)value
                                                                               *
                                                                               * @param[out] buffer
                                                                               *    Pointer to the buffer to store the feature data
                                                                               *
                                                                               * @param[in] num_elements
                                                                               *    The number of elements corresponding to the size of the buffer, if this is
                                                                               *    not large enough to store the entire feature buffer the function will return
                                                                               *    with an error.
                                                                               *
                                                                               * @param[in] dynamic_range
                                                                               *    Dynamic range of uint16 spectrogram to be mapped to int8
                                                                               *    dynamic_range = DYNAMIC_RANGE_DB*(2^log_scale_shift)*ln(10)/20
                                                                               *    300 corresponds to a DYNAMIC_RANGE_DB of 40 dB
                                                                               *
                                                                               * @note
                                                                               *    This function overwrites the entire buffer.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_INVALID_PARAMETER invalid input parameters
                                                                               ******************************************************************************/
sl_status_t sli_ml_audio_feature_generation_get_features_dynamically_quantized(
    int8_t *buffer, size_t num_elements, uint16_t dynamic_range);

/***************************************************************************/ /**
  * @brief
  *    Retrieve the features, scales them by the given scaler, and fills float
  buffer.
  *
  *    buffer = (float)uint16_features_data * scaler

  * @param[out] buffer
  *    Pointer to the buffer to store the scaled feature data
  *
  * @param[in] num_elements
  *    The number of elements corresponding to the size of the buffer; If this
  is
  *    not large enough to store the entire feature buffer the function will
  return
  *    with an error.
  *
  * @note
  *    This function overwrites the entire buffer.
  *
  * @return
  *    SL_STATUS_OK for success
  *    SL_STATUS_INVALID_PARAMETER num_elements too small
  ******************************************************************************/
sl_status_t sl_ml_audio_feature_generation_get_features_scaled(
    float *buffer, size_t num_elements, float scaler);

/***************************************************************************/ /**
  * @brief
  *    Retrieve the features, normalizes them by centering about their mean and
  standard deviation
  *    and fills float buffer.
  *
  *    buffer = ((float)uint16_features_data - mean(uint16_features_data)) /
  std(uint16_features_data)

  * @param[out] buffer
  *    Pointer to the buffer to store the normalized feature data
  *
  * @param[in] num_elements
  *    The number of elements corresponding to the size of the buffer; If this
  is
  *    not large enough to store the entire feature buffer the function will
  return
  *    with an error.
  *
  * @note
  *    This function overwrites the entire buffer.
  *
  * @return
  *    SL_STATUS_OK for success
  *    SL_STATUS_INVALID_PARAMETER num_elements too small
  ******************************************************************************/
sl_status_t sl_ml_audio_feature_generation_get_features_mean_std_normalized(
    float *buffer, size_t num_elements);

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Fill a TensorFlow tensor with feature data of type int8.
                                                                               *
                                                                               *    The int8 values are derived by quantizing the microfrontend output, expected
                                                                               *    to be in the range 0 to 670, to signed integer numbers in
                                                                               *    -128 to 127 range.
                                                                               *
                                                                               * @param[in] input_tensor
                                                                               *    The input tensor to fill with features.
                                                                               *
                                                                               * @note
                                                                               *    This function overwrites the entire input tensor.
                                                                               *
                                                                               * @note
                                                                               *    Supports tensors of type kTfLiteInt8.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK for success
                                                                               *    SL_STATUS_INVALID_PARAMETER Tensor type or size does not correspond with
                                                                               *    configuration
                                                                               ******************************************************************************/
sl_status_t
sl_ml_audio_feature_generation_fill_tensor(TfLiteTensor *input_tensor);

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Return the number of new or unfetched feature slices that have been updated
                                                                               *    since the last call to sl_ml_audio_feature_generation_get_features_raw or
                                                                               *    sl_ml_audio_feature_generation_fill_tensor.
                                                                               *
                                                                               * @return
                                                                               *    The number of unfetched feature slices
                                                                               ******************************************************************************/
int sl_ml_audio_feature_generation_get_new_feature_slice_count();

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Return the feature buffer size.
                                                                               *
                                                                               * @return
                                                                               *    Size of the feature buffer
                                                                               ******************************************************************************/
int sl_ml_audio_feature_generation_get_feature_buffer_size();

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Reset the state of the audio feature generator.
                                                                               ******************************************************************************/
void sl_ml_audio_feature_generation_reset();

/***************************************************************************/ /**
                                                                               * @brief
                                                                               *    Return if the activity detection block detected activity in the audio
                                                                               *    stream.
                                                                               *
                                                                               *     @ref sl_ml_audio_feature_generation_update_features() must be periodically
                                                                               *     called to detect activity.
                                                                               *
                                                                               *    @note SL_ML_FRONTEND_ACTIVITY_DETECTION_ENABLE must be 1 to use this API.
                                                                               *
                                                                               *    @note The internal state is reset after calling this API.
                                                                               *          i.e. If this API returns SL_STATUS_OK, then calling this API
                                                                               *          again will return SL_STATUS_IN_PROGRESS until new activity is detected.
                                                                               *
                                                                               * @return
                                                                               *    SL_STATUS_OK is activity was detected
                                                                               *    SL_STATUS_IN_PROGRESS is no activity detected
                                                                               *    SL_STATUS_NOT_AVAILABLE if the activity detection block is not enabled
                                                                               ******************************************************************************/
sl_status_t sl_ml_audio_feature_generation_activity_detected();

typedef void (*sl_ml_audio_feature_generation_mic_callback_t)(
    const int16_t *data, uint32_t n_frames);
sl_status_t sl_ml_audio_feature_generation_set_mic_callback(
    sl_ml_audio_feature_generation_mic_callback_t callback);

extern int16_t *sl_ml_audio_feature_generation_audio_buffer;

/** @} (end addtogroup ml_audio_feature_generation) */

#ifdef __cplusplus
}
#endif

#endif // SL_ML_AUDIO_FEATURE_GENERATION_H
