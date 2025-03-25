section .text
    global multiply_three

multiply_three:
    mov eax, ecx

    imul eax, edx
    imul eax, r8d

    ret