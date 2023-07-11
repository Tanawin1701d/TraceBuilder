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
            {"ymm1",   203},{"xmm1",   203},
            {"ymm2",   206},{"xmm2",   206},
            {"ymm3",   209},{"xmm3",   209},
            {"ymm4",   212},{"xmm4",   212},
            {"ymm5",   215},{"xmm5",   215},
            {"ymm6",   218},{"xmm6",   218},
            {"ymm7",   221},{"xmm7",   221},
            {"ymm8",   224},{"xmm8",   224},
            {"ymm9",   227},{"xmm9",   227},
            {"ymm10",  230},{"xmm10",  230},
            {"ymm11",  233},{"xmm11",  233},
            {"ymm12",  236},{"xmm12",  236},
            {"ymm13",  239},{"xmm13",  239},
            {"ymm14",  242},{"xmm14",  242},
            {"ymm15",  245},{"xmm15",  245},
            {"ymm16",  248},{"xmm16",  248},
            {"ymm17",  251},{"xmm17",  251},
            {"ymm18",  254},{"xmm18",  254},
            {"ymm19",  257},{"xmm19",  257},
            {"ymm20",  260},{"xmm20",  260},
            {"ymm21",  263},{"xmm21",  263},
            {"ymm22",  266},{"xmm22",  266},
            {"ymm23",  269},{"xmm23",  269},
            {"ymm24",  272},{"xmm24",  272},
            {"ymm25",  275},{"xmm25",  275},
            {"ymm26",  278},{"xmm26",  278},
            {"ymm27",  281},{"xmm27",  281},
            {"ymm28",  284},{"xmm28",  284},
            {"ymm29",  287},{"xmm29",  287},
            {"ymm30",  290},{"xmm30",  290},
            {"ymm31",  293},{"xmm31",  293},


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

    MREGNUM archRegToMReg(int regNum, int subIdx){
        if (regNum >= START_VECREGID && regNum <= STOP_VECREGID){
            return regNum + subIdx;
        }
        return regNum;
    }


}