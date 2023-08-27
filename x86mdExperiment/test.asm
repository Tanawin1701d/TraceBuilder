; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;     nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _start

          section   .text
_start:
           ; //////////////////////////////////////////////////////////////////////////
           ;  add and
           mov      rax, myNumber           ; rax is address to the number
           mov      rcx, zeroNumber         ; rcx is address to the data number zero
           mov      rbx, 0                  ; rbx is alway zero
           mov      rdx, allone              ; mov to all one
           mov      r8 , 1                  ; mov 1

          ; ADC (add with carry)
          adc       [rax], rbx               ; ADC mem,reg64   X86_64,LONG
          adc qword [rax], 0                 ; ADC rm64, imm
          adc       rax,   [rcx]             ; ADC reg64,rm  X86_64,LONG
          adc       rax,   rbx               ; ADC reg64,reg64 X86_64,LONG
          adc       rbx,   0                 ; ADC rm64,imm8  X86_64,LONG
          ; ADD (add with out carry)
          add       [rax], rbx               ; ADD mem,reg64   X86_64,LONG
          add qword [rax], 0                 ; ADD rm64, reg64
          add       rax,   [rcx]             ; ADD reg64,mem  X86_64,LONG
          add       rax,   rbx               ; ADD reg64,reg64 X86_64,LONG
          add       rbx,   0                 ; ADD rm64,imm8  X86_64,LONG
          ; AND (and)
          and       [rax], rdx               ; ADD mem,reg64   X86_64,LONG
          and qword [rax], 0                 ; AND rm64, imm x86_64
          and       rax,   [rdx]             ; ADD reg64,mem  X86_64,LONG
          and       rax,   rax               ; ADD reg64,reg64 X86_64,LONG
          and       rbx,   0                 ; ADD rm64,imm8  X86_64,LONG
          ; CALL

           ; //////////////////////////////////////////////////////////////////////////
          ; div
          mov       rax ,  10
          mov       rcx ,  1
          xor       rdx , rdx
          div       rcx
          ; div using memory
          mov       rax, 10
          mov       qword [myNumber], 1
          xor       rdx, rdx
          mov       rbx, myNumber
          div       qword [rbx]
          ; idiv
          mov       rax ,  10
          mov       rcx ,  1
          xor       rdx , rdx
          idiv       rcx
          ; idiv using memory
          mov       rax, 10
          mov       qword [myNumber], 1
          xor       rdx, rdx
          mov       rbx, myNumber
          div       qword [rbx]
          ;//////////////////////////////////////////////////////////////////////////
          ; multiplier
          xor       rax, rax
          xor       rbx, rbx
          xor       rcx, rcx
          xor       rdx, rdx
          mov       rbx, myNumber

          ; single operand
          imul      rax
          imul      qword [rbx + rax]
          imul      rax, [rbx + rax]
          ; double
          imul      rax, rax
          imul      rax, 5
          ; triple operand
          ; sub


          mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rsi, message            ; address of string to output
          mov       rdx, 13                 ; number of bytes
          syscall                           ; invoke operating system to do the write
          mov       rax, 60                 ; system call for exit
          xor       rdi, rdi                ; exit code 0
          syscall                           ; invoke operating system to exit

          section   .data
message:    db      "Hello, World", 10      ; note the newline at the end
myNumber:   dq      1234                    ; number in double word
zeroNumber: dq      0                       ; zero number
allone:     dq      0xFFFFFFFFFFFFFFFF      ; fill all bit