; ArithmeticShiftRight.asm
; -------------------------
; Problem: Perform arithmetic shift right on a signed integer.
; Input:
;   ECX = number (signed)
;   EDX = shift count
; Output:
;   EAX = arithmetic shifted result
; Logic:
;   Use SAR instruction to shift right while preserving the sign bit.
; Windows x64 calling convention.

section .text
    global ArithmeticShiftRight

ArithmeticShiftRight:
    mov eax, ecx
    mov cl, dl
    sar eax, cl

.done:
    ret