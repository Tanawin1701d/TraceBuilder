//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_STRHELP_H
#define TRACEBUILDER_STRHELP_H
#include<iostream>
#include<vector>
#include <sstream>
#include<boost/algorithm/string.hpp>


void splitNstrip(std::string raw, std::vector<std::string>& result);

void spiltLineFromStrNstrip(const std::string&         raw,
                                  std::vector<std::string>& result
                            );

void strip(std::string& raw);

uintptr_t hexStr2uint  (std::string raw);
int       decStr2int   (std::string raw);
uintptr_t decStr2uint  (std::string raw);

std::string    concatVec    (std::vector<std::string>& raws);

#endif //TRACEBUILDER_STRHELP_H
