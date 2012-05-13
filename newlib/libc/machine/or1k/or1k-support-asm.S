/* or1k-support - OR1K CPU support functions
  
   Copyright (C) 2011, ORSoC AB
  
   Contributor Julius Baxter  <julius.baxter@orsoc.se>
  
   This file is part of Newlib.
  
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

#include "or1k-asm.h"
#include "spr-defs.h"

/* -------------------------------------------------------------------------- */
/*!Function to control MMU
                                                                              */
/* -------------------------------------------------------------------------- */

/* MMU control functions always switch MMU control with a l.rfe to return
   from function */
	.section .text
	
	.global or1k_dmmu_enable
or1k_dmmu_enable:
        l.mfspr r3,r0,SPR_SR
        l.ori   r3,r3,SPR_SR_DME
        l.mtspr r0,r3,SPR_ESR_BASE
        l.mtspr r0,r9,SPR_EPCR_BASE
        l.rfe


	.global or1k_dmmu_disable
or1k_dmmu_disable:
	l.ori   r3,r0,SPR_SR_DME
	l.xori	r4,r3,0xffff
        l.mfspr r3,r0,SPR_SR
	l.and	r3,r4,r3
        l.mtspr r0,r3,SPR_ESR_BASE
        l.mtspr r0,r9,SPR_EPCR_BASE
        l.rfe


	.global or1k_immu_enable
or1k_immu_enable:
        l.mfspr r3,r0,SPR_SR
        l.ori   r3,r3,SPR_SR_IME
        l.mtspr r0,r3,SPR_ESR_BASE
        l.mtspr r0,r9,SPR_EPCR_BASE
        l.rfe

	.global or1k_immu_disable
or1k_immu_disable:
	l.ori   r3,r0,SPR_SR_IME
	l.xori	r4,r3,0xffff
        l.mfspr r3,r0,SPR_SR
	l.and	r3,r4,r3
        l.mtspr r0,r3,SPR_ESR_BASE
        l.mtspr r0,r9,SPR_EPCR_BASE
        l.rfe




/* -------------------------------------------------------------------------- */
/*!Function used at reset to clear and enable all caches
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_cache_init
        .type	or1k_cache_init,@function

or1k_cache_init:
	/* Instruction cache enable */
	/* Check if IC present and skip enabling otherwise */
.L6:	l.mfspr r3,r0,SPR_UPR
	l.andi  r4,r3,SPR_UPR_ICP
	l.sfeq  r4,r0
	OR1K_DELAYED_NOP(OR1K_INST(l.bf    .L8))
	
	/* Disable IC */
	l.mfspr r6,r0,SPR_SR
	l.addi  r5,r0,-1
	l.xori  r5,r5,SPR_SR_ICE
	l.and   r5,r6,r5
	l.mtspr r0,r5,SPR_SR
	
	/* Establish cache block size
	If BS=0, 16;
	If BS=1, 32;
	r14 contain block size
	*/
	l.mfspr r3,r0,SPR_ICCFGR
	l.andi  r4,r3,SPR_ICCFGR_CBS
	l.srli  r7,r4,7
	l.ori   r8,r0,16
	l.sll   r14,r8,r7
	
	/* Establish number of cache sets
	r13 contains number of cache sets
	r7 contains log(# of cache sets)
	*/
	l.andi  r4,r3,SPR_ICCFGR_NCS
	l.srli  r7,r4,3
	l.ori   r8,r0,1
	l.sll   r13,r8,r7
	
	/* Invalidate IC */
	l.addi  r6,r0,0
	l.sll   r5,r14,r7
	
