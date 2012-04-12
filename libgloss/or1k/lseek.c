/* lseek.c. Implementation of the _lseek syscall for newlib

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
/*!Set a position in a file when using a UART.

   We only support stdin, stdout and stderr for which positioning is always to
   offset 0.

   Remember that this function is *not* reentrant, so no static state should
   be held.

   @param[in] file    The fileno to lseek.
   @param[in] offset  The desired offset.
   @param[in] whence  Where to lseek from.

   @return  0, indicating the offset achieved.                                */
/* -------------------------------------------------------------------------- */
int
_lseek (int   file,
	int   offset,
	int   whence)
{
  if ((BOARD_HAS_UART && (STDIN_FILENO  == file)) ||
      (STDOUT_FILENO == file) ||
      (STDERR_FILENO == file))
    {
      return  0;
    }
  else
    {
      errno = EBADF;
      return (long) -1;
    }
}	/* _lseek () */
