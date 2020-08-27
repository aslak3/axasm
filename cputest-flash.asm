		ORG 0

start:		clear r0		; current delay
		loadi r1,0x0400		; max delay
		loadi r2,0x1000		; step
		loadi r3,0xffff
		clear r4
		loadi r5,0xfffe
		clear r6
		storer r5,r6

on:		storer r3,r4		; turn the led on with an opcode!
		copy r0,r1		; grab the current maxdelay in r1
onloop:		dec r0			; -1
		branchnz onloop		; back for more?
		not r4
off:		storer r3,r4		; led off
		copy r0,r1		; grab the current maxdelay again
offloop:	dec r0			; -1
		branchnz offloop	; back for more
		not r4
;		sub r1,r2		; decrease max delay by step
		inc r6
		storer r5,r6
		brancha on		; back again

		END