.L7:	l.mtspr r0,r6,SPR_ICBIR
	l.sfne  r6,r5
        OR1K_DELAYED(
	OR1K_INST(l.add   r6,r6,r14),
	OR1K_INST(l.bf    .L7)
        )
	
	/* Enable IC */
	l.mfspr r6,r0,SPR_SR
	l.ori   r6,r6,SPR_SR_ICE
	l.mtspr r0,r6,SPR_SR
	l.nop
	l.nop
	l.nop
	l.nop
	l.nop
	l.nop
	l.nop
	l.nop

	/* Data cache enable */
        /* Check if DC present and skip enabling otherwise */
.L8:    l.mfspr r3,r0,SPR_UPR
        l.andi  r4,r3,SPR_UPR_DCP
        l.sfeq  r4,r0
        OR1K_DELAYED_NOP(OR1K_INST(l.bf    .L10))
        /* Disable DC */
        l.mfspr r6,r0,SPR_SR
        l.addi  r5,r0,-1
        l.xori  r5,r5,SPR_SR_DCE
	l.and   r5,r6,r5
        l.mtspr r0,r5,SPR_SR
        /* Establish cache block size
           If BS=0, 16;
           If BS=1, 32;
           r14 contain block size
        */
        l.mfspr r3,r0,SPR_DCCFGR
        l.andi  r4,r3,SPR_DCCFGR_CBS
        l.srli  r7,r4,7
        l.ori   r8,r0,16
        l.sll   r14,r8,r7
        /* Establish number of cache sets
           r13 contains number of cache sets
           r7 contains log(# of cache sets)
        */
	l.andi  r4,r3,SPR_DCCFGR_NCS
	l.srli  r7,r4,3
        l.ori   r8,r0,1
        l.sll   r13,r8,r7
        /* Invalidate DC */
        l.addi  r6,r0,0
        l.sll   r5,r14,r7

.L9:    l.mtspr r0,r6,SPR_DCBIR
        l.sfne  r6,r5
	OR1K_DELAYED(
	OR1K_INST(l.add   r6,r6,r14),
        OR1K_INST(l.bf    .L9)
        )
        /* Enable DC */
        l.mfspr r6,r0,SPR_SR
        l.ori   r6,r6,SPR_SR_DCE
        l.mtspr r0,r6,SPR_SR

.L10:	
	/* Return */
	OR1K_DELAYED_NOP(OR1K_INST(l.jr	r9))

/* -------------------------------------------------------------------------- */
/*!Function to enable instruction cache
                                                                              */
/* -------------------------------------------------------------------------- */
	
	.global	or1k_icache_enable
        .type	or1k_icache_enable,@function

or1k_icache_enable:
	/* Enable IC */
	l.mfspr r13,r0,SPR_SR
	l.ori  	r13,r13,SPR_SR_ICE
	l.mtspr r0,r13,SPR_SR
	l.nop
	l.nop
	l.nop
	l.nop
	l.nop
	OR1K_DELAYED_NOP(OR1K_INST(l.jr	r9))

/* -------------------------------------------------------------------------- */
/*!Function to disable instruction cache
                                                                              */
/* -------------------------------------------------------------------------- */	
	.global	or1k_icache_disable
        .type	or1k_icache_disable,@function

or1k_icache_disable:
	/* Disable IC */
	l.mfspr r13,r0,SPR_SR
	l.addi  r12,r0,-1
	l.xori  r12,r12,SPR_SR_ICE
	l.and   r12,r13,r12
	l.mtspr r0,r12,SPR_SR
	OR1K_DELAYED_NOP(OR1K_INST(l.jr	r9))

/* -------------------------------------------------------------------------- */
/*!Function to flush address of instruction cache
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_icache_flush
        .type	or1k_icache_flush,@function

or1k_icache_flush:
        OR1K_DELAYED(
	OR1K_INST(l.mtspr r0,r3,SPR_ICBIR),
	/* Push r3 into IC invalidate reg */
	OR1K_INST(l.jr	r9)
        )
	

