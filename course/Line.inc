include pixels.inc ;�������� ������� ������ �����, ���� � �������

Line macro x,y,xk,yk
local l1,l2,l3
pusha
mov x1,x
mov x2,xk
mov y1,y
mov y2,yk
mov ax,x1
mov bx,x2
cmp ax,bx
jg l2
mov xdiv2,x
mov ydiv2,y
mov ax,xk
sub ax,x
mov bx,y
sub bx,yk
jmp l3
l2:
 mov xdiv2,xk
 mov ydiv2,yk
 mov ax,x
 sub ax,xk
 mov bx,yk
 sub bx,y
l3:
mov rx,ax
mov ry,bx
finit ;������������� ������������
fild word ptr ry
fild word ptr rx
fdiv
fstp tmp

mov ax,rx
mov bx,100
mul bx
mov cx,ax
finit ;������������� ������������
fldz
fstp alpha

l1:
 fld alpha        ;st(0)=alpha
 frndint           ;st(0)=round(gx*alpha)
 fild word ptr xdiv2         ;st(0)=xdiv2 st(1)=round(gx*alpha)
 fadd              ;st(0)=xdiv2+round(gx*alpha) - ���������� X �������!!!
 fistp word ptr xr ;������� X � ���������� ��� ������ �� �����

 fld alpha        ;st(0)=alpha
 fld tmp
 fmul              ;st(0)=gy*sin(alpha)
 frndint           ;st(0)=round(gy*sin(alpha))
 fstp tmp2          ;tmp=round(gy*sin(alpha))
 fild word ptr ydiv2         ;st(0)=ydiv2
 fsub tmp2          ;st(0)=ydiv2-round(gy*sin(alpha)) - ���������� Y �������!!!
 fistp word ptr yr ;������� Y � ���������� ��� ������ �� �����

 PutPixel xr,yr,0ah ;������� ����� ������� ������

 fld delta2 ;��������� ����� �������� alpha
 fld alpha
 fadd
 fstp alpha
loop l1 ;���� �� cx

endm