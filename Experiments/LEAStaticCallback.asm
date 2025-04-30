; LEAStaticCallback.asm
; ---------------------
; void LEAStaticCallback(void (*cb)(int*, int*, int*));
;
; Windows x64 calling convention:
;   RCX = pointer to callback function
;
; Behavior:
;   - Defines three static integers:
;       x = 3, y = 4, result = 0
;   - Uses LEA to get their addresses
;   - Calls cb(&x, &y, &result)
;
; Notes:
;   - Static data defined in .data section
;   - No locals or stack allocation needed
;   - Uses LEA instruction to pass addresses

section .data
    x:       dd 3
    y:       dd 4
    result:  dd 0

section .text
    global LEAStaticCallback

LEAStaticCallback:
    push rsi
    ; Save the callback pointer (RCX) in a non-volatile register
    mov rsi, rcx   ; RSI is preserved across function calls

    ; Get addresses of static variables using RIP-relative addressing
    lea rcx, [rel x]      ; First argument: &x
    lea rdx, [rel y]      ; Second argument: &y
    lea r8,  [rel result] ; Third argument: &result

    ; Align stack to 16 bytes before call (Windows x64 requirement)
    sub rsp, 32
    and rsp, -16 ; ensures rsp is multiple of 16
    ; Call the callback function
    call rsi

    ; Restore stack alignment
    add rsp, 32
    pop rsi
    ret