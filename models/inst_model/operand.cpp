//
// Created by tanawin on 7/2/2566.
//

#include "operand.h"

OPERAND::OPERAND(OPR_TYPE _OT, size_t _mcArgSIdx):
OT(_OT),
mcArgSIdx(_mcArgSIdx){}
///////////////////////////////////////////////////////////
/// reg operand
REG_OPERAND::REG_OPERAND(REGNUM _regId, size_t _mcArgSIdx):
regId(_regId),
OPERAND(O_REG, _mcArgSIdx)
{}

REGNUM REG_OPERAND::getRegId() const {
    return regId;
}

REGNUM
REG_OPERAND::getMeta(){ return regId;}
///////////////////////////////////////////////////////////
/// memory operand
MEM_OPERAND::MEM_OPERAND(
                            REGNUM _baseRegId,
                            REGNUM _indexRegId,
                            int    _scaleFactor,
                            IMM    _displacement,
                            ADDR    _size,
                            int    _memopNum,
                            OPR_TYPE _setOpr,
                            size_t _mcArgSIdx
                        ) :
baseRegId   (_baseRegId),
indexRegId  (_indexRegId),
scaleFactor (_scaleFactor),
displacement(_displacement),
size(_size),
memopNum(_memopNum),
OPERAND(_setOpr, _mcArgSIdx)
{}

REGNUM
MEM_OPERAND::getBaseRegId() const {
    return baseRegId;
}

REGNUM
MEM_OPERAND::getIndexRegId() const {
    return indexRegId;
}

int
MEM_OPERAND::getScaleFactor() const {
    return scaleFactor;
}

IMM
MEM_OPERAND::getDisplacement() const {
    return displacement;
}

ADDR
MEM_OPERAND::getSize() const {
    return size;
}

int MEM_OPERAND::getMemopNum() const {
    return memopNum;
}

ADDR MEM_OPERAND::getPhyAddr() const {
    return phyAddr;
}

ADAS
MEM_OPERAND::getMeta(){return {phyAddr, size};}

/////////////////  set

void MEM_OPERAND::setPhyAddr(ADDR _phyAddr) {
    MEM_OPERAND::phyAddr = _phyAddr;
}
///////////////////////////////////////////////////////////
/// load operand

LD_OPERAND::LD_OPERAND(
REGNUM _baseRegId,
REGNUM _indexRegId,
int    _scaleFactor,
IMM    _displacement,
ADDR    _size,
int    _memopNum,
size_t _mcArgSIdx
):
    MEM_OPERAND(_baseRegId,
                _indexRegId,
                _scaleFactor,
                _displacement,
                _size,
                _memopNum,
                O_MEM_LD,
                _mcArgSIdx){}
///////////////////////////////////////////////////////////
/// store operand

ST_OPERAND::ST_OPERAND(REGNUM _baseRegId,
                       REGNUM _indexRegId,
                       int    _scaleFactor,
                       IMM    _displacement,
                       ADDR   _size,
                       int    _memopNum,
                       size_t _mcArgSIdx
                       ):
        MEM_OPERAND(_baseRegId,
                    _indexRegId,
                    _scaleFactor,
                    _displacement,
                    _size,
                    _memopNum,
                    O_MEM_ST,
                    _mcArgSIdx){}
///////////////////////////////////////////////////////////
/// imm operand

IMM_OPERAND::IMM_OPERAND(IMM _imm):
imm(_imm),
OPERAND(O_IMM,-1)
{}

IMM
IMM_OPERAND::getImm() const {
    return imm;
};

IMM
IMM_OPERAND::getValue(){ return imm;}
