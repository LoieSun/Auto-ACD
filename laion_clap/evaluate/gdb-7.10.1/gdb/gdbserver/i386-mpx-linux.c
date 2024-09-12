/* *INDENT-OFF* */ /* THIS FILE IS GENERATED */

/* A register protocol for GDB, the GNU debugger.
   Copyright (C) 2001-2013 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* This file was created with the aid of ``regdat.sh'' and ``./../regformats/i386/i386-mpx-linux.dat''.  */

#include "server.h"
#include "regdef.h"
#include "tdesc.h"

static struct reg regs_i386_mpx_linux[] = {
  { "eax", 0, 32 },
  { "ecx", 32, 32 },
  { "edx", 64, 32 },
  { "ebx", 96, 32 },
  { "esp", 128, 32 },
  { "ebp", 160, 32 },
  { "esi", 192, 32 },
  { "edi", 224, 32 },
  { "eip", 256, 32 },
  { "eflags", 288, 32 },
  { "cs", 320, 32 },
  { "ss", 352, 32 },
  { "ds", 384, 32 },
  { "es", 416, 32 },
  { "fs", 448, 32 },
  { "gs", 480, 32 },
  { "st0", 512, 80 },
  { "st1", 592, 80 },
  { "st2", 672, 80 },
  { "st3", 752, 80 },
  { "st4", 832, 80 },
  { "st5", 912, 80 },
  { "st6", 992, 80 },
  { "st7", 1072, 80 },
  { "fctrl", 1152, 32 },
  { "fstat", 1184, 32 },
  { "ftag", 1216, 32 },
  { "fiseg", 1248, 32 },
  { "fioff", 1280, 32 },
  { "foseg", 1312, 32 },
  { "fooff", 1344, 32 },
  { "fop", 1376, 32 },
  { "xmm0", 1408, 128 },
  { "xmm1", 1536, 128 },
  { "xmm2", 1664, 128 },
  { "xmm3", 1792, 128 },
  { "xmm4", 1920, 128 },
  { "xmm5", 2048, 128 },
  { "xmm6", 2176, 128 },
  { "xmm7", 2304, 128 },
  { "mxcsr", 2432, 32 },
  { "orig_eax", 2464, 32 },
  { "ymm0h", 2496, 128 },
  { "ymm1h", 2624, 128 },
  { "ymm2h", 2752, 128 },
  { "ymm3h", 2880, 128 },
  { "ymm4h", 3008, 128 },
  { "ymm5h", 3136, 128 },
  { "ymm6h", 3264, 128 },
  { "ymm7h", 3392, 128 },
  { "bnd0raw", 3520, 128 },
  { "bnd1raw", 3648, 128 },
  { "bnd2raw", 3776, 128 },
  { "bnd3raw", 3904, 128 },
  { "bndcfgu", 4032, 64 },
  { "bndstatus", 4096, 64 },
};

static const char *expedite_regs_i386_mpx_linux[] = { "ebp", "esp", "eip", 0 };
static const char *xmltarget_i386_mpx_linux = "i386-mpx-linux.xml";

const struct target_desc *tdesc_i386_mpx_linux;

void
init_registers_i386_mpx_linux (void)
{
  static struct target_desc tdesc_i386_mpx_linux_s;
  struct target_desc *result = &tdesc_i386_mpx_linux_s;

  result->reg_defs = regs_i386_mpx_linux;
  result->num_registers = sizeof (regs_i386_mpx_linux) / sizeof (regs_i386_mpx_linux[0]);
  result->expedite_regs = expedite_regs_i386_mpx_linux;
  result->xmltarget = xmltarget_i386_mpx_linux;

  init_target_desc (result);

  tdesc_i386_mpx_linux = result;
}
