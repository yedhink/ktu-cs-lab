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

readNo macro
mov ah,01h
int 21h
sub al,30h
endm

.data
arr db 10 dup(?)
msg2 db 0dh,0ah,"enter length of arr = ","$"
msg1 db 0dh,0ah,"element = ","$"
m_p db 0dh,0ah,"Is Palindrome",0dh,0ah,"$"
m_l db 0dh,0ah,"Length = ","$"
m_np db 0dh,0ah,"Not Palindrome",0dh,0ah,"$"
num db ?
.code
mov ax,@data
mov ds,ax

Disp msg2
readNo
mov cl,al ; read total len of arr
mov num,al ; read total len of arr
mov si,0h ; initialize counter as 0
read : 
       Disp msg1
       mov ah,01h
       int 21h
       mov arr[si],al
       inc si
       loop read


; display array
write : 
        mov di,si ; counter for arr indexes
        mov si,0h
        jmp inner
        inner : 
                dec di
                mov dl,[di]
                cmp dl,00h
                jz palin
                mov al,arr[si]
                mov bl,arr[di]
                cmp al,bl
                jnz not_palin
                inc si
                jmp inner


palin : Disp m_p
        jmp exit1

not_palin : Disp m_np
            jmp exit1

exit1 : mov ah,4ch
        int 21h
        end