/* CPU data header for or1k.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright 1996-2010 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#ifndef OR1K_CPU_H
#define OR1K_CPU_H

#define CGEN_ARCH or1k

/* Given symbol S, return or1k_cgen_<S>.  */
#define CGEN_SYM(s) or1k##_cgen_##s


/* Selected cpu families.  */
#define HAVE_CPU_OR1K32F

#define CGEN_INSN_LSB0_P 1

/* Minimum size of any insn (in bytes).  */
#define CGEN_MIN_INSN_SIZE 4

/* Maximum size of any insn (in bytes).  */
#define CGEN_MAX_INSN_SIZE 4

#define CGEN_INT_INSN_P 1

/* Maximum number of syntax elements in an instruction.  */
#define CGEN_ACTUAL_MAX_SYNTAX_ELEMENTS 17

/* CGEN_MNEMONIC_OPERANDS is defined if mnemonics have operands.
   e.g. In "b,a foo" the ",a" is an operand.  If mnemonics have operands
   we can't hash on everything up to the space.  */
#define CGEN_MNEMONIC_OPERANDS

/* Maximum number of fields in an instruction.  */
#define CGEN_ACTUAL_MAX_IFMT_OPERANDS 8

/* Enums.  */

/* Enum declaration for special purpose register groups.  */
typedef enum spr_groups {
  SPR_GROUP_SYS, SPR_GROUP_DMMU, SPR_GROUP_IMMU, SPR_GROUP_DCACHE
 , SPR_GROUP_ICACHE, SPR_GROUP_MAC, SPR_GROUP_DEBUG, SPR_GROUP_PERF
 , SPR_GROUP_POWER, SPR_GROUP_PIC, SPR_GROUP_TICK, SPR_GROUP_FPU
} SPR_GROUPS;

/* Enum declaration for SYS SPR register indices.  */
typedef enum spr_sys_indices {
  SPR_INDEX_SYS_VR = 0, SPR_INDEX_SYS_UPR = 1, SPR_INDEX_SYS_CPUCFGR = 2, SPR_INDEX_SYS_DMMUCFGR = 3
 , SPR_INDEX_SYS_IMMUCFGR = 4, SPR_INDEX_SYS_DCCFGR = 5, SPR_INDEX_SYS_ICCFGR = 6, SPR_INDEX_SYS_DCFGR = 7
 , SPR_INDEX_SYS_PCCFGR = 8, SPR_INDEX_SYS_NPC = 16, SPR_INDEX_SYS_SR = 17, SPR_INDEX_SYS_PPC = 18
 , SPR_INDEX_SYS_FPCSR = 20, SPR_INDEX_SYS_EPCR0 = 32, SPR_INDEX_SYS_EPCR1 = 33, SPR_INDEX_SYS_EPCR2 = 34
 , SPR_INDEX_SYS_EPCR3 = 35, SPR_INDEX_SYS_EPCR4 = 36, SPR_INDEX_SYS_EPCR5 = 37, SPR_INDEX_SYS_EPCR6 = 38
 , SPR_INDEX_SYS_EPCR7 = 39, SPR_INDEX_SYS_EPCR8 = 40, SPR_INDEX_SYS_EPCR9 = 41, SPR_INDEX_SYS_EPCR10 = 42
 , SPR_INDEX_SYS_EPCR11 = 43, SPR_INDEX_SYS_EPCR12 = 44, SPR_INDEX_SYS_EPCR13 = 45, SPR_INDEX_SYS_EPCR14 = 46
 , SPR_INDEX_SYS_EPCR15 = 47, SPR_INDEX_SYS_EEAR0 = 48, SPR_INDEX_SYS_EEAR1 = 49, SPR_INDEX_SYS_EEAR2 = 50
 , SPR_INDEX_SYS_EEAR3 = 51, SPR_INDEX_SYS_EEAR4 = 52, SPR_INDEX_SYS_EEAR5 = 53, SPR_INDEX_SYS_EEAR6 = 54
 , SPR_INDEX_SYS_EEAR7 = 55, SPR_INDEX_SYS_EEAR8 = 56, SPR_INDEX_SYS_EEAR9 = 57, SPR_INDEX_SYS_EEAR10 = 58
 , SPR_INDEX_SYS_EEAR11 = 59, SPR_INDEX_SYS_EEAR12 = 60, SPR_INDEX_SYS_EEAR13 = 61, SPR_INDEX_SYS_EEAR14 = 62
 , SPR_INDEX_SYS_EEAR15 = 63, SPR_INDEX_SYS_ESR0 = 64, SPR_INDEX_SYS_ESR1 = 65, SPR_INDEX_SYS_ESR2 = 66
 , SPR_INDEX_SYS_ESR3 = 67, SPR_INDEX_SYS_ESR4 = 68, SPR_INDEX_SYS_ESR5 = 69, SPR_INDEX_SYS_ESR6 = 70
 , SPR_INDEX_SYS_ESR7 = 71, SPR_INDEX_SYS_ESR8 = 72, SPR_INDEX_SYS_ESR9 = 73, SPR_INDEX_SYS_ESR10 = 74
 , SPR_INDEX_SYS_ESR11 = 75, SPR_INDEX_SYS_ESR12 = 76, SPR_INDEX_SYS_ESR13 = 77, SPR_INDEX_SYS_ESR14 = 78
 , SPR_INDEX_SYS_ESR15 = 79
} SPR_SYS_INDICES;

