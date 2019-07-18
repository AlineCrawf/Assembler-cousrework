include pixels.inc ;содержит макросы вывода точки, осей и символа

Spiral macro mas,x0,y0,color,itersCount ;mas - масштаб, x0,y0 - центр, ItersCount - кол-во итераций (длина спирали)
local l1
mov divK,mas
mov xdiv2,x0
mov ydiv2,y0
mov cx,itersCount ;количество итераций цикла - 5*Pi/0.001
finit ;инициализация сопроцессора
fldz
fstp alpha ;обнуление alpha

l1:
 fld alpha        ;тут все просто
 fcos             ;ф-лы x=round(alpha*DivK*cos(alpha))
 fstp tmp
 fld alpha        ;y=round(alpha*DivK*sin(alpha))
 fild word ptr divK 
 fmul
 fmul tmp              
 frndint           
 fild word ptr xdiv2         
 fadd              
 fistp word ptr xr ;заносим X в переменную для вывода на экран

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
 fistp word ptr yr ;заносим Y в переменную для вывода на экран

 PutPixel xr,yr,0ah ;выводим точку зеленым цветом

 fld delta ;вычисляем новое значение alpha
 fld alpha
 fadd
 fstp alpha
loop l1 ;цикл по cx

endm
