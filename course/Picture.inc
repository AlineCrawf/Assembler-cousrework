include	pixels.inc
include	rose3l.inc
include	spiral.inc
include	circle.inc
include	sinus.inc
include	line.inc

StartDraw macro
	local	l2,neI,next
	pusha
	mov	ah,0h
	mov	al,12h
	int	10h

	pusha
	mov	cx,80
	mov	bx,0
l2:
	mov	al,AboutMe[bx]
	cmp	bx,21
	jb	neI
	cmp	bx,58
	jg	neI
	OutCharG bl,1,0ch,al
	jmp	next
neI:
	OutCharG  bl,1,3h,al
next:
	inc	bx
	loop	l2
popa
endm

Picture macro
	pusha
	Spiral 3,60,60,14,13000
	Rose3l 10,320,240,12
	Rose3l 9,320,240,12
	Rose3l 8,320,240,12
	Rose3l 7,320,240,12
	Rose3l 6,320,240,12
	Rose3l 5,320,240,12
	Rose3l 4,320,240,12
	Rose3l 3,320,240,12
	Rose3l 2,320,240,12
	Rose3l 1,320,240,12
	Circle 320,240,15,15,4
	Spiral 1,320,240,13,12000
	Sinus 30,15,0,420,320*65
	Sinus 30,15,0,400,320*65
	Sinus 30,15,0,440,320*65
	AxleY	320,340,415,10
	popa
endm