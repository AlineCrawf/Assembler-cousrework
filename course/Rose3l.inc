include pixels.inc ;�������� ������� ������ �����, ���� � �������

Rose3l macro mas,x0,y0,color ;mas - �������, x0,y0 - �����
local l1
mov divK,mas
mov xdiv2,x0
mov ydiv2,y0
mov cx,188ch ;���������� �������� ����� - (2*pi)/0.001
finit ;������������� ������������
fldz
fstp alpha ;��������� alpha

l1:
 fld alpha         ;�-�� r=10*sin(3*alpha)
 fmul x3
 fsin
 fmul x10
 fstp tmp
 fld alpha
 fcos
 fild word ptr divK
 fmul
 fmul tmp            
 frndint           
 fild word ptr xdiv2         
 fadd              
 fistp word ptr xr 

 fld alpha
 fsin
 fild word ptr divK
 fmul
 fmul tmp              
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