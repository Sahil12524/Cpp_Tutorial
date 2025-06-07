; RotateLeft.asm
; --------------
; Problem: Rotate a 32-bit signed integer left by 'k' bits using ROL (Rotate Left).
;
; Inputs:
;   ECX = integer value to rotate (num)
;   EDX = number of bits to rotate left (k)
;
; Output:
;   EAX = result after rotating ECX left by k bits
;
; Logic:
;   - Move input value (ECX) to EAX
;   - Move shift amount (EDX) to CL
;   - Use ROL instruction to rotate EAX left by CL bits
;
; Notes:
;   - ROL wraps bits that go beyond the most significant bit back to the least significant bit.
;   - Useful for circular bit manipulations.
;
; Windows x64 calling convention

section .text
    global RotateLeft

RotateLeft:
    mov eax, ecx
    movzx ecx, dl
    rol eax, cl
    ret