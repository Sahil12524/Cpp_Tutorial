section .text
    global add_numbers

add_numbers:
    mov rax, rcx
    add rax, rdx
    add rax, r8
    add rax, r9
    ret