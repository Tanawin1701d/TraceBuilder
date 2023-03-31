import os
import sys

sys.path.append(os.path.dirname(os.path.realpath(__file__)))


import uop.translator as uop
import mop.translator as mop
import decoder.translator as dec

decOPR_to_mopOPR = {
                      "R"     : "REG",
                      "L"     : "MEM",
                      "S"     : "MEM",
                      "I"     : "DUMMY"
}


def satisfyDecWithMop( singleDec, MOP_DICT ):
    #print(singleDec)
    if singleDec[dec.DEC_META_NAME] not in MOP_DICT:
        raise ValueError(f"there is no MACROOP to map from {singleDec}")
    macroopName = singleDec[dec.DEC_META_NAME]

    #### check input side
    decInputTypes = [decOPR_to_mopOPR[decType]
                     for decType in singleDec[dec.DEC_META_INPUT]
                     if  decType != dec.DEC_IO_TYPE_IMM
                    ]
    mopInputTypes = [(vt, vid) for vt, vid in MOP_DICT[macroopName][mop.MOP_META_INPUT].values()]  # name : (vt, vid)
    mopInputTypes = sorted(mopInputTypes, key= lambda x: x[1])  ## sort by input macroop order
    mopInputTypes = [vt for vt, vid in mopInputTypes]
    if mopInputTypes != decInputTypes:
        raise AttributeError(f"decoder input {singleDec} \n\n\n      MISMATCH with \n\n\n\n    {MOP_DICT[macroopName]}     !")


    #### check output side
    decOutputType = [decOPR_to_mopOPR[decType]
                    for decType in singleDec[dec.DEC_META_OUTPUT]
                    if  decType != dec.DEC_IO_TYPE_IMM
                    ]
    mopOutputTypes = [(vt, vid) for vt, vid in MOP_DICT[macroopName][mop.MOP_META_OUTPUT].values()]
    mopOutputTypes = sorted(mopOutputTypes, key= lambda x: x[1])
    mopOutputTypes = [vt for vt, vid in mopOutputTypes]
    if mopOutputTypes != decOutputType:
        raise AttributeError(f"decoder output {singleDec} \n\n\n      MISMATCH with \n\n\n\n    {MOP_DICT[macroopName]}     !")
    #######################
def satisfyMopWithUop(singleMop, UOP_DICT):
    # mopdict is name -> mopmeta data
    for uopRelName, uopMeta in singleMop[mop.MOP_META_MICROOP].items():  # uop relative name in mop view
        if not (uopMeta[mop.MOP_META_MICROOP_TYPE] in UOP_DICT):
            raise (ValueError(f"there is no microop type for name {uopRelName} "
                              f"in uop dictionary from mop {singleMop[mop.MOP_META_NAME]}"))

        uopType = uopMeta[mop.MOP_META_MICROOP_TYPE]
        ##### check input
        inputInMacroView = []
        inputInuopView   = UOP_DICT[uopType][uop.UOP_MT_INPUT_VT]

        for varName in uopMeta[mop.MOP_META_MICROOP_INPUT]:
            #### get type from macro op
            if varName in singleMop[mop.MOP_META_VARTEMP]:
                inputInMacroView.append(mop.MOP_IO_TYPE_TEMP)
            elif varName in singleMop[mop.MOP_META_INPUT]:
                ##### case
                inputInMacroView.append(singleMop[mop.MOP_META_INPUT][varName][0])
            else:
                raise ( AttributeError(f"check uop input from mop faile due to missing "
                                       f"vartype for {varName} in {singleMop}") )

        if inputInMacroView != inputInuopView:
            raise ( AttributeError(f"uop input argument from macrooop{inputInMacroView} for {singleMop} is mismatch from uop argument {inputInuopView}") )


        ##### check output
        outputInMacroView = []
        outputInuopView   = UOP_DICT[uopType][uop.UOP_MT_OUTPUT_VT]

        for varName in uopMeta[mop.MOP_META_MICROOP_OUTPUT]:
            #### get type from macro op
            if varName in singleMop[mop.MOP_META_VARTEMP]:
                outputInMacroView.append(mop.MOP_IO_TYPE_TEMP)
            elif varName in singleMop[mop.MOP_META_OUTPUT]:
                ##### case
                outputInMacroView.append(singleMop[mop.MOP_META_OUTPUT][varName][0])   ## ... [varName] will get (TYPE, id) so, we should [0] to get type
            else:
                raise ( AttributeError(f"check uop output from mop fail due to missing "
                                       f"vartype for {varName} in {singleMop}") )


        if outputInMacroView != outputInuopView:
            raise ( AttributeError(f"uop output argument from macrooop{outputInMacroView} is mismatch from uop argument {outputInuopView}") )


def convertUopListToUopDict(uopList):
    ret = dict()

    for singleUop in uopList:
        ret.update({singleUop[uop.UOP_MT_NAME]: singleUop})

    return  ret

def convertMopListToMopDict(mopList):
    ret = dict()
    for singleMop in mopList:
        ret.update({singleMop[mop.MOP_META_NAME]: singleMop})
    return ret


def start():
    uopMetaList  = uop.start()
    UOPDICT      = convertUopListToUopDict(uopMetaList)

    mopMetaList  = mop.start()
    MOPDICT      = convertMopListToMopDict(mopMetaList)

    ###### satisfy mop
    for singleMop in mopMetaList:
        satisfyMopWithUop(singleMop, UOPDICT)
    ###################################################

    decMetaList =  dec.start()

    ###### satisfy dec
    for singleDec in decMetaList:
        satisfyDecWithMop(singleDec, MOPDICT)
    ###################################################

start()
