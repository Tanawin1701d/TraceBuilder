//
// Created by tanawin on 6/1/2566.
//

#include "strHelp.h"
void
splitNstrip(string raw, vector<string>& result) {
    boost::algorithm::split(result,
                            raw,
                            boost::is_any_of("\t "),
                            boost::token_compress_on);

    for (string& preStr: result) {
        strip(raw);
    }
}

void
strip(string& raw) {
    boost::algorithm::trim_right(raw);
    boost::algorithm::trim_left (raw);
}

uintptr_t hexStr2uint(string raw) {
    strip(raw);
    return stoull(raw, nullptr, 16);
}

int decStr2int(string raw) {
    strip(raw);
    int cres = 0;
    try {
        cres = stoi(raw);;
    }catch (const invalid_argument& e ){
        cout  << "[warning:instr.cpp:~101] error to convert " << raw << "   to unsigned long convert ignore\n";
    }
    return cres;
}

uintptr_t decStr2uint(string raw) {
    strip(raw);

    uintptr_t cres = 0;
    try {
        cres = stoul(raw);
    }catch (const invalid_argument& e ){
        cout  << "[warning:instr.cpp:~113] error to convert " << raw << "   to unsigned long convert ignore\n";
    }

    return cres;
}