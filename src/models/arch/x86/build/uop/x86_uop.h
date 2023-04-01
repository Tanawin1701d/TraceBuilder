#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"../../../dep.h"
#include"../../../uop_base.h"




 
class UOP_GEN_MEM_LD_T : public UOP_BASE{
public:
  UOP_GEN_MEM_LD_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( MEM_OPERAND* A, TREGNUM* B );
};

 
class UOP_GEN_MEM_ST_T : public UOP_BASE{
public:
  UOP_GEN_MEM_ST_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* A, MEM_OPERAND* B );
};

 
class UOP_GEN_MOV_R_R : public UOP_BASE{
public:
  UOP_GEN_MOV_R_R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* A, REG_OPERAND* B );
};

 
class UOP_GEN_MOV_R_T : public UOP_BASE{
public:
  UOP_GEN_MOV_R_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* A, TREGNUM* B );
};

 
class UOP_GEN_MOV_T_R : public UOP_BASE{
public:
  UOP_GEN_MOV_T_R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* A, REG_OPERAND* B );
};

 
class UOP_GEN_COMP_R_R_R : public UOP_BASE{
public:
  UOP_GEN_COMP_R_R_R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* A, REG_OPERAND* B, REG_OPERAND* C );
};

 
class UOP_GEN_COMP_R_T_R : public UOP_BASE{
public:
  UOP_GEN_COMP_R_T_R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* A, TREGNUM* B, REG_OPERAND* C );
};

 
class UOP_GEN_COMP_T_R_R : public UOP_BASE{
public:
  UOP_GEN_COMP_T_R_R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* A, REG_OPERAND* B, REG_OPERAND* C );
};

 
class UOP_GEN_COMP_T_T_R : public UOP_BASE{
public:
  UOP_GEN_COMP_T_T_R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* A, TREGNUM* B, REG_OPERAND* C );
};

 
class UOP_GEN_COMP_R_R_T : public UOP_BASE{
public:
  UOP_GEN_COMP_R_R_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* A, REG_OPERAND* B, TREGNUM* C );
};

 
class UOP_GEN_COMP_R_T_T : public UOP_BASE{
public:
  UOP_GEN_COMP_R_T_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* A, TREGNUM* B, TREGNUM* C );
};

 
class UOP_GEN_COMP_T_R_T : public UOP_BASE{
public:
  UOP_GEN_COMP_T_R_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* A, REG_OPERAND* B, TREGNUM* C );
};

 
class UOP_GEN_COMP_T_T_T : public UOP_BASE{
public:
  UOP_GEN_COMP_T_T_T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* A, TREGNUM* B, TREGNUM* C );
};

 
class UOP_GEN_LD_IMM : public UOP_BASE{
public:
  UOP_GEN_LD_IMM();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* T1 );
};

 
class UOP_LD_RIP : public UOP_BASE{
public:
  UOP_LD_RIP();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* RIP, TREGNUM* T1 );
};

 
class UOP_ST_RIP_1T : public UOP_BASE{
public:
  UOP_ST_RIP_1T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* T1, REG_OPERAND* RIP );
};

 
class UOP_ST_RIP_1R : public UOP_BASE{
public:
  UOP_ST_RIP_1R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* R1, REG_OPERAND* RIP );
};

 
class UOP_ST_RIP_2R : public UOP_BASE{
public:
  UOP_ST_RIP_2R();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REG_OPERAND* R1, REG_OPERAND* R2, REG_OPERAND* RIP );
};

 
class UOP_ST_RIP_2T : public UOP_BASE{
public:
  UOP_ST_RIP_2T();
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( TREGNUM* T1, TREGNUM* T2, REG_OPERAND* RIP );
};

#endif