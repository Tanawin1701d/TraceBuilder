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
        traceFile    (new PIN_IO(_traceFileName)),
        instrModelMng(_instr_model_mng),
        memMng       (_memMng),
        lastSeqN     (UINT64_MAX),
        lastFetTick  (0),
        instrWindow  (_instr_model_mng, _windowSize),
        newCInstr    (nullptr),
        newFtInstr   (nullptr)
{
    assert(traceFile);
    // traceFile is aleady assert for unable to open file already
    protoFile_data  = new ProtoOutputStream(_outputFileName_data);
    protoFile_instr = new ProtoOutputStream(_outputFileName_instr);
    ///////instr side init
    ProtoMessage::PacketHeader inst_pkt_header;
    inst_pkt_header.set_obj_id("gem5");
    inst_pkt_header.set_tick_freq(1000000000);
    protoFile_instr->write(inst_pkt_header);
    ////// data side init
    ProtoMessage::InstDepRecordHeader data_rec_header;
    data_rec_header.set_obj_id("gem5");
    data_rec_header.set_tick_freq(1000000000);
    data_rec_header.set_window_size(120); /// for now we use identical to gem5/util
    protoFile_data->write(data_rec_header);
    ///////////////////////////////////////////////////////////////////////////////////////
    ////// instruction side init
    assert(memMng);
    assert(_windowSize >= 20);
    //traceFile->rdbuf()->pubsetbuf(preRead_trace, MAX_PRE_RW_BUFF);


}

ETRACER::~ETRACER() {
    delete traceFile;
    delete protoFile_data;
    delete protoFile_instr;

}

void ETRACER::step() {
    //////////////////////////////////////////////////////////////////

    unsigned long icount = 0;
    string line;
    RT_OBJ singleInstr{};
    while(traceFile->readInstr(singleInstr) ){
        #ifdef debug
            if (icount < 50) {
                cout << "-----------" << icount << "------------------" << endl;
                cout << to_string(singleInstr) << endl;
            }
        #else
        if ((icount % 10000000) == 0)
            cout << "instruction pass : " << icount << endl;
        #endif
        /// readInstr will read single instruction from file
        initInstr(singleInstr);
        //// write to google protobuf file
        tryWriteAll();
        //// push to observation window
        tryPushWindowAll();
        /////// clear processing data due to added to instruction window
        clear_inproc_instr();
        icount++;
    }
}

//int ETRACER::regMapper(string regName) {
//    boost::trim_left(regName);
//    boost::trim_right(regName);
//    return regMapAutoAdd(regName);
//}

uint64_t ETRACER::genSeqN() {
    return ++lastSeqN;
}


void ETRACER::initInstr(RT_OBJ& instr_rt){
    ///////// for fetch instruction instrMdId will be used to answer instruction while other is used to initialize instruction
    /// things to make sure

    /////// 1.instruction is add to global class member which will be added to obs window
    /////// 2.instructions are initiate in order ====> |fetch|load|comp|store|
    /////// 3. instruction model id is set and get in fetch instr init


    /// init fetch instruction first
             newFtInstr  = new FETCH_INSTR(this, instr_rt);
    uint64_t _instrMdId  = newFtInstr->getInstrMdId();


    /// init load instruction
    int loadOpAmt = instrModelMng->getInstrModel(_instrMdId)->getLoadOpAmt();
    for (int loadIdx = 0; loadIdx  < loadOpAmt; loadIdx++){
        newLdInstr.push_back(new LOAD_INSTR(this,
                                            instr_rt,
                                            loadIdx,
                                            _instrMdId));
    }
    getstatPoolCount("count_loadInstr" ) += loadOpAmt;



    /// init comp instruction
    newCInstr = new COMP_INSTR(this, _instrMdId);
    getstatPoolCount("count_compInstr" ) += 1;


    /// init store instruction
    int storeOpAmt = instrModelMng->getInstrModel(_instrMdId)->getStoreOpAmt();
    for (int storeIdx = 0; storeIdx  < storeOpAmt; storeIdx++){
        newStInstr.push_back(new STORE_INSTR(this,
                                             instr_rt,
                                             storeIdx,
                                             _instrMdId)
                             );
    }
    getstatPoolCount("count_storeInstr") += storeOpAmt;

}

void ETRACER::tryPushWindowAll() {
    //// we push store first because it will be push to front of queue not at the back.
    ////  ------------------>>
    ////  |STORE|COMP|LOAD|
    for (const auto sldInstr: newLdInstr){
        instrWindow.tryPushWindow((MEM_INSTR*)sldInstr);
    }
    instrWindow.tryPushWindow((COMP_INSTR*)newCInstr);
    for (const auto sstInstr: newStInstr){
        instrWindow.tryPushWindow((MEM_INSTR*) sstInstr);
    }
}

void ETRACER::tryWriteAll() {
    ////  ------------------>>
    ////  |LOAD|COMP|STORE|

    ///// for elastic trace
    for (const auto sLdInstr: newLdInstr){
        tryWriteProto((INSTR *) sLdInstr, protoFile_data);
    }
    tryWriteProto((INSTR *) newCInstr, protoFile_data);
    for (const auto sStInstr: newStInstr){
        tryWriteProto((INSTR *) sStInstr, protoFile_data);
    }
    ///// for static fetch trace
    tryWriteProto((INSTR *) newFtInstr, protoFile_instr);
}

void ETRACER::clear_inproc_instr() {
    newLdInstr.clear();
    newStInstr.clear();
    ////// fet node must be deleted right now because it isn't added to observation window
    delete newFtInstr;
}

void ETRACER::tryWriteProto(INSTR* newOp, ProtoOutputStream* printFile) {
    if (!newOp)
        return;

    newOp->genProtoMsg(printFile);


}

TICK ETRACER::stepInstrExeTick(TICK amount) {
    TICK curTick = lastFetTick;
    lastFetTick += amount;
    return curTick;
}