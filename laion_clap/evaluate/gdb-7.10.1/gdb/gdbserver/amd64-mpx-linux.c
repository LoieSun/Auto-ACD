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

/* This file was created with the aid of ``regdat.sh'' and ``./../regformats/i386/amd64-mpx-linux.dat''.  */

#include "server.h"
#include "regdef.h"
#include "tdesc.h"

static struct reg regs_amd64_mpx_linux[] = {
  { "rax", 0, 64 },
  { "rbx", 64, 64 },
  { "rcx", 128, 64 },
  { "rdx", 192, 64 },
  { "rsi", 256, 64 },
  { "rdi", 320, 64 },
  { "rbp", 384, 64 },
  { "rsp", 448, 64 },
  { "r8", 512, 64 },
  { "r9", 576, 64 },
  { "r10", 640, 64 },
  { "r11", 704, 64 },
  { "r12", 768, 64 },
  { "r13", 832, 64 },
  { "r14", 896, 64 },
  { "r15", 960, 64 },
  { "rip", 1024, 64 },
  { "eflags", 1088, 32 },
  { "cs", 1120, 32 },
  { "ss", 1152, 32 },
  { "ds", 1184, 32 },
  { "es", 1216, 32 },
  { "fs", 1248, 32 },
  { "gs", 1280, 32 },
  { "st0", 1312, 80 },
  { "st1", 1392, 80 },
  { "st2", 1472, 80 },
  { "st3", 1552, 80 },
  { "st4", 1632, 80 },
  { "st5", 1712, 80 },
  { "st6", 1792, 80 },
  { "st7", 1872, 80 },
  { "fctrl", 1952, 32 },
  { "fstat", 1984, 32 },
  { "ftag", 2016, 32 },
  { "fiseg", 2048, 32 },
  { "fioff", 2080, 32 },
  { "foseg", 2112, 32 },
  { "fooff", 2144, 32 },
  { "fop", 2176, 32 },
  { "xmm0", 2208, 128 },
  { "xmm1", 2336, 128 },
  { "xmm2", 2464, 128 },
  { "xmm3", 2592, 128 },
  { "xmm4", 2720, 128 },
  { "xmm5", 2848, 128 },
  { "xmm6", 2976, 128 },
  { "xmm7", 3104, 128 },
  { "xmm8", 3232, 128 },
  { "xmm9", 3360, 128 },
  { "xmm10", 3488, 128 },
  { "xmm11", 3616, 128 },
  { "xmm12", 3744, 128 },
  { "xmm13", 3872, 128 },
  { "xmm14", 4000, 128 },
  { "xmm15", 4128, 128 },
  { "mxcsr", 4256, 32 },
  { "orig_rax", 4288, 64 },
  { "ymm0h", 4352, 128 },
  { "ymm1h", 4480, 128 },
  { "ymm2h", 4608, 128 },
  { "ymm3h", 4736, 128 },
  { "ymm4h", 4864, 128 },
  { "ymm5h", 4992, 128 },
  { "ymm6h", 5120, 128 },
  { "ymm7h", 5248, 128 },
  { "ymm8h", 5376, 128 },
  { "ymm9h", 5504, 128 },
  { "ymm10h", 5632, 128 },
  { "ymm11h", 5760, 128 },
  { "ymm12h", 5888, 128 },
  { "ymm13h", 6016, 128 },
  { "ymm14h", 6144, 128 },
  { "ymm15h", 6272, 128 },
  { "bnd0raw", 6400, 128 },
  { "bnd1raw", 6528, 128 },
  { "bnd2raw", 6656, 128 },
  { "bnd3raw", 6784, 128 },
  { "bndcfgu", 6912, 64 },
  { "bndstatus", 6976, 64 },
};

static const char *expedite_regs_amd64_mpx_linux[] = { "rbp", "rsp", "rip", 0 };
static const char *xmltarget_amd64_mpx_linux = "amd64-mpx-linux.xml";

const struct target_desc *tdesc_amd64_mpx_linux;

void
init_registers_amd64_mpx_linux (void)
{
  static struct target_desc tdesc_amd64_mpx_linux_s;
  struct target_desc *result = &tdesc_amd64_mpx_linux_s;

  result->reg_defs = regs_amd64_mpx_linux;
  result->num_registers = sizeof (regs_amd64_mpx_linux) / sizeof (regs_amd64_mpx_linux[0]);
  result->expedite_regs = expedite_regs_amd64_mpx_linux;
  result->xmltarget = xmltarget_amd64_mpx_linux;

  init_target_desc (result);

  tdesc_amd64_mpx_linux = result;
}
