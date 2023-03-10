//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_STRHELP_H
#define TRACEBUILDER_STRHELP_H
#include<iostream>
#include<vector>
#include<boost/algorithm/string.hpp>

using namespace std;

void splitNstrip(string raw, vector<string>& result);
void strip(string& raw);

uintptr_t hexStr2uint  (string raw);
int       decStr2int   (string raw);
uintptr_t decStr2uint  (string raw);

#endif //TRACEBUILDER_STRHELP_H
