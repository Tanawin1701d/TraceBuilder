//
// Created by tanawin on 6/1/2566.
//

#ifndef TRACEBUILDER_INSTR_MODEL_H
#define TRACEBUILDER_INSTR_MODEL_H

#include "../regMap/regMapper.h"
#include "instr.h"



enum REALINSTR_TYPE{
    R_LOAD0   = 0,
    R_LOAD1   = 1,
    R_LOAD2   = 2,
    R_LOAD3   = 3,
    R_STORE0  = 4,
    R_STORE1  = 5,
    R_STORE2  = 6,
    R_STORE3  = 7,
    R_COMP    = 8,
    R_FETCH   = 9,
    REALINSTR_TYPE_AMT = 10
    //DUMMY
};

class INSTR_MODEL{


private:
  static const int amt_operandType = 10;
    static const int MAXMEMOP = 4;


  static const int C_CMD_IDX  = 0;
  static const int C_SD_IDX   = 1; // source or des reg index
  static const int C_REG_IDX  = 2;

  static const int LS_REG_IDX1   = 1;
  static const int LS_REG_IDX2   = 2;
  static const int LS_SIZE       = 3;
  static const int LS_MEMOP      = 4;

  static const int F_ADDR   = 1; // source or des reg index
  static const int F_SIZE   = 2; // source or des reg index
  static const int F_ID     = 3; // source or des reg index
  static const int F_NAME   = 4; // source or des reg index

  ADDR     instrAddr{};
  int      instrSize{};
  uint64_t instrId{};
  [[maybe_unused]] vector<string> instr_name;

private:

    //// store neccessary src and des register for each comp load store
  unordered_set<REGNUM> srcReg [amt_operandType];
  unordered_set<REGNUM> desReg [amt_operandType];   // des reg for load and store operand is not used.
  int                   effSize[amt_operandType]{}; // effective memory address size // for comp and fetch is set to 0
  void handleComInstr(vector<string>& raw);
  void handleLSInstr (vector<string>& raw);
  void handleFInstr  (vector<string>& raw);
public:
    explicit INSTR_MODEL(const vector<string>& _raw);

    // instruction compute load detailed
    unordered_set<REGNUM> getSrcRegComp();
    unordered_set<REGNUM> getDesRegComp();
    pair<unordered_set<REGNUM>, int> getSrcRegLS(bool isLoad, int memop); //return src reg and size of effective address

    // instuction get and set
    ADDR             getInstrAddr() const;
    int              getInstrSize() const;
    uint64_t         getInstrId  () const;
    [[maybe_unused]] vector<string> getInstrName() const;



};

class INSTR_MODEL_MANAGER{

private:
    unordered_map<uint64_t, INSTR_MODEL*> instr_pool;
    ifstream* inputFile;

    static const int TYPE_IDX = 0;

public:
    explicit INSTR_MODEL_MANAGER(const string& instr_model_file);
    ~INSTR_MODEL_MANAGER();
    INSTR_MODEL* getInstrModel(uint64_t instr_id);


};


#endif //TRACEBUILDER_INSTR_MODEL_H
