//
// Created by tanawin on 14/2/2566.
//

#ifndef TRACEBUILDER_DYNTRACEVAR_H
#define TRACEBUILDER_DYNTRACEVAR_H
#include<iostream>
#include <vector>

namespace traceBuilder::core {

    const uint32_t maxMemOpPerLS = 2;
    const uint8_t DUMMY_MEM_OP_NUM = -1;

#pragma pack(push, 1)
    struct RT_OBJ {
        uint64_t loadAddr[maxMemOpPerLS];
        uint64_t storeAddr[maxMemOpPerLS];
        uint32_t fetchId;
        uint8_t amt_load;
        uint8_t amt_store;
    };
#pragma pack(pop)


/////// this struct is used for store the converted
/////// data that received from trace front end like
/////// (memory mapping, runtime interupt bra bra bra ..)
    struct CVT_RT_OBJ { /// converted runtime object
        ///// assume that the address array is in memop order
        uint64_t phyLoadAddr[maxMemOpPerLS];
        uint64_t phyStoreAddr[maxMemOpPerLS];
        uint32_t fetchId;
        uint8_t amt_load;
        uint8_t amt_store;
    };

    struct dynTraceData {
        RT_OBJ rawData;   //// this is used for each instruction
        ///// others data that we reccord from dynamic pintool will be filled here.
    };

}

#endif //TRACEBUILDER_DYNTRACEVAR_H