/* Enum declaration for SYS MAC register indices.  */
typedef enum spr_mac_indices {
  SPR_INDEX_MAC_MACLO = 1, SPR_INDEX_MAC_MACHI = 2
} SPR_MAC_INDICES;

/* Enum declaration for SYS FPCSR register field starts.  */
typedef enum spr_field_starts_sys_fpcsr {
  SPR_FIELD_START_SYS_FPCSR_FPEE = 0, SPR_FIELD_START_SYS_FPCSR_RM = 2, SPR_FIELD_START_SYS_FPCSR_OVF = 3, SPR_FIELD_START_SYS_FPCSR_UNF = 4
 , SPR_FIELD_START_SYS_FPCSR_SNF = 5, SPR_FIELD_START_SYS_FPCSR_QNF = 6, SPR_FIELD_START_SYS_FPCSR_ZF = 7, SPR_FIELD_START_SYS_FPCSR_IXF = 8
 , SPR_FIELD_START_SYS_FPCSR_IVF = 9, SPR_FIELD_START_SYS_FPCSR_INF = 10, SPR_FIELD_START_SYS_FPCSR_DZF = 11
} SPR_FIELD_STARTS_SYS_FPCSR;

/* Enum declaration for SYS FPCSR register field lengths.  */
typedef enum spr_field_lengths_fpcsr {
  SPR_FIELD_LENGTH_SYS_FPCSR_FPEE = 1, SPR_FIELD_LENGTH_SYS_FPCSR_RM = 2, SPR_FIELD_LENGTH_SYS_FPCSR_OVF = 1, SPR_FIELD_LENGTH_SYS_FPCSR_UNF = 1
 , SPR_FIELD_LENGTH_SYS_FPCSR_SNF = 1, SPR_FIELD_LENGTH_SYS_FPCSR_QNF = 1, SPR_FIELD_LENGTH_SYS_FPCSR_ZF = 1, SPR_FIELD_LENGTH_SYS_FPCSR_IXF = 1
 , SPR_FIELD_LENGTH_SYS_FPCSR_IVF = 1, SPR_FIELD_LENGTH_SYS_FPCSR_INF = 1, SPR_FIELD_LENGTH_SYS_FPCSR_DZF = 1
} SPR_FIELD_LENGTHS_FPCSR;

