//
// Created by tanawin on 7/6/2566.
//

#ifndef TRACEBUILDER_DEP_SIMPLE_H
#define TRACEBUILDER_DEP_SIMPLE_H

#include "dep_base.h"

namespace traceBuilder::model {

    class REG_DEP : public DEP_BASE {
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
        dep_iter getRegDep_iter() { return getDep_iter();};
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
    class MEM_DEP : public DEP_BASE {
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

        dep_iter getMemDep_iter() {return getDep_iter();};

        ///////////////
        ///// metaMng
        ///////////////
        ///// for adding source/des of the micro-op meta-data
        virtual void addMemMeta(ADAS adas, bool isLoad);

        std::vector<ADAS>& getAll_LD_ADAS() { return loadAdas; }

        std::vector<ADAS>& getAll_ST_ADAS() { return storeAdas; }

    };

////// temporary register  order dependency some physical register
    class TEM_DEP : public DEP_BASE {
        std::vector<TREGNUM> srcTRegs;
        std::vector<UOP_BASE*>  preAddedDep; /// bacause dep's uop is added before it is pushed to uop_window
                                                /// we first added to this vector and tracer will add to main dep when ready
    public:
        ///////////////
        ///// dependMng
        ///////////////
        virtual void doTemDepenCheck(UOP_WINDOW* uop_window) = 0;
        ///// for get
        void addTemDep(UOP_BASE* uop);
        void finalizeTemDep(UOP_WINDOW* trace_window);


        dep_iter getTemDep() {return getDep_iter();};

        ///////////////
        ///// metaMng
        ///////////////
        ///// for adding source/des of the micro-op meta-data
        void addTRegMeta(TREGNUM tregnum);

        std::vector <TREGNUM> &getdesTRegs() { return srcTRegs; }
    };
///////////////////////////////////////////////////////////////////////

    class EXEC_UNIT_DEP : public DEP_BASE {
    public:
        ///////////////
        ///// dependMng
        ///////////////
        virtual void doExecDepenCheck(UOP_WINDOW *traceWindow) = 0;
        ///// for add dependency
        bool addExecDep(UOP_BASE *uop, UOP_WINDOW *traceWindow) {return addDep(uop, traceWindow);};
        ///// for get dependency
        dep_iter getExecDep() {return getDep_iter();};
    };

}

#endif //TRACEBUILDER_DEP_SIMPLE_H
