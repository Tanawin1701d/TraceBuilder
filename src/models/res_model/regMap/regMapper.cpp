//
// Created by tanawin on 28/12/2565.
//
#include "regMapper.h"

namespace traceBuilder::model {


////// define extern variable
    std::map<std::string, REGNUM> regmap = {

            {"rax",     0},{"eax",     0},{"ax",      0},{"al",      10},{"ah",     0},
            {"rcx",     1},{"ecx",     1},{"cx",      1},{"cl",      11},{"ch",     1},
            {"rdx",     2},{"edx",     2},{"dx",      2},{"dl",      12},{"dh",     2},
            {"rbx",     3},{"ebx",     3},{"bx",      3},{"bl",      13},{"bh",     3},
            {"rsi",     4},{"esi",     4},{"si",      4},{"sil",     14},{"sih",    4},
            {"rdi",     5},{"edi",     5},{"di",      5},{"dil",     15},{"dih",    5},
            {"rsp",     6},{"esp",     6},{"sp",      6},{"spl",     16},{"sph",    6},
            {"rbp",     7},{"ebp",     7},{"bp",      7},{"bpl",     17},{"bph",    7},
            {"r8",      8},{"r8d",     8},{"r8w",     8},{"r8b",     18},
            {"r9",      9},{"r9d",     9},{"r9w",     9},{"r9b",     19},
            {"r10",    10},{"r10d",   10},{"r10w",   10},{"r10b",   10},
            {"r11",    11},{"r11d",   11},{"r11w",   11},{"r11b",   11},
            {"r12",    12},{"r12d",   12},{"r12w",   12},{"r12b",   12},
            {"r13",    13},{"r13d",   13},{"r13w",   13},{"r13b",   13},
            {"r14",    14},{"r14d",   14},{"r14w",   14},{"r14b",   14},
            {"r15",    15},{"r15d",   15},{"r15w",   15},{"r15b",   15},
            {"rip",    16},
            /** floating point register */
            {"st0",   100},{"mmx0",   100},
            {"st1",   101},{"mmx1",   101},
            {"st2",   102},{"mmx2",   102},
            {"st3",   103},{"mmx3",   103},
            {"st4",   104},{"mmx4",   104},
            {"st5",   105},{"mmx5",   105},
            {"st6",   106},{"mmx6",   106},
            {"st7",   107},{"mmx7",   107},
            /**xmm register */
            {"ymm0",   200},{"xmm0",   200},
            {"ymm1",   201},{"xmm1",   201},
            {"ymm2",   202},{"xmm2",   202},
            {"ymm3",   203},{"xmm3",   203},
            {"ymm4",   204},{"xmm4",   204},
            {"ymm5",   205},{"xmm5",   205},
            {"ymm6",   206},{"xmm6",   206},
            {"ymm7",   207},{"xmm7",   207},
            {"ymm8",   208},{"xmm8",   208},
            {"ymm9",   209},{"xmm9",   209},
            {"ymm10",  210},{"xmm10",  210},
            {"ymm11",  211},{"xmm11",  211},
            {"ymm12",  212},{"xmm12",  212},
            {"ymm13",  213},{"xmm13",  213},
            {"ymm14",  214},{"xmm14",  214},
            {"ymm15",  215},{"xmm15",  215},
            {"ymm16",  216},{"xmm16",  216},
            {"ymm17",  217},{"xmm17",  217},
            {"ymm18",  218},{"xmm18",  218},
            {"ymm19",  219},{"xmm19",  219},
            {"ymm20",  220},{"xmm20",  220},
            {"ymm21",  221},{"xmm21",  221},
            {"ymm22",  222},{"xmm22",  222},
            {"ymm23",  223},{"xmm23",  223},
            {"ymm24",  224},{"xmm24",  224},
            {"ymm25",  225},{"xmm25",  225},
            {"ymm26",  226},{"xmm26",  226},
            {"ymm27",  227},{"xmm27",  227},
            {"ymm28",  228},{"xmm28",  228},
            {"ymm29",  229},{"xmm29",  229},
            {"ymm30",  230},{"xmm30",  230},
            {"ymm31",  231},{"xmm31",  231},


    };

    int lastRegName = START_UNREGID;


    REGNUM
    regMapAutoAdd(const std::string &regName) {
        assert(!regName.empty());

        if (regName == unusedRegStr) {
            return UNUSEDREG;
        }

        auto finder = regmap.find(regName);
        if (finder != regmap.end()) {
            return finder->second;
        }
        assert(lastRegName < MAXREG_AMT);

        regmap.insert(make_pair(regName, lastRegName));
        std::cout << "[warning] detect new register : " << regName << " assign to " << lastRegName << std::endl;

        ///we have new unrecorded register
        lastRegName++;

        ////////////////////////////////////////
        ////////////////////////////////////////
        stat::MAIN_STAT["count_regMapNewCreate"].asUINT()++;
        ////////////////////////////////////////
        ////////////////////////////////////////

        return lastRegName;
    }


}