; ArithmeticShiftRight1.asm
; ------------------------
; Problem: Perform arithmetic right shift (SAR) on a signed integer by k positions.
; Input:
;   ECX = signed integer
;   EDX = shift count
; Output:
;   EAX = result of arithmetic shift right
; Logic:
;   SAR preserves the sign bit (MSB) during the shift.
; Windows x64 calling convention.

section .text
    global ArithmeticShiftRight1

ArithmeticShiftRight1:
    mov eax, ecx
    mov cl, dl
    sar eax, cl

.done:
    ret