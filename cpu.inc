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
#define r7 7

#define NOP DW(0)

#define JUMP(i)		DW(0x0800);DW(_JUMP(i))
#define JUMPNZ(i)	DW(0x0800+0b010010000);DW(_JUMP(i))
#define JUMPC(i)	DW(0x0800+0b100100100);DW(_JUMP(i)i)

#define _JUMP(a) (a<<1)
#define _BRANCH(a) ((((a)-_solo_add)<<1))

#define BRANCH(i)	DW(0x0c00);DW(_BRANCH(i))
#define BRANCHNZ(i)	DW(0x0c00+0b010010000);DW(_BRANCH(i))
#define BRANCHC(i)	DW(0x0c00+0b100100100);DW(_BRANCH(i))

#define LOADI			LOADIW
#define STOREI			STOREIW
#define LOADR			LOADRW
#define STORER			STORERW
#define LOADRD			LOADRDW
#define STORERD			STORERDW

#define LOADIW(d,i)		LOADI_ROOT(0b00,d,i)
#define LOADIBU(d,i)		LOADI_ROOT(0b10,d,i)
#define LOADIBS(d,i)		LOADI_ROOT(0b11,d,i)
#define STOREIW(i,s)		STOREI_ROOT(0b00,i,s)
#define STOREIB(i,s)		STOREI_ROOT(0b10,i,s)
#define LOADRBW(d,s)		LOADR_ROOT(0b00,d,s)
#define LOADRBU(d,s)		LOADR_ROOT(0b10,d,s)
#define LOADRBS(d,s)		LOADR_ROOT(0b11,d,s)
#define STORERW(d,s)		STORER_ROOT(0b00,d,s)
#define STORERB(d,s)		STORER_ROOT(0b10,d,s)
#define LOADRDBW(d,s,i)		LOADR_ROOT(0b00,d,s,i)
#define LOADRDBU(d,s,i)		LOADRD_ROOT(0b10,d,s,i)
#define LOADRDBS(d,s,i)		LOADRD_ROOT(0b11,d,s,i)
#define STORERDW(d,s,i)		STORERD_ROOT(0b00,d,s,i)
#define STORERDB(d,s,i)		STORERD_ROOT(0b10,d,s,i)

#define LOADI_ROOT(w,d,i)	DW(0x2000+(((w)&3)<<8)+((d)&7)); DW(i)
#define STOREI_ROOT(w,i,s)	DW(0x2400+(((w)&3)<<8)+((s)&7)); DW(i)
#define LOADR_ROOT(w,d,s)	DW(0x2800+(((w)&3)<<8)+(((s)&7)<<3)+((d)&7))
#define STORER_ROOT(w,d,s)	DW(0x2c00+(((w)&3)<<8)+(((d)&7)<<3)+((s)&7))
#define LOADRD_ROOT(w,d,s,i)	DW(0x6800+(((w)&3)<<8)+(((s)&7)<<3)+((d)&7)); DW(i)
#define STORERD_ROOT(w,d,s,i)	DW(0x6c00+(((w)&3)<<8)+(((d)&7)<<3)+((s)&7)); DW(i)

#define CLEAR(d) DW(0x3000+((d)&7));

#define ADD(d,s)	DW(0x3800+(0x0<<6)+(((s)&7)<<3)+((d)&7))
#define ADDC(d,s)	DW(0x3800+(0x1<<6)+((s)&7)<<3)+((d)&7))
#define SUB(d,s)	DW(0x3800+(0x2<<6)+(((s)&7)<<3)+((d)&7))
#define SUBC(d,s)	DW(0x3800+(0x3<<6)+(((s)&7)<<3)+((d)&7))
#define INC(d)		DW(0x3800+(0x4<<6)+((d)&7))
#define DEC(d) 		DW(0x3800+(0x5<<6)+((d)&7))
#define AND(d,s)	DW(0x3800+(0x6<<6)+(((s)&7)<<3)+((d)&7))
#define OR(d,s) 	DW(0x3800+(0x7<<6)+(((s)&7)<<3)+((d)&7))
#define XOR(d,s)	DW(0x3800+(0x8<<6)+(((s)&7)<<3)+((d)&7))
#define NOT(d) 		DW(0x3800+(0x9<<6)+((d)&7))
#define LEFT(d) 	DW(0x3800+(0xa<<6)+((d)&7))
#define RIGHT(d) 	DW(0x3800+(0xb<<6)+((d)&7))
#define COPY(d,s) 	DW(0x3800+(0xc<<6)+(((s)&7)<<3)+((d)&7))
#define NEG(d)		DW(0x3800+(0xd<<6)+((d)&7))
#define CMP(d,s) 	DW(0x3800+(0xf<<6)+(((s)&7)<<3)+((d)&7))

#define ADDI(d,i) 	DW(0x3c00+(0x0<<6)+((d)&7)); DW(i)
#define ADDCI(d,i)	DW(0x3c00+(0x1<<6)+((d)&7)); DW(i)
#define SUBI(d,i) 	DW(0x3c00+(0x2<<6)+((d)&7)); DW(i)
#define SUBCI(d,i) 	DW(0x3c00+(0x3<<6)+((d)&7)); DW(i)
#define ANDI(d,i) 	DW(0x3c00+(0x6<<6)+((d)&7)); DW(i)
#define ORI(d,i) 	DW(0x3c00+(0x7<<6)+((d)&7)); DW(i)
#define XORI(d,i) 	DW(0x3c00+(0x8<<6)+((d)&7)); DW(i)
#define COPYI(d,i) 	DW(0x3c00+(0xc<<6)+((d)&7)); DW(i)
#define CMPI(d,i) 	DW(0x3c00+(0xf<<6)+((d)&7)); DW(i)

#define CALLJUMP(i)	DW(0x4000+0b111111); DW(_JUMP(i))
#define CALLBRANCH(i)	DW(0x4400+0b111111); DW(_BRANCH(i))
#define RETURN		DW(0x4800+0b111111)

#define PUSHQUICK(d,s)	DW(0x5000+(((d)&7)<<3)+((s)&7))
#define POPQUICK(d,s)	DW(0x5400+(((s)&7)<<3)+((d)&7))
#define PUSHMULTI(d,i)	DW(0x5800+(((d)&7)<<3)); DW(i)
#define POPMULTI(s,i)	DW(0x5c00+(((s)&7)<<3)); DW(i)

#endif
