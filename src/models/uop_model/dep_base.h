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

    class DEP_BASE {
    protected:
        UOP_BASE* depUops[UOP_WINDOW_SIZE] = {};
        int       depCnt                    = 0;
        class dep_iter{
        private:
            DEP_BASE* owner;
            int curIdx{};
        public:

            explicit dep_iter(DEP_BASE* _owner): owner(_owner){}
            dep_iter(DEP_BASE* _owner, int _curIdx): owner(_owner), curIdx(_curIdx){
                assert(curIdx >= 0 && curIdx <= owner->depCnt);
            }

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
                return {owner, 0};
            };
            dep_iter end(){
                return {owner, owner->depCnt};
            }


        };
    public:
        virtual bool addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) = 0;
        virtual bool isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) = 0;
        dep_iter getDep_iter() {return dep_iter(this);}
    };


    ///// dependency management
    //////// Dependency that related with uop window
    //////////////// class machanism is valid when no change occur with uop window
    //////////////// this uop window must freeze when first addDep is called
    //////////////// the uop dependency of this class must be already added to uop_window
    class DEP_RWD_BASE: public DEP_BASE {
    protected:
        ///// current dependency of this microop
        uint64_t  depSet[AMT_USED_UOP_REP]  = {};
        DEP_RWD_BASE* depPool               = nullptr;

    public:
        virtual ~DEP_RWD_BASE() = default;
        //////// other derive dependency do not need the virtual deconstructor because base class have been implemented already.
        bool addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        bool isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        std::pair<int, int> getDepSetIdx(UOP_BASE* uop, UOP_WINDOW* traceWindow);
        void setDepPool(DEP_RWD_BASE* _depPool){ depPool = _depPool;};
    };
///////////////////////////////////////////////////////////////////////
    ///// dependency management
    //////// Dependency that expect uniq (not add the added uop)
    //////////////// class machanism is not garantee uniq of the uop that added to class
    class DEP_ULS_BASE : public DEP_BASE {
    public:
        virtual ~DEP_ULS_BASE() = default;
        bool addDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
        bool isThereDep(UOP_BASE* uop, UOP_WINDOW* traceWindow) override;
    };
}

#endif //TRACEBUILDER_DEP_BASE_H