/* Enum declaration for insn main opcode enums.  */
typedef enum insn_opcode {
  OPC_J = 0, OPC_JAL = 1, OPC_BNF = 3, OPC_BF = 4
 , OPC_NOP = 5, OPC_MOVHIMACRC = 6, OPC_SYSTRAPSYNCS = 8, OPC_RFE = 9
 , OPC_VECTOR = 10, OPC_JR = 17, OPC_JALR = 18, OPC_MACI = 19
 , OPC_CUST1 = 28, OPC_CUST2 = 29, OPC_CUST3 = 30, OPC_CUST4 = 31
 , OPC_LD = 32, OPC_LWZ = 33, OPC_LWS = 34, OPC_LBZ = 35
 , OPC_LBS = 36, OPC_LHZ = 37, OPC_LHS = 38, OPC_ADDI = 39
 , OPC_ADDIC = 40, OPC_ANDI = 41, OPC_ORI = 42, OPC_XORI = 43
 , OPC_MULI = 44, OPC_MFSPR = 45, OPC_SHROTI = 46, OPC_SFI = 47
 , OPC_MTSPR = 48, OPC_MAC = 49, OPC_FLOAT = 50, OPC_SD = 52
 , OPC_SW = 53, OPC_SB = 54, OPC_SH = 55, OPC_ALU = 56
 , OPC_SF = 57, OPC_CUST5 = 60, OPC_CUST6 = 61, OPC_CUST7 = 62
 , OPC_CUST8 = 63
} INSN_OPCODE;

/* Enum declaration for systrapsync insn opcode enums.  */
typedef enum insn_opcode_systrapsyncs {
  OPC_SYSTRAPSYNCS_SYSCALL = 0, OPC_SYSTRAPSYNCS_TRAP = 8, OPC_SYSTRAPSYNCS_MSYNC = 16, OPC_SYSTRAPSYNCS_PSYNC = 20
 , OPC_SYSTRAPSYNCS_CSYNC = 24
} INSN_OPCODE_SYSTRAPSYNCS;

/* Enum declaration for movhi/macrc insn opcode enums.  */
typedef enum insn_opcode_movehimacrc {
  OPC_MOVHIMACRC_MOVHI, OPC_MOVHIMACRC_MACRC
} INSN_OPCODE_MOVEHIMACRC;

/* Enum declaration for multiply/accumulate insn opcode enums.  */
typedef enum insn_opcode_mac {
  OPC_MAC_MAC = 1, OPC_MAC_MSB = 2
} INSN_OPCODE_MAC;

/* Enum declaration for shift/rotate insn opcode enums.  */
typedef enum insn_opcode_shorts {
  OPC_SHROTS_SLL, OPC_SHROTS_SRL, OPC_SHROTS_SRA, OPC_SHROTS_ROR
} INSN_OPCODE_SHORTS;

/* Enum declaration for extend byte/half opcode enums.  */
typedef enum insn_opcode_extbhs {
  OPC_EXTBHS_EXTHS, OPC_EXTBHS_EXTBS, OPC_EXTBHS_EXTHZ, OPC_EXTBHS_EXTBZ
} INSN_OPCODE_EXTBHS;

/* Enum declaration for extend word opcode enums.  */
typedef enum insn_opcode_extws {
  OPC_EXTWS_EXTWS, OPC_EXTWS_EXTWZ
} INSN_OPCODE_EXTWS;

/* Enum declaration for alu reg/reg insn opcode enums.  */
typedef enum insn_opcode_alu_regreg {
  OPC_ALU_REGREG_ADD = 0, OPC_ALU_REGREG_ADDC = 1, OPC_ALU_REGREG_SUB = 2, OPC_ALU_REGREG_AND = 3
 , OPC_ALU_REGREG_OR = 4, OPC_ALU_REGREG_XOR = 5, OPC_ALU_REGREG_MUL = 6, OPC_ALU_REGREG_SHROT = 8
 , OPC_ALU_REGREG_DIV = 9, OPC_ALU_REGREG_DIVU = 10, OPC_ALU_REGREG_MULU = 11, OPC_ALU_REGREG_EXTBH = 12
 , OPC_ALU_REGREG_EXTW = 13, OPC_ALU_REGREG_CMOV = 14, OPC_ALU_REGREG_FFL1 = 15
} INSN_OPCODE_ALU_REGREG;

