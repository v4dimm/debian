global _start

section .data
matrix db '1', '2','3', '4', '5', '6', '7', '8', '9'
matrix_len equ $ - matrix

section .text
_start: mov eax, 0  ; номер строки
mov ebx,0			; номер столбца

again:
 mov edx, eax 
 add edx, eax 
 add edx, eax 
 mov edi, ebx 
 add edi, ebx 
 add edi, ebx 

 mov cl, [matrix + edx + ebx]
 push ecx
 mov cl, [matrix + edi + eax]
 mov [matrix + edx + ebx], cl
 xor ecx, ecx
 pop ecx
 mov [matrix + edi + eax], cl
 inc ebx
 cmp ebx, 3
 jl again
 inc eax
 mov ebx, eax
 inc ebx
 cmp eax, 2		
 jl again		

 ; вывод в терминале результата
 mov eax, 4
 mov ebx, 1
 mov ecx, matrix
 mov edx, 9
 int 80h

 mov eax, 1
 mov ebx, 0
 int 80h