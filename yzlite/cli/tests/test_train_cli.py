import os

from yzlite import YZLITE_DIR
from yzlite.utils.test_helper import run_yzlite_command
from yzlite.utils.test_helper.data import TEST_MODEL_WEIGHTS

archive_path = f'{YZLITE_DIR}/utils/test_helper/test_image_model.yzlite.zip'


def test_train_help():
    if os.path.exists(archive_path):
        os.remove(archive_path)
    run_yzlite_command('train', '--help')


def test_train_model_name_cli():
    run_yzlite_command('train', 'test_image_model',
                       '-v', update_model_path=True)


def test_train_model_name_test_cli():
    run_yzlite_command('train', 'test_image_model-test',
                       '-v', update_model_path=True)


def test_train_model_spec_path_cli():
    spec_path = f'{YZLITE_DIR}/utils/test_helper/test_image_model.py'
    run_yzlite_command('train', spec_path, '-v')


def test_train_resume_cli():
    run_yzlite_command('train', 'test_image_model', '--clean',
                       '-v', '--epochs', 2, '--no-evaluate', update_model_path=True)
    run_yzlite_command('train', 'test_image_model', '--resume',
                       '--no-evaluate', update_model_path=True)


def test_train_resume_epoch_cli():
    run_yzlite_command('train', 'test_image_model',  '--clean',
                       '-v', '--epochs', 3, '--no-evaluate', update_model_path=True)
    run_yzlite_command('train', 'test_image_model', '--resume-epoch',
                       2, '--no-evaluate', update_model_path=True)


def test_train_weights_best_cli():
    run_yzlite_command('train', 'test_image_model', '--weights',
                       'best', '--no-evaluate', update_model_path=True)


def test_train_weights_path_cli():
    run_yzlite_command('train', 'test_image_model', '--weights',
                       TEST_MODEL_WEIGHTS, '--no-evaluate', update_model_path=True)
