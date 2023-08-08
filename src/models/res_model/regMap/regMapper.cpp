//
// Created by tanawin on 28/12/2565.
//
#include "regMapper.h"

namespace traceBuilder::model {


////// define extern variable
    std::map<std::string, AREGNUM> regmap = {

            {"rax",    { 0, MAXSUBREG_R}},{"eax",   {  0, MAXSUBREG_R}},{"ax",    { 0, MAXSUBREG_R}},{"al",     { 0, MAXSUBREG_R}},{"ah",     {0, MAXSUBREG_R}},
            {"rcx",    { 1, MAXSUBREG_R}},{"ecx",   {  1, MAXSUBREG_R}},{"cx",    { 1, MAXSUBREG_R}},{"cl",     { 1, MAXSUBREG_R}},{"ch",     {1, MAXSUBREG_R}},
            {"rdx",    { 2, MAXSUBREG_R}},{"edx",   {  2, MAXSUBREG_R}},{"dx",    { 2, MAXSUBREG_R}},{"dl",     { 2, MAXSUBREG_R}},{"dh",     {2, MAXSUBREG_R}},
            {"rbx",    { 3, MAXSUBREG_R}},{"ebx",   {  3, MAXSUBREG_R}},{"bx",    { 3, MAXSUBREG_R}},{"bl",     { 3, MAXSUBREG_R}},{"bh",     {3, MAXSUBREG_R}},
            {"rsi",    { 4, MAXSUBREG_R}},{"esi",   {  4, MAXSUBREG_R}},{"si",    { 4, MAXSUBREG_R}},{"sil",    { 4, MAXSUBREG_R}},{"sih",    {4, MAXSUBREG_R}},
            {"rdi",    { 5, MAXSUBREG_R}},{"edi",   {  5, MAXSUBREG_R}},{"di",    { 5, MAXSUBREG_R}},{"dil",    { 5, MAXSUBREG_R}},{"dih",    {5, MAXSUBREG_R}},
            {"rsp",    { 6, MAXSUBREG_R}},{"esp",   {  6, MAXSUBREG_R}},{"sp",    { 6, MAXSUBREG_R}},{"spl",    { 6, MAXSUBREG_R}},{"sph",    {6, MAXSUBREG_R}},
            {"rbp",    { 7, MAXSUBREG_R}},{"ebp",   {  7, MAXSUBREG_R}},{"bp",    { 7, MAXSUBREG_R}},{"bpl",    { 7, MAXSUBREG_R}},{"bph",    {7, MAXSUBREG_R}},
            {"r8",     { 8, MAXSUBREG_R}},{"r8d",   {  8, MAXSUBREG_R}},{"r8w",   { 8, MAXSUBREG_R}},{"r8b",    { 8, MAXSUBREG_R}},
            {"r9",     { 9, MAXSUBREG_R}},{"r9d",   {  9, MAXSUBREG_R}},{"r9w",   { 9, MAXSUBREG_R}},{"r9b",    { 9, MAXSUBREG_R}},
            {"r10",    {10, MAXSUBREG_R}},{"r10d",  { 10, MAXSUBREG_R}},{"r10w",  {10, MAXSUBREG_R}},{"r10b",   {10, MAXSUBREG_R}},
            {"r11",    {11, MAXSUBREG_R}},{"r11d",  { 11, MAXSUBREG_R}},{"r11w",  {11, MAXSUBREG_R}},{"r11b",   {11, MAXSUBREG_R}},
            {"r12",    {12, MAXSUBREG_R}},{"r12d",  { 12, MAXSUBREG_R}},{"r12w",  {12, MAXSUBREG_R}},{"r12b",   {12, MAXSUBREG_R}},
            {"r13",    {13, MAXSUBREG_R}},{"r13d",  { 13, MAXSUBREG_R}},{"r13w",  {13, MAXSUBREG_R}},{"r13b",   {13, MAXSUBREG_R}},
            {"r14",    {14, MAXSUBREG_R}},{"r14d",  { 14, MAXSUBREG_R}},{"r14w",  {14, MAXSUBREG_R}},{"r14b",   {14, MAXSUBREG_R}},
            {"r15",    {15, MAXSUBREG_R}},{"r15d",  { 15, MAXSUBREG_R}},{"r15w",  {15, MAXSUBREG_R}},{"r15b",   {15, MAXSUBREG_R}},
            {"rip",    ARCH_RIP},
            /** floating point register it is 64 bit register*/
            {"st0",   {100, MAXSUBREG_MMX}},{"mmx0",   {100, MAXSUBREG_MMX}},
            {"st1",   {101, MAXSUBREG_MMX}},{"mmx1",   {101, MAXSUBREG_MMX}},
            {"st2",   {102, MAXSUBREG_MMX}},{"mmx2",   {102, MAXSUBREG_MMX}},
            {"st3",   {103, MAXSUBREG_MMX}},{"mmx3",   {103, MAXSUBREG_MMX}},
            {"st4",   {104, MAXSUBREG_MMX}},{"mmx4",   {104, MAXSUBREG_MMX}},
            {"st5",   {105, MAXSUBREG_MMX}},{"mmx5",   {105, MAXSUBREG_MMX}},
            {"st6",   {106, MAXSUBREG_MMX}},{"mmx6",   {106, MAXSUBREG_MMX}},
            {"st7",   {107, MAXSUBREG_MMX}},{"mmx7",   {107, MAXSUBREG_MMX}},
            /**xmm register */
            {"ymm0",   {200, MAXSUBREG_YMM}},{"xmm0",   {200, MAXSUBREG_XMM}},
            {"ymm1",   {204, MAXSUBREG_YMM}},{"xmm1",   {204, MAXSUBREG_XMM}},
            {"ymm2",   {208, MAXSUBREG_YMM}},{"xmm2",   {208, MAXSUBREG_XMM}},
            {"ymm3",   {212, MAXSUBREG_YMM}},{"xmm3",   {212, MAXSUBREG_XMM}},
            {"ymm4",   {216, MAXSUBREG_YMM}},{"xmm4",   {216, MAXSUBREG_XMM}},
            {"ymm5",   {220, MAXSUBREG_YMM}},{"xmm5",   {220, MAXSUBREG_XMM}},
            {"ymm6",   {224, MAXSUBREG_YMM}},{"xmm6",   {224, MAXSUBREG_XMM}},
            {"ymm7",   {228, MAXSUBREG_YMM}},{"xmm7",   {228, MAXSUBREG_XMM}},
            {"ymm8",   {232, MAXSUBREG_YMM}},{"xmm8",   {232, MAXSUBREG_XMM}},
            {"ymm9",   {236, MAXSUBREG_YMM}},{"xmm9",   {236, MAXSUBREG_XMM}},
            {"ymm10",  {240, MAXSUBREG_YMM}},{"xmm10",  {240, MAXSUBREG_XMM}},
            {"ymm11",  {244, MAXSUBREG_YMM}},{"xmm11",  {244, MAXSUBREG_XMM}},
            {"ymm12",  {248, MAXSUBREG_YMM}},{"xmm12",  {248, MAXSUBREG_XMM}},
            {"ymm13",  {252, MAXSUBREG_YMM}},{"xmm13",  {252, MAXSUBREG_XMM}},
            {"ymm14",  {256, MAXSUBREG_YMM}},{"xmm14",  {256, MAXSUBREG_XMM}},
            {"ymm15",  {260, MAXSUBREG_YMM}},{"xmm15",  {260, MAXSUBREG_XMM}}



    };

