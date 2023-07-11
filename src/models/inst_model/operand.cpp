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
            MEM_META memMeta,
            OPR_TYPE _setOpr,
            size_t _mcArgSIdx
    ) :
    _meta(memMeta),
    OPERAND(_setOpr, _mcArgSIdx) {
        assert(MAX_BYTE_PER_MICROOP > 0);
        ///// caculate expect uop that should handle this instr
    }

    MEM_META
    OPR_MEM::getMeta(ADDR startByte, ADDR stopByte) const{
        assert(startByte >= 0 && ((stopByte - startByte) <= MAX_BYTE_PER_MICROOP));
        MEM_META temp = _meta;
        temp.p_area.addr += startByte;
        temp.v_area.addr += startByte;
        temp.size = stopByte - startByte;
        assert((temp.p_area.addr + temp.size) <= (_meta.p_area.addr +  _meta.size));
        return temp;
    }

///////////////////////////////////////////////////////////
/// load operand

    OPR_MEM_LD::OPR_MEM_LD(MEM_META memMeta,size_t _mcArgSIdx)
    : OPR_MEM(memMeta,O_MEM_LD,_mcArgSIdx) {}
///////////////////////////////////////////////////////////
/// store operand

    OPR_MEM_ST::OPR_MEM_ST(MEM_META memMeta,size_t _mcArgSIdx
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