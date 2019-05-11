.model small
.data
msg db "enter first num : ","$"
msg1 db 0AH,"enter 2nd num   : ","$"
msg2  db 0AH,"sum             : ","$"
.code
mov ax,@data
mov ds,ax

mov dx,offset msg
mov ah,09H
int 21H

mov ah,01h
int 21h

mov bl,al
sub bl,30h

mov dx,offset msg1
mov ah,09h
int 21h

mov ah,01h
int 21h
sub al,30h

add al,bl
add al,30h

mov dx,offset msg2
mov ah,09h
int 21h

mov dl,al
mov ah,02h
int 21h

mov ah,4ch
int 21h
end