/* Enum declaration for setflag insn opcode enums.  */
typedef enum insn_opcode_setflag {
  OPC_SF_EQ = 0, OPC_SF_NEQ = 1, OPC_SF_GTU = 2, OPC_SF_GEU = 3
 , OPC_SF_LTU = 4, OPC_SF_LEU = 5, OPC_SF_GTS = 10, OPC_SF_GES = 11
 , OPC_SF_LTS = 12, OPC_SF_LES = 13
} INSN_OPCODE_SETFLAG;

/* Enum declaration for floating point reg/reg insn opcode enums.  */
typedef enum insn_opcode_float_regreg {
  OPC_FLOAT_REGREG_ADD_S = 0, OPC_FLOAT_REGREG_SUB_S = 1, OPC_FLOAT_REGREG_MUL_S = 2, OPC_FLOAT_REGREG_DIV_S = 3
 , OPC_FLOAT_REGREG_ITOF_S = 4, OPC_FLOAT_REGREG_FTOI_S = 5, OPC_FLOAT_REGREG_REM_S = 6, OPC_FLOAT_REGREG_MADD_S = 7
 , OPC_FLOAT_REGREG_SFEQ_S = 8, OPC_FLOAT_REGREG_SFNE_S = 9, OPC_FLOAT_REGREG_SFGT_S = 10, OPC_FLOAT_REGREG_SFGE_S = 11
 , OPC_FLOAT_REGREG_SFLT_S = 12, OPC_FLOAT_REGREG_SFLE_S = 13, OPC_FLOAT_REGREG_ADD_D = 16, OPC_FLOAT_REGREG_SUB_D = 17
 , OPC_FLOAT_REGREG_MUL_D = 18, OPC_FLOAT_REGREG_DIV_D = 19, OPC_FLOAT_REGREG_ITOF_D = 20, OPC_FLOAT_REGREG_FTOI_D = 21
 , OPC_FLOAT_REGREG_REM_D = 22, OPC_FLOAT_REGREG_MADD_D = 23, OPC_FLOAT_REGREG_SFEQ_D = 24, OPC_FLOAT_REGREG_SFNE_D = 25
 , OPC_FLOAT_REGREG_SFGT_D = 26, OPC_FLOAT_REGREG_SFGE_D = 27, OPC_FLOAT_REGREG_SFLT_D = 28, OPC_FLOAT_REGREG_SFLE_D = 29
} INSN_OPCODE_FLOAT_REGREG;

/* Attributes.  */

/* Enum declaration for machine type selection.  */
typedef enum mach_attr {
  MACH_BASE, MACH_OR32, MACH_MAX
} MACH_ATTR;

/* Enum declaration for instruction set selection.  */
typedef enum isa_attr {
  ISA_ORBIS32, ISA_ORFPX32, ISA_MAX
} ISA_ATTR;

/* Number of architecture variants.  */
#define MAX_ISAS  ((int) ISA_MAX)
#define MAX_MACHS ((int) MACH_MAX)

/* Ifield support.  */

/* Ifield attribute indices.  */

/* Enum declaration for cgen_ifld attrs.  */
typedef enum cgen_ifld_attr {
  CGEN_IFLD_VIRTUAL, CGEN_IFLD_PCREL_ADDR, CGEN_IFLD_ABS_ADDR, CGEN_IFLD_RESERVED
 , CGEN_IFLD_SIGN_OPT, CGEN_IFLD_SIGNED, CGEN_IFLD_END_BOOLS, CGEN_IFLD_START_NBOOLS = 31
 , CGEN_IFLD_MACH, CGEN_IFLD_ISA, CGEN_IFLD_END_NBOOLS
} CGEN_IFLD_ATTR;

