#ifndef _SOLO_ASM_INC
#define _SOLO_ASM_INC
#include <stdio.h>
#include <stdlib.h>
#include <soloasm.h>

// We assume the first ORG is the lowest address
#define ORG(n) unsigned int genasm(int _solo_pass) { \
   unsigned _solo_add=n;\
   _solo_info.psize=16; \
   _solo_info.begin=n; \
   _solo_info.memsize=0xFFFF; \
   _solo_info.ary=malloc(_solo_info.memsize)


#define REORG(n) _solo_add=n;
#define END _solo_info.end=_solo_add-1; return _solo_add; }

#define DEFLABEL(l) static unsigned l
#define LABEL(l) l=_solo_add

#define DW(n) _solo_info.ary[_solo_add++]=(n&0xffff)

#define r0 0
#define r1 1
#define r2 2
#define r3 3
#define r4 4
#define r5 5
#define r6 6
#define r7 6

#define NOP DW(0)

#define JUMPA(i) DW(0x0008);DW(i)
#define JUMPC(i) DW(0x000b);DW(i)
#define JUMPNC(i) DW(0x000a);DW(i)
#define JUMPZ(i) DW(0x000d);DW(i)
#define JUMPNZ(i) DW(0x000c);DW(i)
#define JUMPN(i) DW(0x000f);DW(i)
#define JUMPNN(i) DW(0x000e);DW(i)

#define _BRANCH(a) (( (a)-_solo_add ))

#define BRANCHA(i) DW(0x0018);DW(_BRANCH(i))
#define BRANCHC(i) DW(0x001b);DW(_BRANCH(i))
#define BRANCHNC(i) DW(0x001a);DW(_BRANCH(i))
#define BRANCHZ(i) DW(0x001d);DW(_BRANCH(i))
#define BRANCHNZ(i) DW(0x001c);DW(_BRANCH(i))
#define BRANCHN(i) DW(0x001f);DW(_BRANCH(i))
#define BRANCHNN(i) DW(0x001e);DW(_BRANCH(i))

#define LOADI(d,i) DW(0x0010+((d)&7)); DW(i)
#define STOREI(i,s) DW(0x0020+((s)&7)); DW(i)
#define CLEAR(d) DW(0x0030+((d)&7));
#define LOADR(d,s) DW(0x0040+(((s)&7)<<3)+((d)&7))
#define STORER(d,s) DW(0x0080+(((d)&7)<<3)+((s)&7))
#define LED(o) DW(0x00c0+((o)&1))
#define ADD(d,s) DW(0x1000+(((s)&7)<<3)+((d)&7))
#define ADDC(d,s) DW(0x1100+(((s)&7)<<3)+((d)&7))
#define SUB(d,s) DW(0x1200+(((s)&7)<<3)+((d)&7))
#define SUBC(d,s) DW(0x1300+(((s)&7)<<3)+((d)&7))
#define INC(d) DW(0x1400+((d)&7))
#define DEC(d) DW(0x1500+((d)&7))
#define AND(d,s) DW(0x1600+(((s)&7)<<3)+((d)&7))
#define OR(d,s) DW(0x1700+(((s)&7)<<3)+((d)&7))
#define XOR(d,s) DW(0x1800+(((s)&7)<<3)+((d)&7))
#define NOT(d) DW(0x1900+((d)&7))
#define LEFT(d) DW(0x1a00+((d)&7))
#define RIGHT(d) DW(0x1b00+((d)&7))
#define COPY(d,s) DW(0x1c00+(((s)&7)<<3)+((d)&7))

#endif
