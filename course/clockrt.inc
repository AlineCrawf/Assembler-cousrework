;---------------------------------------------------------------------------
;������ ���������� ����������� ����� (16-����) �� ����� � ������ �� �� �����
Decomposition macro time 
mov bh,time ;������������ bx
mov bl,time
and bh,11110000b
shr bh,4h
and bl,00001111b
endm
;-------------------------------------
Delay macro time ;������ ������� � ���
local ext,iter
push cx
mov cx,time
ext:
push cx
mov cx,5000
iter:
loop iter
pop cx
loop ext
pop cx
endm