/* -------------------------------------------------------------------------- */
/*!Function to enable data cache
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_dcache_enable
        .type	or1k_dcache_enable,@function

or1k_dcache_enable:
	/* Enable DC */
	l.mfspr r13,r0,SPR_SR
	l.ori  	r13,r13,SPR_SR_DCE
	l.mtspr r0,r13,SPR_SR
	l.nop
	l.nop
	l.nop
	l.nop
	l.nop
        OR1K_DELAYED_NOP(OR1K_INST(l.jr	r9))

/* -------------------------------------------------------------------------- */
/*!Function to disable data cache
                                                                              */
/* -------------------------------------------------------------------------- */	
	.global	or1k_dcache_disable
        .type	or1k_dcache_disable,@function

or1k_dcache_disable:
	/* Disable DC */
	l.mfspr r13,r0,SPR_SR
	l.addi  r12,r0,-1
	l.xori  r12,r12,SPR_SR_DCE
	l.and   r12,r13,r12
	l.mtspr r0,r12,SPR_SR
        OR1K_DELAYED_NOP(OR1K_INST(l.jr	r9))

/* -------------------------------------------------------------------------- */
/*!Function to flush address of data cache
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_dcache_flush
        .type	or1k_dcache_flush,@function

or1k_dcache_flush:
        OR1K_DELAYED(
	OR1K_INST(l.mtspr r0,r3,SPR_DCBIR),
	/* Push r3 into DC invalidate reg */
	OR1K_INST(l.jr	r9)
        )
	



/* -------------------------------------------------------------------------- */
/*!Generic interrupt handler function for or1k
                                                                              */
/* -------------------------------------------------------------------------- */

#define INTERRUPT_HANDLER_NOT_SET -1
	
	.data
	.align 4
	.global or1k_interrupt_handler_table
or1k_interrupt_handler_table:	
or1k_interrupt_handler0:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler1:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler2:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler3:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler4:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler5:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler6:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler7:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler8:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler9:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler10:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler11:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler12:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler13:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler14:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler15:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler16:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler17:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler18:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler19:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler20:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler21:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler22:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler23:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler24:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler25:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler26:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler27:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler28:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler29:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler30:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler31:	.long	INTERRUPT_HANDLER_NOT_SET	

	.global or1k_interrupt_handler_data_ptr_table
or1k_interrupt_handler_data_ptr_table:	
or1k_interrupt_handler_data_ptr0:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr1:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr2:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr3:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr4:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr5:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr6:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr7:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr8:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr9:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr10:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr11:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr12:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr13:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr14:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr15:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr16:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr17:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr18:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr19:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr20:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr21:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr22:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr23:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr24:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr25:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr26:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr27:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr28:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr29:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr30:	.long	INTERRUPT_HANDLER_NOT_SET
or1k_interrupt_handler_data_ptr31:	.long	INTERRUPT_HANDLER_NOT_SET	
	
	
/* -------------------------------------------------------------------------- */
/*!Function to call appropriate interrupt handler            
                                                                              */
/* -------------------------------------------------------------------------- */
	
	.section .text
	.global	or1k_interrupt_handler
        .type	or1k_interrupt_handler,@function

or1k_interrupt_handler:
	/* Make room on stack, save link register */
	l.addi	r1,r1,-12
	l.sw	0(r1),r9
	
	/* Read PICSR */
	l.mfspr	r3,r0,SPR_PICSR

	/* Load handler table base address */
	l.movhi r7,hi(or1k_interrupt_handler_table)
	l.ori	r7,r7,lo(or1k_interrupt_handler_table)
	/* Check to see if this handler has been set yet */
	l.movhi r8,hi(INTERRUPT_HANDLER_NOT_SET)
	l.ori 	r8,r8,lo(INTERRUPT_HANDLER_NOT_SET)
	/* Load data pointer table base address */
	l.movhi r12,hi(or1k_interrupt_handler_data_ptr_table)
	l.ori	r12,r12,lo(or1k_interrupt_handler_data_ptr_table)
	
