section .text
global _start

_start:
    ; Unconditional jump to label loop
    mov ecx, 20
    jmp loop

    ; Print "Hello, world!"
    mov eax, 4
    mov ebx, 1
    mov ecx, message
    mov edx, message_len
    int 0x80

loop:
    ; Increment ecx register
    dec ecx

    ; Compare ecx to the value 10
    cmp ecx, 10

    ; If ecx is less than 10, jump to label loop
    jl loop

    ; Jump to address stored in ebx register
    mov ebx, viewAddress
    jmp [ebx]

    ; This code will never be executed
    mov eax, 1
    xor ebx, ebx
    syscall

viewn:
    mov eax, 0 ; interrupt code
    mov ebx, 0 ; argument, in this case: return value
    syscall

section .data
    message db "Hello, world!", 0xa
    message_len equ $-message
    address dd _start
    viewAddress dd viewn
