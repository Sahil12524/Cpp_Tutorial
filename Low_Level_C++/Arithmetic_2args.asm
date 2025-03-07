section .text
    global add_numbers

add_numbers:
    mov rax, rcx
    add rax, rdx
    ret