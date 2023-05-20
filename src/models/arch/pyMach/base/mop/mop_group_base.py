import itertools

import base.mop.mop_gen  as mop_gen
import base.uop.uop_gen  as uop_gen
import base.dec.dec_gen  as dec_gen

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

    def addMopArgExtractComb(self, arg : tuple):
        isValidArg =  all(isinstance(ele, (list, tuple)) for ele in arg)
        if not isValidArg:
            MopGroupError(f"can't extract args with {arg}")
        for exactArg  in itertools.product(*arg):
            self.addMopArg(exactArg)


    def gen(self):
        for arg in self.args:
            #print(arg)
            mop = self.MOP_TEMPLATE(*arg)
            mop_gen.addToMopGenGroup(mop)
            dec_gen.addToDecGenGroup(mop)
            for uop in mop.getUops():
                uop_gen.addToUopGenGroup(uop)
