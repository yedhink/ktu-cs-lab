.model small
.data
msg1 db 0dh,0ah,"enter two digit no = ","$"
msg2 db 0dh,0ah,"your two digit no  = ","$"
num1 db ?
num2 db ?
two db ?
.code
mov ax,@data
mov ds,ax

mov dx,offset msg1
mov ah,09h
int 21h

mov ah,01h
int 21h
sub al,30h
mov num1,al

mov ah,01h
int 21h
sub al,30h
mov num2,al

mov al,num1
mov bl,0Ah
mul bl
add al,num2
mov two,al

mov ah,00h
mov al,two
mov bl,0Ah
div bl

mov dx,offset msg2
mov ah,09h
int 21h

add al,30h
mov dl,al
mov ah,02h
int 21h

add ah,30h
mov dh,ah
mov ah,02h
int 21h

mov ah,4ch
int 21h
end
