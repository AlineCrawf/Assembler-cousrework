
AsciiToBin	macro
	xor	di,di
	xor	ax,ax
	mov	cl,act
	xor	ch,ch
	xor	bx,bx
	mov	si,cx
	mov	cl,10
asc2hex:
	mov	bl,byte	ptr field[di]
	sub	bl,'0'
	jb	asc_err
	cmp	bl,'9'
	ja	asc_err
	mul	cx
	add	ax,bx
	inc	di
	cmp	di,si
	jb	asc2hex
	ret
asc_err:
	mov	dx,offset err_msg
	writeString
	mov	dx,offset MsgUpExit
	writeString
	waitPressing
	ExitProgram
endm

BinToAscii	macro
	mov	cx,L			; output line size
Fill_Buff:
	mov	byte ptr[bx],' '
	inc	bx
	loop	Fill_Buff
	mov	si,10
Cld_Dvd:
	xor	dx,dx
	div	si
	add	dx,'0'
	dec	bx
	mov	byte ptr[bx],dl		;char to buf
	inc	cx
	or	ax,ax
	jnz	Cld_Dvd
	ret
endm

readString	macro
	push	ax
	mov	dx,offset buffer
	mov	ah,0ch
	mov	al,0ah
	int	21h
	xor	ch,ch
	mov	cl,act
	add	dx,2
	pop	ax
	ret
endm

writeString	macro
	push	ax
	mov	ah,09h
	int	21h
	pop	ax
	ret
endm
waitPressing	macro
	push	ax
	mov	ah,8
	int	21h
	pop	ax
	ret
endm

ExitProgram	macro
	mov	ax,4c00h
	int	21h
	ret
endm

; out msg and put value from console to value 
EnterValue macro value,	msg
	pusha
	mov	dx, offset msg
	writeString
	readString
	AsciiToBin
	mov	value,ax
	mov	dx,offset nextLine
	writeString
	popa
endm