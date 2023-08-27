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
        metaDatas[META_SRC_MREG] = new META_GRP<MREG_META> ;
        metaDatas[META_SRC_TEMP] = new META_GRP<TREG_META>;
        metaDatas[META_SRC_MEM ] = new META_GRP<MEM_META> ;
        metaDatas[META_SRC_IMM ] = new META_GRP<IMM_META>;
        metaDatas[META_DES_MREG] = new META_GRP<MREG_META> ;
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
            //std::cout << "deleting metaDatas" << std::endl;
            delete metaData;
        }
        for (auto& dep: deps){
            //std::cout << "deleting dep" << std::endl;
            delete dep;
        }
        //std::cout << "----------------------------------" << std::endl;


    }

    void BIND_UOP_TYPE(py::module& m){
        py::enum_<UOP_TYPE>(m, "UOP_TYPE")
        .value("UOP_COMP", UOP_TYPE::UOP_COMP)
        .value("UOP_LOAD", UOP_TYPE::UOP_LOAD)
        .value("UOP_STORE",UOP_TYPE::UOP_STORE)
        .value("UOP_IMM",  UOP_TYPE::UOP_IMM)
        .value("UOP_DUMMY",UOP_TYPE::UOP_DUMMY)
        .export_values();
    }

}