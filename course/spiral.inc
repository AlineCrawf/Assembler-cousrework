include pixels.inc ;�������� ������� ������ �����, ���� � �������

Spiral macro mas,x0,y0,color,itersCount ;mas - �������, x0,y0 - �����, ItersCount - ���-�� �������� (����� �������)
local l1
mov divK,mas
mov xdiv2,x0
mov ydiv2,y0
mov cx,itersCount ;���������� �������� ����� - 5*Pi/0.001
finit ;������������� ������������
fldz
fstp alpha ;��������� alpha

l1:
 fld alpha        ;��� ��� ������
 fcos             ;�-�� x=round(alpha*DivK*cos(alpha))
 fstp tmp
 fld alpha        ;y=round(alpha*DivK*sin(alpha))
 fild word ptr divK 
 fmul
 fmul tmp              
 frndint           
 fild word ptr xdiv2         
 fadd              
 fistp word ptr xr ;������� X � ���������� ��� ������ �� �����

 fld alpha        
 fsin              
 fstp tmp
 fld alpha        
 fild word ptr divK 
 fmul
 fmul tmp              
 frndint           
 fstp tmp          
 fild word ptr ydiv2         
 fsub tmp          
 fistp word ptr yr ;������� Y � ���������� ��� ������ �� �����

 PutPixel xr,yr,0ah ;������� ����� ������� ������

 fld delta ;��������� ����� �������� alpha
 fld alpha
 fadd
 fstp alpha
loop l1 ;���� �� cx

endm
