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


/*
 * do{X}depenCheck
 * add{X}dep
 * get{X}dep
 * ///////////// meta zone
 * add{X}Meta
 * get{X}
 *
 * */

////// register dependency
class REG_DEP: public DEP_BASE{
private:
    std::vector<REGNUM> srcReg;
    std::vector<REGNUM> desReg;

public:
    ///////////////
    ///// dependMng
    ///////////////
    ///// for asking procedure to get dep
    virtual void doRegDepenCheck(UOP_WINDOW* traceWindow) = 0;
    ///// for get/set dependency
    bool addRegDep(UOP_BASE* uop);
    ///// get reg dep
    std::unordered_set<UOP_BASE*>& getRegDep();
    ///////////////
    ///// metaMng
    ///////////////
    ///// for adding source/des of the micro-op meta-data
    void addRegMeta(const REGNUM regnum, bool isSrc); //// if false it is des
    ///// for get des register
    std::vector<REGNUM>& getdesReg();
};
///////////////////////////////////////////////////////////////////////



////// memory addresss dependency
class MEM_DEP: public DEP_BASE{
protected:
    std::vector<ADAS> loadAdas;
    std::vector<ADAS> storeAdas;
    ///// scan overlaping
    static bool scanOverlap(ADAS adas, std::vector<ADAS>& adasVec);

public:
    ///////////////
    ///// dependMng
    ///////////////
    ///// for successor to ask about dependency
    virtual bool isdependOnMem(const ADAS adas, bool isLoad);
    ///// for asking procedure to get dep
    virtual void doMemDepenCheck(UOP_WINDOW* traceWindow) = 0;
    ///// for get/set dependency
    bool addMemDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getMemDep();
    ///////////////
    ///// metaMng
    ///////////////
    ///// for adding source/des of the micro-op meta-data
    virtual void addMemMeta(ADAS adas, bool isLoad);
    std::vector<ADAS>& getAll_LD_ADAS() {return loadAdas;}
    std::vector<ADAS>& getAll_ST_ADAS() {return storeAdas;}

};

////// temporary register  order dependency some physical register
class TEM_DEP: public DEP_BASE{
    std::vector<TREGNUM> srcTRegs;
public:
    ///////////////
    ///// dependMng
    ///////////////
    virtual void doTemDepenCheck(UOP_WINDOW* uop_window) = 0;
    ///// for get/set dependency
    bool addTemDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getTemDep();
    ///////////////
    ///// metaMng
    ///////////////
    ///// for adding source/des of the micro-op meta-data
    void addTRegMeta(TREGNUM tregnum);
    std::vector<TREGNUM>& getdesTRegs() {return srcTRegs;}
};
///////////////////////////////////////////////////////////////////////

class EXEC_UNIT_DEP: public DEP_BASE{
public:
    ///////////////
    ///// dependMng
    ///////////////
    virtual void doExecDepenCheck(UOP_WINDOW* traceWindow) = 0;
    bool addExecDep(UOP_BASE* uop);
    std::unordered_set<UOP_BASE*>& getExecDep();

};

#endif //TRACEBUILDER_DEP_H
