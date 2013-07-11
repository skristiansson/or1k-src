/* crt0.S. C design runtime startup file.

   Copyright (C) 2004, Jacob Bower
   Copyright (C) 2010, Embecosm Limited <info@embecosm.com>
   Copyright (C) 2011, ORSoC AB

   Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>
   Contributor Julius Baxter  <julius.baxter@orsoc.se>

   This file is part of Newlib.

   The original work by Jacob Bower is provided as-is without any kind of
   warranty. Use it at your own risk!

   All subsequent work is bound by version 3 of the GPL as follows.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3 of the License, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along
   with this program.  If not, see <http://www.gnu.org/licenses/>.            */
/* -------------------------------------------------------------------------- */
/* This program is commented throughout in a fashion suitable for processing
   with Doxygen.                                                              */
/* -------------------------------------------------------------------------- */

#include "or1k-asm.h"
#include "spr-defs.h"

/* -------------------------------------------------------------------------- */
/*!Macro to load a symbol's address into a register.         
  
  @param[in] gpr  General purpose register to load address into.       
  @param[in] symbol Name of symbol to load.                                   */
/* -------------------------------------------------------------------------- */
#define LOAD_SYMBOL_2_GPR(gpr,symbol)  \
	.global symbol ;               \
	l.movhi gpr, hi(symbol) ;      \
	l.ori   gpr, gpr, lo(symbol)

/* -------------------------------------------------------------------------- */
/*!Macro to handle exceptions.                               

  Load NPC into r3, EPCR into r4
                                                                              */
/* -------------------------------------------------------------------------- */
// Size of redzone + size of space required to store state
// This value must match that in the support library or1k_exception_handler
// function
#define EXCEPTION_STACK_SIZE (128+128)
	
#define CALL_EXCEPTION_HANDLER            		\
	l.addi  r1, r1, -EXCEPTION_STACK_SIZE;          \
	l.sw    4(r1), r3;             			\
	l.sw    8(r1), r4;             			\
	l.mfspr r3,r0,SPR_NPC;          		\
        OR1K_DELAYED(					\
	OR1K_INST(l.mfspr r4,r0,SPR_EPCR_BASE),		\
	OR1K_INST(l.j 	or1k_exception_handler)		\
        )

/* -------------------------------------------------------------------------- */
/*!Exception vectors                                                          */
/* -------------------------------------------------------------------------- */
	.section .vectors,"ax"

	/* 0x100: RESET exception */
        .org	0x100 	
__reset:
	l.movhi r0, 0
	l.movhi r1, 0
	l.movhi r2, 0
	l.movhi r3, 0
	l.movhi r4, 0
	l.movhi r5, 0
	l.movhi r6, 0
	l.movhi r7, 0
	l.movhi r8, 0
	l.movhi r9, 0
	l.movhi r10, 0
	l.movhi r11, 0
	l.movhi r12, 0
	l.movhi r13, 0
	l.movhi r14, 0
	l.movhi r15, 0
	l.movhi r16, 0
	l.movhi r17, 0
	l.movhi r18, 0
	l.movhi r19, 0
	l.movhi r20, 0
	l.movhi r21, 0
	l.movhi r22, 0
	l.movhi r23, 0
	l.movhi r24, 0
	l.movhi r25, 0
	l.movhi r26, 0
	l.movhi r27, 0
	l.movhi r28, 0
	l.movhi r29, 0
	l.movhi r30, 0
	l.movhi r31, 0

	/* Clear status register, set supervisor mode */
	l.ori r1, r0, SPR_SR_SM
	l.mtspr r0, r1, SPR_SR
	/* Clear timer mode register*/
	l.mtspr r0, r0, SPR_TTMR
	/* Jump to program initialisation code */
	LOAD_SYMBOL_2_GPR(r4, _start)
	OR1K_DELAYED_NOP(OR1K_INST(l.jr    r4))

	.org	0x200
	CALL_EXCEPTION_HANDLER

	/* 0x300: Data Page Fault exception */
	.org	0x300
	CALL_EXCEPTION_HANDLER
	
	/* 0x400: Insn Page Fault exception */
	.org	0x400
	CALL_EXCEPTION_HANDLER

	/* 0x500: Timer exception */
	.org	0x500
	CALL_EXCEPTION_HANDLER

	/* 0x600: Aligment exception */
	.org	0x600
	CALL_EXCEPTION_HANDLER
	
	/* 0x700: Illegal insn exception */
	.org	0x700
	CALL_EXCEPTION_HANDLER

	/* 0x800: External interrupt exception */
	.org	0x800
	CALL_EXCEPTION_HANDLER

	/* 0x900: DTLB miss exception */
	.org	0x900
	CALL_EXCEPTION_HANDLER
	
	/* 0xa00: ITLB miss exception */
	.org	0xa00
	CALL_EXCEPTION_HANDLER
	
	/* 0xb00: Range exception */
	.org	0xb00
	CALL_EXCEPTION_HANDLER
	
	/* 0xc00: Syscall exception */
	.org	0xc00
	CALL_EXCEPTION_HANDLER
	
	/* 0xd00: floating point exception */
	.org	0xd00
	CALL_EXCEPTION_HANDLER
	
	/* 0xe00: Trap exception */
	.org	0xe00
	CALL_EXCEPTION_HANDLER
	
	/* 0xf00: Reserved exceptions */
	.org	0xf00
	CALL_EXCEPTION_HANDLER
	
	.org	0x1000
	CALL_EXCEPTION_HANDLER
	
	.org	0x1100
	CALL_EXCEPTION_HANDLER
	
	.org	0x1200
	CALL_EXCEPTION_HANDLER
	
	.org	0x1300
	CALL_EXCEPTION_HANDLER
	
	.org	0x1400
	CALL_EXCEPTION_HANDLER
	
	.org	0x1500
	CALL_EXCEPTION_HANDLER
	
	.org	0x1600
	CALL_EXCEPTION_HANDLER
	
	.org	0x1700
	CALL_EXCEPTION_HANDLER
	
	.org	0x1800
	CALL_EXCEPTION_HANDLER
	
	.org	0x1900
	CALL_EXCEPTION_HANDLER
	
	.org	0x1a00
	CALL_EXCEPTION_HANDLER
	
	.org	0x1b00
	CALL_EXCEPTION_HANDLER
	
	.org	0x1c00
	CALL_EXCEPTION_HANDLER
	
	.org	0x1d00
	CALL_EXCEPTION_HANDLER
	
	.org	0x1e00
	CALL_EXCEPTION_HANDLER
	
	.org	0x1f00
	CALL_EXCEPTION_HANDLER

	/* Pad to the end */
	.org	0x1ffc
	l.nop