.L0:
	/* Find first set bit in PICSR */
	l.ff1	r4,r3
	/* Any bits set? */
	l.sfne	r4,r0
	/* If none, finish */
	OR1K_DELAYED_NOP(OR1K_INST(l.bnf	.L2))
	/* What is IRQ function table offset? */
	l.addi	r5,r4,-1
	l.slli	r6,r5,2
	/* Add this to table bases */
	l.add	r6,r6,r7
	l.add	r13,r6,r12

	/* Fetch handler function address */
	l.lwz	r6,0(r6)

	/* Double check it's valid, compare against INTERRUPT_HANDLER_NOT_SET */
	l.sfne	r6,r8
	/* Skip if no handler: TODO: Indicate interrupt fired but no handler*/
	OR1K_DELAYED_NOP(OR1K_INST(l.bnf .L1))
	
	/* Pull out data pointer from table, save r3, we'll write over it */
	l.sw	4(r1),r3
	l.lwz	r3,0(r13)
	/* Call handler, save r5 in delay slot */
        OR1K_DELAYED(
	OR1K_INST(l.sw	8(r1),r5),
	OR1K_INST(l.jalr	r5)
        )

	/* Reload r3,r5 */
	l.lwz	r3,4(r1)
	l.lwz	r5,8(r1)
.L1:
	/* Clear bit from PICSR, return to start of checking loop */
	l.ori	r6,r0,1
	l.sll	r6,r6,r5
        OR1K_DELAYED(
	OR1K_INST(l.xor	r3,r3,r6),
	OR1K_INST(l.j	.L0)
        )

.L2:
	/* Finish up - write PICSR back, restore r9*/
	l.lwz	r9,0(r1)
	l.mtspr	r0,r3,SPR_PICSR
        OR1K_DELAYED(
	OR1K_INST(l.jr	r9),
	OR1K_INST(l.addi	r1,r1,12)
        )


	
/* -------------------------------------------------------------------------- */
/*!Function to add handler to table
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_interrupt_handler_add
        .type	or1k_interrupt_handler_add,@function
	
	/* r3 should have IRQ line for peripheral */
	/* r4 should have handler function address */
or1k_interrupt_handler_add:
	l.addi 	r1,r1,-4
	l.sw	0(r1),r6
	/* Convert interrupt number into word address */
	l.slli	r3,r3,2
	l.addi	r3,r3,-4
	/* Get address of interrupt handler table */
	l.movhi r6,hi(or1k_interrupt_handler_table)
	l.ori	r6,r6,lo(or1k_interrupt_handler_table)
	/* Add handler offset to table base */
	l.add	r6,r6,r3
	/* Store handler function address */
	l.sw 	0(r6),r4
	/* Get address of interrupt handler data ptr table */
	l.movhi r6,hi(or1k_interrupt_handler_data_ptr_table)
	l.ori	r6,r6,lo(or1k_interrupt_handler_data_ptr_table)
	/* Add handler offset to table base */
	l.add	r6,r6,r3
	/* Store handler data pointer address */
	l.sw 	0(r6),r5
	/* Restore r6 */
	l.lwz	r6,0(r1)
        OR1K_DELAYED(
	/* Restore stack value */
	OR1K_INST(l.addi	r1,r1,4),
	/* Return via link register */
	OR1K_INST(l.jr	r9)
        )


/* -------------------------------------------------------------------------- */
/*!Function to enable an interrupt handler in the PICMR
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_interrupt_enable
        .type	or1k_interrupt_enable,@function

	/* r3 should have IRQ line for peripheral */
or1k_interrupt_enable:
	l.addi 	r1,r1,-4
	l.sw	0(r1),r4
	l.ori	r4,r0,0x1
	l.sll	r4,r4,r3
	l.mfspr	r3,r0,SPR_PICMR
	l.or	r3,r3,r4
	l.mtspr	r0,r3,SPR_PICMR
	l.lwz	r4,0(r1)
        OR1K_DELAYED(
	OR1K_INST(l.addi	r1,r1,4),
	OR1K_INST(l.jr	r9)
        )

