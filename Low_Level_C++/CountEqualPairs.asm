; CountEqualPairs.asm
; -------------------
; void CountEqualPairs(const int* input, int* output, size_t size)
;
; Parameters:
;   RCX = pointer to input array
;   RDX = pointer to output array
;   R8  = size of array
;
; Output:
;   output[0] = total number of (i, j) pairs where i < j and input[i] == input[j]

section .text
    global CountEqualPairs

CountEqualPairs:
    push r12
    xor rax, rax
    xor r9, r9 ; i = 0
    xor r10, r10 ; j = 0

    outer_loop:
    cmp r9, r8
    jae end_function

    mov r10, r9 ; j = i
    inc r10 ; j = i + 1

    inner_loop:
    cmp r10, r8
    jae next_outer

    mov r11d, [rcx + r9*4] ; input[i]
    mov r12d, [rcx + r10*4] ; input[j]
    cmp r11d, r12d
    jne skip
    inc eax ; count++
    mov [rdx], eax


    skip:
    inc r10
    jmp inner_loop

    next_outer:
    inc r9
    jmp outer_loop

end_function:
    pop r12
    ret