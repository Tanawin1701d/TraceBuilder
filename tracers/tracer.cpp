//
// Created by tanawin on 24/12/2565.
//

#include "tracer.h"


ETRACER::ETRACER(const string& _traceFileName,
                 const string& _outputFileName_data,
                 const string& _outputFileName_instr,
                 int _windowSize,
                 INSTR_MODEL_MANAGER* _instr_model_mng,
                 MEM_MNG* _memMng
                 ):
        traceFile       (new PIN_IO(_traceFileName)),
        instrModelMng(_instr_model_mng),
        memMng(_memMng),
        lastSeqN(UINT64_MAX),
        lastFetTick(0),
        instrWindow(_instr_model_mng, _windowSize),
        newCInstr(nullptr),
        newFtInstr(nullptr)
{
    assert(traceFile);
    // traceFile is aleady assert for unable to open file already
#ifndef debug
    protoFile_data  = new ProtoOutputStream(_outputFileName_data);
    protoFile_instr = new ProtoOutputStream(_outputFileName_instr);
    ProtoMessage::InstDepRecordHeader data_rec_header;

    ////// data side init
    data_rec_header.set_obj_id("gem5.5");
    data_rec_header.set_tick_freq(1000000000);
    data_rec_header.set_window_size(120); /// for now we use identical to gem5/util
    protoFile_data->write(data_rec_header);
    ///////////////////////////////////////////////////////////////////////////////////////
    ////// instruction side init

#else
    assert(outputFile_data);
    assert(outputFile_instr);
    outputFile_data (new ofstream(_outputFileName_data)),
    outputFile_instr(new ofstream(_outputFileName_instr)),
    preWrite_data.reserve(MAX_PRE_RW_BUFF + 1000);
    preWrite_instr.reserve(MAX_PRE_RW_BUFF + 1000);
#endif
    assert(memMng);
    assert(_windowSize >= 20);
    //traceFile->rdbuf()->pubsetbuf(preRead_trace, MAX_PRE_RW_BUFF);


}

ETRACER::~ETRACER() {
    delete traceFile;

#ifndef debug
    //delete protoFile_data;
    //delete protoFile_instr;
#else
    flushWrite(outputFile_data, preWrite_data);
    flushWrite(outputFile_instr, preWrite_instr);
    outputFile_data->close();
    outputFile_instr->close();
#endif

    delete newCInstr;


}

void ETRACER::step() {
    //////////////////////////////////////////////////////////////////

    unsigned long icount = 0;
    string line;
    RT_OBJ singleInstr{};
    while(traceFile->readInstr(singleInstr) ){
        /// readInstr will read single instruction from file
        initInstr(singleInstr);
    }
}

int ETRACER::regMapper(string regName) {
    boost::trim_left(regName);
    boost::trim_right(regName);
    return regMapAutoAdd(regName);
}

uint64_t ETRACER::genSeqN() {
    return ++lastSeqN;
}


void ETRACER::initAllPerInstrType(RT_OBJ& instr_rt){
    ///////// for fetch instruction instrMdId will be used to answer instruction while other is used to initialize instruction
    /// things to make sure

    /////// 1.instruction is add to global class member which will be added to obs window
    /////// 2.instruction is initiate in order ====> |fetch|load|comp|store|
    /////// 3. instruction model id is set in fetch instr init


    /// init fetch instruction first
             newFtInstr  = new FETCH_INSTR(this, instr_rt);
    uint64_t _instrMdId  = newFtInstr->getInstrMdId();
    /// init load instruction
    int loadOpAmt = instrModelMng->getInstrModel(_instrMdId)->getLoadOpAmt();
    for (int loadIdx = 0; loadIdx  < loadOpAmt; loadIdx++){
        newLdInstr.push_back(new LOAD_INSTR(this, loadIdx, _instrMdId));
    }
    getstatPoolCount("count_loadInstr" ) += loadOpAmt;
    /// init comp instruction
    newCInstr = new COMP_INSTR(this, _instrMdId);
    getstatPoolCount("count_compInstr" ) += 1;
    /// init store instruction
    int storeOpAmt = instrModelMng->getInstrModel(_instrMdId)->getStoreOpAmt();
    for (int storeIdx = 0; storeIdx  < storeOpAmt; storeIdx++){
        newStInstr.push_back(new STORE_INSTR(this, storeIdx, _instrMdId));
    }
    getstatPoolCount("count_storeInstr") += storeOpAmt;
}

void ETRACER::tryPushWindowAll() {
    //// we push store first because it will be push to front of queue not at the back.
    ////  ------------------>>
    ////  |LOAD|COMP|STORE|

    for (const auto sstInstr: newStInstr){
        instrWindow.tryPushWindow((MEM_INSTR*) sstInstr);
    }
    instrWindow.tryPushWindow((COMP_INSTR*)newCInstr);
    for (const auto sldInstr: newLdInstr){
        instrWindow.tryPushWindow((MEM_INSTR*)sldInstr);
    }
}

void ETRACER::tryWriteAll() {
    ////  ------------------>>
    ////  |LOAD|COMP|STORE|

    ///// for elastic trace
#ifndef debug
    for (const auto sLdInstr: newLdInstr){
        tryWriteProto((INSTR *) sLdInstr, protoFile_data);
    }
    tryWriteProto((INSTR *) newCInstr, protoFile_data);
    for (const auto sStInstr: newStInstr){
        tryWriteProto((INSTR *) sStInstr, protoFile_data);
    }
    ///// for static fetch trace
    tryWriteProto((INSTR *) newFtInstr, protoFile_data);
#else
    for (const auto sLdInstr: newLdInstr){
        tryWriteASCII((INSTR *) sLdInstr, outputFile_data, preWrite_data);
    }
    tryWriteASCII((INSTR *) newCInstr, outputFile_data, preWrite_data);
    for (const auto sStInstr: newStInstr){
        tryWriteASCII((INSTR *) sStInstr, outputFile_data, preWrite_data);
    }
    ///// for static fetch trace
    tryWriteASCII((INSTR *) newFtInstr, outputFile_instr, preWrite_instr);
#endif
}

void ETRACER::tryWriteProto(INSTR* newOp, ProtoOutputStream* printFile) {
    if (!newOp)
        return;

    newOp->genProtoMsg(printFile);


}


#ifdef debug
    void ETRACER::tryWriteASCII(INSTR* newOp, ofstream* printFile, string& preWriteStr) const {
        if (newOp) {
            //*printFile << newOp->genAscLine() << endl;
            if (preWriteStr.size() >= MAX_PRE_RW_BUFF){
                flushWrite(printFile, preWriteStr);
            }
            preWriteStr += newOp->genAscLine();
            preWriteStr += '\n';
        }
    }


    void ETRACER::flushWrite(ofstream* printFile, string& preWriteStr) {
        if (!preWriteStr.empty()){
            *printFile << preWriteStr;
            preWriteStr.clear();
        }
    }

#endif


TICK ETRACER::stepInstrExeTick(TICK amount) {
    TICK curTick = lastFetTick;
    lastFetTick += amount;
    return curTick;
}

