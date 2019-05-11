.model small

Disp macro msg
mov dx,offset msg
mov ah,09h
int 21h
endm

Disp2 macro num
mov al,num
mov dl,al
mov ah,02h
int 21h
endm

.data
arr db 10 dup(?)
msg1 db 0dh,0ah,"element = ","$"
m_l db 0dh,0ah,"largest = ","$"
m_s db 0dh,0ah,"smallest = ","$"
small db ?
large db ?
.code
mov ax,@data
mov ds,ax

mov cl,05h
mov si,0h ; initialize counter as 0
read : 
       Disp msg1
       mov ah,01h
       int 21h
       mov arr[si],al
       inc si
       loop read

write : 
        mov large,0H
        mov small,99h
        mov si,0h
        inner :
            cmp si,05h
            jz exit
            mov al,arr[si]
            cmp al,small
            jc is_small
            small_return:
                cmp al,large
                jnc is_large
            large_return:
                inc si
            jmp inner

is_small :
        mov small,al
        jmp small_return

is_large :
        mov large,al
        jmp large_return

exit :  
    Disp m_l
    Disp2 large
    Disp m_s
    Disp2 small
    mov ah,4ch
    int 21h
    end