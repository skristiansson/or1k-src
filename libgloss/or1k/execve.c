/* execve.c. Implementation of the _execve syscall for newlib

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


#undef errno;
extern int  errno;


/* -------------------------------------------------------------------------- */
/*!Transfer control to a new process.

   We have no other processes, so this always fails.

   Remember that this function is *not* reentrant, so no static state should
   be held.

   @param[in] name  The program to be launched a a new process.
   @param[in] argv  Argv for the new process (null terminated).
   @param[in] env   Environment vector for the new process (null terminated).

   @return  -1 to indicate failure, with an error code in the global variable
            errno.                                                            */
/* -------------------------------------------------------------------------- */
int
_execve (char  *name,
	 char **argv,
	 char **env)
{
  errno = ENOMEM;
  return -1;			/* Always fails */

}	/* _execve () */
