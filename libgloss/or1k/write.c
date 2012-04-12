/* write.c. Implementation of the _write syscall for newlib

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

#include <errno.h>
#include <unistd.h>

#include "or1k-support.h"


#undef errno
extern int  errno;


/* -------------------------------------------------------------------------- */
/*!Write a single character to standard output for the simulator

   @param[in] c  The character to write                                       */
/* -------------------------------------------------------------------------- */
static void
outbyte (char  c)
{
	
	if (BOARD_HAS_UART)
	{
		__uart_putc (c);
	}
	else
	{
		register char  t1 asm ("r3") = c;
		
		asm volatile ("\tl.nop\t%0" : : "K" (NOP_PUTC), "r" (t1));
	}
	
}	/* outbyte () */


/* -------------------------------------------------------------------------- */
/*!Write a buffer to a file.

   Only output to stdout or stderr is supported, and both of those are
   directed to the single output stream.

   Remember that this function is *not* reentrant, so no static state should
   be held.

   @param[in] file  The fileno for output.
   @param[in] buf   The bytes to write.
   @param[in] nbytes  The number of bytes to write.

   @return  The number of bytes written on success, or -1 with an error code
            in the global variable errno on failure.                          */
/* -------------------------------------------------------------------------- */
int
_write (int   file,
        char *buf,
        int   nbytes)
{
  int i;

  /* We only handle stdout and stderr */
  if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
    {
      errno = EBADF;
      return -1;
    }

  /* Output character at at time */
  for (i = 0; i < nbytes; i++)
    {
      outbyte (buf[i]);
    }
	
  return nbytes;

}	/* _write () */
