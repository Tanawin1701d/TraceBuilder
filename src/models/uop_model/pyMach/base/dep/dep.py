import base.operand.opr_simple as oprSm

##### map between opr type to depend class enum to suggest uop to connect
####### dep

DEPCLASS_DEP_REG        = "DEP_REG"
DEPCLASS_DEP_MEM        = "DEP_MEM"
DEPCLASS_DEP_TEMP       = "DEP_TEMP"
DEPCLASS_DEP_EXEC_UNIT  = "DEP_EXEC_UNIT"

oprTypeToDepClassMap = {
    oprSm.OPR_REG : DEPCLASS_DEP_REG,
    oprSm.OPR_MEM : DEPCLASS_DEP_MEM,
    oprSm.OPR_TEMP: DEPCLASS_DEP_TEMP
}
