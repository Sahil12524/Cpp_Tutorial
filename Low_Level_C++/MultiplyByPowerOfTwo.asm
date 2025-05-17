; MultiplyByPowerOfTwo.asm
; -------------------------
; Problem: Multiply a signed integer by 2^k using SAL (Shift Arithmetic Left).
; Input:
;   ECX = signed integer
;   EDX = shift amount (k)
; Output:
;   EAX = result of ECX * (2^k) using SAL
;
; Logic:
;   - Copy ECX to EAX
;   - Use SAL to shift left by k bits
;
; Windows x64 calling convention

section .text
    global MultiplyByPowerOfTwo

MultiplyByPowerOfTwo:
    mov eax, ecx
    mov cl, dl
    sal eax, cl
    
.done:
    ret