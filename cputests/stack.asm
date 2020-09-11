	ORG 0

start:	loadi r0,1
	loadi r1,2
	loadi r2,3
	loadi r3,4
	loadi r4,5
	loadi r5,6
	loadi r6,7
	loadi r7,0x80
	pushmulti r7,0x7f
	clear r0
	clear r1
	clear r2
	clear r3
	clear r4
	clear r5
	clear r6
	popmulti r7,0x7f
	pushmulti r7,0x7f
	pushquick r7,r4
	popquick r4,r7
hop:	jump hop

	END
