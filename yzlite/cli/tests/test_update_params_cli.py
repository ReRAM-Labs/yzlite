import json
import os
import shutil

import pytest
import yaml

from yzlite import YZLITE_DIR
from yzlite.core import (TfliteModel, TfliteModelParameters,
                         load_tflite_or_keras_model, load_yzlite_model)
from yzlite.utils.path import create_tempdir
from yzlite.utils.test_helper import run_yzlite_command
from yzlite.utils.test_helper.data import IMAGE_CLASSIFICATION_TFLITE_PATH

test_model_src = f'{YZLITE_DIR}/utils/test_helper/test_image_model.py'
tmp_dir = create_tempdir("tests/update_params")
test_model_dst = f'{tmp_dir}/test_params_model.py'
test_archive_path = f'{tmp_dir}/test_params_model.yzlite.zip'


@pytest.mark.dependency()
def test_train_model():
    os.environ['YZLITE_MODEL_PATHS'] = tmp_dir
    shutil.copy(test_model_src, test_model_dst)
    run_yzlite_command('train', 'test_params_model', '--no-evaluate')
    shutil.copy(test_archive_path, test_archive_path + '.bak')


def test_help():
    run_yzlite_command('update_params', '--help')


@pytest.mark.dependency(depends=['test_train_model'])
def test_update_script():
    os.environ['YZLITE_MODEL_PATHS'] = tmp_dir
    shutil.copy(test_archive_path + '.bak', test_archive_path)

    with open(test_model_dst, 'r') as fp:
        spec = fp.read()

    # Add some new model parameters
    spec += '\n'
    spec += "yzlite_model.model_parameters['str_param'] = 'my string'\n"
    spec += "yzlite_model.model_parameters['int_param'] = 43\n"
    spec += "yzlite_model.model_parameters['float_param'] = 3.14\n"

    with open(test_model_dst, 'w') as fp:
        fp.write(spec)

    run_yzlite_command('update_params', 'test_params_model')

    yzlite_model = load_yzlite_model('test_params_model')

    assert 'str_param' in yzlite_model.model_parameters
    assert yzlite_model.model_parameters['str_param'] == 'my string'
    assert 'int_param' in yzlite_model.model_parameters
    assert yzlite_model.model_parameters['int_param'] == 43
    assert 'float_param' in yzlite_model.model_parameters
    assert yzlite_model.model_parameters['float_param'] == pytest.approx(3.14)


@pytest.mark.dependency(depends=['test_train_model'])
def test_name_cli_params():
    os.environ['YZLITE_MODEL_PATHS'] = tmp_dir
    shutil.copy(test_archive_path + '.bak', test_archive_path)

    run_yzlite_command(
        'update_params', 'test_params_model',
        'str_param=my string',
        'int_param=43',
        'float_param=3.14'
    )

    tf_model = load_tflite_or_keras_model(
        test_archive_path, model_type='tflite')
    tf_params = TfliteModelParameters.load_from_tflite_model(tf_model)

    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)


@pytest.mark.dependency(depends=['test_train_model'])
def test_json():
    os.environ['YZLITE_MODEL_PATHS'] = tmp_dir
    shutil.copy(test_archive_path + '.bak', test_archive_path)

    params = dict(
        str_param='my string',
        int_param=43,
        float_param=3.14
    )
    json_path = f'{tmp_dir}/params.json'
    with open(json_path, 'w') as fp:
        json.dump(params, fp)

    run_yzlite_command(
        'update_params', 'test_params_model',
        '--params', json_path
    )

    tf_model = load_tflite_or_keras_model(
        test_archive_path, model_type='tflite')
    tf_params = TfliteModelParameters.load_from_tflite_model(tf_model)

    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)


@pytest.mark.dependency(depends=['test_train_model'])
def test_yaml():
    os.environ['YZLITE_MODEL_PATHS'] = tmp_dir
    shutil.copy(test_archive_path + '.bak', test_archive_path)

    params = dict(
        str_param='my string',
        int_param=43,
        float_param=3.14
    )
    yaml_path = f'{tmp_dir}/params.yaml'
    with open(yaml_path, 'w') as fp:
        yaml.dump(params, fp, Dumper=yaml.SafeDumper)

    run_yzlite_command(
        'update_params', 'test_params_model',
        '--params', yaml_path
    )

    tf_model = load_tflite_or_keras_model(
        test_archive_path, model_type='tflite')
    tf_params = TfliteModelParameters.load_from_tflite_model(tf_model)

    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)


@pytest.mark.dependency(depends=['test_train_model'])
def test_archive():
    shutil.copy(test_archive_path + '.bak', test_archive_path)

    run_yzlite_command(
        'update_params', test_archive_path,
        'str_param=my string',
        'int_param=43',
        'float_param=3.14'
    )

    tf_model = load_tflite_or_keras_model(
        test_archive_path, model_type='tflite')
    tf_params = TfliteModelParameters.load_from_tflite_model(tf_model)

    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)


def test_tflite():
    output_path = f'{tmp_dir}/image_classification.tflite'
    shutil.copy(IMAGE_CLASSIFICATION_TFLITE_PATH, output_path)

    run_yzlite_command(
        'update_params', output_path,
        '--description', 'This is test....',
        'str_param=my string',
        'int_param=43',
        'float_param=3.14'
    )
    assert os.path.exists(output_path)

    tf_params: TfliteModelParameters = TfliteModelParameters.load_from_tflite_file(
        output_path)
    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)

    tf_model = TfliteModel.load_flatbuffer_file(output_path)
    assert tf_model.description == 'This is test....'


def test_tflite_output_dir():
    output_path = f'{tmp_dir}/image_classification.tflite'
    shutil.copy(IMAGE_CLASSIFICATION_TFLITE_PATH, output_path)

    run_yzlite_command(
        'update_params', output_path,
        '--output', os.path.dirname(output_path),
        '--description', 'This is test....',
        'str_param=my string',
        'int_param=43',
        'float_param=3.14'
    )
    assert os.path.exists(output_path)

    tf_params: TfliteModelParameters = TfliteModelParameters.load_from_tflite_file(
        output_path)
    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)

    tf_model = TfliteModel.load_flatbuffer_file(output_path)
    assert tf_model.description == 'This is test....'


def test_tflite_output_file():
    output_path = f'{tmp_dir}/image_classification.tflite'
    shutil.copy(IMAGE_CLASSIFICATION_TFLITE_PATH, output_path)

    run_yzlite_command(
        'update_params', output_path,
        '--output', output_path,
        '--description', 'This is test....',
        'str_param=my string',
        'int_param=43',
        'float_param=3.14'
    )
    assert os.path.exists(output_path)

    tf_params: TfliteModelParameters = TfliteModelParameters.load_from_tflite_file(
        output_path)
    assert 'str_param' in tf_params
    assert tf_params['str_param'] == 'my string'
    assert 'int_param' in tf_params
    assert tf_params['int_param'] == 43
    assert 'float_param' in tf_params
    assert tf_params['float_param'] == pytest.approx(3.14)

    tf_model = TfliteModel.load_flatbuffer_file(output_path)
    assert tf_model.description == 'This is test....'
