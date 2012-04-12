/* uart.c. UART support functions

   Copyright (C) 2004, Jacob Bower
   Copyright (C) 2010, Embecosm Limited <info@embecosm.com>
 
   Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>
  
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
   with this program.  If not, see <http:#www.gnu.org/licenses/>.             */
/* -------------------------------------------------------------------------- */
/* This program is commented throughout in a fashion suitable for processing
   with Doxygen.                                                              */
/* -------------------------------------------------------------------------- */

#include "or1k-support.h"
#include "uart.h"

/*! Macro to access a UART register */
#define UREG8(reg) REG8 (_board_uart_base + reg)

/*! Macro to check if transmit and transmit holding registers are both empty. */
#define BOTH_EMPTY (UART_LSR_TEMT | UART_LSR_THRE)

/*! Macro to wait until a char has been transmitted */
#define WAIT_FOR_XMITR				\
  do						\
    {						\
      lsr = UREG8 (UART_LSR);			\
    }						\
  while ((lsr & BOTH_EMPTY) != BOTH_EMPTY)

/*! Macro to wait until a char can be transmitted */
#define WAIT_FOR_THRE				\
  do						\
    {						\
      lsr = UREG8 (UART_LSR);			\
    }						\
  while ((lsr & UART_LSR_THRE) != UART_LSR_THRE)

/* Macro to see if a character has been received */
#define CHECK_FOR_CHAR (UREG8 (UART_LSR) & UART_LSR_DR)

/* Macro to wait until a character is received */
#define WAIT_FOR_CHAR \
         do { \
                lsr = UREG8 (UART_LSR); \
         } while ((lsr & UART_LSR_DR) != UART_LSR_DR)


/* -------------------------------------------------------------------------- */
/*!Initialize the UART                                                        */
/* -------------------------------------------------------------------------- */
void
__uart_init ()
{
	int divisor;

	/* Reset receiver and transmiter */
	UREG8 (UART_FCR) = UART_FCR_ENABLE_FIFO |
	                   UART_FCR_CLEAR_RCVR  |
	                   UART_FCR_CLEAR_XMIT  |
	                   UART_FCR_TRIGGER_14;

	/* Disable all interrupts */
	UREG8 (UART_IER) = 0x00;

	/* Set 8 bit char, 1 stop bit, no parity */
	UREG8 (UART_LCR) = UART_LCR_WLEN8 & ~(UART_LCR_STOP | UART_LCR_PARITY);

	/* Set baud rate */
	divisor = (_board_clk_freq / _board_uart_baud + 8) / 16;

	UREG8 (UART_LCR) |= UART_LCR_DLAB;
	UREG8 (UART_DLL)  = divisor & 0x000000ff;
	UREG8 (UART_DLM)  = (divisor >> 8) & 0x000000ff;
	UREG8 (UART_LCR) &= ~(UART_LCR_DLAB);

}	/* __uart_init () */


/* -------------------------------------------------------------------------- */
/*!Put a character out on the UART

   @param[in] c  The character to output				      */
/* -------------------------------------------------------------------------- */
void __uart_putc (char  c)
{
  unsigned char lsr;

  /* Wait until we are free to transmit */
  WAIT_FOR_THRE;

  /* Put the character to be transmitted and wait until it has gone. */
  UREG8 (UART_TX) = c;
  WAIT_FOR_XMITR;

}	/* __uart_putc () */


/* -------------------------------------------------------------------------- */
/*!Get a character from the UART

   @reurn  The character read.                                                */
/* -------------------------------------------------------------------------- */
char
__uart_getc ()
{
  unsigned char lsr;
  char c;

  /* Wait until a char is available, then get it. */
  WAIT_FOR_CHAR;

  return  UREG8 (UART_RX);

}	/* __uart_getc () */
