include pixels.inc ;�������� ������� ������ �����, ���� � �������

Sinus macro gx,gy,x0,y0,IterCount
local l1
mov rx,gx
mov ry,gy
mov xdiv2,x0
mov ydiv2,y0
mov cx,IterCount ;���������� �������� �����
finit ;������������� ������������
fldz
fstp alpha

l1:
 fld alpha        ;st(0)=alpha
 fild word ptr rx            ;st(0)=gx st(1)=alpha
 fmul              ;st(0)=gx*alpha
 frndint           ;st(0)=round(gx*alpha)
 fild word ptr xdiv2         ;st(0)=xdiv2 st(1)=round(gx*alpha)
 fadd              ;st(0)=xdiv2+round(gx*alpha) - ���������� X �������!!!
 fistp word ptr xr ;������� X � ���������� ��� ������ �� �����

 fld alpha        ;st(0)=alpha
 fsin              ;st(0)=sin(alpha)
 fild word ptr ry            ;st(0)=gy st(1)=sin(alpha)
 fmul              ;st(0)=gy*sin(alpha)
 frndint           ;st(0)=round(gy*sin(alpha))
 fstp tmp          ;tmp=round(gy*sin(alpha))
 fild word ptr ydiv2         ;st(0)=ydiv2
 fsub tmp          ;st(0)=ydiv2-round(gy*sin(alpha)) - ���������� Y �������!!!
 fistp word ptr yr ;������� Y � ���������� ��� ������ �� �����

 PutPixel xr,yr,0ah ;������� ����� ������� ������

 fld delta ;��������� ����� �������� alpha
 fld alpha
 fadd
 fstp alpha
loop l1 ;���� �� cx

endm