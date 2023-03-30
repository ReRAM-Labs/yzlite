
import itertools
import json
import math
import os
import random
from typing import List, Tuple, Union

import numpy as np
import scipy.signal as sps
import tensorflow as tf
import tqdm
from numba import jit

from yzlite.core.keras import array_to_img, img_to_array, load_img
from yzlite.utils.archive_downloader import download_verify_extract
from yzlite.utils.hasher import generate_hash
from yzlite.utils.path import fullpath, recursive_listdir
from yzlite.utils.python import prepend_exception_msg


class FingerprintSignatureGeneratorDataset:
    def __init__(
        self,
        dataset_path_or_url: str,
        dataset_hash: str,
        nomatch_multiplier: int = 10,
        preprocess_samples=True,
        g_filter_size=5,  # approximates radius of 2.5
        g_filter_sigma=8,
        contrast=2.0,
        border=32,
        balance_threshold_max=240,
        balance_threshold_min=0,
        verify_imin=32,
        verify_imax=224,
        verify_full_threshold=3,
        verify_center_threshold=2
    ):
        self.dataset_path_or_url = dataset_path_or_url
        self.dataset_hash = dataset_hash
        self.nomatch_multiplier = nomatch_multiplier
        """The number of pairs of non-matching fingerprints to generate for each fingerprint"""

        self.preprocess_samples_enabled = preprocess_samples

        self.preprocess_params = dict(
            g_filter_size=g_filter_size,
            g_filter_sigma=g_filter_sigma,
            contrast=contrast,
            border=border,
            balance_threshold_min=balance_threshold_min,
            balance_threshold_max=balance_threshold_max,
            verify_imin=verify_imin,
            verify_imax=verify_imax,
            verify_full_threshold=verify_full_threshold,
            verify_center_threshold=verify_center_threshold
        )

        g_filter = generate_gaussian_filter(
            self.preprocess_params['g_filter_size'],
            self.preprocess_params['g_filter_sigma']
        )
        self.sharpen_filter, self.sharpen_gain = generate_sharpening_filter(
            g_filter,
            self.preprocess_params['contrast']
        )

    @property
    def previous_verify_msg(self) -> str:
        """Return the previous msg generated by sample verification
        This is used for debugging"""
        return get_previous_verify_msg()

    def preprocess_sample(self, x: np.ndarray) -> np.ndarray:
        """Given a fingerprint image, balance the colorspace and sharpen the image"""
        if len(x.shape) == 3:
            x = np.squeeze(x, axis=-1)
        x = balance_colorspace(x,
                               threshold_min=self.preprocess_params['balance_threshold_min'],
                               threshold_max=self.preprocess_params['balance_threshold_max'],
                               border=self.preprocess_params['border']
                               )
        x = sharpen_image(x,
                          filter=self.sharpen_filter,
                          gain=self.sharpen_gain
                          )
        return x

    def verify_sample(self, x: np.ndarray) -> bool:
        """Return if the image is able to be used (i.e. is not too blurry)"""
        return verify_sample(
            x,
            imin=self.preprocess_params['verify_imin'],
            imax=self.preprocess_params['verify_imax'],
            border=self.preprocess_params['border'],
            full_threshold=self.preprocess_params['verify_full_threshold'],
            center_threshold=self.preprocess_params['verify_center_threshold']
        )

    def load_data(self) -> str:
        """Download and extract the dataset and return the path to the extract directory"""

        # If a valid directory path was given
        # then just use that
        dataset_path = fullpath(self.dataset_path_or_url)
        if os.path.exists(dataset_path):
            unprocessed_dir = dataset_path

        # Otherwise, try to download and extract the dataset archive
        else:
            try:
                unprocessed_dir = download_verify_extract(
                    url=self.dataset_path_or_url,
                    dest_subdir='datasets/fingerprints_dataset/unprocessed',
                    file_hash=self.dataset_hash,
                    remove_root_dir=True
                )
            except Exception as e:
                prepend_exception_msg(e,
                                      'Failed to download fingerprint dataset.\n\n'
                                      'For privacy purposes, no dataset is provided with this model.\n'
                                      'As such, you must generate your own dataset to train this model.\n'
                                      'Refer to the following tutorial for more details:\n'
                                      'https://github.com/chenxingqiang/yzlite/yzlite/tutorials/fingerprint_authentication.html\n\n'
                                      )
                raise

        if not self.preprocess_samples_enabled:
            return unprocessed_dir

        processed_base_dir = os.path.dirname(unprocessed_dir).replace(
            '\\', '/') + '/processed_fingerprint_dataset'

        params_hash = generate_hash(self.preprocess_params)[:8]
        processed_dir = f'{processed_base_dir}/{params_hash}'
        processed_params_path = f'{processed_dir}/params.json'
        dropped_samples_path = f'{processed_dir}/dropped_samples.txt'

        os.makedirs(processed_dir, exist_ok=True)
        if not os.path.exists(processed_params_path):
            print(f'Generating {processed_dir} ...')
            all_samples = self.list_all_samples(unprocessed_dir, flatten=True)
            dropped_samples = []
            sampled_count = 0
            with tqdm.tqdm(total=len(all_samples), unit='sample', desc='Preprocessing samples') as progbar:
                for fn in all_samples:
                    sample_path = f'{unprocessed_dir}/{fn}'
                    img = load_img(sample_path, color_mode='grayscale')
                    x = img_to_array(img, dtype='uint8')
                    img.close()

                    x_norm = self.preprocess_sample(x)
                    if not self.verify_sample(x_norm):
                        dropped_samples.append(fn)
                        progbar.update()
                        continue

                    dst_path = f'{processed_dir}/{fn}'
                    os.makedirs(os.path.dirname(dst_path), exist_ok=True)
                    img = array_to_img(x, scale=False, dtype=np.uint8)
                    img.save(dst_path)
                    sampled_count += 1
                    progbar.update()

            print(f'Generating {dropped_samples_path}')
            with open(dropped_samples_path, 'w') as f:
                for fn in dropped_samples:
                    f.write(fn + '\n')

            print(f'Generating {processed_params_path}')
            with open(processed_params_path, 'w') as f:
                json.dump(self.preprocess_params, f, indent=3)

            print(f'  Total samples dropped: {len(dropped_samples)}')
            print(f'  Total samples used: {sampled_count}')

        return processed_dir

    def list_valid_filenames_in_directory(
        self,
        base_directory: str,
        search_class: str,
        white_list_formats: List[str],
        split: float,
        follow_links: bool,
        shuffle_index_directory: str
    ) -> Tuple[str, List[str]]:
        """Return a list of the filenames for the given search class"""
        if search_class == 'match':
            fp_pairs = self._generate_match_pairs(base_directory)
        else:
            fp_pairs = self._generate_nomatch_pairs(base_directory)

        if split:
            num_files = len(fp_pairs)
            if split[0] == 0:
                start = 0
                stop = math.ceil(split[1] * num_files)

                # We want to ensure that we do NOT split
                # on the same person's fingerprints

                # Get the directory name that starts on the other side of the split
                other_subset = os.path.dirname(fp_pairs[stop][0])

                # Keep moving the 'stop' index back while
                # it points to the same person's fingerprints
                while stop > 0 and fp_pairs[stop-1][0].startswith(other_subset):
                    stop -= -1

            else:
                start = math.ceil(split[0] * num_files)
                stop = num_files

                other_subset = os.path.dirname(fp_pairs[start][0])
                while start > 0 and fp_pairs[start-1][0].startswith(other_subset):
                    start -= 1

            fp_pairs = fp_pairs[start:stop]

        return search_class, fp_pairs

    def list_all_samples(self, base_directory: str, flatten: bool):
        """Return a list of all the samples in the dataset"""
        retval = []
        fingerprint_samples = {}

        def _callback(p: str) -> bool:
            fn = os.path.basename(p)
            if not fn.startswith('raw_') or not fn.endswith('.jpg'):
                return

            relpath = os.path.relpath(p, base_directory).replace('\\', '/')
            if flatten:
                retval.append(relpath)
            else:
                dir_name = os.path.dirname(relpath)
                if dir_name not in fingerprint_samples:
                    fingerprint_samples[dir_name] = []
                fingerprint_samples[dir_name].append(relpath)

        recursive_listdir(base_directory, regex=_callback)

        if not flatten:
            for samples in fingerprint_samples.values():
                # At least two samples of the same fingerprint are required to generate the pairs
                if len(samples) >= 2:
                    retval.append(samples)

        return retval

    def _generate_match_pairs(self, base_directory: str):
        """Generate a list of all possible matching fingerprint pairs"""
        index_path = f'{base_directory}/.index/match.txt'

        fp_pairs = []
        if os.path.exists(index_path):
            with open(index_path, 'r') as f:
                for line in f:
                    fp_pairs.append(tuple(line.strip().split(',')))
            return fp_pairs

        sample_batches = self.list_all_samples(base_directory, flatten=False)
        for sample_batch in sample_batches:
            for perm in itertools.permutations(sample_batch, 2):
                fp_pairs.append(perm)

        os.makedirs(os.path.dirname(index_path), exist_ok=True)
        with open(index_path, 'w') as f:
            for p in fp_pairs:
                f.write(','.join(p) + '\n')

        return fp_pairs

    def _generate_nomatch_pairs(self, base_directory: str):
        """Generate a list of pairs of each fp and a randomly chosen non-matching fp"""
        index_path = f'{base_directory}/.index/nomatch-{self.nomatch_multiplier}.txt'

        fp_pairs = []
        if os.path.exists(index_path):
            with open(index_path, 'r') as f:
                for line in f:
                    fp_pairs.append(tuple(line.strip().split(',')))
            return fp_pairs

        all_samples = self.list_all_samples(base_directory, flatten=True)

        for sample in all_samples:
            sample_dir = os.path.dirname(sample)
            for _ in range(self.nomatch_multiplier):
                while True:
                    nonmatch_sample = random.choice(all_samples)
                    # Ensure the nomatch_sample is not in the current sample's batch
                    if not nonmatch_sample.startswith(sample_dir):
                        break
                fp_pairs.append((sample, nonmatch_sample))

        os.makedirs(os.path.dirname(index_path), exist_ok=True)
        with open(index_path, 'w') as f:
            for p in fp_pairs:
                f.write(','.join(p) + '\n')

        return fp_pairs


