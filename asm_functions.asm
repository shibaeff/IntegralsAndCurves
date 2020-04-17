extern printf

global asm_hello
section .rodata
    string db `Hello\n`, 0
    c1 dq 0.6
    c2 dq 3.0
    c3 dq -2.0
    c4 dq -1.0
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


    fld qword[ebp+8]
    fld qword[c1]
    fmul
    fld qword[c2]
    fadd
;	fld	qword[c2]
;	faddp	st1, st0

    leave
    ret

global df1
df1:
    push ebp
    mov ebp, esp
    finit
    fld qword[c1]
    leave
    ret

global f2
f2:
    push ebp
    mov ebp ,esp
    finit
    fld qword[ebp + 8]
    fld qword[c3]
    fadd
    fst qword[ebp-8]
    fld qword[ebp-8]
    fmulp
    fld  qword[ebp-8]
    fmulp
    fld qword[c4]
    faddp
    leave
    ret

global df2:
df2:
    push ebp
    mov ebp, esp
    fld qword[ebp + 8]
    fld qword[c3]
    faddp

    fld st0
    fmulp

    fld qword[c2]
    fmul
    leave
    ret

global f3
f3:
    push ebp
    mov ebp, esp

    fld qword[c2]
    fld qword[ebp + 8]
    fdiv
    leave
    ret

global df3
df3:
    push ebp
    mov ebp, esp

    fld1
    fld qword[ebp + 8]

    fdivp
    fld qword[ebp + 8]
    fdivp
    fld qword[c2]
    fmul
    fchs
    leave
    ret