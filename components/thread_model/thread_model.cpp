//
// Created by tanawin on 6/1/2566.
//

#include "thread_model.h"

////////////////////////////////////////////////////////////////////////
////////////// instruction model pool

THREAD_MODEL::THREAD_MODEL(const string &instr_model_file)
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
        if (line.substr(0,1) == ST_VAL_COMPO_FETCH){
            auto* newInstr = new RT_INSTR();
            /// interpret instruction
            newInstr->interpretSt(rawLines);
            /// insert new instruction to instruction pool
            instr_pool.insert({newInstr->getRtInstrId(), newInstr});
            /// clear traced line
            rawLines.clear();
            icount++;
            if (icount % 1000000 == 0){
                cout << "[INSTR MODEL] pass initialize " << icount << endl;
            }
        }
    }
    cout << "[INSTR MODEL] all instruction is fully initialized\n";
}

THREAD_MODEL::~THREAD_MODEL() {
    for (auto& e : instr_pool){
        delete e.second;
    }
    inputFile->close();
    delete inputFile;
}

RT_INSTR
THREAD_MODEL::getInstrTemplate(uint64_t instr_id) {
    auto finder = instr_pool.find(instr_id);
    assert( finder != instr_pool.end() );
    return *(finder->second);

}
