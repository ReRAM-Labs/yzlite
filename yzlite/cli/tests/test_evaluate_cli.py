import os

import pytest

from yzlite import YZLITE_DIR
from yzlite.utils.test_helper import run_yzlite_command

test_image_model_archive_path = f'{YZLITE_DIR}/utils/test_helper/test_image_model.yzlite.zip'
test_autoencoder_model_archive_path = f'{YZLITE_DIR}/utils/test_helper/test_autoencoder_model.yzlite.zip'


@pytest.mark.dependency()
def test_eval_train_image_model():
    if os.path.exists(test_image_model_archive_path):
        os.remove(test_image_model_archive_path)
    run_yzlite_command('train', 'test_image_model', '--clean',
                       '-v', '--no-evaluate', update_model_path=True)


@pytest.mark.dependency()
def test_eval_train_ae_model():
    if os.path.exists(test_autoencoder_model_archive_path):
        os.remove(test_autoencoder_model_archive_path)
    run_yzlite_command('train', 'test_autoencoder_model',
                       '--clean', '-v', '--no-evaluate', update_model_path=True)


def test_eval_help():
    run_yzlite_command('evaluate', '--help')


@pytest.mark.dependency(depends=['test_eval_train_image_model'])
def test_eval_image_model_h5():
    run_yzlite_command('evaluate', 'test_image_model',
                       '-v', update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_image_model'])
def test_eval_image_model_h5_archive():
    run_yzlite_command('evaluate', test_image_model_archive_path, '-v')


@pytest.mark.dependency(depends=['test_eval_train_image_model'])
def test_eval_image_model_tflite():
    run_yzlite_command('evaluate', 'test_image_model', '-v',
                       '--tflite', update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_image_model'])
def test_eval_image_model_tflite_count():
    run_yzlite_command('evaluate', 'test_image_model', '-v',
                       '--tflite', '--count', 3, update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_image_model'])
def test_eval_image_model_tflite_dump():
    run_yzlite_command('evaluate', 'test_image_model', '-v',
                       '--tflite', '--dump', update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_image_model'])
def test_eval_image_model_weights_best():
    run_yzlite_command('evaluate', 'test_image_model', '-v',
                       '--weights', 'best', update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_ae_model'])
def test_eval_ae_model_h5():
    run_yzlite_command('evaluate', 'test_autoencoder_model',
                       '-v', update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_ae_model'])
def test_eval_ae_model_h5_archive():
    run_yzlite_command('evaluate', test_autoencoder_model_archive_path, '-v')


@pytest.mark.dependency(depends=['test_eval_train_ae_model'])
def test_eval_ae_model_tflite():
    run_yzlite_command('evaluate', 'test_autoencoder_model',
                       '-v', '--tflite', update_model_path=True)


@pytest.mark.dependency(depends=['test_eval_train_ae_model'])
def test_eval_ae_model_weights_best():
    run_yzlite_command('evaluate', 'test_autoencoder_model',
                       '-v', '--weights', 'best', update_model_path=True)
