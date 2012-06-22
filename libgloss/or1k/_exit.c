/* _exit.c. Implementation of the _exit syscall for newlib

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


/* -------------------------------------------------------------------------- */
/*!Exit a program with no tidy up.

   We use the l.nop 1 code to terminate execution of the simulator.

   Remember that this function is *not* reentrant, so no static state should
   be held.

   @param[in] rc  The return code on exit.
/* -------------------------------------------------------------------------- */
void 
_exit (int  rc)
{
  register int  t1 asm ("r3") = rc;
  
  asm volatile ("\tl.j\t_board_exit\n"
#ifndef __OR1K_NODELAY__
                "\tl.nop"
#endif
                );
  
  __builtin_unreachable ();
  
}	/* _exit () */
