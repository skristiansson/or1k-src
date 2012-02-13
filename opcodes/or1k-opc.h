/* Instruction opcode header for or1k.

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

#ifndef OR1K_OPC_H
#define OR1K_OPC_H

/* -- opc.h */
#undef  CGEN_DIS_HASH_SIZE
#define CGEN_DIS_HASH_SIZE 64
#undef  CGEN_DIS_HASH
#define CGEN_DIS_HASH(buffer, value) (((unsigned char *) (buffer))[0] >> 2)

extern long or1k_sign_extend_16bit (long);
/* -- */
/* Enum declaration for or1k instruction types.  */
typedef enum cgen_insn_type {
  OR1K_INSN_INVALID, OR1K_INSN_L_J, OR1K_INSN_L_JAL, OR1K_INSN_L_JR
 , OR1K_INSN_L_JALR, OR1K_INSN_L_BNF, OR1K_INSN_L_BF, OR1K_INSN_L_TRAP
 , OR1K_INSN_L_SYS, OR1K_INSN_L_RFE, OR1K_INSN_L_NOP_IMM, OR1K_INSN_L_NOP
 , OR1K_INSN_L_MOVHI, OR1K_INSN_L_MFSPR, OR1K_INSN_L_MTSPR, OR1K_INSN_L_LWZ
 , OR1K_INSN_L_LWS, OR1K_INSN_L_LBZ, OR1K_INSN_L_LBS, OR1K_INSN_L_LHZ
 , OR1K_INSN_L_LHS, OR1K_INSN_L_SW, OR1K_INSN_L_SB, OR1K_INSN_L_SH
 , OR1K_INSN_L_SLL, OR1K_INSN_L_SLLI, OR1K_INSN_L_SRL, OR1K_INSN_L_SRLI
 , OR1K_INSN_L_SRA, OR1K_INSN_L_SRAI, OR1K_INSN_L_ROR, OR1K_INSN_L_RORI
 , OR1K_INSN_L_ADD, OR1K_INSN_L_SUB, OR1K_INSN_L_AND, OR1K_INSN_L_OR
 , OR1K_INSN_L_XOR, OR1K_INSN_L_ADDC, OR1K_INSN_L_MUL, OR1K_INSN_L_MULU
 , OR1K_INSN_L_DIV, OR1K_INSN_L_DIVU, OR1K_INSN_L_FF1, OR1K_INSN_L_FL1
 , OR1K_INSN_L_ADDI, OR1K_INSN_L_ANDI, OR1K_INSN_L_ORI, OR1K_INSN_L_XORI
 , OR1K_INSN_L_MULI, OR1K_INSN_L_ADDIC, OR1K_INSN_L_SFGTU, OR1K_INSN_L_SFGEU
 , OR1K_INSN_L_SFLTU, OR1K_INSN_L_SFLEU, OR1K_INSN_L_SFGTS, OR1K_INSN_L_SFGES
 , OR1K_INSN_L_SFLTS, OR1K_INSN_L_SFLES, OR1K_INSN_L_SFGTUI, OR1K_INSN_L_SFGEUI
 , OR1K_INSN_L_SFLTUI, OR1K_INSN_L_SFLEUI, OR1K_INSN_L_SFGTSI, OR1K_INSN_L_SFGESI
 , OR1K_INSN_L_SFLTSI, OR1K_INSN_L_SFLESI, OR1K_INSN_L_SFEQ, OR1K_INSN_L_SFEQI
 , OR1K_INSN_L_SFNE, OR1K_INSN_L_SFNEI
} CGEN_INSN_TYPE;

/* Index of `invalid' insn place holder.  */
#define CGEN_INSN_INVALID OR1K_INSN_INVALID

/* Total number of insns in table.  */
#define MAX_INSNS ((int) OR1K_INSN_L_SFNEI + 1)

/* This struct records data prior to insertion or after extraction.  */
struct cgen_fields
{
  int length;
  long f_nil;
  long f_anyof;
  long f_opcode;
  long f_r1;
  long f_r2;
  long f_r3;
  long f_simm16;
  long f_uimm16;
  long f_uimm5;
  long f_uimm6;
  long f_hi16;
  long f_lo16;
  long f_op_25_2;
  long f_op_25_5;
  long f_op_16_1;
  long f_op_7_4;
  long f_op_3_4;
  long f_op_9_2;
  long f_op_7_2;
  long f_resv_25_26;
  long f_resv_25_10;
  long f_resv_23_8;
  long f_resv_20_5;
  long f_resv_20_4;
  long f_resv_15_8;
  long f_resv_10_11;
  long f_resv_10_7;
  long f_resv_10_3;
  long f_resv_5_2;
  long f_i16_1;
  long f_i16_2;
  long f_disp26;
  long f_i16nc;
};

#define CGEN_INIT_PARSE(od) \
{\
}
#define CGEN_INIT_INSERT(od) \
{\
}
#define CGEN_INIT_EXTRACT(od) \
{\
}
#define CGEN_INIT_PRINT(od) \
{\
}


#endif /* OR1K_OPC_H */
