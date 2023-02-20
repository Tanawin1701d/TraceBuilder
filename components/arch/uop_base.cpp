//
// Created by tanawin on 12/2/2566.
//

#include "uop_base.h"

#include <utility>

uint64_t
UOP_BASE::getSeqNum() const {
    return seqNum;
}

void
UOP_BASE::setSeqNum(uint64_t _seqNum) {
    seqNum = _seqNum;
}


////// simple compute reg
/////////////////////////////////////////////////////////////////////////////
SIMPLE_COMP_REG_UOP::SIMPLE_COMP_REG_UOP(vector<REG_OPERAND> _srcRegs,
                                         vector<REG_OPERAND> _desRegs):
srcRegs(std::move(_srcRegs)),
desRegs(std::move(_desRegs))
{}

bool SIMPLE_COMP_REG_UOP::isdependOnReg(const REGNUM &sucReg) {
    for (const REG_OPERAND& mydesOperand: desRegs){
        if (mydesOperand.getRegId() == sucReg)
            return true;
    }
    return false;
}

void SIMPLE_COMP_REG_UOP::doDepenCheck() {
    /// TODO ask connect to instruction window

}

vector<REG_OPERAND>&
SIMPLE_COMP_REG_UOP::getSrcRegs() {
    return srcRegs;
}

vector<REG_OPERAND>&
SIMPLE_COMP_REG_UOP::getDesRegs(){
    return desRegs;
}

////// simple load uop
/////////////////////////////////////////////////////////////////////////////

SIMPLE_LOAD_UOP::SIMPLE_LOAD_UOP(LD_OPERAND _srcLoad) :
srcLoad(_srcLoad) {}

bool
SIMPLE_LOAD_UOP::isdependOnMem(const ADDR &sucAddr, int size, bool isLoad) {
    return false;
}

void
SIMPLE_LOAD_UOP::doDepenCheck(/*TODO pass instruction window*/) {

}

LD_OPERAND&
SIMPLE_LOAD_UOP::getSrcLoad() {
    return srcLoad ;
}


////// simple store uop
/////////////////////////////////////////////////////////////////////////////

SIMPLE_STORE_UOP::SIMPLE_STORE_UOP(ST_OPERAND _desStore) :
desStore(_desStore){}

bool
SIMPLE_STORE_UOP::isdependOnMem(const ADDR &sucAddr, int size, bool isLoad) {
    if (isLoad){
        //// TODO check overlaping

    }
    return false; /// if store rob will handle
}

void
SIMPLE_STORE_UOP::doDepenCheck(/*TODO pass instruction window*/) {

}

ST_OPERAND&
SIMPLE_STORE_UOP::getDesStore() {
    return desStore ;
}

////// simple store uop
/////////////////////////////////////////////////////////////////////////////

SIMPLE_IMM_UOP::SIMPLE_IMM_UOP(IMM_OPERAND _srcImm ) :
        srcImm(_srcImm){}

void
SIMPLE_IMM_UOP::doDepenCheck(/*TODO pass instruction window*/) {

}

IMM_OPERAND&
SIMPLE_IMM_UOP::getSrcImm() {
    return srcImm ;
}
