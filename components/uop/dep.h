//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_DEP_H
#define TRACEBUILDER_DEP_H

#include<iostream>
#include<unordered_set>
#include "../regMap/regMapper.h"
#include "../memMap/MemMng.h"

class UOP_BASE;
///// dependency management
class DEP_BASE{
protected:
    ///// current dependency of this microop
    std::unordered_set<UOP_BASE*> predecessors;
public:
    bool addDep(UOP_BASE* uop);
};
////// register dependency
class REG_DEP: public DEP_BASE{
public:
    ///// for successor to ask about dependency
    virtual bool isdependOnReg(const REGNUM& sucReg) { return false;};
    void addRegDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getRegDep();
};
////// memory addresss dependency
class MEM_DEP: public DEP_BASE{
public:
    ///// for successor to ask about dependency
    virtual bool isdependOnMem(const ADDR& sucAddr, int size, bool isLoad) { return false;};
    void addMemDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getMemDep();
};
////// execute order dependency
class EXE_DEP: public DEP_BASE{
public:
    ///// for successor to ask about dependency
    virtual bool isdepenOnEXE(const UOP_BASE* uop) { return false;};
    void addExeDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getExeDep();
};
////// temporary register  order dependency some physical register
class TEM_DEP: public DEP_BASE{
public:
    ///// for successor to ask about dependency
    virtual bool isdepenOnEXE(const UOP_BASE* uop) { return false;};
    void addTemDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getTemDep();
};




#endif //TRACEBUILDER_DEP_H