/* Number of non-boolean elements in cgen_ifld_attr.  */
#define CGEN_IFLD_NBOOL_ATTRS (CGEN_IFLD_END_NBOOLS - CGEN_IFLD_START_NBOOLS - 1)

/* cgen_ifld attribute accessor macros.  */
#define CGEN_ATTR_CGEN_IFLD_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_IFLD_MACH-CGEN_IFLD_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_IFLD_ISA_VALUE(attrs) ((attrs)->nonbool[CGEN_IFLD_ISA-CGEN_IFLD_START_NBOOLS-1].bitset)
#define CGEN_ATTR_CGEN_IFLD_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_IFLD_PCREL_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_PCREL_ADDR)) != 0)
#define CGEN_ATTR_CGEN_IFLD_ABS_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_ABS_ADDR)) != 0)
#define CGEN_ATTR_CGEN_IFLD_RESERVED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_RESERVED)) != 0)
#define CGEN_ATTR_CGEN_IFLD_SIGN_OPT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_SIGN_OPT)) != 0)
#define CGEN_ATTR_CGEN_IFLD_SIGNED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_IFLD_SIGNED)) != 0)

/* Enum declaration for or1k ifield types.  */
typedef enum ifield_type {
  OR1K_F_NIL, OR1K_F_ANYOF, OR1K_F_OPCODE, OR1K_F_R1
 , OR1K_F_R2, OR1K_F_R3, OR1K_F_OP_25_2, OR1K_F_OP_25_5
 , OR1K_F_OP_16_1, OR1K_F_OP_7_4, OR1K_F_OP_3_4, OR1K_F_OP_9_2
 , OR1K_F_OP_9_4, OR1K_F_OP_7_8, OR1K_F_OP_7_2, OR1K_F_RESV_25_26
 , OR1K_F_RESV_25_10, OR1K_F_RESV_23_8, OR1K_F_RESV_20_5, OR1K_F_RESV_20_4
 , OR1K_F_RESV_15_8, OR1K_F_RESV_15_6, OR1K_F_RESV_10_11, OR1K_F_RESV_10_7
 , OR1K_F_RESV_10_3, OR1K_F_RESV_5_2, OR1K_F_IMM16_25_5, OR1K_F_IMM16_10_11
 , OR1K_F_DISP26, OR1K_F_UIMM16, OR1K_F_SIMM16, OR1K_F_UIMM6
 , OR1K_F_UIMM16_SPLIT, OR1K_F_SIMM16_SPLIT, OR1K_F_MAX
} IFIELD_TYPE;

#define MAX_IFLD ((int) OR1K_F_MAX)

/* Hardware attribute indices.  */

/* Enum declaration for cgen_hw attrs.  */
typedef enum cgen_hw_attr {
  CGEN_HW_VIRTUAL, CGEN_HW_CACHE_ADDR, CGEN_HW_PC, CGEN_HW_PROFILE
 , CGEN_HW_END_BOOLS, CGEN_HW_START_NBOOLS = 31, CGEN_HW_MACH, CGEN_HW_ISA
 , CGEN_HW_END_NBOOLS
} CGEN_HW_ATTR;

/* Number of non-boolean elements in cgen_hw_attr.  */
#define CGEN_HW_NBOOL_ATTRS (CGEN_HW_END_NBOOLS - CGEN_HW_START_NBOOLS - 1)

/* cgen_hw attribute accessor macros.  */
#define CGEN_ATTR_CGEN_HW_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_HW_MACH-CGEN_HW_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_HW_ISA_VALUE(attrs) ((attrs)->nonbool[CGEN_HW_ISA-CGEN_HW_START_NBOOLS-1].bitset)
#define CGEN_ATTR_CGEN_HW_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_HW_CACHE_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_CACHE_ADDR)) != 0)
#define CGEN_ATTR_CGEN_HW_PC_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_PC)) != 0)
#define CGEN_ATTR_CGEN_HW_PROFILE_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_HW_PROFILE)) != 0)

