;������ ������ ������� � ����������� ������ (char - ASCII ��� �������)
OutCharG macro x,y,color,char
pusha
mov ah,02h
mov bh,0h
mov dh,y
mov dl,x
int 10h
mov ah,09h
mov al,char
mov bh,0h
mov bl,color
mov cx,01h
int 10h
popa
endm
;----------------------------------------------------------
;������ ������ ������
OutStr macro x,y,str,strLen,color
local l3
pusha
xor cx,cx
mov cl,strLen
mov bx,0
l3:
 mov al,str[bx]
 inc bx
 add bx,x
 OutCharG bl,y,color,al
 sub bx,x
loop l3
popa
endm
;----------------------------------------------------------
;������ ������ ������� �� ����� � �����. x,y � ������ color
PutPixel macro x,y,color 
pusha
mov ah,0ch
mov al,color
mov bh,0h
mov cx,x
mov dx,y
int 10h
popa
endm
;---------------------------------------------------------
;������ ������ �������������� ����� � �������� ������ 
AxleX macro x1,x2,y,color
local iter
pusha
mov cx,x2
iter:
 mov dx,cx
 PutPixel cx,y,color
 dec cx
 cmp cx,x1
jge iter
popa
endm
;---------------------------------------------------------
;������ ������ ������������ ����� � ������� X
AxleY macro x,y1,y2,color
local iter1
pusha
mov cx,y2
iter1:
 mov dx,cx
 PutPixel x,dx,color
 dec cx
 cmp cx,y1
jge iter1
popa
endm
;----------------------------------------------------------
 

