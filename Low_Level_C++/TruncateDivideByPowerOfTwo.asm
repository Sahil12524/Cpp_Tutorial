; TruncateDivideByPowerOfTwo.asm
; ------------------------------
; Problem: Simulate signed integer division by 2^k using arithmetic shift (SAR).
; Input:
;   ECX = signed integer (number to divide)
;   EDX = shift amount (k, the power of 2)
; Output:
;   EAX = result of floor division by 2^k
; Logic:
;   - Perform SAR on the signed integer
;   - SAR automatically performs sign extension, which gives correct result
;     for floor division behavior on signed integers
; Windows x64 calling convention.

section .text
    global TruncateDivideByPowerOfTwo

TruncateDivideByPowerOfTwo:
    mov eax, ecx
    mov cl, dl
    sar eax, cl

.done:
    ret