#ifndef X86_UOPL_H
#define X86_UOPL_H
#include"../../../dep.h"
#include"../../../uop_base.h"




 
class UOP_ADD : public UOP_BASE{
public:
  UOP_ADD() = default;
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( REGNUM A, TREGNUM B, REGNUM C );
};

 
class UOP_LD : public UOP_BASE{
public:
  UOP_LD() = default;
  void doDepenCheck(UOP_WINDOW* uop_window) override;
  void addMeta( ADAS A, TREGNUM C );
};

#endif