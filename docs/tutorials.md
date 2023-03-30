__NOTE:__ Refer to the [online documentation](https://github.com/ReRAM-Labs/yzlite) to properly view this file

# Tutorials

The following tutorials provide end-to-end guides on how to develop machine learning model using the YZLITE:

| Name                                                                                                                                      | Description                                                                                                                                                                                            |
|-------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [Keyword Spotting - On/Off](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/keyword_spotting_on_off.html)                               | Develop an ML model to detect the keywords: "on" or "off"                                                                                                                                              |
| [Keyword Spotting - Pac-Man](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/keyword_spotting_pacman.html)                              | Develop a demo to play the game Pac-Man in a web browser using the keywords: "Left", "Right", "Up", "Down", "Stop", "Go"                                                                               |
| [Keyword Spotting - Alexa](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/keyword_spotting_alexa.html)                                 | Develop a demo to issue "Alexa" commands to the [AVS](https://developer.amazon.com/en-US/docs/alexa/alexa-voice-service/get-started-with-alexa-voice-service.html) cloud and locally play the response |
| [Image Classification - Rock/Paper/Scissors](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/image_classification.html)                 | Develop an image classification ML model to detect the hand gestures: "rock", "paper", "scissors"                                                                                                      |
| [Model Training in the "Cloud"](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/cloud_training_with_vast_ai.html)                       | _Vastly_ improve model training times by training a model in the "cloud" using [vast.ai](http://vast.ai)                                                                                               |
| [Logging to the Cloud](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/cloud_logging_with_wandb.html)                                   | Log model files and metrics to the cloud during training and evaluation using [Weights & Biases](http://wandb.ai)                                                                                               |
| [Model Optimization for MVP Hardware Accelerator](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/model_optimization.html)              | Use the various YZLITE tools to optimize a model to fit within an embedded device's resource constraints                                                                                                 |
| [Keyword Spotting with Transfer Learning](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/keyword_spotting_with_transfer_learning.html) | Use a pre-trained model to quickly train a new model that detects the keywords: "one", "two", "three", "four"                                                                                          |
| [Fingerprint Authentication](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/fingerprint_authentication.html)                           | Use ML to generate unique signatures from images of fingerprints to authenticate users                                                                                                                 |
| [ONNX to TF-Lite Model Conversion](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/onnx_to_tflite.html)                                 | Describes how to convert an [ONNX](https://onnx.ai/) formatted model file to the `.tflite` model format required by embedded targets                                                                   |
| [Model Debugging](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/model_debugging.html)                                                 | Describes how to debug an ML model during training                                                                                                                                                     |
| [Add an Existing Script to the YZLITE](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/add_existing_script_to_yzlite.html)                  | Describes how to convert an existing Tensorflow training script to support the YZLITE training flow                                                                                                      |
| [Synthetic Audio Dataset Generation](https://github.com/ReRAM-Labs/yzlite/yzlite/tutorials/synthetic_audio_dataset_generation.html)           | Describes how to generate a custom audio dataset using synthetic data. This allows for training keyword spotting ML models with custom keywords                                                                                                      |

```{eval-rst}
.. toctree::
   :maxdepth: 1
   :hidden:

   /yzlite/tutorials/keyword_spotting_on_off
   /yzlite/tutorials/keyword_spotting_pacman
   /yzlite/tutorials/keyword_spotting_alexa
   /yzlite/tutorials/image_classification
   /yzlite/tutorials/cloud_training_with_vast_ai
   /yzlite/tutorials/cloud_logging_with_wandb
   /yzlite/tutorials/model_optimization
   /yzlite/tutorials/keyword_spotting_with_transfer_learning
   /yzlite/tutorials/fingerprint_authentication
   /yzlite/tutorials/onnx_to_tflite
   /yzlite/tutorials/model_debugging
   /yzlite/tutorials/add_existing_script_to_yzlite
   /yzlite/tutorials/synthetic_audio_dataset_generation
```
