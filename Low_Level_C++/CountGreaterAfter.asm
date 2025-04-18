; CountGreaterAfter.asm
; ----------------------
; For each element in the array, this program counts how many elements to its right are greater than it.
;
; Parameters:
;   RCX = pointer to input array
;   RDX = pointer to output array
;   R8  = array size

section .text
    global CountGreaterAfter

CountGreaterAfter:
    push rbx
    xor r9, r9 ; i = 0

outer_loop:
    cmp r9, r8
    jae end_function

    xor r10, r10
    ;mov r10d, 0 ; count = 0

    mov r11, r9
    inc r11 ; j = i + 1

inner_loop:
    cmp r11, r8
    jae store_result

    mov eax, [rcx + r9*4] ; arr[i]
    mov ebx, [rcx + r11*4] ; arr[j]
    cmp ebx, eax
    jle skip
    inc r10d

skip:
    inc r11
    jmp inner_loop

store_result:
    mov [rdx + r9*4], r10d
    inc r9
    jmp outer_loop

end_function:
    pop rbx
    ret