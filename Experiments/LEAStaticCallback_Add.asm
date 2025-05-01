; LEAStaticCallback_Add.asm
; -------------------------
; void LEAStaticCallback_Add(void (*cb)(int*, int*, int*));
;
; Windows x64 calling convention:
;   RCX = pointer to callback function
;
; Behavior:
;   - Defines three static integers:
;       a = 10, b = 5, sum = 0
;   - Uses LEA to get their addresses
;   - Calls cb(&a, &b, &sum)
;
; Notes:
;   - Static data in .data section
;   - Uses LEA for address calculation
;   - Does not allocate stack space for locals

section .data
    a:      dd      10          ; Static variable a = 10
    b:      dd      5           ; Static variable b = 5
    sum:    dd      0           ; Static variable sum, initially 0

section .text
    global LEAStaticCallback_Add

LEAStaticCallback_Add:
    push    rsi                 ; Save non-volatile register RSI (Windows x64 ABI)

    mov     rsi,    rcx         ; Store the callback function pointer from RCX into RSI

    sub     rsp,    32          ; Allocate shadow space (Windows x64 calling convention)
    and     rsp,    -16         ; Ensure stack is 16-byte aligned

    lea     rcx,    [rel a]     ; First argument: address of a
    lea     rdx,    [rel b]     ; Second argument: address of b
    lea     r8,     [rel sum]   ; Third argument: address of sum
    call    rsi                 ; Call the callback function with (a, b, sum)

.done:
    add     rsp,    32          ; Restore stack pointer
    pop     rsi                 ; Restore RSI
    ret                         ; Return to caller