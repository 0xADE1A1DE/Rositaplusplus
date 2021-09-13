// Copyright 2021 University of Adelaide
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "bool2arith.h"

register volatile int *global_ptr asm ("r7");

#define __tostr(x) \
    #x
#define __add(_op1, _op2) \
    "add " #_op1 "," #_op2 "\n\t"
#define __sub(_op1, _op2) \
    "sub " #_op1 "," #_op2 "\n\t"
#define __add_imm(_op1, _op2) \
    "add " #_op1 ", #" #_op2 "\n\t"
#define __sub_imm(_op1, _op2) \
    "sub " #_op1 ", #" #_op2 "\n\t"
#define __ldr_global(_op1, _global) \
   "ldr " #_op1 ","  _global "\n\t"
#define __ldr(_op1, _op2) \
    "ldr " #_op1 ", [" #_op2 "]\n\t"
#define __ldrb(_op1, _op2, _op3) \
    "ldrb " #_op1 ", [" #_op2 "," #_op3 "]\n\t"
#define __ldr_imm(_op1, _op2, _op3) \
    "ldr " #_op1 ", [" #_op2 ", #" #_op3 "]\n\t"
#define __ldrb_imm(_op1, _op2, _op3) \
    "ldrb " #_op1 ", [" #_op2 ", #" #_op3 "]\n\t"
#define __strb_imm(_op1, _op2, _op3) \
    "strb " #_op1 ", [" #_op2 ", #" #_op3 "]\n\t"
#define __str(_op1, _op2) \
    "str " #_op1 ", [" #_op2 "]\n\t"
#define __mov(_op1, _op2) \
    "mov " #_op1 "," #_op2 "\n\t"
#define __mov_imm(_op1, _op2) \
    "mov " #_op1 ",#" #_op2 "\n\t"
#define __lsl(_op1, _op2) \
    "lsl " #_op1 "," #_op2 "\n\t"
#define __lsr(_op1, _op2) \
    "lsr " #_op1 "," #_op2 "\n\t"
#define __lsl_imm(_op1, _op2) \
    "lsl " #_op1 ", #" #_op2 "\n\t"
#define __lsr_imm(_op1, _op2) \
    "lsr " #_op1 ", #" #_op2 "\n\t"
#define __and(_op1, _op2) \
    "and " #_op1 "," #_op2 "\n\t"
#define __eor(_op1, _op2) \
    "eor " #_op1 "," #_op2 "\n\t"
#define __mul(_op1, _op2) \
    "mul " #_op1 "," #_op2 "\n\t"
#define __decl_word(_label, _global) \
    "b " _label "__0 \n" \
    ".align 2\n\t" \
    _label ":\n\t" \
    ".word " #_global "\n" \
    _label "__0:\n\t"
