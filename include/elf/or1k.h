/* Or1k ELF support for BFD.
   Copyright 2001, 2010 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _ELF_OR1K_H
#define _ELF_OR1K_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_or1k_reloc_type)
  RELOC_NUMBER (R_OR1K_NONE,           0)
  RELOC_NUMBER (R_OR1K_32,             1)
  RELOC_NUMBER (R_OR1K_16,             2)
  RELOC_NUMBER (R_OR1K_8,              3)
  RELOC_NUMBER (R_OR1K_LO_16_IN_INSN,  4)
  RELOC_NUMBER (R_OR1K_HI_16_IN_INSN,  5)
  RELOC_NUMBER (R_OR1K_INSN_REL_26,    6)
  RELOC_NUMBER (R_OR1K_GNU_VTENTRY,    7)
  RELOC_NUMBER (R_OR1K_GNU_VTINHERIT,  8)
  RELOC_NUMBER (R_OR1K_32_PCREL,       9)
  RELOC_NUMBER (R_OR1K_16_PCREL,      10)
  RELOC_NUMBER (R_OR1K_8_PCREL,       11)
END_RELOC_NUMBERS (R_OR1K_max)

#define EF_OR1K_NODELAY (1UL << 0)

#endif /* _ELF_OR1K_H */
