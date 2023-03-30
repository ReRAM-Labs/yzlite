import os
import re
import subprocess
import sys
import time

from setuptools import find_packages, setup
from setuptools.command.build_py import build_py

import yzlite
from yzlite.utils.path import clean_directory

long_description = """Yizhu Technology ReRAM YZLite (YZLITE)
==============================================

__NOTICE:__

This package is considered EXPERIMENTAL - YIZHU TECHNOLOGY DOES NOT OFFER ANY WARRANTIES AND DISCLAIMS ALL IMPLIED WARRANTIES CONCERNING THIS SOFTWARE.
This package is made available as a self-serve reference supported only by the on-line documentation, and community support.
There are no Yizhu Technology support services for this software at this time.


This is a Python package with command-line utilities and scripts to aid the development
of machine learning models for Yizhu-Tech's embedded platforms.

See the [YZLITE Overview](https://github.com/ReRAM-Labs/yzlite/docs/overview.html) for an overview of how the various features of the YZLITE are used to
create machine learning models for embedded devices.

The features of this Python package include:
- [Command-line](https://github.com/ReRAM-Labs/yzlite/docs/command_line/index.html) - Execute all ML operations from simple command-line interface
- [Python API](https://github.com/ReRAM-Labs/yzlite/docs/python_api/python_api.html) - Execute all ML operations from a Python script
- [Model Profiler](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_profiler.html) - Determine how efficiently an ML model will execute on an embedded platform
- [Model Training](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_training.html) - Train an ML model using [Google Tensorflow](https://www.tensorflow.org/)
- [Model Training Monitor](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_training_monitor.html) - Monitor/profile the training of a model using [Tensorboard](https://www.tensorflow.org/tensorboard)
- [Remote Training via SSH](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_training_via_ssh.html) - Securely and seamlessly train the model on a remote "cloud" machine
- [Model Evaluation](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_evaluation.html) - Evaluate a trained ML model's accuracy and other metrics
- [Model Summary](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_summary.html) - Generate a summary of the model's contents
- [Model Visualization](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_visualizer.html) - Interactively view the ML model's structure
- [Model Quantization](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_quantization.html) - Reduce the memory footprint of an ML model by using the [Tensorflow-Lite Converter](https://www.tensorflow.org/lite/convert)
- [Model Parameters](https://github.com/ReRAM-Labs/yzlite/docs/guides/model_parameters.html) - Embed custom parameters into the generated model file
- [Audio Utilities](https://github.com/ReRAM-Labs/yzlite/docs/audio/audio_utilities.html) - Utilities to visualize and classify real-time audio for keyword spotting
- [Python C++ Wrappers](https://github.com/ReRAM-Labs/yzlite/docs/cpp_development/wrappers/index.html) - Execute C++ libraries (including [Tensorflow-Lite Micro](https://github.com/tensorflow/tflite-micro)) from a Python interface



## Installation

```shell
# Windows
pip  install yizhu-yzlite

# Linux
pip3 install yizhu-yzlite
```

Refer to [Installation Guide](https://github.com/ReRAM-Labs/yzlite/docs/installation.html) for more details on how to install the YZLITE.


## License

SPDX-License-Identifier: Zlib

The licensor of this software is Yizhu Technology Inc.

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
"""


sys_ver = sys.version_info
python_major_version = sys_ver[0]
pyhton_minor_version = sys_ver[1]
python_version = f'{python_major_version}{pyhton_minor_version}'
if os.name == 'nt':
    wrapper_extension = f'cp{python_version}-*'
else:
    wrapper_extension = f'cpython-{python_version}*'


curdir = os.path.dirname(os.path.abspath(__file__)).replace('\\', '/')


cmdclass = {}

if os.environ.get('YZLITE_NO_BUILD_WRAPPERS', None) != '1':
    try:
        from cpp.tools.setup.build_wrappers_command import BuildWrappersCommand
        cmdclass['build_ext'] = BuildWrappersCommand
    except:
        pass

    class CustomBuildPy(build_py):
        def run(self):
            build_dir = f'{curdir}/build/lib'
            self.announce(f'Cleaning {build_dir}')
            clean_directory(build_dir)

            if 'build_ext' in cmdclass:
                # Build the YZLITE C++ wrappers
                self.run_command('build_ext')
            return super().run()

    cmdclass['build_py'] = CustomBuildPy


try:
    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel

    class BdistWheelCommand(_bdist_wheel):
        def finalize_options(self):
            super().finalize_options()
            # Ensure the generated .whl file is specific to the current Python/OS
            # as it's dependent on the built wrappers
            self.root_is_pure = False
            # Ensure the generated .whl has a unique name
            self.build_number = f'{int(time.time())}'

    cmdclass['bdist_wheel'] = BdistWheelCommand
except:
    pass


additional_install_dependencies = []

