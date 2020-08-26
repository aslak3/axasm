		ORG 0

start:		clear r0		; current delay
		clear r1		; max delay
		loadi r2,0x1000		; step
on:		led 1			; turn the led on with an opcode!
		copy r0,r1		; grab the current maxdelay in r1
onloop:		dec r0			; -1
		jumpnz onloop		; back for more?
off:		led 0			; led off
		copy r0,r1		; grab the current maxdelay again
offloop:	dec r0			; -1
		jumpnz offloop		; back for more
		sub r1,r2		; decrease max delay by step
		jumpa on		; back again

		END
