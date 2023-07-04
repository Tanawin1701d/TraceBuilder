//
// Created by tanawin on 7/6/2566.
//

#ifndef TRACEBUILDER_FIXED_PARAM_H
#define TRACEBUILDER_FIXED_PARAM_H


#include <cstdint>
#include <climits>
/// metadata storage limit in each class of each microop
#define MAX_SIZE_METADATA 5
#define UOP_WINDOW_SIZE 256
#define PY_MODULE_NAME traceBuilder
const   int AMT_BIT_UINT64   = sizeof(uint64_t) * CHAR_BIT;
const   int AMT_USED_UOP_REP = (UOP_WINDOW_SIZE + AMT_BIT_UINT64 - 1) / AMT_BIT_UINT64;


#endif //TRACEBUILDER_FIXED_PARAM_H
