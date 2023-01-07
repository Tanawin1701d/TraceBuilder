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

    class INSTR_WINDOW {
    private:
        static const int MAX_WINDOWSIZE = 120;
        static const int MAX_REGNUM = 80;

        INSTR_MODEL_MANAGER* instrModelMng;
        int    regDep[MAX_REGNUM]{ };
        uint64_t regResult[MAX_REGNUM] {}; //sequence number
        // amount // seqnumber
        deque<INSTR*> currentWindow;

        void addReg(REGNUM regnum, uint64_t seqNum);
        void rmReg(REGNUM regNum);

    public:
        explicit INSTR_WINDOW(INSTR_MODEL_MANAGER* _instr_model);
        void tryPushWindow(COMP_INSTR* newOp);
        void tryPushWindow(MEM_INSTR* newOp);
        void tryPopWindow();
        void assignRegDepHelp(unordered_set<uint64_t>& result, REGNUM regNum);
        void assignMemDepHelp(unordered_set<uint64_t>& result,
                              ADDR effAddr, int effSize, bool isLoad);


    };
    //// dependency management
    int windowSize     = 64;
    int traceBreakSize = 10;
    uint64_t lastSeqN;
    TICK     lastFetTick;
    INSTR_WINDOW instrWindow;

public:
    vector<LOAD_INSTR*>  newLdInstr;
    COMP_INSTR*          newCInstr;
    vector<STORE_INSTR*> newStInstr;
    FETCH_INSTR*         newFtInstr;




    // head is the newest instruction

    /// for constructor
    explicit ETRACER(const string& _traceFileName,
                     const string& _outputFileName_data,
                     const string& _outputFileName_instr,
                     int _windowSize,
                     INSTR_MODEL_MANAGER* _instr_model
                     );
    ~ETRACER();
    /// for main control instruction
    void step();
    /// for each instruction to track themself data
    [[maybe_unused]]static int regMapper(string regName);
    static ADDR memMapper(ADDR virtualAddr);
    static vector<ADAS> memMapAndSplit(ADDR startAddr, int size);
    uint64_t genSeqN();
    void initAllPerInstrType(INSTR_TYPE _instrType,
                             vector<string>& _rawLines,
                             uint64_t& instrMdId);

    ///count node that will inject to window
    void tryPushWindowAll();


    void tryWrite(INSTR* newOp, ofstream* printFile,string& preWriteStr) const;
    void tryWriteAll();
    static void flushWrite(ofstream* printFile, string& preWriteStr);

    TICK stepInstrExeTick(TICK amount);


};

#endif //TRACEBUILDER_TRACER_H
