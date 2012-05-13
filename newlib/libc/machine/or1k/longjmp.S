/* longjmp.S. Implementation of longjmp.

   Copyright (C) 2010, Embecosm Limited <info@embecosm.com>

   Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>

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
/* -------------------------------------------------------------------------- */
/* This program is commented throughout in a fashion suitable for processing
   with Doxygen.                                                              */
/* -------------------------------------------------------------------------- */

#include "or1k-asm.h"
	
/* -------------------------------------------------------------------------- */
/*!_longjmp

   All processor state is restored from the buffer provided. We need not restore
   r0 (it will always be zero) and we need not restore r11 (it will always be
   overridden here).

   We need to take some care, since we cannot restore r3 until all other
   registers are restore, and the value of r4 must first be saved in r11,
   modifying it if its value is zero.

   @todo We should prefer to save and restore the status register, but this is
	 not directly possible in user code. There is some merit in code to
	 set the flag, since in compiled C code, that might be expected to hold
	 a value. We leave a space for this information for future enhancement.

   @param[out] env(r3)  A buffer from which to restore all the current
	                processor state.
   @param[in]  val(r4)  A value to return

   @return  val, unless val is zero, in which case 1 is returned.
/* -------------------------------------------------------------------------- */
	.align	4
        .global	longjmp
        .type	longjmp,@function
longjmp:
	/* Sort out the return value */
	l.sfne	r4,r0
	OR1K_DELAYED_NOP(OR1K_INST(l.bf	1f))

	OR1K_DELAYED(
	OR1K_INST(l.addi	r11,r0,1),		/* 1 as result */
	OR1K_INST(l.j	2f)
	)

1:	l.addi	r11,r4,0		/* val as result */

	/* Restore all the other registers, leaving r3 to last. */
2:	l.lwz	r31,120(r3)
	l.lwz	r30,116(r3)
	l.lwz	r29,112(r3)
	l.lwz	r28,108(r3)
	l.lwz	r27,104(r3)
	l.lwz	r26,100(r3)
	l.lwz	r25,96(r3)
	l.lwz	r24,92(r3)
	l.lwz	r23,88(r3)
	l.lwz	r22,84(r3)
	l.lwz	r21,80(r3)
	l.lwz	r20,76(r3)
	l.lwz	r19,72(r3)
	l.lwz	r18,68(r3)
	l.lwz	r17,64(r3)
	l.lwz	r16,60(r3)
	l.lwz	r15,56(r3)
	l.lwz	r14,52(r3)
	l.lwz	r13,48(r3)
	l.lwz	r12,44(r3)
	l.lwz	r10,40(r3)		/* Omit r11 */
	l.lwz	r9,36(r3)
	l.lwz	r8,32(r3)
	l.lwz	r7,28(r3)
	l.lwz	r6,24(r3)
	l.lwz	r5,20(r3)
	l.lwz	r4,16(r3)
	l.lwz	r2,8(r3)		/* Skip r3 */
	l.lwz	r1,4(r3)		/* Slot 0 saved for flag in future */
	l.lwz	r3,12(r3)		/* Now safe */
	
	/* Result is already in r11. Having restored r9, it will appear as
	   though we have returned from the earlier call to setjmp. The
	   non-zero result gives it away though. */
	OR1K_DELAYED_NOP(OR1K_INST(l.jr	r9))

	.size	longjmp, .-longjmp
