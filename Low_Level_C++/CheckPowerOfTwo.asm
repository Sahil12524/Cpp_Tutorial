; CheckPowerOfTwo.asm
; -------------------
; Checks if ECX is a power of 2.
; Returns 1 in EAX if true, else 0.
; Uses: Bitwise trick (n & (n-1)) == 0
; Windows x64 calling convention.

section .text
    global CheckPowerOfTwo

CheckPowerOfTwo:
    xor rax, rax

    test ecx, ecx
    jle .done

    mov edx, ecx
    dec edx
    and edx, ecx

    test edx, edx
    jnz .done

    mov eax, 1

.done:
    ret