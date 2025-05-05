; CountSetBitsKernighan.asm
; -------------------------
; Uses Brian Kernighan's algorithm to count set bits in ECX.
; More efficient for sparse bit patterns.
; Result (count) returned in EAX.
; Follows Windows x64 calling convention.

section .text
    global CountSetBitsKernighan

CountSetBitsKernighan:
    ; Initialize counter (RAX) to zero
    xor rax, rax            ; RAX = 0 (will hold the bit count)

.loop:
    ; Check if ECX is zero (no more bits to count)
    test ecx, ecx           ; Set ZF if ECX == 0
    jz .done                ; If zero, jump to done (exit loop)

    ; Increment the bit counter
    inc rax                 ; RAX++ (count this bit)

    ; Kernighan's magic: Clear the least significant set bit
    mov edx, ecx            ; EDX = ECX (copy original value)
    dec edx                 ; EDX = ECX - 1 (flips bits right of LSB)
    and ecx, edx            ; ECX &= EDX (clears the LSB)

    ; Repeat until ECX becomes zero
    jmp .loop

.done:
    ; Return with count in EAX (Windows x64 return value convention)
    ret                     ; Result is in RAX (EAX for 32-bit)