/* Enum declaration for or1k hardware types.  */
typedef enum cgen_hw_type {
  HW_H_MEMORY, HW_H_SINT, HW_H_UINT, HW_H_ADDR
 , HW_H_IADDR, HW_H_PC, HW_H_GR, HW_H_SPR
 , HW_H_SYS_SR, HW_H_SYS_ESR0, HW_H_SYS_EPCR0, HW_H_MAC_MACLO
 , HW_H_MAC_MACHI, HW_H_SYS_SR_F, HW_H_SYS_SR_CY, HW_H_SYS_SR_OV
 , HW_H_SYS_FPCSR_RM, HW_H_DELAY_INSN, HW_H_SIMM16, HW_H_UIMM16
 , HW_H_UIMM6, HW_MAX
} CGEN_HW_TYPE;

#define MAX_HW ((int) HW_MAX)

/* Operand attribute indices.  */

/* Enum declaration for cgen_operand attrs.  */
typedef enum cgen_operand_attr {
  CGEN_OPERAND_VIRTUAL, CGEN_OPERAND_PCREL_ADDR, CGEN_OPERAND_ABS_ADDR, CGEN_OPERAND_SIGN_OPT
 , CGEN_OPERAND_SIGNED, CGEN_OPERAND_NEGATIVE, CGEN_OPERAND_RELAX, CGEN_OPERAND_SEM_ONLY
 , CGEN_OPERAND_END_BOOLS, CGEN_OPERAND_START_NBOOLS = 31, CGEN_OPERAND_MACH, CGEN_OPERAND_ISA
 , CGEN_OPERAND_END_NBOOLS
} CGEN_OPERAND_ATTR;

/* Number of non-boolean elements in cgen_operand_attr.  */
#define CGEN_OPERAND_NBOOL_ATTRS (CGEN_OPERAND_END_NBOOLS - CGEN_OPERAND_START_NBOOLS - 1)

/* cgen_operand attribute accessor macros.  */
#define CGEN_ATTR_CGEN_OPERAND_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_OPERAND_MACH-CGEN_OPERAND_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_OPERAND_ISA_VALUE(attrs) ((attrs)->nonbool[CGEN_OPERAND_ISA-CGEN_OPERAND_START_NBOOLS-1].bitset)
#define CGEN_ATTR_CGEN_OPERAND_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_PCREL_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_PCREL_ADDR)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_ABS_ADDR_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_ABS_ADDR)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_SIGN_OPT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_SIGN_OPT)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_SIGNED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_SIGNED)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_NEGATIVE_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_NEGATIVE)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_RELAX_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_RELAX)) != 0)
#define CGEN_ATTR_CGEN_OPERAND_SEM_ONLY_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_OPERAND_SEM_ONLY)) != 0)

/* Enum declaration for or1k operand types.  */
typedef enum cgen_operand_type {
  OR1K_OPERAND_PC, OR1K_OPERAND_SYS_SR, OR1K_OPERAND_SYS_ESR0, OR1K_OPERAND_SYS_EPCR0
 , OR1K_OPERAND_SYS_SR_F, OR1K_OPERAND_SYS_SR_CY, OR1K_OPERAND_SYS_SR_OV, OR1K_OPERAND_SYS_FPCSR_RM
 , OR1K_OPERAND_MAC_MACHI, OR1K_OPERAND_MAC_MACLO, OR1K_OPERAND_DISP26, OR1K_OPERAND_UIMM6
 , OR1K_OPERAND_RD, OR1K_OPERAND_RA, OR1K_OPERAND_RB, OR1K_OPERAND_SIMM16
 , OR1K_OPERAND_UIMM16, OR1K_OPERAND_SIMM16_SPLIT, OR1K_OPERAND_UIMM16_SPLIT, OR1K_OPERAND_RDSF
 , OR1K_OPERAND_RASF, OR1K_OPERAND_RBSF, OR1K_OPERAND_MAX
} CGEN_OPERAND_TYPE;

