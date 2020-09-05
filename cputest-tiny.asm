	ORG 0

start:	loadi r0,0x1000
	loadi r1,0x0400
	storer r1, r0
hop:	jumpa hop

	END
