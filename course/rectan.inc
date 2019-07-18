;------------------------------------------------------------
;Put pixel on screen
Pixel macro x,y,color 
	pusha
	mov ah,0ch
	mov al,color
	mov bh,0h
	mov cx,x
	mov dx,y
	int 10h
	popa
endm
;-------------------------------------------------------------
;draws a vertical line
Vertical macro x,y1,y2,color
	local iter1
	pusha
	mov cx,y2
iter1:
	mov dx,cx
	Pixel x,dx,color
	dec cx
	cmp cx,y1
	jge iter1
	popa
endm
;--------------------------------------------------------------
; draws horizontal line
Horizontal macro x1,x2,y,color
	local iter
	pusha
	mov cx,x2
iter:
	mov dx,cx
	Pixel cx,y,color
	dec cx
	cmp cx,x1
	jge iter
	popa
endm
;--------------------------------------------------------------
Fill	macro x0,y0,x1,y1,color
	local	lp1
	pusha
	mov	di,y0
	mov	ax,x0
	add	ax,1
	mov	bx,x1
	sub	bx,1
	mov	si,y1
	sub	si,1

lp1:
	inc	di
	Horizontal  ax,bx,di,color
	cmp	di,si
	jne	 lp1
	popa
endm
; draw a rectangle
Rectangle macro x0,y0,x1,y1,outCol,innerCol    ; outCol - colour of outline, innerCol - fill colour
	local notFill
	pusha
	Horizontal x0,x1,y0,outCol
	Vertical x0,y0,y1,outCol
	Vertical x1,y0,y1,outCol
	Horizontal x0,x1,y1,outCol
	cmp	innerCol,0
	je notFill
	Fill x0,y0,x1,y1,innerCol
notFill:	
	popa
endm

