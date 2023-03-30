
import pytest

from yzlite.utils.test_helper import (generate_run_model_params,
                                      run_model_operation)


@pytest.mark.parametrize(*generate_run_model_params())
def test_tflite_micro_speech(op, tflite, build):
    run_model_operation('tflite_micro_speech', op, tflite, build)


@pytest.mark.parametrize(*generate_run_model_params())
def test_tflite_micro_magic_wand(op, tflite, build):
    run_model_operation('tflite_micro_magic_wand', op, tflite, build)