    int lastRegName = START_UNREGID;


    AREGNUM
    regMapAutoAdd(const std::string &regName) {
        assert(!regName.empty());

        if (regName == unusedRegStr) {
            return UNUSED_AREG;
        }

        auto finder = regmap.find(regName);
        if (finder != regmap.end()) {
            return finder->second;
        }
        assert(lastRegName < MAXMREG_AMT);

        AREGNUM newAregId = {lastRegName, 1};
        regmap.insert(make_pair(regName, newAregId));
        std::cout << "[warning] detect new register : " << regName << " assign to " << lastRegName << std::endl;
        ///we have new unrecorded register
        lastRegName++;
        ////////////////////////////////////////
        ////////////////////////////////////////
        stat::MAIN_STAT["count_regMapNewCreate"].asUINT()++;
        ////////////////////////////////////////
        ////////////////////////////////////////

        return newAregId;
    }

    MREGNUM archRegToMReg(AREGNUM reg, int subIdx){

        assert(subIdx >= 0 && reg.maxSubRegId > 0 );
        return reg.archRegId + subIdx % reg.maxSubRegId;

    }


    void BIND_REG_TYPE(py::module& m){

        py::class_<AREGNUM, std::shared_ptr<AREGNUM>>(m,"AREGNUM")
                .def(py::init<int, int>())
                .def_readwrite("archRegId", &AREGNUM::archRegId)
                .def_readwrite("maxSubRegId", &AREGNUM::maxSubRegId);
    }


}