/* Number of operands types.  */
#define MAX_OPERANDS 22

/* Maximum number of operands referenced by any insn.  */
#define MAX_OPERAND_INSTANCES 8

/* Insn attribute indices.  */

/* Enum declaration for cgen_insn attrs.  */
typedef enum cgen_insn_attr {
  CGEN_INSN_ALIAS, CGEN_INSN_VIRTUAL, CGEN_INSN_UNCOND_CTI, CGEN_INSN_COND_CTI
 , CGEN_INSN_SKIP_CTI, CGEN_INSN_DELAY_SLOT, CGEN_INSN_RELAXABLE, CGEN_INSN_RELAXED
 , CGEN_INSN_NO_DIS, CGEN_INSN_PBB, CGEN_INSN_NOT_IN_DELAY_SLOT, CGEN_INSN_END_BOOLS
 , CGEN_INSN_START_NBOOLS = 31, CGEN_INSN_MACH, CGEN_INSN_ISA, CGEN_INSN_END_NBOOLS
} CGEN_INSN_ATTR;

/* Number of non-boolean elements in cgen_insn_attr.  */
#define CGEN_INSN_NBOOL_ATTRS (CGEN_INSN_END_NBOOLS - CGEN_INSN_START_NBOOLS - 1)

/* cgen_insn attribute accessor macros.  */
#define CGEN_ATTR_CGEN_INSN_MACH_VALUE(attrs) ((attrs)->nonbool[CGEN_INSN_MACH-CGEN_INSN_START_NBOOLS-1].nonbitset)
#define CGEN_ATTR_CGEN_INSN_ISA_VALUE(attrs) ((attrs)->nonbool[CGEN_INSN_ISA-CGEN_INSN_START_NBOOLS-1].bitset)
#define CGEN_ATTR_CGEN_INSN_ALIAS_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_ALIAS)) != 0)
#define CGEN_ATTR_CGEN_INSN_VIRTUAL_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_VIRTUAL)) != 0)
#define CGEN_ATTR_CGEN_INSN_UNCOND_CTI_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_UNCOND_CTI)) != 0)
#define CGEN_ATTR_CGEN_INSN_COND_CTI_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_COND_CTI)) != 0)
#define CGEN_ATTR_CGEN_INSN_SKIP_CTI_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_SKIP_CTI)) != 0)
#define CGEN_ATTR_CGEN_INSN_DELAY_SLOT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_DELAY_SLOT)) != 0)
#define CGEN_ATTR_CGEN_INSN_RELAXABLE_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_RELAXABLE)) != 0)
#define CGEN_ATTR_CGEN_INSN_RELAXED_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_RELAXED)) != 0)
#define CGEN_ATTR_CGEN_INSN_NO_DIS_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_NO_DIS)) != 0)
#define CGEN_ATTR_CGEN_INSN_PBB_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_PBB)) != 0)
#define CGEN_ATTR_CGEN_INSN_NOT_IN_DELAY_SLOT_VALUE(attrs) (((attrs)->bool_ & (1 << CGEN_INSN_NOT_IN_DELAY_SLOT)) != 0)

/* cgen.h uses things we just defined.  */
#include "opcode/cgen.h"

extern const struct cgen_ifld or1k_cgen_ifld_table[];

/* Attributes.  */
extern const CGEN_ATTR_TABLE or1k_cgen_hardware_attr_table[];
extern const CGEN_ATTR_TABLE or1k_cgen_ifield_attr_table[];
extern const CGEN_ATTR_TABLE or1k_cgen_operand_attr_table[];
extern const CGEN_ATTR_TABLE or1k_cgen_insn_attr_table[];

/* Hardware decls.  */

extern CGEN_KEYWORD or1k_cgen_opval_h_gr;

extern const CGEN_HW_ENTRY or1k_cgen_hw_table[];



#endif /* OR1K_CPU_H */
