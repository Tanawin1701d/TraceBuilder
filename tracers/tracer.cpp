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
        traceFile       (new ifstream(_traceFileName)),
        outputFile_data (new ofstream(_outputFileName_data)),
        outputFile_instr(new ofstream(_outputFileName_instr)),
        instrModelMng(_instr_model_mng),
        memMng(_memMng),
        lastSeqN(UINT64_MAX),
        lastFetTick(0),
        instrWindow(_instr_model_mng, _windowSize),
        newCInstr(nullptr),
        newFtInstr(nullptr)
{
    assert(memMng);
    assert(traceFile);
    assert(outputFile_data);
    assert(outputFile_instr);
    assert(_windowSize >= 20);
    traceFile->rdbuf()->pubsetbuf(preRead_trace, MAX_PRE_RW_BUFF);
    preWrite_data.reserve(MAX_PRE_RW_BUFF + 1000);
    preWrite_instr.reserve(MAX_PRE_RW_BUFF + 1000);

}

ETRACER::~ETRACER() {
    traceFile->close();
    flushWrite(outputFile_data, preWrite_data);
    flushWrite(outputFile_instr, preWrite_instr);
    outputFile_data->close();
    outputFile_instr->close();
    delete newCInstr;


}

void ETRACER::step() {
    // for inject for each   line mean raw data that retrive from pintool
    [[maybe_unused]] vector<string> computeLines; // means multiple line is single instruction
    vector<string> loadLines;    // multiple load lines is multiple instruction
    vector<string> storeLines;   // multiple store lines is multiple instruction
    vector<string> fetchLine;    // single line of fetch per instruction

    //////////////////////////////////////////////////////////////////

    unsigned long icount = 0;
    string line;
    while(getline(*traceFile, line) ){
            /// detect microp in x86 and add to correspond type
            char instrType = line[0];
            switch (instrType) {

                case 'L' : {
                    loadLines.push_back(line);
                    break;
                }
                case 'S' : {
                    storeLines.push_back(line);
                    break;
                }
                case 'F' : {
                    assert(fetchLine.empty());
                    fetchLine.push_back(line);
                    if ((icount % 1000000) == 0)
                        cout << "pass " << icount << "file retrieved" <<  traceFile->tellg() / 1073741824 << endl;
                    icount++;
                    /// this means real single instruction is retrieved already
                    /// order of init instruction is restricted due to rob dependency connection
                    uint64_t instrMdId = -1;
                    initAllPerInstrType(FETCH, fetchLine, instrMdId); ////// fetch will give me instrMdId
                    assert(instrMdId != -1);
                    initAllPerInstrType(LOAD, loadLines   , instrMdId);
                    initAllPerInstrType(COMP, computeLines, instrMdId);
                    initAllPerInstrType(STORE,storeLines  , instrMdId);
                    ///stat
                    ///////////////// write instruction to file
                    tryPushWindowAll();
                    tryWriteAll();
                    /// clear new Instruction
                    newStInstr.clear();
                    newCInstr = nullptr;
                    newLdInstr.clear();
                    delete newFtInstr; /// fetch will not be clear by instruction window so we need to delete now
                    newFtInstr = nullptr;
                    /// clear string line
                    fetchLine.clear();
                    loadLines.clear();
                    computeLines.clear();
                    storeLines.clear();
                    break;
                }
                default:
                    throw invalid_argument("unknown instruction " + line);
            }

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
//
//int ETRACER::countNewWindowReqSize() const {
//    return (int)(newStInstr.size()) +
//           (int)(newLdInstr.size()) +
//           (int)(newCInstr != nullptr);
//}
//

void ETRACER::initAllPerInstrType(INSTR_TYPE _instrType, vector<string>& _rawLines,uint64_t& _instrMdId){
    ///////// for fetch instruction instrMdId will be used to answer instruction while other is used to initialize instruction
    if (_instrType == LOAD) {
        for (const auto& line: _rawLines){
            newLdInstr.push_back(new LOAD_INSTR(this, line, _instrMdId));
        }
        getstatPoolCount("count_loadInstr" ) += _rawLines.size();
    }else if (_instrType == STORE){
        for (const auto& line: _rawLines) {
            newStInstr.push_back(new STORE_INSTR(this, line, _instrMdId));
        }
        getstatPoolCount("count_storeInstr") += _rawLines.size();
    }else if (_instrType == COMP){
            newCInstr = new COMP_INSTR(this, _instrMdId);
            getstatPoolCount("count_compInstr" ) += 1;
    }else if (_instrType == FETCH){
        assert(!_rawLines.empty());
        newFtInstr = new FETCH_INSTR(this, _rawLines[0]);
        _instrMdId  = newFtInstr->getInstrMdId();
    }
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
    if(!newOp)
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

