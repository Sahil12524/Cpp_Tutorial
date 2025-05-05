; IsParityEven.asm
; ----------------
; Checks if the number of 1-bits (set bits) in ECX is even.
; Uses Brian Kernighan's algorithm to count the set bits efficiently.
; Instead of counting all, only parity (even/odd) is tracked.
; Returns:
;   EAX = 1 if number of set bits is even
;   EAX = 0 if odd
; Follows Windows x64 calling convention.

section .text
    global IsParityEven

IsParityEven:
    xor rax, rax        ; Clear RAX (will store the result: 1 = even, 0 = odd)
    xor rdx, rdx        ; Clear RDX (temporary register for ECX - 1)
    xor r8, r8          ; R8 used to track count of set bits

.loop:
    test ecx, ecx       ; Check if ECX is 0 (no more bits left)
    jz .parityCheck     ; If yes, check parity

    inc r8              ; Found a set bit → increment count

    mov edx, ecx        ; Copy ECX to EDX
    dec edx             ; EDX = ECX - 1
    and ecx, edx        ; Clear the lowest set bit in ECX
    jz .skip            ; If result is zero, jump to skip

.skip:
    jmp .loop           ; Repeat until all bits are cleared

.parityCheck:
    test r8, 1          ; Check if set bit count is odd (last bit is 1)
    jnz .odd            ; If odd, jump to set result 0
    mov rax, 1          ; Even parity → set result to 1
    jmp .done

.odd:
    xor rax, rax        ; Set result to 0 (odd parity)

.done:
    ret                 ; Return result in RAX
