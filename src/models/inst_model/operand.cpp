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
            REGNUM _baseRegId,
            REGNUM _indexRegId,
            int _scaleFactor,
            IMM _displacement,
            ADDR _size,
            int _memopNum,
            OPR_TYPE _setOpr,
            size_t _mcArgSIdx
    ) :
            baseRegId(_baseRegId),
            indexRegId(_indexRegId),
            scaleFactor(_scaleFactor),
            displacement(_displacement),
            size(_size),
            memopNum(_memopNum),
            current_ruop_count(0),
            OPERAND(_setOpr, _mcArgSIdx) {
        assert(MAX_BYTE_PER_MICROOP > 0);
        ///// caculate expect uop that should handle this instr
        expect_ruop_count = (int) ((_size + MAX_BYTE_PER_MICROOP - 1) / MAX_BYTE_PER_MICROOP);

    }

    REGNUM
    OPR_MEM::getBaseRegId() const {
        return baseRegId;
    }

    REGNUM
    OPR_MEM::getIndexRegId() const {
        return indexRegId;
    }

    int
    OPR_MEM::getScaleFactor() const {
        return scaleFactor;
    }

    IMM
    OPR_MEM::getDisplacement() const {
        return displacement;
    }

    ADDR
    OPR_MEM::getSize() const {
        return size;
    }

    void OPR_MEM::setPhyAddr(ADDR _phyAddr) {
        OPR_MEM::phyAddr = _phyAddr;
        OPR_MEM::nextPhyAddr = _phyAddr;
    }

    int OPR_MEM::getMemopNum() const {
        return memopNum;
    }

    ADDR OPR_MEM::getPhyAddr() const {
        return phyAddr;
    }

    ADAS
    OPR_MEM::getMeta() {
        if (nextPhyAddr >= (phyAddr + size)) {
            return {0, MAX_BYTE_PER_MICROOP};
        }
        ADDR nextSize = std::min((ADDR) MAX_BYTE_PER_MICROOP, (phyAddr + size) - nextPhyAddr);
        ADAS preRet = {nextPhyAddr, nextSize};
        nextPhyAddr += nextSize;
        return preRet;
    }

    void
    OPR_MEM::resetSharedOperandTracker() {
        current_ruop_count = 0;
        nextPhyAddr = phyAddr;
    }

///////////////////////////////////////////////////////////
/// load operand

    OPR_MEM_LD::OPR_MEM_LD(
            REGNUM _baseRegId,
            REGNUM _indexRegId,
            int _scaleFactor,
            IMM _displacement,
            ADDR _size,
            int _memopNum,
            size_t _mcArgSIdx
    ) :
            OPR_MEM(_baseRegId,
                    _indexRegId,
                    _scaleFactor,
                    _displacement,
                    _size,
                    _memopNum,
                    O_MEM_LD,
                    _mcArgSIdx) {}
///////////////////////////////////////////////////////////
/// store operand

    OPR_MEM_ST::OPR_MEM_ST(REGNUM _baseRegId,
                           REGNUM _indexRegId,
                           int _scaleFactor,
                           IMM _displacement,
                           ADDR _size,
                           int _memopNum,
                           size_t _mcArgSIdx
    ) :
            OPR_MEM(_baseRegId,
                    _indexRegId,
                    _scaleFactor,
                    _displacement,
                    _size,
                    _memopNum,
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