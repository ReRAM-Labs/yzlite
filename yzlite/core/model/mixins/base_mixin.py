
from ..model_attributes import YZLiteModelAttributes


class BaseMixin(object):
    _attributes: YZLiteModelAttributes = None

    def _register_attributes(self):
        pass
