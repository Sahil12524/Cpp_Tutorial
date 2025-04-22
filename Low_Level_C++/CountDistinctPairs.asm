; CountDistinctPairs.asm
; ----------------------
; void CountDistinctPairs(const int* input, int* output, size_t size)
;
; This function counts how many pairs (i, j) satisfy:
; - i < j
; - input[i] != input[j]
;
; Parameters:
;   RCX = pointer to input array
;   RDX = pointer to output array
;   R8  = size of array
;
; Output:
;   output[0] = number of distinct (i, j) pairs where i < j and input[i] != input[j]

section .text
    global CountDistinctPairs

; --- Implementation to be done by you ---
; Tip: Very similar to CountEqualPairs, just reverse the comparison!


CountDistinctPairs:
    push rsi ; input[i]
    push rdi ; input[j]

    xor r9, r9 ; i = 0
    xor r10, r10 ; j = 0
    xor eax, eax ; count = 0

    outer_loop:
    cmp r9, r8
    jae end_function

    mov r10, r9 ; j = i
    inc r10 ; j = i + 1

    inner_loop:
    cmp r10, r8
    jae next_outer

    mov esi, [rcx + r9*4] ; input[i]
    mov edi, [rcx + r10*4] ; input[j]
    cmp esi, edi
    je skip

    inc eax ; count++
    mov [rdx], eax

    skip:
    inc r10 ; ++j
    jmp inner_loop

    next_outer:
    inc r9 ; ++i
    jmp outer_loop

end_function:
    pop rdi
    pop rsi
    ret