/* -------------------------------------------------------------------------- */
/*!Function to disable an interrupt handler in the PICMR
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_interrupt_disable
        .type	or1k_interrupt_disable,@function

	/* r3 should have IRQ line for peripheral */
or1k_interrupt_disable:
	l.addi 	r1,r1,-4
	l.sw	0(r1),r4
	l.ori	r4,r0,0x1
	l.sll	r4,r4,r3
	l.xori	r4,r4,0xffff
	l.mfspr	r3,r0,SPR_PICMR
	l.and	r3,r3,r4
	l.mtspr	r0,r3,SPR_PICMR
	l.lwz	r4,0(r1)
        OR1K_DELAYED(
	OR1K_INST(l.addi	r1,r1,4),
	OR1K_INST(l.jr	r9)
        )


/* -------------------------------------------------------------------------- */
/*!Generic exception handler function
                                                                              */
/* -------------------------------------------------------------------------- */
// Warning - this must be the same as specified in crt0.S	
#define EXCEPTION_STACK_SIZE 128+128 

// Value handler addresses are initialised to
#define EXCEPTION_HANDLER_NOT_SET -1

	
	.data
	.align 4
	.global or1k_exception_handler_table
	.extern _interrupt_handler
or1k_exception_handler_table:
or1k_exception_handler_buserr:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_dpfault:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_ipfault:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_tick:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_align:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_illegal:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_interrupt:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_dtlbmiss:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_itlbmiss:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_range:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_systemcall:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_float:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_trap:		.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved0:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved1:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved2:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved3:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved4:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved5:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved6:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved7:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved8:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved9:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved10:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved11:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved12:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved13:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved14:	.long	EXCEPTION_HANDLER_NOT_SET
or1k_exception_handler_reserved15:	.long	EXCEPTION_HANDLER_NOT_SET
	
/* -------------------------------------------------------------------------- */
/*!Function to call appropriate exception handler            
                                                                              */
/* -------------------------------------------------------------------------- */
	.section .text
	.global	or1k_exception_handler
        .type	or1k_exception_handler,@function

	/*
	r3 = address of exception vector
	r4 = address where exception occurred
	*/

