	ORG 0

start:	loadi r0,1
	loadi r1,0xffff
	storer r1, r0
hop:	jumpa hop

	END
