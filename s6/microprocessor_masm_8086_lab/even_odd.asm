.model small

Disp macro msg
mov dx,offset msg
mov ah,09h
int 21h
endm

Disp2 macro num
mov al,num
mov dx,al
mov ah,02h
int 21h
endm

Readno macro
mov ah,01
int 21h
endm

.data
arr db 10 dup(?)
m_inp db 0dh,0ah,"Enter num = ","$"
m_even db 0dh,0ah,"Even no = ","$"
m_odd db 0dh,0ah,"Odd no = ","$"
result db ?

.code
mov ax,@data
mov ds,ax

mov si,0h
mov cx,6h
read:
	Disp m_inp
	Readno
	mov arr[si],al
	inc si
	loop read

write:
	mov si,0h
	traverse:
		mov ah,0
		mov al,arr[si]
		mov result,al
		mov bl,02h
		div bl
		cmp ah,0h
		jz is_even
		jnz is_odd
		back:
			inc si
			cmp si,6h
			jz exit
			jmp traverse
is_even:
	Disp m_even
	Disp2 result
	jmp back

is_odd:
	Disp m_odd
	Disp2 result
	jmp back

exit:
	mov ah,4ch
	int 21h
	end
