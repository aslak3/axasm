	ORG 0

start:	clear r0
	loadi r1,1
	loadi r3,fib
	loadi r4,0xe
loop:	copy r2,r1
	add r1,r0
	copy r0,r2
	storer r3,r1
	inc r3
	dec r4
	branchnz loop
hop:	brancha hop

fib:
	END
