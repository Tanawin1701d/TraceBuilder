//
// Created by tanawin on 17/4/2566.
//

#include "statRecType.h"


/////////////////////////////////////// uint

STAT_REC_TYPE_UINT::STAT_REC_TYPE_UINT():
value(0){}

std::string
STAT_REC_TYPE_UINT::printReport() {
    return std::to_string(value);
}

/////////////////////////////////////// string

STAT_REC_TYPE_STR::STAT_REC_TYPE_STR():
value(std::string())
{}

std::string
STAT_REC_TYPE_STR::printReport() {
    return value;
}