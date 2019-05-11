.model small

Disp macro msg
mov dx,offset msg
mov ah,09h
int 21h
endm

Disp2 macro
mov dl,al
mov ah,02h
int 21h
endm

.data
arr db 5 dup(?)
msg2 db 0dh,0ah,"enter number = ","$"
m_arr db 0dh,0ah,"Your Array:",0dh,0ah,"$"
m_exit db 0dh,0ah,"Exiting...",0dh,0ah,"$"
.code
mov ax,@data
mov ds,ax

mov si,0h ; counter for arr indexes
read : cmp si,05H ; check if we are over arr length
       jz write
       Disp msg2
       mov ah,01H ; read from console
       int 21H
       mov arr[si],al
       inc si
       jmp read


; display array
write : mov si,0h ; counter for arr indexes
        Disp m_arr
        jmp inner
        inner : cmp si,05H ; check if we are over arr length
                jz exit1
                mov al,arr[si]
                Disp2
                inc si
                jmp inner

exit1 : Disp m_exit
        mov ah,4ch
        int 21h
        end

