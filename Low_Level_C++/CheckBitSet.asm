; CheckBitSet.asm
; -------------
; Problem: Check if the k-th bit (0-indexed) is set (1).
; Input:
;   ECX = number
;   EDX = bit position k (0 = LSB)
; Output:
;   EAX = 1 if k-th bit is set, 0 if not
; Logic:
;   Create a mask with a 1 at the k-th position.
;   Use AND operation to check the k-th bit.
; Windows x64 calling convention.

section .text
    global CheckBitSet

CheckBitSet:
    xor rax, rax
    mov r9d, ecx
    mov cl, dl

    xor r8d, r8d
    inc r8d
    shl r8d, cl

    and r9d, r8d
    test r9d, r9d
    setne al

.done:
    ret