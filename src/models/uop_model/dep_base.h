//
// Created by tanawin on 12/2/2566.
//

#ifndef TRACEBUILDER_DEP_BASE_H
#define TRACEBUILDER_DEP_BASE_H

#include<iostream>
#include<unordered_set>
#include "models/res_model/memMng/MemMng.h"
#include "models/res_model/regMap/regMapper.h"
#include "config/fixed_param.h"
#include "base/setVec/setVec.h"

namespace traceBuilder::core{
    class UOP_WINDOW;
}

namespace traceBuilder::model {

    using namespace traceBuilder::core;

    class UOP_BASE;
    /* iterator that is used to loop over the dep element*/
    typedef ARRAY_FWD_ITERATOR<UOP_BASE*> DEP_ITER;

    class DEP_BASE {
    protected:

    public:
        virtual bool         addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) = 0;
        virtual bool         isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) = 0;
        /** DEP_BASE was a iterable object but uop may inherit many dep type
         * this will ensure that derive class will help us get precisely iterator begin() end()*/
        virtual DEP_BASE&    getDep_iter(){return *this;};
        virtual DEP_ITER begin() = 0;
        virtual DEP_ITER end() = 0;
    };

/**
 * dependency management
 * Dependency that related with uop window
 * class machanism is valid when no change occur with uop window
 * this uop window must freeze when first addDep is called
 * the uop dependency of this class must be already added to uop_window
 */
    class DEP_RWD_BASE: public DEP_BASE {
    protected:
        DEP_RWD_BASE* _depPool; //// used to store all dependency that occure in DEP_RWD_BASE
        /**set vec to store the dependency*/
        SETVEC<UOP_BASE*, UOP_WINDOW_SIZE> depUops;

    public:
        explicit DEP_RWD_BASE();
        virtual ~DEP_RWD_BASE() = default;
        //////// other derive dependency do not need the virtual deconstructor because base class have been implemented already.
        bool      addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        bool      isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        void      setDepPool(DEP_RWD_BASE* depPool){ depPool = _depPool;};
        DEP_ITER  begin() override{return depUops.begin();}
        DEP_ITER  end()   override{return depUops.end();}

    };
/**
 * dependency management
 * Dependency that expect uniq (not add the added uop)
 * class machanism is not garantee uniq of the uop that added to class
 */
    class DEP_ULS_BASE : public DEP_BASE {
        UOP_BASE* _depUops[UOP_WINDOW_SIZE];
        size_t    _depCnt{};
    public:
        virtual ~DEP_ULS_BASE() = default;
        /** this won't check that there is that existed uop already, you must check using isThereDep() or accept the identical possibility*/
        bool addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        bool isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        DEP_ITER  begin() override{return DEP_ITER(0, _depUops      );}
        DEP_ITER  end()   override{return DEP_ITER(_depCnt, _depUops);}
    };
}

#endif //TRACEBUILDER_DEP_BASE_H
