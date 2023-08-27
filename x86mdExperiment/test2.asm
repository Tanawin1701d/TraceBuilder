; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;     nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _start

          section   .text
_start:
           mov r8, 3
           mov r9, 4
           add r8, r9
           push r8
           pop  r8
           mov rax, 60
           mov rdi, 0
           syscall