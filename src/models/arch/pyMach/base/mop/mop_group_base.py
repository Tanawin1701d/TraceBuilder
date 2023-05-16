import base.mop.mop_base as mop_base
import base.mop.mop_gen  as mop_gen

class MopGroupError(Exception):
    def __init__(self, message):
        super().__init__(message)

### this is used to generate same mop with multiple input argument at a time
class MOP_GROUP_BASE:
    args         : list ### list of tuple. the tuple is argument to initialize class
    argCount     : int
    MOP_TEMPLATE = None ## macro-op template class


    def __init__(self, _argCount,_mop_template):
        self.args = []
        self.argCount = _argCount
        self.MOP_TEMPLATE = _mop_template


    def addMopArg(self, arg):
        if len(arg) != self.argCount:
            raise(MopGroupError(f"mop group add argment error expect {str(self.argCount)} but got {arg}"))

        self.args.append(arg)

    def genMop(self):
        for arg in self.args:
            mop = self.MOP_TEMPLATE(*arg)
            mop_gen.addToMopGenGroup(mop)