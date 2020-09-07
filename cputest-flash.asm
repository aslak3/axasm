		ORG 0

start:		clear r0		; current delay
		loadi r1,0x1000		; max delay
		loadi r2,0x100		; step
		loadi r3,0x0200
		loadi r4,0x1234
		loadi r5,0x8000
		loadi r6,0x0000
		loadi r7,0x100

		storer r3,r4

oloop:		copy r0,r1		; grab the current maxdelay in r1
iloop:		dec r0			; -1
		branchnz iloop		; back for more?
;		sub r1,r2		; decrease max delay by step
		inc r4			; inc counter
		storer r3,r4		; show counter
		inc r5
		inc r6
		add r6,r7
		storer r5,r6
		branch oloop		; back again

		END
