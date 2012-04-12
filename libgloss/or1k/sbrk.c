/* sbrk.c. Implementation of the _sbrk syscall for newlib

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


#undef errno
extern int  errno;

#define STACK_BUFFER  65536	/*!< Reserved stack space in bytes. */


/* -------------------------------------------------------------------------- */
/*!Extend the heap

   We just increment a pointer in what's left of memory on the board.

   While the heap grows upwards, the stack grows downwards.  Eventually these
   two things may colide and sbrk() won't even be able to return properly.

   To mitigate this we reserve upto STACK_BUFFER _words_ at the top of memory.
   Note this doesn't actually solve the problem, it just provides an error
   margin. The real solution is to use an OS with a proper virtual memory
   manager.

   Remember that this function is *not* reentrant, so no static state should
   be held.

   @todo  We break this rule with heap_ptr. This needs to be clean, so that a
          re-entrant call to sbrk (e.g. in an ISR) is certain to work.

   @param[in] nbytes  The number of bytes to be allocated.

   @return  The previous heap end on success, -1 on failure with an error
            code in errno.                                                    */
/* -------------------------------------------------------------------------- */
void *
_sbrk (int nbytes)
{
  /* Symbol defined by linker map */
  extern int  end;		/* start of free memory (as symbol) */

  /* Value set by crt0.S */
  extern void *stack;		/* end of free memory */

  /* The statically held previous end of the heap, with its initialization. */
  static void *heap_ptr = (void *)&end;		/* Previous end */

  if ((stack - (heap_ptr + nbytes)) > STACK_BUFFER )
    {
      void *base  = heap_ptr;
      heap_ptr   += nbytes;
		
      return  base;
    }
  else
    {
      errno = ENOMEM;
      return  (void *) -1;
    }
}	/* _sbrk () */
