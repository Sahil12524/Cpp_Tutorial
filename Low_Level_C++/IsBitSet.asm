; IsBitSet.asm
; ------------
; Checks whether the k-th bit (0-indexed from right) in a number is set.
; Input:
;   ECX = number
;   EDX = bit position to check (0 = LSB)
; Output:
;   EAX = 1 if the bit at position 'k' is set, 0 otherwise.
; Logic:
;   Create a bitmask by shifting 1 left by 'k' positions → (1 << k).
;   AND the number with the mask. If result ≠ 0, the bit is set.
; Windows x64 calling convention.

section .text
    global IsBitSet

IsBitSet:
    xor r8, r8
    
    mov r8d, ecx
    mov cl, dl

    mov r9, 1
    shl r9, cl
    and r8, r9
    jz .done

    mov eax, 1
    ret

.done:
    xor eax, eax
    ret