//
// Created by tanawin on 7/6/2566.
//

#ifndef TRACEBUILDER_DEP_SIMPLE_H
#define TRACEBUILDER_DEP_SIMPLE_H

#include "dep_base.h"

namespace traceBuilder::model {

    class REG_DEP : public DEP_RWD_BASE {
    private:
        std::vector <REGNUM> srcReg;
        std::vector <REGNUM> desReg;

    public:
        ///////////////
        ///// dependMng
        ///////////////
        ///// for asking procedure to get dep
        virtual void doRegDepenCheck(UOP_WINDOW *traceWindow) = 0;
        ///// for get/set dependency
        bool addRegDep(UOP_BASE *uop, UOP_WINDOW *traceWindow){return addDep(uop, traceWindow);};
        ///// get reg dep
        DEP_BASE& getRegDep_iter() { return getDep_iter();};
        ///////////////
        ///// metaMng
        ///////////////
        ///// for adding source/des of the micro-op meta-data
        void addRegMeta(REGNUM regnum, bool isSrc); //// if false it is des
        ///// for get des register
        std::vector<REGNUM>& getdesReg() { return desReg;};
    };
///////////////////////////////////////////////////////////////////////



////// memory addresss dependency
    class MEM_DEP : public DEP_RWD_BASE {
    protected:
        std::vector <ADAS> loadAdas;
        std::vector <ADAS> storeAdas;
        ///// scan overlaping
        static bool scanOverlap(ADAS adas, std::vector <ADAS> &adasVec);

    public:
        ///////////////
        ///// dependMng
        ///////////////
        ///// for successor to ask about dependency
        virtual bool isdependOnMem(ADAS adas, bool isLoad);

        ///// for asking procedure to get dep
        virtual void doMemDepenCheck(UOP_WINDOW *traceWindow) = 0;

        ///// for get/set dependency
        bool addMemDep(UOP_BASE *uop, UOP_WINDOW *traceWindow) {return addDep(uop, traceWindow);};

        DEP_BASE& getMemDep_iter() {return getDep_iter();};

        ///////////////
        ///// metaMng
        ///////////////
        ///// for adding source/des of the micro-op meta-data
        virtual void addMemMeta(ADAS adas, bool isLoad);

        std::vector<ADAS>& getAll_LD_ADAS() { return loadAdas; }

        std::vector<ADAS>& getAll_ST_ADAS() { return storeAdas; }

    };

////// temporary register  order dependency some physical register
////// due to the fact that macro-op add the dep by themselves so, we must use ULS instead RWD
    class TEM_DEP : public DEP_ULS_BASE {
        std::vector<TREGNUM> srcTRegs;
        std::vector<TREGNUM> desTReg;
    public:
        ///////////////
        ///// dependMng
        ///////////////
        virtual void doTemDepenCheck(UOP_WINDOW* uop_window) = 0;
        ///// for get
        void addTemDep(UOP_BASE* uop);
        DEP_BASE& getTemDep() {return getDep_iter();};

        ///////////////
        ///// metaMng
        ///////////////
        ///// for adding source/des of the micro-op meta-data
        void addTRegMeta(TREGNUM tregnum, bool isSrc);

        std::vector<TREGNUM>& getSrcTRegs() { return srcTRegs;}
        std::vector<TREGNUM>& getdesTRegs() { return desTReg; }
    };
///////////////////////////////////////////////////////////////////////

    class EXEC_UNIT_DEP : public DEP_RWD_BASE {
    public:
        ///////////////
        ///// dependMng
        ///////////////
        virtual void doExecDepenCheck(UOP_WINDOW *traceWindow) = 0;
        ///// for add dependency
        bool addExecDep(UOP_BASE *uop, UOP_WINDOW *traceWindow) {return addDep(uop, traceWindow);};
        ///// for get dependency
        DEP_BASE& getExecDep_iter() {return getDep_iter();};
    };

}

#endif //TRACEBUILDER_DEP_SIMPLE_H
