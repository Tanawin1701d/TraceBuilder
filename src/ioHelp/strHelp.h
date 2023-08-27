//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_STRHELP_H
#define TRACEBUILDER_STRHELP_H
#include<iostream>
#include<vector>
#include <sstream>
#include<boost/algorithm/string.hpp>

namespace traceBuilder::util {

    void splitNstrip(std::string raw, std::vector<std::string> &result);

    void spiltLineFromStrNstrip(const std::string &raw,
                                std::vector<std::string> &result
    );

    std::string getProgPf(std::string file, int lineNumber);

    void strip(std::string &raw);

    void convertToUpperStr(std::string &str);

    uintptr_t hexStr2uint(std::string raw);

    int decStr2int(std::string raw);

    uintptr_t decStr2uint(std::string raw);

    std::string concatVec(std::vector<std::string> &raws, std::string catTok = " ");

    std::string genRepeatStr(size_t n, std::string str);

}

#endif //TRACEBUILDER_STRHELP_H
