extern printf

global asm_hello
section .rodata
    string db `Hello\n`, 0
    c1 dq 0.6
    c2 dq 3
section .text

asm_hello:
    push ebp
    mov ebp, esp
    and esp, -16
    add esp, 4
    push string
    call printf
    xor eax, eax
    leave
    ret

global f1
f1:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp + 8]
    fld qword[c1]
    fmul
    fld qword[c2]
    fadd
    leave
    ret