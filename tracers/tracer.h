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
#include "../components/inst/rtInstr.h"
#include "../components/inst/instr_model.h"
#include "../components/memMap/MemMng.h"
#include "../ioHelp/pinIoSh/pinIo.h"
#include <google/protobuf/message.h>
//#include "../ioHelp/protoHelp/protoio.hh"
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
    PIN_IO* traceFile;
    ProtoOutputStream* protoFile_data;
    ProtoOutputStream* protoFile_instr;

    /////////INSTR_MODEL
    INSTR_MODEL_MANAGER* instrModelMng;
    /////////MEMORY_MANAGER
    MEM_MNG* memMng;
    ////////INSTR_WINDOW
    class INSTR_WINDOW {
    private:
               const int MAX_WINDOWSIZE = 120;
        static const int MAX_REGNUM     = 80;

        INSTR_MODEL_MANAGER* instrModelMng;
        int      regDep   [MAX_REGNUM] {};
        uint64_t regResult[MAX_REGNUM] {}; //sequence number
        // amount // seqnumber
        deque<INSTR*> currentWindow;

        void addReg(REGNUM regNum, uint64_t seqNum);
        void rmReg (REGNUM regNum);

    public:
        explicit INSTR_WINDOW(INSTR_MODEL_MANAGER* _instr_model, int _windowSize);
        ~INSTR_WINDOW();
        void tryPushWindow(COMP_INSTR* newOp);
        void tryPushWindow(MEM_INSTR * newOp);
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

    /////////INPROCESSING INSTRUCTION
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
    uint64_t genSeqN(); ///gen new sequence number for newly generated instruction
    void initInstr(RT_OBJ& instr_rt); //// init instruction from raw string file
    //// push all new micro instruction to window
    void tryPushWindowAll();
    void tryWriteAll();
    void clear_inproc_instr();

    void tryWriteProto(INSTR* newOp, ProtoOutputStream* printFile);
    //// for get instr fetch time and step for next instruction
    TICK stepInstrExeTick(TICK amount);
};

#endif //TRACEBUILDER_TRACER_H
