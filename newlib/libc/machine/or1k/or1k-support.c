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

#include "or1k-support.h"
#include "spr-defs.h"

/* Board-specific CPU clk HZ value */
extern unsigned long _board_clk_freq;

/* Tick timer variable */
volatile unsigned long or1k_timer_ticks;

/* Tick rate storage */
unsigned long or1k_timer_period;


/* --------------------------------------------------------------------------*/
/*!Report a 32-bit value

   Uses the built-in simulator functionality.

   @param[in] value  Value to report.                                        */
/* --------------------------------------------------------------------------*/
void
or1k_report (unsigned long int  value)
{
  __asm__ __volatile__ ("l.addi\tr3,%0,0\n\t"
                        "l.nop %1": : "r" (value), "K" (NOP_REPORT));

}       /* report () */

/* --------------------------------------------------------------------------*/
/*!Write a SPR

   @todo Surely the SPR should be a short int, since it is only 16-bits. Left
         as is for now due to large amount of user code that might need
         changing.

   @param[in] spr    The SPR to write
   @param[in] value  The value to write to the SPR                           */
/* --------------------------------------------------------------------------*/
void
or1k_mtspr (unsigned long int  spr,
       unsigned long int  value)
{       
  __asm__ __volatile__ ("l.mtspr\t\t%0,%1,0": : "r" (spr), "r" (value));

}       /* mtspr () */

/* --------------------------------------------------------------------------*/
/*!Read a SPR

   @todo Surely the SPR should be a short int, since it is only 16-bits. Left
         as is for now due to large amount of user code that might need
         changing.

   @param[in] spr    The SPR to write

   @return  The value read from the SPR                                      */
/* --------------------------------------------------------------------------*/
unsigned long int
or1k_mfspr (unsigned long spr)
{       
  unsigned long value;

  __asm__ __volatile__ ("l.mfspr\t\t%0,%1,0" : "=r" (value) : "r" (spr));

  return value;

}       /* mfspr () */

/* --------------------------------------------------------------------------*/
/*!Pseudo-random number generator

   This should return pseudo-random numbers, based on a Galois LFSR

   @return The next pseudo-random number                                     */
/* --------------------------------------------------------------------------*/
unsigned long int
or1k_rand ()
{
  static unsigned long int lfsr = 1;
  static int period = 0;
  /* taps: 32 31 29 1; characteristic polynomial: x^32 + x^31 + x^29 + x + 1 */
  lfsr = (lfsr >> 1) ^ (unsigned long int)((0 - (lfsr & 1u)) & 0xd0000001u); 
  ++period;
  return lfsr;
}


/* --------------------------------------------------------------------------*/
/*!Tick timer interrupt handler

   Increment timer ticks counter, reload TTMR
                                                                             */
/* --------------------------------------------------------------------------*/
void 
or1k_timer_interrupt_handler(void)
{
  or1k_timer_ticks++;
  or1k_mtspr(SPR_TTMR, SPR_TTMR_IE | SPR_TTMR_RT | 
	(or1k_timer_period & SPR_TTMR_PERIOD));
}

/* --------------------------------------------------------------------------*/
/*!Enable tick timer    

   Install handler, calculate TTMR period, reset tick counter

   @param[in] hz     Rate at which to trigger timer ticks                    */
/* --------------------------------------------------------------------------*/
void 
or1k_timer_init(unsigned int hz)
{

  /* Set this, for easy access when reloading */
  or1k_timer_period = _board_clk_freq/hz;

  /* Reset timer tick counter */
  or1k_timer_ticks = 0;
  
  /* Install handler */
  or1k_exception_handler_add(0x5,or1k_timer_interrupt_handler);

}

/* --------------------------------------------------------------------------*/
/*!Enable tick timer    

   Enable timer interrupt, install handler, load TTMR
                                                                             */
/* --------------------------------------------------------------------------*/
void 
or1k_timer_enable(void)
{
  or1k_mtspr(SPR_TTMR, SPR_TTMR_IE | SPR_TTMR_RT | 
	(or1k_timer_period & SPR_TTMR_PERIOD));
  or1k_mtspr(SPR_SR, SPR_SR_TEE | or1k_mfspr(SPR_SR));

}

/* --------------------------------------------------------------------------*/
/*!Disable tick timer    

   Disable timer interrupt in SR
                                                                             */
/* --------------------------------------------------------------------------*/
void 
or1k_timer_disable(void)
{
   or1k_mtspr(SPR_SR, ~SPR_SR_TEE & or1k_mfspr(SPR_SR));
}

/* --------------------------------------------------------------------------*/
/*!Get tick timer    

   Return value of tick timer
                                                                             */
/* --------------------------------------------------------------------------*/
unsigned long
or1k_timer_get_ticks(void)
{
  return or1k_timer_ticks;
}

/* --------------------------------------------------------------------------*/
/*!Reset tick timer    

   Clear value of tick timer
                                                                             */
/* --------------------------------------------------------------------------*/
void
or1k_timer_reset_ticks(void)
{
  or1k_timer_ticks = 0;
}



