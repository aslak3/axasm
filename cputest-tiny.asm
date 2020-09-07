	ORG 0

start:	loadi r0,0x1234
	loadi r1,0x0200
	storer r1,r0
hop:	jump hop

	END
