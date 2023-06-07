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

namespace traceBuilder::core{
    class UOP_WINDOW;
}

namespace traceBuilder::model {

    using namespace traceBuilder::core;
    class UOP_BASE;


    ///// dependency management
    class DEP_BASE {
    protected:
        ///// current dependency of this microop
        uint64_t  depSet[AMT_USED_UOP_REP]  = {};
        UOP_BASE* depUops[UOP_WINDOW_SIZE] = {};
        int       depCnt                    = 0;
        DEP_BASE* depPool                   = nullptr;

        class dep_iter{
            private:
                DEP_BASE* owner;
                int curIdx;
            public:

            dep_iter(DEP_BASE* _owner): owner(_owner){}

            dep_iter& operator++(){
                curIdx++;
                return *this;
            }
            auto operator*() const{
                return owner->depUops[curIdx];
            }
            bool operator!=(const dep_iter& other) const{
                return !(curIdx == other.curIdx && owner == other.owner);
            }
            dep_iter begin(){
                return dep_iter(owner);
            };
            dep_iter end(){
                return dep_iter(owner);
            }


        };

    public:
        virtual ~DEP_BASE() = default;
        //////// other derive dependency do not need the virtual deconstructor because base class have been implemented already.
        bool addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow);
        bool isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow);
        std::pair<int, int> getDepSetIdx(UOP_BASE* uop, UOP_WINDOW* traceWindow);
        dep_iter getDep_iter() {return dep_iter(this);}
        void setDepPool(DEP_BASE* _depPool){depPool = _depPool;};
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


}

#endif //TRACEBUILDER_DEP_BASE_H
