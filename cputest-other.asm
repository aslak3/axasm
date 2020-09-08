		ORG 0

start:		loadi r0,0xf00f		; canary
		loadi r1,0x8000		; start of video memory

		loadi r7,0x40		; stack pointer

loop:		calljump printmessage	; call sub
		loadi r2,0x8000		; delay
delay:		dec r2			; dec delay
		jumpnz delay		; more delay
		jump loop		; more printing

printmessage:	loadi r2,message	; get start of message in r2
messageloop:	loadr r3,r2		; get this letter in r3
		inc r2			; next letter
		storer r1,r3		; write letter
		inc r1			; inc video pointer
		xori r1,0x8000		; flip the top bit
		storei 0x200,r1		; put the address-8000 on the lcd
		xori r1,0x8000		; flip it back
		cmpi r3,0		; check letter for 0
		jumpnz messageloop	; not zero? back for more
printmessageo:	return

message:	dw 0x480f		; H
		dw 0x650f		; e
		dw 0x6c0f		; l
		dw 0x6c0f		; l
		dw 0x6f0f		; o
		dw 0x200f		; ' '
		dw 0

		END
