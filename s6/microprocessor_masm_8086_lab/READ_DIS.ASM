.model small
.data
r_msg db "enter number : ","$"
d_msg db 0AH,"the no you entered : ","$"
.code
mov ax,@data
mov ds,ax

mov dx,offset r_msg
mov ah,09H
int 21H

mov ah,01H
int 21H

mov dx,offset d_msg
mov ah,09H
int 21H

mov dl,al

mov ah,02H
int 21H

mov ah,4CH
int 21H
end
