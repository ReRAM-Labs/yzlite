# automatically generated by the FlatBuffers compiler, do not modify

# namespace:

import flatbuffers
from flatbuffers.compat import import_numpy

np = import_numpy()


class Uint64Value(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Uint64Value()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsUint64Value(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # Uint64Value

    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Uint64Value
    def Value(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint64Flags, o + self._tab.Pos)
        return 0


def Start(builder): builder.StartObject(1)


def Uint64ValueStart(builder):
    """This method is deprecated. Please switch to Start."""
    return Start(builder)


def AddValue(builder, value): builder.PrependUint64Slot(0, value, 0)


def Uint64ValueAddValue(builder, value):
    """This method is deprecated. Please switch to AddValue."""
    return AddValue(builder, value)


def End(builder): return builder.EndObject()


def Uint64ValueEnd(builder):
    """This method is deprecated. Please switch to End."""
    return End(builder)
