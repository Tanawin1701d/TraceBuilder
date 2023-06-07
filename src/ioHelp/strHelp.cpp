//
// Created by tanawin on 6/1/2566.
//

#include "strHelp.h"

namespace traceBuilder::util {

    void
    splitNstrip(std::string raw, std::vector<std::string> &result) {
        boost::algorithm::split(result,
                                raw,
                                boost::is_any_of("\t "),
                                boost::token_compress_on);

        for (std::string &preStr: result) {
            strip(preStr);
        }
    }

    void
    spiltLineFromStrNstrip(const std::string &raw,
                           std::vector<std::string> &result
    ) {

        std::stringstream ss(raw);
        std::string line;
        while (std::getline(ss, line)) {
            result.push_back(line);
        }
        /////// strip
        for (std::string &preStr: result) {
            strip(preStr);
        }
    }

    std::string
    getProgPf(std::string file, int lineNumber) {
        return "[" + file + ":" + std::to_string(lineNumber) + "] ";
    }

    void
    strip(std::string &raw) {
        boost::algorithm::trim_right(raw);
        boost::algorithm::trim_left(raw);
    }

    void
    convertToUpperStr(std::string &str) {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    }

    uintptr_t hexStr2uint(std::string raw) {
        strip(raw);
        return stoull(raw, nullptr, 16);
    }

    int decStr2int(std::string raw) {
        strip(raw);
        int cres = 0;
        try {
            cres = stoi(raw);;
        } catch (const std::invalid_argument &e) {
            std::cout << "[warning:instr.cpp:~101] error to convert " << raw << "   to unsigned long convert ignore\n";
        }
        return cres;
    }

    uintptr_t decStr2uint(std::string raw) {
        strip(raw);

        uintptr_t cres = 0;
        try {
            cres = stoul(raw);
        } catch (const std::invalid_argument &e) {
            std::cout << "[warning:instr.cpp:~113] error to convert " << raw << "   to unsigned long convert ignore\n";
        }

        return cres;
    }

    std::string concatVec(std::vector<std::string> &raws, std::string catTok) {
        std::string preRet;
        bool isFirst = true;
        for (auto &e: raws) {
            if (isFirst) {
                isFirst = false;
            } else {
                preRet += catTok;
            }
            preRet += e;
        }
        return preRet;
    }


    std::string genRepeatStr(size_t n, std::string str) {
        std::string preRet;
        for (int i = 0; i < n; i++) {
            preRet += str;
        }
        return preRet;
    }
}