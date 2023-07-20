//
// Created by tanawin on 28/12/2565.
//

#ifndef TRACEBUILDER_RT_INSTR_H
#define TRACEBUILDER_RT_INSTR_H


////// runtime instr it like dynamic instruction in gem5
#include <pybind11/stl.h>
#include "operand.h"

#include "core/tracerFrontEnd/staticTraceVar.h"
#include "core/tracerFrontEnd/dynTraceVar.h"
#include "models/res_model/memMng/MemMng.h"
#include "ioHelp/strHelp.h"
#include "models/uop_model/uop_base.h"
#include "models/inst_model/operand.h"
#include "models/uop_model/agent/mop_agent.h"


namespace traceBuilder::model {



        /** pybind  function*/
#define GET_RT_INSTR_SRC_REG_OPR_FN  getSrcRegOperands
#define GET_RT_INSTR_SRC_MEM_OPR_FN  getSrcLdOperands
#define GET_RT_INSTR_SRC_IMM_OPR_FN  getSrcImmOperands
#define GET_RT_INSTR_SRC_POOL_OPR_FN getSrcMacroPoolOperands
#define GET_RT_INSTR_DES_REG_OPR_FN  getDesRegOperands
#define GET_RT_INSTR_DES_MEM_OPR_FN  getDesStOperands
#define GET_RT_INSTR_DES_POOL_OPR_FN getDesMacroPoolOperands

#define GET_RT_INSTR_SRC_REG_OPR_FN_STR  "getSrcRegOperands"
#define GET_RT_INSTR_SRC_MEM_OPR_FN_STR  "getSrcLdOperands"
#define GET_RT_INSTR_SRC_IMM_OPR_FN_STR  "getSrcImmOperands"
#define GET_RT_INSTR_SRC_POOL_OPR_FN_STR "getSrcMacroPoolOperands"
#define GET_RT_INSTR_DES_REG_OPR_FN_STR  "getDesRegOperands"
#define GET_RT_INSTR_DES_MEM_OPR_FN_STR  "getDesStOperands"
#define GET_RT_INSTR_DES_POOL_OPR_FN_STR "getDesMacroPoolOperands"

        typedef uint64_t RT_INSTR_ID;
        typedef std::shared_ptr<RT_INSTR> RT_INSTR_PTR;

///////////////// !=====IMPORTANT=====!
////////////////////// every class member must be
////////////////////// referred in copy constructor to prevent data missing

        class RT_INSTR {
        private:
            const std::string DEC_REG_OPR = "R";
            const std::string DEC_LD_OPR = "M";
            const std::string DEC_ST_OPR = "M";
            const std::string DEC_IMM_OPR = "I";
            const std::string DEC_DILEM = "$";
            const std::string DEC_DILEM_OPR = "_";


            /////// id and identifier
            uint64_t rt_instr_id{};
            /////// for debug and provide information
            std::string mnemonic;
            std::vector<std::string> srcDecodeKey;
            std::vector<std::string> desDecodeKey;
            std::string debugDecodeKey;
            std::string debugName; //// the instruction that obtain from raw data
            /////// instruction metadata
            //[[maybe_unused]]
            ADDR addr{};
            ADDR size{};
            /////// src operand data and metadata
            std::vector<OPR_REG> srcRegOperands;
            std::vector<OPR_MEM> srcLdOperands;
            std::vector<OPR_IMM> srcImmOperands;
            /////// pool operand to allow macro-op access in correct order
            std::vector<OPERAND_PTR> srcMacroPoolOperands; /// pool the  src operand for macroop will get it and fill into micro-op
            /////// des operand data and metadata
            /// for now we assume that order is matter to classify instruction and micro-op
            std::vector<OPR_REG> desRegOperands;
            std::vector<OPR_MEM> desStOperands;
            /////// pool operand to allow macro-op access in correct order
            std::vector<OPERAND_PTR> desMacroPoolOperands;/// pool the  des operand for macroop will get it and fill into micro-op
            /** mop agent for generate microop*/
            MOP_AGENT_PTR _mopAgentPtr;



        protected:

            /// interpret operand for each type from raw data that recieve from pintool
            virtual void
            interpretRegOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx);

            virtual void
            interpretLOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx);

            virtual void
            interpretSOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx);

            virtual void interpretLSOperand(std::vector<std::string> &tokens, bool isLoad, size_t &lstSrcMacroIdx,
                                            size_t &lstDesMacroIdx);

            virtual void
            interpretImmOperand(std::vector<std::string> &tokens, size_t &lstSrcMacroIdx, size_t &lstDesMacroIdx);

            virtual void interpretFetch(std::vector<std::string> &tokens);

            virtual void interpretDebugStr(std::vector<std::string> &tokens);

        public:
            RT_INSTR(RT_INSTR &host); ///copy constructor
            RT_INSTR(); /// vanila constructor
            virtual ~RT_INSTR();

            ///////// entry point to interpret single instruction
            void interpretStaticTracedData(const std::vector<std::string> &st_raw); // interpret from raw static tracer
            ///////// fill dynamic data tracing
            void fillDynData( core::RT_OBJ& rawDynData, core::CVT_RT_OBJ &cvtDynData);

            ///////// generate uop    /////// HOTSPOT
            void genUOPS(std::vector<UOP_BASE*> &results);

            void setMopAgent(const MOP_AGENT_PTR& mopAgentPtr){
                assert(mopAgentPtr != nullptr);
                _mopAgentPtr = mopAgentPtr;
            }

            uint64_t getRtInstrId() const { return rt_instr_id; };

            const std::string& getMnemonic() const { return mnemonic; };

            const std::string getDebugDecodeKey() const { return debugDecodeKey; };

            const std::string getDebugName() const { return debugName; };

            ADDR getAddr() const { return addr; };

            int getSize() const { return size; };

            std::string getDecodeKey();


            ////// get method
            std::vector<OPR_REG>&   GET_RT_INSTR_SRC_REG_OPR_FN()  { return srcRegOperands;};
            std::vector<OPR_MEM>&   GET_RT_INSTR_SRC_MEM_OPR_FN() { return srcLdOperands; };
            std::vector<OPR_IMM>&   GET_RT_INSTR_SRC_IMM_OPR_FN() { return srcImmOperands; };
            std::vector<OPERAND_PTR>& GET_RT_INSTR_SRC_POOL_OPR_FN() { return srcMacroPoolOperands; };
            std::vector<OPR_REG>&   GET_RT_INSTR_DES_REG_OPR_FN() { return desRegOperands; };
            std::vector<OPR_MEM>&   GET_RT_INSTR_DES_MEM_OPR_FN() { return desStOperands; };
            std::vector<OPERAND_PTR>& GET_RT_INSTR_DES_POOL_OPR_FN() { return desMacroPoolOperands; };



            ////// count method
            int countSrcRegOperands() const { return (int) srcRegOperands.size(); };
            int countSrcLdOpeands()   const { return (int) srcLdOperands.size(); };
            int countSrcImmOperands() const { return (int) srcImmOperands.size(); };
            int countDesRegOperands() const { return (int) desRegOperands.size(); };
            int countDesStOperands()  const { return (int) desStOperands.size(); };

        };

    ////////////////////////////////////////////////////////////////////////////////////////
    ///////// pybind declaration
    namespace py = pybind11;
    void BIND_RT_INSTR(py::module& m);

}


#endif //TRACEBUILDER_RT_INSTR_H
