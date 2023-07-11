//
// Created by tanawin on 12/2/2566.
//

#include "uop_base.h"
#include "core/tracers/uop_wd.h"

//////////////////////////////////////
////// UOP_BASE
//////////////////////////////////////

namespace traceBuilder::model {

    using namespace traceBuilder::core;

    UOP_BASE::UOP_BASE() :
            seqNum(UINT64_MAX),
            uop_type(UOP_DUMMY),
            exec_unit_id(DUMMY_EXEC_UNIT_ID) {
        /** initialize meta data*/
        metaDatas[META_SRC_MREG ] = new META_GRP<MREG_META> ;
        metaDatas[META_SRC_TEMP] = new META_GRP<TREG_META>;
        metaDatas[META_SRC_MEM ] = new META_GRP<MEM_META> ;
        metaDatas[META_DES_MREG ] = new META_GRP<MREG_META> ;
        metaDatas[META_DES_TEMP] = new META_GRP<TREG_META>;
        metaDatas[META_DES_MEM ] = new META_GRP<MEM_META> ;
        /** initialize dep*/
        deps[DEP_MREG]       = new REG_DEP();
        deps[DEP_MEM]       = new MEM_DEP();
        deps[DEP_TEMP]      = new TEM_DEP();
        deps[DEP_EXEC_UNIT] = new EXEC_UNIT_DEP();
        /** assign dep pool for easily gathering*/
        deps[DEP_MREG]      ->castDown<DEP_RWD_BASE>()->setDepPool(&dep_inter_pool);
        deps[DEP_MEM]      ->castDown<DEP_RWD_BASE>()->setDepPool(&dep_inter_pool);
        deps[DEP_EXEC_UNIT]->castDown<DEP_RWD_BASE>()->setDepPool(&dep_inter_pool);
            ////// please remind that temp is intra dep that base on ULS_DEP which is not
            ////// compatible with dep pool

    }

    UOP_BASE::~UOP_BASE() {
        for (auto& metaData : metaDatas){
            delete metaData;
        }
        for (auto& dep: deps){
            delete dep;
        }

    }
    /////////////////////////////////
    /** operation on meta data*/
    /////////////////////////////////
    template<META_CLASS meta_class_enum, typename META_TYPE>
    void UOP_BASE::addMeta(META_TYPE metaDayta) {
        auto metaGrp = getMetaPtr<meta_class_enum, META_TYPE>();
        metaGrp->addMeta(metaDayta);
    }

    template<META_CLASS meta_class_enum, typename META_TYPE>
    META_GRP<META_TYPE>*
    UOP_BASE::getMetaPtr(){
        return metaDatas[meta_class_enum]->castDown<META_GRP<META_TYPE>>();
    }
    /////////////////////////////////
    /** operation on dep*/
    /////////////////////////////////
    template<DEP_CLASS dep_class_enum>
    bool UOP_BASE::addDep(UOP_BASE* uop, UOP_WINDOW* uop_window){
        auto dep = getDepClassPtr<dep_class_enum>();
        return dep->addDep(this, uop_window);
    }

    template<DEP_CLASS dep_class_enum>
    DEP_BASE* UOP_BASE::getDepClassPtr(){
        return deps[dep_class_enum];
    }


    template<DEP_CLASS dep_class_enum>
    void UOP_BASE::doDepenCheck(UOP_WINDOW *traceWindow){
        auto depPtr = getDepClassPtr<dep_class_enum>();
        depPtr->doDepenCheck(this, traceWindow);
    }
    /////////////////////////////////

////// simple compute reg
/////////////////////////////////////////////////////////////////////////////
    void UOP_SIMPLE::doPlannedDepenCheck(UOP_WINDOW *uop_window) {
        //////// we check all possible dependency
        doDepenCheck<DEP_MREG      >(uop_window);
        doDepenCheck<DEP_MEM      >(uop_window);
        doDepenCheck<DEP_EXEC_UNIT>(uop_window);
    }

    UOP_SIMPLE::UOP_SIMPLE(UOP_TYPE _uop_type) :
            UOP_BASE() {
        uop_type = _uop_type;
    }



}