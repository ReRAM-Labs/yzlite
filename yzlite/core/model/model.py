from __future__ import annotations

import inspect
import logging
import os
from typing import Any, Callable, Dict, List, Tuple

import typer

from yzlite.core.utils import get_yzlite_logger
from yzlite.utils.logger import get_logger
from yzlite.utils.path import clean_directory, create_user_dir
from yzlite.utils.string_formatting import format_units

from .mixins.archive_mixin import ArchiveMixin
from .mixins.tflite_model_metadata_mixin import TfliteModelMetadataMixin
from .mixins.tflite_model_parameters_mixin import TfliteModelParametersMixin
from .model_attributes import (YZLiteModelAttributes,
                               YZLiteModelAttributesDecorator)
from .model_event import YZLiteModelEvent


@YZLiteModelAttributesDecorator()
class YZLiteModel(
    ArchiveMixin,
    TfliteModelMetadataMixin,
    TfliteModelParametersMixin
):
    """The root YZLITE Model object

    This must be defined in a model specification file.

    Refer to the `Model Specification <https://github.com/ReRAM-Labs/yzlite/docs/guides/model_specification.html>`_ guide fore more details.
    """

    def __init__(self, model_script_path: str = None):
        self._model_script_path = model_script_path
        # If not model script path was provided
        # then attempt to automatically determine it from the
        # filepath that instantiated this YZLiteModel object
        # i.e The model script path is the path of the script that created this YZLiteModel object
        if self._model_script_path is None:
            try:
                call_stack = inspect.stack()
                self._model_script_path = call_stack[1].filename.replace(
                    '\\', '/')
            except:
                pass

        self._cli = typer.Typer(
            context_settings=dict(
                max_content_width=100
            ),
            add_completion=False
        )
        self._attributes = YZLiteModelAttributes()
        self._event_handlers: Dict[YZLiteModelEvent,
                                   Tuple[Callable[[YZLiteModel, Any], None], dict]] = {}
        # At this point, no model properties have been registered
        # See load_yzlite_model_with_path() for the AFTER_MODEL_LOAD event
        self.trigger_event(YZLiteModelEvent.BEFORE_MODEL_LOAD)

    @property
    def attributes(self) -> YZLiteModelAttributes:
        """Return all model attributes"""
        return self._attributes

    def get_attribute(self, name: str):
        """Return attribute value or None if unknown"""
        return self._attributes.get_value(name)

    @property
    def cli(self) -> typer.Typer:
        """Custom command CLI

        This is used to register custom commands
        The commands may be invoked with:
        yzlite custom <model name> [command args]
        """
        return self._cli

    @property
    def model_specification_path(self) -> str:
        """Return the absolute path to the model's specification python script"""
        return self._attributes['model_specification_path']

    @property
    def name(self) -> str:
        """The name of this model, this the filename of the model's Python script.
        """
        return self._attributes['name']

    @property
    def version(self) -> int:
        """The model version, e.g. 3
        """
        return self._attributes['version']

    @version.setter
    def version(self, v: int):
        if not isinstance(v, int):
            raise ValueError('Version must be an integer')
        self._attributes['version'] = v

    @property
    def description(self) -> str:
        """A description of this model and how it should be use.
        This is added to the .tflite model flatbuffer "description" field
        """
        return self._attributes['description']

    @description.setter
    def description(self, v: str):
        self._attributes['description'] = v

    @property
    def log_dir(self) -> str:
        """Path to directory where logs will be generated
        """
        log_dir = self._attributes['log_dir']
        if not log_dir:
            self._attributes['log_dir'] = create_user_dir(
                suffix=f'models/{self.name}',
            )
        elif not os.path.exists(log_dir):
            self._attributes['log_dir'] = create_user_dir(
                base_dir=log_dir,
            )
        return self._attributes['log_dir']

    @log_dir.setter
    def log_dir(self, v: str):
        self._attributes['log_dir'] = v

    def create_log_dir(self, suffix: str = '', delete_existing=False) -> str:
        """Create a directory for storing model log files"""
        log_dir = create_user_dir(
            suffix=suffix,
            base_dir=self.log_dir
        )
        if delete_existing:
            clean_directory(log_dir)
        return log_dir

    def create_logger(self, name, parent: logging.Logger = None) -> logging.Logger:
        """Create a logger for this model"""
        train_log_dir = self.create_log_dir(name)
        log_file = f'{train_log_dir}/log.txt'
        train_logger = get_logger(name, log_file=log_file, log_file_mode='w')
        if parent is not None:
            train_logger.parent = parent
            train_logger.propagate = True
        return train_logger

    @property
    def h5_log_dir_path(self) -> str:
        """Path to .h5 model file that is generated in the log directory at the end of training"""
        h5_path = f'{self.log_dir}/{self.name}'
        if self.test_mode_enabled:
            h5_path += '.test.h5'
        else:
            h5_path += '.h5'

        return h5_path

    @property
    def tflite_log_dir_path(self) -> str:
        """Path to .tflite model file that is generated in the log directory at the end of training (if quantization is enabled)"""
        tflite_path = f'{self.log_dir}/{self.name}'
        if self.test_mode_enabled:
            tflite_path += '.test.tflite'
        else:
            tflite_path += '.tflite'

        return tflite_path

    @property
    def unquantized_tflite_log_dir_path(self) -> str:
        """Path to unquantized/float32 .tflite model file that is generated in the
        log directory at the end of training (if enabled)"""
        tflite_path = f'{self.log_dir}/{self.name}.float32'
        if self.test_mode_enabled:
            tflite_path += '.test.tflite'
        else:
            tflite_path += '.tflite'

        return tflite_path

    @property
    def classes(self) -> List[str]:
        """Return a list of the class name strings this model expects"""
        try:
            return self._attributes.get_value('*classes')
        except AttributeError:
            # pylint: disable=raise-missing-from
            raise ValueError(
                'Model does not specify the dataset\'s classes.\n'
                'It must either be manually specified, e.g. my_model.classes = ["dog", "cat"] or inherit a mixin that supports an classes, e.g.: ImageDatasetMixin')

    @classes.setter
    def classes(self, v: List[str]):
        try:
            self._attributes.set_value('*classes', v)
        except AttributeError:
            self._attributes.register('dataset.classes', dtype=(list, tuple))
            self._attributes.set_value('dataset.classes', v)

    @property
    def n_classes(self) -> int:
        """Return the number of classes this model expects"""
        return len(self.classes)

    @property
    def input_shape(self) -> Tuple[int]:
        """Return the image input shape as a tuple of integers"""
        try:
            return self._attributes.get_value('*input_shape')
        except AttributeError:
            # pylint: disable=raise-missing-from
            raise ValueError(
                'Model does not specify the dataset\'s input_shape.\n'
                'It must either be manually specified, e.g. my_model.input_shape = (96,96,3) or inherit a mixin that supports an input_shape, e.g.: ImageDatasetMixin'
            )

    @input_shape.setter
    def input_shape(self, v: Tuple[int]):
        try:
            self._attributes.set_value('*input_shape', v)
        except AttributeError:
            self._attributes.register(
                'dataset.input_shape', dtype=(list, tuple))
            self._attributes.set_value('dataset.input_shape', v)

    @property
    def keras_custom_objects(self) -> dict:
        """Get/set custom objects that should be loaded with the Keras model

        See https://keras.io/guides/serialization_and_saving/#custom-objects for more details.
        """
        return self._attributes.get_value('keras_custom_objects', default={})

    @keras_custom_objects.setter
    def keras_custom_objects(self, v: dict):
        self._attributes['keras_custom_objects'] = v

    @property
    def test_mode_enabled(self) -> bool:
        """Return if testing mode has been enabled"""
        return self._attributes['test_mode_enabled']

    def enable_test_mode(self):
        """Enable testing mode"""
        self._attributes['test_mode_enabled'] = True
        get_yzlite_logger().info('Enabling test mode')
        self.log_dir = f'{self.log_dir}-test'

    def summary(self) -> str:
        """Return a summary of the model"""
        s = f'Name: {self.name}\n'
        s += f'Version: {self.version}\n'
        s += f'Description: {self.description}\n'

        params = self.model_parameters
        exclude_params = ['name', 'version', 'classes', 'runtime_memory_size']

        try:
            classes = self.classes
        except:
            if 'classes' in params:
                classes = params['classes']
            else:
                classes = None

        if classes:
            classes = ', '.join(classes)
            s += f'Classes: {classes}\n'

        try:
            input_shape = 'x'.join(self.input_shape)
            s += f'Input shape: {input_shape}\n'
        except:
            pass

        try:
            dataset = self.dataset  # pylint: disable=no-member
            if isinstance(dataset, str):
                s += f'Dataset: {dataset}\n'
        except:
            pass

        if 'runtime_memory_size' in params and params['runtime_memory_size']:
            s += f'Runtime memory size (RAM): {format_units(params["runtime_memory_size"])}\n'

        for key, value in params.items():
            if (key in ('hash', 'date') and not value) or key in exclude_params:
                continue
            s += f'{key}: {value}\n'

        return s.strip()

    def add_event_handler(
        self,
        event: YZLiteModelEvent,
        handler: Callable[[YZLiteModel, logging.Logger, Any], None],
        **kwargs
    ):
        """Register an event handler

        Register a handler that will be invoked on the corresponding :py:class:`~YZLiteModelEvent`

        The given handler should have the signature:

        .. highlight:: python
        .. code-block:: python

            def my_event_handler(yzlite_model:YZLiteModel, logger:logging.Logger, **kwargs):
                ...

        Where ``kwargs`` will contain keyword arguments specific to the :py:class:`~YZLiteModelEvent`
        as well as any keyword arguments passed to this API.

        .. note::

            - Exceptions raised by the handler will be logged, but not stop further execution
            - Event handlers are invoked in the order in which they are registered

        Args:
            event: The :py:class:`~YZLiteModelEvent` on which the handler will be invoked
            handler: Function to be invoked for the given event
            kwargs: Additional keyword arguments to provided to the ``handler``
                NOTE: These keyword arguments must not collide with the event-specific keyword arguments
        """
        if event not in self._event_handlers:
            self._event_handlers[event] = []

        self._event_handlers[event].append((handler, kwargs))

    def trigger_event(
        self,
        event: YZLiteModelEvent,
        **kwargs
    ):
        """Trigger all handlers for the given event

        This is used internally by the YZLITE.
        """
        from .model_utils import pop_active_model, push_active_model

        get_yzlite_logger().debug(f'Model event: {event}')

        if event in (
            YZLiteModelEvent.TRAIN_STARTUP,
            YZLiteModelEvent.EVALUATE_STARTUP,
            YZLiteModelEvent.QUANTIZE_STARTUP,
        ):
            push_active_model(self)
        elif event in (
            YZLiteModelEvent.TRAIN_SHUTDOWN,
            YZLiteModelEvent.EVALUATE_SHUTDOWN,
            YZLiteModelEvent.QUANTIZE_SHUTDOWN
        ):
            pop_active_model()

        if event not in self._event_handlers:
            return

        logger = kwargs.pop('logger', get_yzlite_logger())

        for handler, kws in self._event_handlers[event]:
            try:
                handler(yzlite_model=self, logger=logger, **kwargs, **kws)
            except Exception as e:
                get_yzlite_logger().warning(
                    f'Model event: {event}, handler: {handler}, failed, err: {e}', exc_info=e)

    def __setattr__(self, name, value):
        if not name.startswith('_') and not self.has_attribute(name):
            raise AttributeError(
                f'YZLiteModel does not have the attribute: {name}')
        object.__setattr__(self, name, value)

    def has_attribute(self, name):
        if name in self._attributes:
            return True

        for key, _ in inspect.getmembers(self.__class__, lambda x: isinstance(x, property)):
            if key == name:
                return True

        return False

    def __str__(self):
        s = f'Name: {self.name}\n'
        s += f'Version: {self.version}\n'
        s += f'Description: {self.description}'
        return s

    def _register_attributes(self):
        if self._model_script_path:
            # By default, the model name is the model file's filename
            model_name = os.path.basename(self._model_script_path)
            idx = model_name.rfind('.')
            if idx != -1:
                model_name = model_name[:idx]
        else:
            model_name = 'my_model'

        self._attributes.register(
            'model_specification_path', self._model_script_path, dtype=str)
        self._attributes.register(
            'description', 'Generated by yizhu Tech\'s YZLITE Python package', dtype=str)
        self._attributes.register('log_dir', '', dtype=str)
        self._attributes.register('name', model_name, dtype=str)
        self._attributes.register('version', 1, dtype=int)
        self._attributes.register('test_mode_enabled', False, dtype=bool)
        self._attributes.register('keras_custom_objects', dtype=dict)
