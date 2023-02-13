//
// Created by tanawin on 7/2/2566.
//

#include "operand.h"

/// reg operand
REG_OPERAND::REG_OPERAND(REGNUM _regId): regId(_regId){}

REGNUM REG_OPERAND::getRegId() const {
    return regId;
}


/// memory operand
MEM_OPERAND::MEM_OPERAND(
                            REGNUM _baseRegId,
                            REGNUM _indexRegId,
                            int    _scaleFactor,
                            IMM    _displacement,
                            int    _size,
                            int    _memopNum
                        ) :
baseRegId   (_baseRegId),
indexRegId  (_indexRegId),
scaleFactor (_scaleFactor),
displacement(_displacement),
size(_size),
memopNum(_memopNum)
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

int
MEM_OPERAND::getSize() const {
    return size;
}


/// load operand

LD_OPERAND::LD_OPERAND(
REGNUM _baseRegId,
REGNUM _indexRegId,
int    _scaleFactor,
IMM    _displacement,
int    _size,
int    _memopNum
):
    MEM_OPERAND(_baseRegId,
                _indexRegId,
                _scaleFactor,
                _displacement,
                _size,
                _memopNum){}

/// store operand

ST_OPERAND::ST_OPERAND(REGNUM _baseRegId,
                       REGNUM _indexRegId,
                       int    _scaleFactor,
                       IMM    _displacement,
                       int     _size,
                       int    _memopNum):
        MEM_OPERAND(_baseRegId,
                    _indexRegId,
                    _scaleFactor,
                    _displacement,
                    _size,
                    _memopNum){}

/// imm operand

IMM_OPERAND::IMM_OPERAND(IMM _imm): imm(_imm){}

IMM
IMM_OPERAND::getImm() const {
    return imm;
};

