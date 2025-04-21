; CountGreaterThanRight.asm
; --------------------------
; void CountGreaterThanRight(const int* input, int* output, size_t size)
;
; For each element in the input array, this function counts how many elements
; to its right are smaller than it, and stores the count in the output array.
;
; Parameters:
;   RCX = pointer to input array
;   RDX = pointer to output array
;   R8  = size of the array
;
; Output:
;   Output array is written at RDX

section .text
    global CountGreaterThanRight

CountGreaterThanRight:
    push r12 ; input[j]
    xor r9, r9 ; i = 0
    xor r10, r10 ; j = 0
    xor r11d, r11d ; count = 0


outer_loop:
    cmp r9, r8
    jae end_function

    xor r11d, r11d
    mov r10, r9
    inc r10d ; j = i + 1

inner_loop:
    cmp r10, r8
    jae next_outer

    mov eax, [rcx + r9*4] ; input[i]
    mov r12d, [rcx + r10*4] ; input[j]
    cmp r12d, eax
    jge skip
    inc r11d ; count++

skip:
    inc r10d ; j++
    jmp inner_loop

next_outer:
    mov [rdx + r9*4], r11d
    inc r9d ; i++
    jmp outer_loop

end_function:
    pop r12
    ret