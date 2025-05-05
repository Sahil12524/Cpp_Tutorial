; CountSetBits.asm
; ----------------
; Counts the number of set bits (1s) in the binary representation of a number.
; Expects the number in ECX.
; Returns the count in EAX.
; Follows Windows x64 calling convention.

section .text
    global CountSetBits

CountSetBits:
    xor rax, rax        ; Clear RAX (to store result count)
    
.loop:
    test ecx, ecx       ; Is ECX == 0? If yes, we're done
    jz .done

    test ecx, 1         ; Check LSB (ecx & 1)
    jz .skip            ; If LSB is 0, skip increment

    inc rax             ; LSB is 1 → count it

.skip:
    shr ecx, 1          ; Shift ECX right to check next bit
    jmp .loop           ; Repeat

.done:
    ret                 ; Result is in RAX