def euclidean_distance(vects):
    """Find the Euclidean distance between two vectors.

    Euclidean distance = sqrt(sum(square(t1-t2)))

    Arguments:
        vects: List containing two tensors of same length.

    Returns:
        Tensor containing euclidean distance
        (as floating point value) between vectors.
    """

    x = vects[0]
    y = vects[1]
    sum_square = tf.math.reduce_sum(
        tf.math.square(x - y), axis=1, keepdims=True)
    return tf.math.sqrt(tf.math.maximum(sum_square, tf.keras.backend.epsilon()))


@jit
def balance_colorspace(
    x: np.ndarray,
    imax=0,
    imin=255,
    border=32,
    threshold_min=0,
    threshold_max=240,
) -> np.ndarray:
    """Simple statistical centering, remove outliers
        Both brightness and space
    """
    height, width = x.shape
    out = np.zeros_like(x)

    for i in range(border, height-border):
        for j in range(border, width-border):
            if x[i, j] < threshold_max:
                imax = max(imax, int(x[i, j]))
            if x[i, j] > threshold_min:
                imin = min(imin, int(x[i, j]))

    for i in range(height):
        for j in range(width):
            val_norm = (255/(imax-imin))*(int(x[i, j])-imin)
            out[i, j] = min(255, max(0, val_norm))

    return out