/*masks = [ [0](r1, r2), [2](s1, s2), [4](g1, g2, a) ] */
#define __Bool2Arith(boolx /*x'*/, arithx /*x''*/, masks, t0, t1, t2, t3, t4) \
    __mov(t2, masks) \
    __ldr_imm(t1, t2, 0) /* t1 = r1 */\
    __ldr_imm(t3, t2, 16)  /* t3 = g1 */\
    __eor(t3, t1) /* z = g1 ^ r1 */\
    __ldr_imm(t1, t2, 20)  /* t1 = g2 */\
    __eor(t3, t1) /* z = z ^ g2 */\
    __ldr_imm(t1, t2, 4) /* t1 = r2 */\
    __eor(t3, t1) /* z = z ^ r2 */\
    __mov(t1, boolx) \
    __eor(t1, t3) /* u = x' ^ z */\
    __ldr_imm(t4, t2, 24) \
    __eor(t3, t4)  /* z = z ^ a */\
    __add(t1, t3) /* u = u + z */\
    __ldr_imm(t3, t2, 16) /* t3 = g1*/\
    __mov(t0, boolx) \
    __eor(t0, t3) /* v = x' ^ g1 */\
    __eor(t0, t4) /* v = v ^ a */\
    __add(t0, t3) /* v = v + g1 */\
    __ldr_imm(t3, t2, 20) /* t3 = g2 */\
    __mov(t2, boolx) /* t2 = x' */\
    __eor(t2, t3) /* w = x' ^ g2 */\
    __eor(t2, t4) /* w = w ^ a */\
    __add(t2, t3) /* w = w + g2 */\
    __mov(arithx, t2) /* h5 = w */\
    __mov(t2, masks) /**/ \
    __ldr_imm(t3, t2, 8) /* t3 = s1 */ \
    __ldr_imm(t4, t2, 4) /* t4 = r2 */ \
    __eor(t3, t4) /* z = s1 ^ r2 */ \
    __eor(t1, t4) /* u = u ^ r2 */ \
    __eor(t1, t0) /* u = u ^ v */ \
    __mov(t2, arithx) /* t2 = w */ \
    __eor(t1, t2) /* u = u ^ w */ \
    __mov(t0, t1) /* t0 = u */\
    __mov(t2, masks) /**/ \
    __ldr_imm(t2, t2, 8) /* t2 = s1 */ \
    __eor(t0, t2) /* v = u ^ s1 */\
    __add(t0, t4) /* v = v + r2 */\
    __mov(t2, t1) /* t2 = u */\
    __eor(t2, t3) /* w = u ^ z */ \
    __eor(t0, t2) /* v = v ^ w */ \
    __mov(t2, t1) /* t2 = u */\
    __add(t2, t3) /* w = u + z*/\
    __mov(t3, t0) /* z = v */\
    __eor(t3, t2) /* z = v ^ w */\
    __mov(arithx, t3) /* h5 = z */\
    __mov(t3, masks) \
    __ldr_imm(t0, t3, 24) /* t0 = a */ \
    __eor(t0, t4) /* w = a ^ r2 */ \
    __ldr_imm(t4, t3, 12) /* t4 = s2 */ \
    __ldr_imm(t3, t3, 0) /* t3 = r1 */ \
    __mov(t1, t4) /* t1 = s2 */\
    __eor(t1, t3) /* u = s2 ^ r1 */\
    __sub(t1, t0) /* u = u - w */\
    __eor(t0, t4) /* w = w ^ s2 */\
    __mov(t4, t0) /* v = w */ \
    __eor(t4, t3) /* v = w ^ r1*/ \
    __sub(t0, t3) /* w = w - r1 */\
    __eor(t1, t4) /* u = u ^ v */\
    __eor(t1, t0) /* u = u ^ w */\
    __mov(t0, arithx) \
    __add(t0, t1) /* z = z + u */\
    __mov(arithx, t0) 
/*
 * Algorithm 2 from
 * Hutter, M. and Tunstall, M. Constant-Time Higher-Order Boolean-to-Arithmetic Masking
 * at: https://eprint.iacr.org/2016/1023.pdf
 */

u32 testBool2Arith(u32 bx, u32* masks)
{
    u32 z,w,y,u,v;
    u32 r1=masks[0];
    u32 r2=masks[1];
    u32 s1=masks[2];
    u32 s2=masks[3];
    u32 g1=masks[4];
    u32 g2=masks[5];
    u32 a=masks[6];
    z = g1 ^ r1;
    z = z ^ g2;
    z = z ^ r2;
    u = bx ^ z;
    z = z ^ a;
    u = u + z;
    v = bx ^ g1;
    v = v ^ a;
    v = v + g1;
    w = bx ^ g2;
    w =  w ^ a;
    w = w + g2;
    z = r2 ^ s1;
    u = u ^ r2;
    u = u ^ v;
    u = u ^ w;
    v = u ^ s1;
    v = v + r2;
    w = u ^ z;
    v = v ^ w;
    w = u + z;
    z = v ^ w;
    w = a ^ r2;
    u = s2 ^ r1;
    u = u - w;
    w = w ^ s2;
    v = w ^ r1;
    w = w - r1;
    u = u ^ v;
    u = u ^ w;
    z = z + u;
    return z;
}
u32 Bool2Arith(u32 bx, u32* masks)
{
    u32 ax=0;
    asm volatile (
            "push {r0-r5}\n\t"
            "bl starttrigger\n\t"
            "pop {r0-r5}\n\t"
            "movs r7, r7\n\t"
            "movs r7, r7\n\t"
   /*         "movs r4, #0\n\t"
            "movs r3, #0\n\t"
            "movs r2, #0\n\t"
            "movs r1, #0\n\t"
            "movs r0, #0\n\t"*/
            "movs r7, r7\n\t"
            "movs r7, r7\n\t"
            __Bool2Arith(%[bx],%[ax],%[masks], r0, r1, r2, r3, r4)
            "movs r7, r7\n\t"
            "movs r7, r7\n\t"
            "movs r7, r7\n\t"
            "movs r7, r7\n\t"
            "push {r0-r5}\n\t"
            "bl endtrigger\n\t"
            "pop {r0-r5}\n\t"
            : [ax] "=&r" (ax)
            : [bx] "r" (bx), [masks] "r" (masks)
            : "r0", "r1", "r2", "r3", "r4");
    return ax;
}
    
