; CountUpperTriangleSum.asm
; --------------------------
; int CountUpperTriangleSum(const int* matrix, size_t size)
;
; Given a square matrix stored as a flat 1D array (row-major),
; this function returns the sum of the elements in the upper triangle,
; excluding the diagonal. That is, it sums all elements where (j > i).
;
; Parameters:
;   RCX = pointer to matrix
;   RDX = matrix size (rows == cols)
;
; Returns:
;   EAX = sum of upper triangle values (excluding diagonal)

section .text
    global CountUpperTriangleSum

CountUpperTriangleSum:
    xor r8d, r8d ; i = 0
    xor r9d, r9d ; j = 0
    xor r10d, r10d ; index
    xor rax, rax ; sum = 0

outer_loop:
    cmp r8d, edx
    jae end_function

    mov r9d, r8d ; reset j
    inc r9d

inner_loop:
    cmp r9d, edx
    jae next_outer

    mov r10d, r8d
    imul r10d, edx
    add r10d, r9d

    add eax, [rcx + r10*4]
    inc r9d
    jmp inner_loop

next_outer:
    inc r8d
    jmp outer_loop

end_function:
    ret