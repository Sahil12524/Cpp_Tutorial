section .text
    global compare_integers

compare_integers:
    ; Load arguments correctly from Windows calling convention
    mov eax, ecx      ; Load the first argument (num1)
    mov edx, edx      ; Load the second argument (num2)
    
    cmp eax, edx      ; Compare num1 and num2
    je .equal         ; If equal, jump to .equal
    jg .greater       ; If greater, jump to .greater

.less:
    mov eax, -1       ; Return -1 (num1 < num2)
    ret

.greater:
    mov eax, 1        ; Return 1 (num1 > num2)
    ret

.equal:
    xor eax, eax      ; Return 0 (num1 == num2)
    ret
