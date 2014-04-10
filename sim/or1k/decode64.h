/* Decode header for or1k64bf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright 1996-2010 Free Software Foundation, Inc.

This file is part of the GNU simulators.

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

#ifndef OR1K64BF_DECODE_H
#define OR1K64BF_DECODE_H

extern const IDESC *or1k64bf_decode (SIM_CPU *, IADDR,
                                  CGEN_INSN_WORD, CGEN_INSN_WORD,
                                  ARGBUF *);
extern void or1k64bf_init_idesc_table (SIM_CPU *);
extern void or1k64bf_sem_init_idesc_table (SIM_CPU *);
extern void or1k64bf_semf_init_idesc_table (SIM_CPU *);

/* Enum declaration for instructions in cpu family or1k64bf.  */
typedef enum or1k64bf_insn_type {
  OR1K64BF_INSN_X_INVALID, OR1K64BF_INSN_X_AFTER, OR1K64BF_INSN_X_BEFORE, OR1K64BF_INSN_X_CTI_CHAIN
 , OR1K64BF_INSN_X_CHAIN, OR1K64BF_INSN_X_BEGIN, OR1K64BF_INSN_L_J, OR1K64BF_INSN_L_JAL
 , OR1K64BF_INSN_L_JR, OR1K64BF_INSN_L_JALR, OR1K64BF_INSN_L_BNF, OR1K64BF_INSN_L_BF
 , OR1K64BF_INSN_L_TRAP, OR1K64BF_INSN_L_SYS, OR1K64BF_INSN_L_RFE, OR1K64BF_INSN_L_NOP_IMM
 , OR1K64BF_INSN_L_MOVHI, OR1K64BF_INSN_L_MACRC, OR1K64BF_INSN_L_MFSPR, OR1K64BF_INSN_L_MTSPR
 , OR1K64BF_INSN_L_LWZ, OR1K64BF_INSN_L_LWS, OR1K64BF_INSN_L_LWA, OR1K64BF_INSN_L_LBZ
 , OR1K64BF_INSN_L_LBS, OR1K64BF_INSN_L_LHZ, OR1K64BF_INSN_L_LHS, OR1K64BF_INSN_L_SW
 , OR1K64BF_INSN_L_SB, OR1K64BF_INSN_L_SH, OR1K64BF_INSN_L_SWA, OR1K64BF_INSN_L_SLL
 , OR1K64BF_INSN_L_SLLI, OR1K64BF_INSN_L_SRL, OR1K64BF_INSN_L_SRLI, OR1K64BF_INSN_L_SRA
 , OR1K64BF_INSN_L_SRAI, OR1K64BF_INSN_L_ROR, OR1K64BF_INSN_L_RORI, OR1K64BF_INSN_L_AND
 , OR1K64BF_INSN_L_OR, OR1K64BF_INSN_L_XOR, OR1K64BF_INSN_L_ADD, OR1K64BF_INSN_L_SUB
 , OR1K64BF_INSN_L_ADDC, OR1K64BF_INSN_L_MUL, OR1K64BF_INSN_L_MULU, OR1K64BF_INSN_L_DIV
 , OR1K64BF_INSN_L_DIVU, OR1K64BF_INSN_L_FF1, OR1K64BF_INSN_L_FL1, OR1K64BF_INSN_L_ANDI
 , OR1K64BF_INSN_L_ORI, OR1K64BF_INSN_L_XORI, OR1K64BF_INSN_L_ADDI, OR1K64BF_INSN_L_ADDIC
 , OR1K64BF_INSN_L_MULI, OR1K64BF_INSN_L_EXTHS, OR1K64BF_INSN_L_EXTBS, OR1K64BF_INSN_L_EXTHZ
 , OR1K64BF_INSN_L_EXTBZ, OR1K64BF_INSN_L_EXTWS, OR1K64BF_INSN_L_EXTWZ, OR1K64BF_INSN_L_CMOV
 , OR1K64BF_INSN_L_SFGTS, OR1K64BF_INSN_L_SFGTSI, OR1K64BF_INSN_L_SFGTU, OR1K64BF_INSN_L_SFGTUI
 , OR1K64BF_INSN_L_SFGES, OR1K64BF_INSN_L_SFGESI, OR1K64BF_INSN_L_SFGEU, OR1K64BF_INSN_L_SFGEUI
 , OR1K64BF_INSN_L_SFLTS, OR1K64BF_INSN_L_SFLTSI, OR1K64BF_INSN_L_SFLTU, OR1K64BF_INSN_L_SFLTUI
 , OR1K64BF_INSN_L_SFLES, OR1K64BF_INSN_L_SFLESI, OR1K64BF_INSN_L_SFLEU, OR1K64BF_INSN_L_SFLEUI
 , OR1K64BF_INSN_L_SFEQ, OR1K64BF_INSN_L_SFEQI, OR1K64BF_INSN_L_SFNE, OR1K64BF_INSN_L_SFNEI
 , OR1K64BF_INSN_L_MAC, OR1K64BF_INSN_L_MSB, OR1K64BF_INSN_L_MACI, OR1K64BF_INSN_L_CUST1
 , OR1K64BF_INSN_L_CUST2, OR1K64BF_INSN_L_CUST3, OR1K64BF_INSN_L_CUST4, OR1K64BF_INSN_L_CUST5
 , OR1K64BF_INSN_L_CUST6, OR1K64BF_INSN_L_CUST7, OR1K64BF_INSN_L_CUST8, OR1K64BF_INSN_LF_ADD_S
 , OR1K64BF_INSN_LF_ADD_D, OR1K64BF_INSN_LF_SUB_S, OR1K64BF_INSN_LF_SUB_D, OR1K64BF_INSN_LF_MUL_S
 , OR1K64BF_INSN_LF_MUL_D, OR1K64BF_INSN_LF_DIV_S, OR1K64BF_INSN_LF_DIV_D, OR1K64BF_INSN_LF_REM_S
 , OR1K64BF_INSN_LF_REM_D, OR1K64BF_INSN_LF_ITOF_S, OR1K64BF_INSN_LF_ITOF_D, OR1K64BF_INSN_LF_FTOI_S
 , OR1K64BF_INSN_LF_FTOI_D, OR1K64BF_INSN_LF_EQ_S, OR1K64BF_INSN_LF_EQ_D, OR1K64BF_INSN_LF_NE_S
 , OR1K64BF_INSN_LF_NE_D, OR1K64BF_INSN_LF_GE_S, OR1K64BF_INSN_LF_GE_D, OR1K64BF_INSN_LF_GT_S
 , OR1K64BF_INSN_LF_GT_D, OR1K64BF_INSN_LF_LT_S, OR1K64BF_INSN_LF_LT_D, OR1K64BF_INSN_LF_LE_S
 , OR1K64BF_INSN_LF_LE_D, OR1K64BF_INSN_LF_MADD_S, OR1K64BF_INSN_LF_MADD_D, OR1K64BF_INSN_LF_CUST1_S
 , OR1K64BF_INSN_LF_CUST1_D, OR1K64BF_INSN__MAX
} OR1K64BF_INSN_TYPE;

