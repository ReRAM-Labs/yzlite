"""Direction Commands
=======================

This is a `synthetically <https://github.com/chenxingqiang/yzlite/yzlite/tutorials/synthetic_audio_dataset_generation.html>`_ generated dataset with the keywords:

- **left**
- **right**
- **up**
- **down**
- **stop**
- **go**

The samples are 16kHz, 16-bit PCM ``.wav`` files.


.. seealso::

    - `AudioDatasetGenerator <https://github.com/chenxingqiang/yzlite/docs/python_api/utils/audio_dataset_generator/index.html>`_
    - `Synthetic Audio Dataset Generation Tutorial <https://github.com/chenxingqiang/yzlite/yzlite/tutorials/synthetic_audio_dataset_generation.html>`_

"""


from .download import CLASSES, DOWNLOAD_URL, VERIFY_SHA1, download
from .generate_dataset import generate_dataset
