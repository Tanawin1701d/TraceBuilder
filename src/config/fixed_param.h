//
// Created by tanawin on 7/6/2566.
//

#ifndef TRACEBUILDER_FIXED_PARAM_H
#define TRACEBUILDER_FIXED_PARAM_H


#include <cstdint>
#include <climits>

#define UOP_WINDOW_SIZE 200
const   int AMT_BIT_UINT64   = sizeof(uint64_t) * CHAR_BIT;
const   int AMT_USED_UOP_REP = (UOP_WINDOW_SIZE + AMT_BIT_UINT64 - 1) / AMT_BIT_UINT64;

#endif //TRACEBUILDER_FIXED_PARAM_H