/* Enum declaration for semantic formats in cpu family or1k64bf.  */
typedef enum or1k64bf_sfmt_type {
  OR1K64BF_SFMT_EMPTY, OR1K64BF_SFMT_L_J, OR1K64BF_SFMT_L_JAL, OR1K64BF_SFMT_L_JR
 , OR1K64BF_SFMT_L_JALR, OR1K64BF_SFMT_L_BNF, OR1K64BF_SFMT_L_TRAP, OR1K64BF_SFMT_L_RFE
 , OR1K64BF_SFMT_L_NOP_IMM, OR1K64BF_SFMT_L_MOVHI, OR1K64BF_SFMT_L_MACRC, OR1K64BF_SFMT_L_MFSPR
 , OR1K64BF_SFMT_L_MTSPR, OR1K64BF_SFMT_L_LWZ, OR1K64BF_SFMT_L_LWS, OR1K64BF_SFMT_L_LWA
 , OR1K64BF_SFMT_L_LBZ, OR1K64BF_SFMT_L_LBS, OR1K64BF_SFMT_L_LHZ, OR1K64BF_SFMT_L_LHS
 , OR1K64BF_SFMT_L_SW, OR1K64BF_SFMT_L_SB, OR1K64BF_SFMT_L_SH, OR1K64BF_SFMT_L_SWA
 , OR1K64BF_SFMT_L_SLL, OR1K64BF_SFMT_L_SLLI, OR1K64BF_SFMT_L_AND, OR1K64BF_SFMT_L_ADD
 , OR1K64BF_SFMT_L_ADDC, OR1K64BF_SFMT_L_DIV, OR1K64BF_SFMT_L_FF1, OR1K64BF_SFMT_L_XORI
 , OR1K64BF_SFMT_L_ADDI, OR1K64BF_SFMT_L_ADDIC, OR1K64BF_SFMT_L_EXTHS, OR1K64BF_SFMT_L_CMOV
 , OR1K64BF_SFMT_L_SFGTS, OR1K64BF_SFMT_L_SFGTSI, OR1K64BF_SFMT_L_MAC, OR1K64BF_SFMT_L_MACI
 , OR1K64BF_SFMT_LF_ADD_S, OR1K64BF_SFMT_LF_ADD_D, OR1K64BF_SFMT_LF_ITOF_S, OR1K64BF_SFMT_LF_ITOF_D
 , OR1K64BF_SFMT_LF_FTOI_S, OR1K64BF_SFMT_LF_FTOI_D, OR1K64BF_SFMT_LF_EQ_S, OR1K64BF_SFMT_LF_EQ_D
 , OR1K64BF_SFMT_LF_MADD_S, OR1K64BF_SFMT_LF_MADD_D
} OR1K64BF_SFMT_TYPE;

/* Function unit handlers (user written).  */


/* Profiling before/after handlers (user written) */

extern void or1k64bf_model_insn_before (SIM_CPU *, int /*first_p*/);
extern void or1k64bf_model_insn_after (SIM_CPU *, int /*last_p*/, int /*cycles*/);

#endif /* OR1K64BF_DECODE_H */