or1k_exception_handler:
	/* Store remainder of state (r3,r4 stored in vector entry)*/
	l.sw    0x00(r1), r2
	l.sw    0x0c(r1), r5
	l.sw    0x10(r1), r6
	l.sw    0x14(r1), r7
	l.sw    0x18(r1), r8
	l.sw    0x1c(r1), r9
	l.sw    0x20(r1), r10
	l.sw    0x24(r1), r11
	l.sw    0x28(r1), r12
	l.sw    0x2c(r1), r13
	l.sw    0x30(r1), r14
	l.sw    0x34(r1), r15
	l.sw    0x38(r1), r16
	l.sw    0x3c(r1), r17
	l.sw    0x40(r1), r18
	l.sw    0x44(r1), r19
	l.sw    0x48(r1), r20
	l.sw    0x4c(r1), r21
	l.sw    0x50(r1), r22
	l.sw    0x54(r1), r23
	l.sw    0x58(r1), r24
	l.sw    0x5c(r1), r25
	l.sw    0x60(r1), r26
	l.sw    0x64(r1), r27
	l.sw    0x68(r1), r28
	l.sw    0x6c(r1), r29
	l.sw    0x70(r1), r30
	l.sw    0x74(r1), r31
	
	/* Determine offset in table of exception handler using r3*/
	l.andi	r13,r3,0xffff
	l.srli	r13,r13,6
	/* Substract 2 words, as we have no vector at 0 and no reset handler */
	l.addi	r13,r13,-8
	/* r13 now contains offset in or1k_exception_handler_table for
	   function
	*/
	/* Get or1k_exception_handler_table address */
	l.movhi r14,hi(or1k_exception_handler_table)
	l.ori	r14,r14,lo(or1k_exception_handler_table)
	/* r14 now contains base of exception handler table */
	l.add	r14,r14,r13
	l.lwz	r13, 0(r14)

	/* Check to see if this handler has been set yet */
	l.movhi r15,hi(EXCEPTION_HANDLER_NOT_SET)
	l.ori 	r15,r15,lo(EXCEPTION_HANDLER_NOT_SET)
	l.sfne	r13,r15
	OR1K_DELAYED_NOP(OR1K_INST(l.bnf	exception_exit))
	
	/* Call exception handler, copy EPCR to r3 */
        OR1K_DELAYED(
	OR1K_INST(l.or	r3,r4,r4),
	OR1K_INST(l.jalr	r13)
        )

	/* Restore state */
	l.lwz    r2, 0x00(r1)
	l.lwz    r3, 0x04(r1)
	l.lwz    r4, 0x08(r1)
	l.lwz    r5, 0x0c(r1)
	l.lwz    r6, 0x10(r1)
	l.lwz    r7, 0x14(r1)
	l.lwz    r8, 0x18(r1)
	l.lwz    r9, 0x1c(r1)
	l.lwz    r10, 0x20(r1)
	l.lwz    r11, 0x24(r1)
	l.lwz    r12, 0x28(r1)
	l.lwz    r13, 0x2c(r1)
	l.lwz    r14, 0x30(r1)
	l.lwz    r15, 0x34(r1)
	l.lwz    r16, 0x38(r1)
	l.lwz    r17, 0x3c(r1)
	l.lwz    r18, 0x40(r1)
	l.lwz    r19, 0x44(r1)
	l.lwz    r20, 0x48(r1)
	l.lwz    r21, 0x4c(r1)
	l.lwz    r22, 0x50(r1)
	l.lwz    r23, 0x54(r1)
	l.lwz    r24, 0x58(r1)
	l.lwz    r25, 0x5c(r1)
	l.lwz    r26, 0x60(r1)
	l.lwz    r27, 0x64(r1)
	l.lwz    r28, 0x68(r1)
	l.lwz    r29, 0x6c(r1)
	l.lwz    r30, 0x70(r1)
	l.lwz    r31, 0x74(r1)

	l.addi  r1, r1, EXCEPTION_STACK_SIZE

	l.rfe
	l.nop

exception_exit:	
	/* Exception handler not set, exit */
        OR1K_DELAYED(
	OR1K_INST(l.or	r3,r4,r4),
	OR1K_INST(l.jal	exit)
        )


	
/* -------------------------------------------------------------------------- */
/*!Function to add handler to table
                                                                              */
/* -------------------------------------------------------------------------- */
	.global	or1k_exception_handler_add
        .type	or1k_exception_handler_add,@function

	.extern or1k_exception_handler_table

	/* r3 should have exception number (2 for buserr, 5 for tick, etc.) */
	/* r4 should have handler function address */
or1k_exception_handler_add:
	l.addi 	r1,r1,-4
	l.sw	0(r1),r5
	/* Convert exception number into word address */
	l.slli	r3,r3,2
	l.addi	r3,r3,-8
	/* Get address of exception handler table */
	l.movhi r5,hi(or1k_exception_handler_table)
	l.ori	r5,r5,lo(or1k_exception_handler_table)
	/* Add handler offset to table base */
	l.add	r5,r5,r3
	/* Store handler function address */
	l.sw 	0(r5),r4
	/* Restore r5 */
	l.lwz	r5,0(r1)
        OR1K_DELAYED(
	/* Restore stack value */
	OR1K_INST(l.addi	r1,r1,4),
	/* Return via link register */
	OR1K_INST(l.jr	r9)
        )
