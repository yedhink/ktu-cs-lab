.model small
.data
msg db "helloworld","$"
.code
mov ax,@data
mov ds,ax
mov dx,offset msg
mov ah,09H
int 21H
mov ah,4CH
int 21H
end