/* -------------------------------------------------------------------------- */
/*!Main entry point
  
   We initialise the stack and frame pointer first, before we set up the
   caches, since otherwise we'll need to disable the instruction cache when
   patching the bus error vector code.

   The remaining tasks are then:
   - optionally set up instruction and/or data caches
   - clear BSS
   - call global and static constructors
   - set up destructors to be called from exit
   - jump to the main function
   - call exit if the main function ever returns.
   - loop forever (should never get here)                                     */
/* -------------------------------------------------------------------------- */
	/* The stack grows down from the top of writable memory. */
	.section .data
	.global stack
stack:	.space	4,0	

	.section .text
	.global	_start
        .type	_start,@function


	/* Following externs from board-specific object passed at link time */
	.extern _board_mem_base
	.extern _board_mem_size
	.extern _board_uart_base
	
_start:
	/* Initialise stack and frame pointer (set to same value) */
	l.movhi	r1,hi(_board_mem_base)
	l.ori	r1,r1,lo(_board_mem_base)
	l.lwz	r1,0(r1)
	l.movhi	r2,hi(_board_mem_size)
	l.ori	r2,r2,lo(_board_mem_size)
	l.lwz	r2,0(r2)
	l.add	r1,r1,r2
	l.or	r2,r1,r1

	/* Store stack address in stack variable */
	l.movhi	r3,hi(stack)
	l.ori	r3,r3,lo(stack)
	l.sw	0(r3),r1
	
	/* Initialise cache */
	/* TODO - potentially make this optional for simulation targets to save
	time during startup */
	OR1K_DELAYED_NOP(OR1K_INST(l.jal 	or1k_cache_init))
	
	/* Clear BSS */
.L10:	l.movhi r3,hi(__bss_start)
	l.ori   r3,r3,lo(__bss_start)
	l.movhi r4,hi(end)
	l.ori   r4,r4,lo(end)

.L1:    l.sw    (0)(r3),r0
        l.sfltu r3,r4
        OR1K_DELAYED(
        OR1K_INST(l.addi  r3,r3,4),
        OR1K_INST(l.bf    .L1)
        )

	/* Reinitialize the reentrancy structure */
	OR1K_DELAYED_NOP(OR1K_INST(l.jal	__impure_init))

	/* Call global and static constructors */
	OR1K_DELAYED_NOP(OR1K_INST(l.jal	_init))
	
	/* Set up destructors to be called from exit if main ever returns */
	l.movhi	r3,hi(_fini)
        OR1K_DELAYED(
	OR1K_INST(l.ori	r3,r3,lo(_fini)),
	OR1K_INST(l.jal	atexit)
        )

	/* Check if UART is to be initialised */
	l.movhi	r4,hi(_board_uart_base)
	l.ori	r4,r4,lo(_board_uart_base)
	l.lwz	r4,0(r4)
	l.sfne	r4,r0		/* Is base set? If not, no UART */
	l.bnf	.L2
	l.or	r3,r0,r0
	OR1K_DELAYED_NOP(OR1K_INST(l.jal	__uart_init))

.L2:	
	/* Jump to main program entry point (argc = argv = envp = 0) */
	l.or	r3,r0,r0
	l.or	r4,r0,r0
        OR1K_DELAYED(
	OR1K_INST(l.or	r5,r0,r0),
	OR1K_INST(l.jal   main)
        )

	/* If program exits, call exit routine */
        OR1K_DELAYED(
	OR1K_INST(l.addi  r3,r11,0),
	OR1K_INST(l.jal   exit)
        )

	/* Loop forever */
.L3:	OR1K_DELAYED_NOP(OR1K_INST(l.j	.L3))
	
	.size	_start, .-_start
