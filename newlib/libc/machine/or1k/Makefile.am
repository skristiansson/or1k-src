# Makefile.am: Automake file for OR1K setjmp

# Copyright (C) 2000, Damjan Lampret
# Copyright (C) 2004, Jacob Bower
# Copyright (C) 2010, Embecosm Limited <info@embecosm.com>

# Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>

# This file is part of Newlib.

# The original work by Jacob Bower is provided as-is without any kind of
# warranty. Use it at your own risk!

# All subsequent work is bound by version 3 of the GPL as follows.

# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 3 of the License, or (at your option)
# any later version.

# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
# more details.

# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.            
# -----------------------------------------------------------------------------
## Process this file with automake to generate Makefile.in

# This is boilerplate.
AUTOMAKE_OPTIONS = cygnus

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

lib_a_SOURCES = longjmp.S setjmp.S
lib_a_CCASFLAGS=$(AM_CCASFLAGS)
lib_a_CFLAGS=$(AM_CFLAGS)

ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
