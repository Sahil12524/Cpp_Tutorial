; SquareAndLog.asm
; ----------------
; void Apply3(int* a, int* b, int* c,
;             void (*cb)(int*))
;
; Windows x64 calling convention:
;   RCX = a
;   RDX = b
;   R8  = c
;   R9  = cb
;
; Goal:
;   Call cb(a);
;   Call cb(b);
;   Call cb(c);
;
; Notes:
;   - RCX is first argument to cb
;   - cb pointer is in R9
;   - Maintain 16-byte stack alignment if needed

section .text
    global Apply3

Apply3:
    push rsi
    push rdi
    push rbx

    mov rsi, r9
    mov rdi, rdx
    mov rbx, r8

    call rsi    ; cb(a)

    mov rcx, rdi    ; cb(b)
    call rsi

    mov rcx, rbx    ; cb(c)
    call rsi

.done:
    pop rbx
    pop rdi
    pop rsi
    ret