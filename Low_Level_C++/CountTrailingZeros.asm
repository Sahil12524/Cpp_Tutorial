; CountTrailingZeros.asm
; ----------------------
; Counts how many trailing zeros are in the binary form of a number.
;
; Input:
;   ECX = number
;
; Output:
;   EAX = number of trailing zeros
;
; Logic:
;   Repeatedly check LSB using AND with 1.
;   If zero, right shift and count.
;   Stop when LSB is 1 or input becomes zero.
;
; Windows x64 calling convention

section .text
    global CountTrailingZeros

CountTrailingZeros:
    xor eax, eax
    test ecx, ecx
    jz .done

.loop:
    test ecx, 1
    jnz .done

    shr ecx, 1
    inc eax
    jmp .loop

.done:
    ret
