/* OR1K support defines
  
   Copyright (C) 2011, ORSoC AB
   Copyright (C) 2008, 2010 Embecosm Limited
  
   Contributor Julius Baxter  <julius.baxter@orsoc.se>
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

/* This machine configuration matches the Or1ksim configuration file in this
   directory. */

#ifndef OR1K_NEWLIB_SUPPORT__H
#define OR1K_NEWLIB_SUPPORT__H

/*! External symbols from each board's object file */
extern unsigned long _board_clk_freq;

extern unsigned long _board_uart_base;
extern unsigned long _board_uart_baud;
extern unsigned long _board_uart_irq;

/*! Check if board has UART - test base address */
#define BOARD_HAS_UART (_board_uart_base)

/*! l.nop constants */
#define NOP_NOP          0x0000      /* Normal nop instruction */
#define NOP_EXIT         0x0001      /* End of simulation, report exit status */
#define NOP_REPORT       0x0002      /* Simple report */
/*#define NOP_PRINTF       0x0003       Simprintf instruction (obsolete)*/
#define NOP_PUTC         0x0004      /* JPB: Simputc instruction */
#define NOP_CNT_RESET    0x0005	     /* Reset statistics counters */
#define NOP_GET_TICKS    0x0006	     /* JPB: Get # ticks running */
#define NOP_GET_PS       0x0007      /* JPB: Get picosecs/cycle */
#define NOP_EXIT_SILENT  0x000c      /* End of simulation, silently exit */
#define NOP_REPORT_FIRST 0x0400      /* Report with number */
#define NOP_REPORT_LAST  0x03ff      /* Report with number */

/*! Register access macro */
#define REG8(add) *((volatile unsigned char *) (add))
#define REG16(add) *((volatile unsigned short *) (add))
#define REG32(add) *((volatile unsigned long *) (add))

/*! Interrupt control function prototypes */
void or1k_interrupt_handler_add(int, void(*)(void*));
void or1k_interrupt_enable(int);
void or1k_interrupt_disable(int);

/*! Exception handler insertion prototype */
void or1k_exception_handler_add(int, void (*)(void));

/*! SPR access prototypes */
void  or1k_mtspr (unsigned long int  spr,
                    unsigned long int  value);
unsigned long int  or1k_mfspr (unsigned long int  spr);

/*! Simulator prototypes */
void or1k_report (unsigned long int  value);

/*! Cache control prototypes */
void or1k_icache_enable(void);
void or1k_icache_disable(void);
void or1k_icache_flush(unsigned long);
void or1k_dcache_enable(void);
void or1k_dcache_disable(void);
void or1k_dcache_flush(unsigned long);

/*! MMU control prototypes */
void or1k_immu_enable(void);
void or1k_immu_disable(void);
void or1k_dmmu_enable(void);
void or1k_dmmu_disable(void);

/*! Timer prototypes */
void or1k_timer_init(unsigned int hz);
void or1k_timer_enable(void);
void or1k_timer_disable(void);
unsigned long or1k_timer_get_ticks(void);
void or1k_timer_reset_ticks(void);

/*! Utility function prototypes */
unsigned long int or1k_rand(void);

#endif	/* OR1K_NEWLIB_SUPPORT__H */