# If we're running Python3.7 then we also need to install pickle5
if python_version == '37':
    print('Adding pickle5 to install dependencies')
    additional_install_dependencies.append('pickle5')
    # The YZLITE does NOT have a dependency on this, but tensorflow does
    additional_install_dependencies.append('gast<=0.4.0')
# Other ensure pickle5 is NOT installed as that will break other dependencies
else:
    print('Uninstalling pickle5 (if necessary)')
    subprocess.run([sys.executable, '-m', 'pip', 'uninstall', 'pickle5'])


install_dependencies = [
    'typer',
    'pytest',
    'pytest-dependency',
    'pytest-html-reporter',
    'cmake',
    'ninja',
    'psutil',
    'pyaml',
    'tensorflow-macos',
    'tensorflow-metal',
    'tensorflow_probability',
    'tflite-support',
    'protobuf<3.20,>=3.9.2',
    'onnx',
    'onnxruntime',
    'numpy',
    'scipy',
    'matplotlib',
    'tqdm',
    'pillow',
    'librosa',
    'bincopy',
    'pyserial',
    'GPUtil',
    'patool',
    'prettytable',
    'msgpack'
] + additional_install_dependencies

extra_dependencies = {
    'full': [
        'opencv-python',
        'netron',
        'paramiko',
        'cryptography',
        'tensorboard_plugin_profile'
    ]
}


setup_dependencies_py = os.environ.get('YZLITE_SETUP_PY_DEPS', '').split('|')
# Find everything before the non-alphanumeric characters
package_name_re = re.compile(r'^(\w+)')
for dep in setup_dependencies_py:
    match = package_name_re.match(dep)
    if not match:
        continue
    dep_name = match.group(1).lower()
    modified = False
    for i, req in enumerate(install_dependencies):
        # If the YZLITE_SETUP_PY_DEPS is already an install requirement,
        # then just replace it
        if req.lower().startswith(dep_name):
            install_dependencies[i] = dep
            print(f'Modifying install requirement: {dep}')
            modified = True
            break
    # Otherwise add the new YZLITE_SETUP_PY_DEPS to the install requirements
    if not modified:
        print(f'Adding install requirement: {dep}')
        install_dependencies.append(dep)


setup(
    name='yizhu-yzlite',
    version=yzlite.__version__,
    description='This allows for developing embedded machine learning models using Tensorflow-Lite Micro',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/ReRAM-Labs/yzlite',
    author='Yizhu Technology',
    license='SPDX-License-Identifier: Zlib',
    classifiers=[
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
    python_requires='>=3.7,<3.11',
    setup_requires=['wheel'],
    install_requires=install_dependencies,
    extras_require=extra_dependencies,
    packages=find_packages(include=['yzlite', 'yzlite.*']),
    package_dir={'': '.'},
    package_data={
        'yzlite.core.tflite_micro': [f'_tflite_micro_wrapper.{wrapper_extension}'],
        'yzlite.core.tflite_micro.accelerators.mvp': [f'_mvp_wrapper.{wrapper_extension}'],
        'yzlite.core.tflite_micro.accelerators.mvp.estimator': ['estimators_url.yaml'],
        'yzlite.core.preprocess.audio.audio_feature_generator': [f'_audio_feature_generator_wrapper.{wrapper_extension}'],
        'yzlite.core.tflite_model_parameters.schema': ['dictionary.fbs', 'generate_schema.sh'],
        'yzlite.models.examples': [
            'audio_example1.yzlite.zip',
            'image_example1.yzlite.zip',
            'autoencoder_example.yzlite.zip',
        ],
        'yzlite.models.yizhutech': [
            'fingerprint_signature_generator.yzlite.zip',
            'keyword_spotting_on_off_v2.yzlite.zip',
            'keyword_spotting_mobilenetv2.yzlite.zip',
            'keyword_spotting_with_transfer_learning.yzlite.zip',
            'keyword_spotting_pacman_v3.yzlite.zip',
            'rock_paper_scissors.yzlite.zip',
            'keyword_spotting_alexa.yzlite.zip'
        ],
        'yzlite.models.tflite_micro': [
            'tflite_micro_speech.yzlite.zip',
            'tflite_micro_magic_wand.yzlite.zip'
        ],
        'yzlite.models.tinyml': [
            'anomaly_detection.yzlite.zip',
            'image_classification.yzlite.zip',
            'keyword_spotting.yzlite.zip',
            'visual_wake_words.yzlite.zip'
        ],
        'yzlite.utils.firmware_apps': ['download_urls.yaml'],
        'yzlite.utils.test_helper.data': ['*.tflite', '*.h5'],
        'yzlite.utils.audio_visualizer.settings': ['config.yaml'],
        'yzlite.utils.audio_visualizer.gui': ['favicon.ico'],
        'yzlite.examples': ['*.md', '.ipynb'],
        'yzlite.tutorials': ['*.md', '.ipynb'],
    },
    cmdclass=cmdclass,
    entry_points={
        'console_scripts': ['yzlite=yzlite.cli.main:main'],
    }
)
