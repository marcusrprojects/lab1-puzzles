#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "puzzles.h"

test_rec test_set[] = {
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
 {"maxVal", (funct_t) maxVal, (funct_t) test_maxVal, 0, "! ~ & ^ | + << >>", 4, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"negCheck", (funct_t) negCheck, (funct_t) test_negCheck, 1,
    "! ~ & ^ | + << >>", 6, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"lsbCopy", (funct_t) lsbCopy, (funct_t) test_lsbCopy, 1,
    "! ~ & ^ | + << >>", 5, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"andBits", (funct_t) andBits, (funct_t) test_andBits, 2, "| ~", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"xorBits", (funct_t) xorBits, (funct_t) test_xorBits, 2, "& ~", 14, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"setThirdBits", (funct_t) setThirdBits, (funct_t) test_setThirdBits, 0,
    "! ~ & ^ | + << >>", 8, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"byteExtract", (funct_t) byteExtract, (funct_t) test_byteExtract, 2,
    "! ~ & ^ | + << >>", 6, 2,
  {{TMin, TMax},{0,3},{TMin,TMax}}},
 {"bitFit", (funct_t) bitFit, (funct_t) test_bitFit, 2,
    "! ~ & ^ | + << >>", 15, 2,
  {{TMin, TMax},{1,32},{TMin,TMax}}},
{"byteSwitch", (funct_t) byteSwitch, (funct_t) test_byteSwitch, 3,
     "! ~ & ^ | + << >>", 25, 2,
    {{TMin, TMax},{0,3},{0,3}}},
 {"addOverflow", (funct_t) addOverflow, (funct_t) test_addOverflow, 2,
    "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"shiftLogical", (funct_t) shiftLogical, (funct_t) test_shiftLogical,
   2, "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{0,31},{TMin,TMax}}},
 {"not", (funct_t) not, (funct_t) test_not, 1,
    "~ & ^ | + << >>", 12, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"signMagnitude", (funct_t) signMagnitude, (funct_t) test_signMagnitude, 1, "! ~ & ^ | + << >>", 15, 3,
  {{TMin+1, TMax},{TMin+1,TMax},{TMin+1,TMax}}},
 {"fp_abs", (funct_t) fp_abs, (funct_t) test_fp_abs, 1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
 {"fp_twice", (funct_t) fp_twice, (funct_t) test_fp_twice, 1,
    "$", 30, 3,
     {{1, 1},{1,1},{1,1}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
