section .text
    global sum_array

sum_array:
    xor rax, rax            ; Clear rax (accumulator)
    test rdx, rdx            ; Check if size is zero
    je end_sum               ; If size is zero, return

sum_loop:
    mov eax, dword [rcx]     ; Load integer from array into eax
    add r8, rax              ; Add eax to r8 (accumulator)
    add rcx, 4               ; Move to the next integer (4 bytes)
    dec rdx                  ; Decrement size
    jnz sum_loop             ; Loop if size is not zero

    mov rax, r8              ; Move the result from r8 to rax

end_sum:
    ret
