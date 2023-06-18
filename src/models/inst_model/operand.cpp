//
// Created by tanawin on 7/2/2566.
//

#include "operand.h"

namespace traceBuilder::model {


    OPERAND::OPERAND(OPR_TYPE OT, size_t _mcArgSIdx) :
            OT(OT),
            mcArgSIdx(_mcArgSIdx) {}

///////////////////////////////////////////////////////////
/// Treg operand
    OPR_TREG::OPR_TREG() :
            regId(0),
            OPERAND(O_REG, 0) {}

    OPR_TREG::OPR_TREG(int regId) :
            regId(regId),
            OPERAND(O_TEMP, 0)
    {
        assert(regId != UNUSEDREG);
    }

    REGNUM OPR_TREG::getRegId() const {
        return regId;
    }

    REGNUM
    OPR_TREG::getMeta() const { return regId; }

///////////////////////////////////////////////////////////
/// reg operand
    OPR_REG::OPR_REG(REGNUM _regId, size_t _mcArgSIdx) :
            regId(_regId),
            OPERAND(O_REG, _mcArgSIdx) {}

    REGNUM OPR_REG::getRegId() const {
        return regId;
    }

    REGNUM
    OPR_REG::getMeta() const { return regId; }

///////////////////////////////////////////////////////////
/// memory operand
    OPR_MEM::OPR_MEM(
            MEM_OPR_META memMeta,
            OPR_TYPE _setOpr,
            size_t _mcArgSIdx
    ) :
    _meta(memMeta),
    current_ruop_count(0),
    OPERAND(_setOpr, _mcArgSIdx) {
        assert(MAX_BYTE_PER_MICROOP > 0);
        ///// caculate expect uop that should handle this instr
        expect_ruop_count = (int) ((_meta.size + MAX_BYTE_PER_MICROOP - 1) / MAX_BYTE_PER_MICROOP);
    }

    void
    OPR_MEM::setVirAddr(ADDR virAddr){
        _virAddr = virAddr;
        _nextVirAddr = virAddr;
    }

    void
    OPR_MEM::setPhyAddr(ADDR phyAddr) {
        OPR_MEM::_phyAddr = phyAddr;
    }

    ADAS
    OPR_MEM::getMeta_phyArea(){
        ADDR diffVirAddr = _nextVirAddr - _virAddr;
        return { _phyAddr + diffVirAddr, getCurUopSize()};
    }
    //// TODO we might have explicit to iterate rather than auto increment from virArea
    ADAS
    OPR_MEM::getMeta_virArea(){
        if (_nextVirAddr >= getEndVirAddr())
            return {0, MAX_BYTE_PER_MICROOP};
        ADDR nowSize = getCurUopSize();
        ADAS preret = {_nextVirAddr, nowSize};
        _nextVirAddr = _nextVirAddr + nowSize;
        return preret;
    }

    void
    OPR_MEM::resetSharedOperandTracker() {
        current_ruop_count = 0;
        _nextVirAddr = _virAddr;
    }

///////////////////////////////////////////////////////////
/// load operand

    OPR_MEM_LD::OPR_MEM_LD(MEM_OPR_META memMeta,size_t _mcArgSIdx)
    : OPR_MEM(memMeta,O_MEM_LD,_mcArgSIdx) {}
///////////////////////////////////////////////////////////
/// store operand

    OPR_MEM_ST::OPR_MEM_ST(MEM_OPR_META memMeta,size_t _mcArgSIdx
    ) :
            OPR_MEM(memMeta,
                    O_MEM_ST,
                    _mcArgSIdx) {}
///////////////////////////////////////////////////////////
/// imm operand

    OPR_IMM::OPR_IMM(IMM _imm, size_t _mcArgSIdx) :
            imm(_imm),
            OPERAND(O_IMM, _mcArgSIdx) {}

    IMM
    OPR_IMM::getImm() const {
        return imm;
    };

    IMM
    OPR_IMM::getValue() const { return imm; }

}