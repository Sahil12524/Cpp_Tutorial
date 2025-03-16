section .text
    global sum_array

sum_array:
    mov r8, rdx
    xorps xmm0, xmm0

sum_loop:
    test r8, r8
    je end_sum
    movss xmm1, dword [rcx]
    addss xmm0, xmm1
    add rcx, 4
    dec r8
    jmp sum_loop

end_sum:
    ret