//
// Created by tanawin on 6/1/2566.
//

#include "instr_model.h"

INSTR_MODEL::INSTR_MODEL(const vector<string> &_raws):
amt_loadOpr(0),
amt_storeOpr(0)
{

    for (auto& e : effSize){ e = 0;} // to be sure

    assert(!_raws.empty());
    for (auto& raw: _raws){
        vector<string> striped;
        splitNstrip(raw, striped);
        assert(!striped.empty());
        if (striped[C_CMD_IDX] == "C"){
            handleComInstr(striped);
        }else if (striped[C_CMD_IDX] == "LS" ||
                  striped[C_CMD_IDX] == "L"  ||
                  striped[C_CMD_IDX] == "S"  ){
            handleLSInstr(striped);
        }else if (striped[C_CMD_IDX] == "F") {
            handleFInstr(striped);
        }else{
            throw invalid_argument("No instruction for " + raw);
        }
    }

}

///// get instruction detail dependency for comp load store operand

unordered_set<REGNUM> INSTR_MODEL::getSrcRegComp() {
    return srcReg[R_COMP];
}

unordered_set<REGNUM> INSTR_MODEL::getDesRegComp() {
    return desReg[R_COMP];
}

pair<unordered_set<REGNUM>, int> INSTR_MODEL::getSrcRegLS(bool isLoad, int memop) {
    assert(memop < MAXMEMOP);
    int idxSearch = (MAXMEMOP * (int)(!isLoad)) + memop;
                                        ////////// for store we use after load
    return {srcReg[idxSearch], effSize[idxSearch] };
}

//// instruction constructor helper

void INSTR_MODEL::handleComInstr(vector<string>& raw) {
    bool mark = false;
    assert(raw[C_CMD_IDX] == "C");
    if (raw[C_SD_IDX] == "S" || raw[C_SD_IDX] == "SD"){
        if (raw[C_REG_IDX] != "-1")
            srcReg[R_COMP].insert(regMapAutoAdd(raw[C_REG_IDX]));
        mark = true;
    }
    if (raw[C_SD_IDX] == "D" || raw[C_SD_IDX] == "SD"){
        if (raw[C_REG_IDX] != "-1")
            desReg[R_COMP].insert(regMapAutoAdd(raw[C_REG_IDX]));
        mark = true;
    }
    if (!mark){
        throw invalid_argument("can't intepret instruction model " + raw[1]);
    }

}

void INSTR_MODEL::handleLSInstr(vector<string>& raw) {

    bool isLoad  = raw[C_CMD_IDX] == "L" || raw[C_CMD_IDX] == "LS";
    bool isStore = raw[C_CMD_IDX] == "S" || raw[C_CMD_IDX] == "LS";
    int memop    = decStr2int(raw[LS_MEMOP]);
    assert(decStr2int(raw[LS_SIZE]) > 0);
    assert(isLoad || isStore);
    if (isLoad) {
        effSize[memop] = decStr2int(raw[LS_SIZE]);
        amt_loadOpr++;
    }
    if (isStore) {
        effSize[MAXMEMOP+memop] = decStr2int(raw[LS_SIZE]);
        amt_storeOpr++;
    }


    for (int regId = LS_REG_IDX1; regId <= LS_REG_IDX2; regId++){
        if (raw[regId] == "-1")
            continue;
        if (isLoad) {
            srcReg [memop].insert(regMapAutoAdd(raw[regId]));
        }
        if (isStore){
            srcReg [MAXMEMOP+memop].insert(regMapAutoAdd(raw[regId]));
        }
    }

}

void INSTR_MODEL::handleFInstr(vector<string>& raw) {
    assert(raw[C_CMD_IDX] == "F");
    instrAddr  = hexStr2uint(raw[F_ADDR]); /// this is virtual address
    instrSize  = decStr2int(raw[F_SIZE]);
    instrId    = decStr2uint(raw[F_ID]);
    instr_name = vector<string>(raw.begin() + F_NAME, raw.end());
}

///// get instruction information only for fetch

ADDR INSTR_MODEL::getInstrAddr() const {
    return instrAddr;
}

int INSTR_MODEL::getInstrSize() const {
    return instrSize;
}

uint64_t INSTR_MODEL::getInstrId() const {
    return instrId;
}

int INSTR_MODEL::getLoadOpAmt() const{
    return amt_loadOpr;
}

int INSTR_MODEL::getStoreOpAmt() const{
    return amt_storeOpr;
}

vector<string> INSTR_MODEL::getInstrName() const {
    return instr_name;
}

////////////////////////////////////////////////////////////////////////
////////////// instruction model pool

INSTR_MODEL_MANAGER::INSTR_MODEL_MANAGER(const string &instr_model_file)
: inputFile(new std::ifstream(instr_model_file))
{
    assert(inputFile);
    vector<string> rawLines; /// for only a instruction
    //////////////////////////////////////////////////////////////////
    string line;
    uint64_t icount = 0;
    while(getline(*inputFile, line)){
        rawLines.push_back(line);
        assert(!line.empty());
        if (line[TYPE_IDX] == 'F'){
            auto* newInstr = new INSTR_MODEL(rawLines);
            //// create new instruction model
            instr_pool.insert({newInstr->getInstrId(), newInstr});
            rawLines.clear();
            icount++;
            if (icount % 1000000 == 0){
                cout << "[INSTR MODEL] pass initialize " << icount << endl;
            }
        }
    }
    cout << "[INSTR MODEL] all instruction is fully initialized\n";
}

INSTR_MODEL_MANAGER::~INSTR_MODEL_MANAGER() {
    for (auto& e : instr_pool){
        delete e.second;
    }
    inputFile->close();
    delete inputFile;
}

INSTR_MODEL* INSTR_MODEL_MANAGER::getInstrModel(uint64_t instr_id) {
    auto finder = instr_pool.find(instr_id);
    assert( finder != instr_pool.end() );
    return finder->second;

}
