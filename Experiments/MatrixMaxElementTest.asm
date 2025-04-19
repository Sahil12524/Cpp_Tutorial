; MatrixMaxElementTest.asm
; -------------------------
; int MatrixMaxElement(const int* matrix, size_t rows, size_t cols)
; 
; RCX = pointer to matrix data (flattened row-major array)
; RDX = number of rows
; R8  = number of columns
; R9  = i = 0
; R10 = j = 0
; R11 = index (i * cols + j)
; ESI = value (data[index])
;
; Returns:
; EAX = max value in the matrix

section .text
    global MatrixMaxElement

MatrixMaxElement:
    push rsi
    xor rax, rax
    xor r9, r9 ; i = 0
    xor r10, r10 ; j = 0

    mov eax, [rcx + r9*4]

outer_loop:
    cmp r9, rdx
    jae end_function
    xor r10, r10 ; reset j after j loops completed
     
inner_loop:
    cmp r10, r8
    jae next_outer

    mov r11, r9
    IMUL r11, r8
    add r11, r10

    mov esi, [rcx + r11*4]
    cmp esi, eax 
    jle skip
    mov eax, esi
    
skip:
    inc r10
    jmp inner_loop

next_outer:
    inc r9
    jmp outer_loop

end_function:
    pop rsi
    ret