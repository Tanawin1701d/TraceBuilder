//
// Created by tanawin on 24/12/2565.
//

#ifndef TRACEBUILDER_TRACER_H
#define TRACEBUILDER_TRACER_H


// load instruction is coming. check there is store
// store instruction is coming. check there is load or store
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>
#include <cassert>
#include<boost/algorithm/string.hpp>
#include "../components/regMap/regMapper.h"
#include "../components/inst/instr.h"
#include "../components/inst/instr_model.h"
#include "../components/memMap/MemMng.h"
#include "statPool.h"
using namespace std;


class ETRACER{
    friend class MEM_INSTR;
    friend class INSTR;
    friend class COMP_INSTR;
    friend class FETCH_INSTR;
    friend class LOAD_INSTR;
    friend class STORE_INSTR;
    //// io file
    ifstream* traceFile;
    ofstream* outputFile_data;
    ofstream* outputFile_instr;
    string preWrite_data;
    unsigned long MAX_PREW_BUFF = 2000000000;
    string preWrite_instr;
    /////////INSTR_MODEL
    INSTR_MODEL_MANAGER* instrModelMng;
    /////////MEMORY_MANAGER
    MEM_MNG* memMng;
    ////////INSTR_WINDOW
    class INSTR_WINDOW {
    private:
               const int MAX_WINDOWSIZE = 120;
        static const int MAX_REGNUM = 80;

        INSTR_MODEL_MANAGER* instrModelMng;
        int      regDep   [MAX_REGNUM] {};
        uint64_t regResult[MAX_REGNUM] {}; //sequence number
        // amount // seqnumber
        deque<INSTR*> currentWindow;

        void addReg(REGNUM regNum, uint64_t seqNum);
        void rmReg (REGNUM regNum);

    public:
        explicit INSTR_WINDOW(INSTR_MODEL_MANAGER* _instr_model, int _windowSize);
        void tryPushWindow(COMP_INSTR* newOp);
        void tryPushWindow(MEM_INSTR* newOp);
        void tryPopWindow();
        void assignRegDepHelp(unordered_set<uint64_t>& result, REGNUM regNum);
        void assignMemDepHelp(unordered_set<uint64_t>& result,
                              ADDR effAddr, int effSize, bool isLoad);


    };
    //// dependency management
    uint64_t     lastSeqN;
    TICK         lastFetTick;
    INSTR_WINDOW instrWindow;

public:

    //// current instruction in analysis
    vector<LOAD_INSTR*>  newLdInstr;
    COMP_INSTR*          newCInstr;
    vector<STORE_INSTR*> newStInstr;
    FETCH_INSTR*         newFtInstr;

    /// for constructor
    explicit ETRACER(const string& _traceFileName,
                     const string& _outputFileName_data,
                     const string& _outputFileName_instr,
                     int _windowSize,
                     INSTR_MODEL_MANAGER* _instr_model,
                     MEM_MNG* _memMng
    );
    ~ETRACER();
    /// for main control instruction
    void step();
    /// for each instruction to track themself data
    [[maybe_unused]] static int regMapper(string regName);
    uint64_t genSeqN(); ///gen new sequence number for newly generated instruction
    void initAllPerInstrType(INSTR_TYPE      _instrType,
                             vector<string>& _rawLines,
                             uint64_t&       _instrMdId); //// init instruction from raw string file

    //// push all new micro instruction to window
    void tryPushWindowAll();

    //// write data
    void tryWrite(INSTR* newOp, ofstream* printFile,string& preWriteStr) const;
    void tryWriteAll();
    static void flushWrite(ofstream* printFile, string& preWriteStr);

    //// for get instr fetch time and step for next instruction
    TICK stepInstrExeTick(TICK amount);
};

#endif //TRACEBUILDER_TRACER_H
