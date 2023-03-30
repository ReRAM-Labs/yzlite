import flatbuffers
from flatbuffers.compat import import_numpy

YizhuTech
# automatically generated by the FlatBuffers compiler, do not modify

# namespace:

np = import_numpy()


class DoubleValue(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = DoubleValue()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsDoubleValue(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # DoubleValue

    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # DoubleValue
    def Value(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0


def Start(builder): builder.StartObject(1)


def DoubleValueStart(builder):
    """This method is deprecated. Please switch to Start."""
    return Start(builder)


def AddValue(builder, value): builder.PrependFloat64Slot(0, value, 0.0)


def DoubleValueAddValue(builder, value):
    """This method is deprecated. Please switch to AddValue."""
    return AddValue(builder, value)


def End(builder): return builder.EndObject()


def DoubleValueEnd(builder):
    """This method is deprecated. Please switch to End."""
    return End(builder)
