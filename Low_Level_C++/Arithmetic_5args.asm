section .text
    global add_numbers

add_numbers:
    mov rax, rcx       ; Load 1st argument into RAX
    add rax, rdx       ; Add 2nd argument
    add rax, r8        ; Add 3rd argument
    add rax, r9        ; Add 4th argument
    add rax, qword [rsp + 40]  ; Correctly access 5th argument on stack
    ret
