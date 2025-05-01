; LEAHybridCallback_ArraySum.asm
; ------------------------------
; void LEAHybridCallback_ArraySum(int* arr, int* count, void (*cb)(int*, int*, int*));
;
; Windows x64 calling convention:
;   RCX = arr pointer (from main)
;   RDX = count pointer (from main)
;   R8  = callback function pointer
;
; Behavior:
;   - Defines static variable: total = 0
;   - Uses LEA to calculate address of total
;   - Calls cb(arr, count, &total)
;
; Notes:
;   - Only `total` is defined in ASM data section
;   - No array math done in ASM — callback handles it
;   - Assembly just sets up pointers and calls callback

section .data
    total: dd 0

section .text
    global LEAHybridCallback_ArraySum

LEAHybridCallback_ArraySum:
    push rsi
    push rdi
    push rbx

    mov rsi, r8
    mov rdi, rcx
    mov rbx, rdx

    sub rsp, 32
    and rsp, -16

    mov rcx, rdi
    mov rdx, rbx
    lea r8, [rel total]
    call rsi

.done:
    add rsp, 32
    pop rbx
    pop rdi
    pop rsi
    ret