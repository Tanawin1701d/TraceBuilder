//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_DEP_H
#define TRACEBUILDER_DEP_H

#include<iostream>
#include<unordered_set>
#include "core/resMng/memMng/MemMng.h"
#include "core/resMng/regMap/regMapper.h"

class UOP_BASE;
class UOP_WINDOW;
///// dependency management
class DEP_BASE{
protected:
    ///// current dependency of this microop
    std::unordered_set<UOP_BASE*> predecessors;
public:
    virtual ~DEP_BASE() = default;
    //////// other derive dependency do not need the virtual deconstructor because base class have been implemented already.
    bool addDep(UOP_BASE* uop);
};
///////////////////////////////////////////////////////////////////////




////// register dependency
class REG_DEP: public DEP_BASE{
private:
    std::vector<REGNUM> srcReg;
    std::vector<REGNUM> desReg;

public:
    ///// for successor to ask about dependency
    virtual bool isdependOnReg(const REGNUM& sucReg); /// sucReg is success reg
    ///// for asking procedure to get dep
    virtual void doRegDepenCheck(UOP_WINDOW* traceWindow);
    ///// for adding source/des of the micro-op meta-data
    virtual void addRegMeta(const REGNUM regnum, bool isSrc); //// if false it is des
    ///// for get des register
    virtual std::vector<REGNUM>& getdesReg();
    ///// for get/set dependency
    bool addRegDep(UOP_BASE* uop);
    ///// get reg dep
    std::unordered_set<UOP_BASE*>& getRegDep();
};
///////////////////////////////////////////////////////////////////////



////// memory addresss dependency
class MEM_DEP: public DEP_BASE{
private:
    std::vector<ADAS> loadAdas;
    std::vector<ADAS> storeAdas;
    ///// scan overlaping
    static bool scanOverlap(const ADAS adas, std::vector<ADAS>& adasVec);

public:
    ///// for successor to ask about dependency
    virtual bool isdependOnMem(const ADAS adas, bool isLoad);
    ///// for asking procedure to get dep
    virtual void doMemDepenCheck(UOP_WINDOW* traceWindow);
    ///// for adding source/des of the micro-op meta-data
    virtual void addMemMeta(ADAS adas, bool isLoad);
    ///// for get/set dependency
    bool addMemDep(UOP_BASE* uop);

    std::unordered_set<UOP_BASE*>& getMemDep();

    std::vector<ADAS>& getAll_LD_ADAS() {return loadAdas;}
    std::vector<ADAS>& getAll_ST_ADAS() {return storeAdas;}

};
///////////////////////////////////////////////////////////////////////



////// execute order dependency
class EXE_DEP: public DEP_BASE{
    /////// for now execution order isn't complete yet

public:
    ///// for successor to ask about dependency
    virtual bool isdepenOnEXE(const UOP_BASE* uop) { return false;} ;
    ///// for get/set dependency
    bool addExeDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getExeDep();
};
///////////////////////////////////////////////////////////////////////



////// temporary register  order dependency some physical register
class TEM_DEP: public DEP_BASE{
    std::vector<TREGNUM> srcTRegs;
    std::vector<TREGNUM> desTRegs;
    /////////TODO we might use bit assign role to enhance the performance
public:
    ///// for successor to ask about dependency
    virtual bool isdepenOnTEM(const TREGNUM sucTreg);
    ///// for asking procedure to get dep
    virtual void doTEMDepenCheck(std::vector<UOP_BASE*>& predecessor); //// there is no need to check with
                                                                        ///// instruction window right now
    ///// for adding source/des of the micro-op meta-data
    virtual void addTRegMeta(const TREGNUM tregnum, bool isSrc); //// if false it is des
    ///// for get/set dependency
    bool addTemDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getTemDep();
};
///////////////////////////////////////////////////////////////////////



#endif //TRACEBUILDER_DEP_H
