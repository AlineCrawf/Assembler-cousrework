include pixels.inc ;�������� ������� ������ �����, ���� � �������

Circle macro x0,y0,x1,y1,color ;x0,y0 - �����, x1,y1 - �������, color - ����
local l1
mov rx,x1
mov ry,y1
mov xdiv2,x0
mov ydiv2,y0
mov cx,188ch ;���������� �������� ����� - (2*pi)/0.001
finit ;������������� ������������
fldz
fstp alpha

l1:
 fld alpha        ;�-��: x=round(rx*cos(alpha))
 fcos	        ;y=round(ry*sin(alpha))
 fild word ptr rx            
 fmul              
 frndint           
 fild word ptr xdiv2         
 fadd              
 fistp word ptr xr 

 fld alpha         
 fsin              
 fild word ptr ry            
 fmul              
 frndint           
 fstp tmp          
 fild word ptr ydiv2         
 fsub tmp          
 fistp word ptr yr 

 PutPixel xr,yr,color ;������� ����� ������� ������

 fld delta ;��������� ����� �������� alpha
 fld alpha
 fadd
 fstp alpha
loop l1 ;���� �� cx

endm
