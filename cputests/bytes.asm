	ORG 0

start:	loadibu r0,0xff34	; 0xff will be discarded
	loadi r1,0x7e
	storerdb r1,r0,1
	loadi r0,0x12
	loadi r1,0x7e
	storerdb r1,r0,0	; 0x1234 in 0x7e

	loadi r1,0x7f
	loadrbu r0,r1
	storeib 0x6e,r0
	loadi r1,0x7e
	loadrbu r0,r1
	storeib 0x6f,r0		; 0x3412 in 0x6e

	loadi r1,(foo*2)	; assembler deals only in words
	loadrdbs r0,r1,1	; load low half of foo, sign ext
	storeiw 0x5e,r0		; should write 0xff80 a in 5e

	; contrived byte-wise copy
	loadi r1,(mess*2)	; start of source
	loadi r2,0x64		; destination
loop:	loadrbu r0,r1		; read one byte
	storerb r2,r0		; store one byte
	inc r1			; increment along one byte
	inc r2			; same for destination
	cmpi r0,0		; look for 0
	branchnz loop		; back if not yet 0

hop:	jump hop
foo:	dw 0x0080
mess:	dw 0x1234
	dw 0x5678
	dw 0x9000

	END
