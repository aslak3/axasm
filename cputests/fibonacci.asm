	ORG 0

	loadi r0,0xf00f		; canary - r0 is a bomb
	loadi r7,0x40		; stack pointer(!)
	callbranch outter	; call the outter sub
hop:	branch hop		; on return, hop

outter:	calljump start		; call the inner
	return			; back to "main"

start:	clear r5		; the running total
	loadi r1,foo		; r1 will be the intial value
	loadrd r1,r1,1		; initial value
	loadi r3,0		; destination counter
	loadi r4,length		; space for our fibs
	loadr r4,r4		; load it
	pushquick r7,r4
	clear r4
	popquick r4,r7
loop:	copy r2,r1		; copy the last written value
	add r1,r5		; accumulate
	branchc done		; overflow? out
	copy r5,r2		; copy it back over the running total
	storerd r3,r1,fib  	; save it in fib table using dest counter
	addi r3,1		; increment alternative
	dec r4			; decrement the space for fibs counter
	branchnz loop		; back if we have more room
done:	loadi r5,0x2a2a		; just so we can test storei
	storei 0x003b,r5		; ...
	loadi r5,0xaa55		; and storer
	loadi r1,0x003a		; ...
	storer r1,r5		; ...
foo:	return			; finished inner sub
	dw 1			; the initial value
length:	dw 0x3a-fib		; and the length

fib:
	END