def generate_gaussian_filter(filter_size: int, sigma) -> np.ndarray:
    """Calculate gaussian filter"""
    g = np.zeros((filter_size, filter_size))  # 2D filter matrix

    # gaussian filter
    for i in range(-(filter_size-1)//2, (filter_size-1)//2+1):
        for j in range(-(filter_size-1)//2, (filter_size-1)//2+1):
            x0 = (filter_size+1)//2  # center
            y0 = (filter_size+1)//2  # center
            x = i+x0  # row
            y = j+y0  # col
            g[y-1, x-1] = np.exp(-((x-x0)**2+(y-y0)**2)/2/sigma/sigma)

    # normalize gaussian filter
    sum = np.sum(g)
    g = g/sum
    return g


def generate_sharpening_filter(g_filter: np.ndarray, amount: float) -> Tuple[np.ndarray, int]:
    """harpening filter, original + (original ? blurred) × amount"""
    filter_size = len(g_filter)

    original = np.zeros((filter_size, filter_size))
    original[(filter_size-1)//2, (filter_size-1)//2] = 1

    s_filter = original + (original - g_filter) * amount

    # Normalize to int8
    gain = 128/s_filter[(len(s_filter)-1)//2, (len(s_filter)-1)//2]
    gain = 2**(np.floor(np.log2(gain)))
    s_filter = np.round(s_filter*gain)
    s_filter[(len(s_filter)-1)//2, (len(s_filter)-1) //
             2] += gain - np.sum(s_filter)

    return s_filter.astype(np.int8), gain.astype(np.int8)


@jit
def conv2d(input: np.ndarray, filter: np.ndarray, gain):
    # input width and input height
    input_w, input_h = input.shape[1], input.shape[0]
    # filter width and filter height
    filter_w, filter_h = filter.shape[1], filter.shape[0]

    output_h = input_h
    output_w = input_w

    pad_along_height = filter_h - 1
    pad_along_width = filter_w - 1

    pad_height = pad_along_height // 2
    pad_width = pad_along_width // 2

    input = input.flatten()
    filter = filter.flatten()
    # convolution output
    output = np.zeros((output_h*output_w,), dtype=np.uint8)
    out_i = 0

    for out_y in range(output_h):
        in_y_origin = out_y - pad_height
        for out_x in range(output_w):
            in_x_origin = out_x - pad_width
            acc = 0
            filter_i = 0
            for filter_y in range(filter_h):
                in_y = in_y_origin + filter_y
                if in_y < 0 or in_y >= input_h:
                    filter_i += filter_w
                    continue
                for filter_x in range(filter_w):
                    in_x = in_x_origin + filter_x
                    if in_x < 0 or in_x >= input_w:
                        filter_i += 1
                        continue

                    acc += input[in_y*input_w + in_x] * filter[filter_i]
                    filter_i += 1

            norm_val = acc // gain

            output[out_i] = min(255, max(0, norm_val))
            out_i += 1

    output = output.reshape((output_h, output_w))

    return output


def sharpen_image(image: np.ndarray, filter: np.ndarray, gain: float) -> np.ndarray:
    """ Sharpen image, conv2d followed by saturation"""
    # Pure conv phase
    image_sharp = sps.convolve2d(image.astype(
        np.int16), filter, mode='same') // gain
    image_sharp = np.clip(image_sharp, 0, 255)
    image_sharp = image_sharp.astype(np.uint8)

    # image_shape2 = conv2d(image, filter, gain)
    # assert np.allclose(image_sharp, image_shape2)

    return image_sharp


_verify_msg = ''


def verify_sample(
    x: np.ndarray,
    imin=32,
    imax=224,
    border=32,
    full_threshold=4,
    center_threshold=3,
) -> bool:
    """Return if the given sample is of poor quality or not"""
    global _verify_msg
    height, width = x.shape
    dark_full = 0
    light_full = 0
    for i in range(height):
        for j in range(width):
            if x[i, j] < imin:
                dark_full += 1
            elif x[i, j] >= imax:
                light_full += 1

    dark_center = 0
    light_center = 0
    for i in range(border, height-border):
        for j in range(border, width-border):
            if x[i, j] < imin:
                dark_center += 1
            elif x[i, j] >= imax:
                light_center += 1

    _verify_msg = f'dark_full={dark_full} light_full={light_full}\n'
    _verify_msg += f'dark_center={dark_center} light_center={light_center}\n'
    _verify_msg += f'abs(dark_full-light_full)={abs(dark_full-light_full)}\n'
    _verify_msg += f'(dark_full+light_full)/full_threshold={(dark_full+light_full)/full_threshold}\n'
    _verify_msg += f'abs(dark_center-light_center)={abs(dark_center-light_center)}\n'
    _verify_msg += f'(dark_center+light_center)/center_threshold={(dark_center+light_center)/center_threshold}\n'

    if ((abs(dark_full-light_full) > (dark_full+light_full)/full_threshold) or
            (abs(dark_center-light_center) > (dark_center+light_center)/center_threshold)):
        return False

    return True


def get_previous_verify_msg() -> str:
    """Return the previous msg generated by sample verification
    This is used for debugging"""
    return _verify_msg