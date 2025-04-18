section .text
    global MatchingPairs

MatchingPairs:
    push rdi

    xor r8, r8 ; i = 0
    xor r9, r9 ; j = 0
    xor r10, r10 ; counter = 0

outer_loop:
    cmp r8, rdx
    jae end_function

    mov r9, r8 ; moved r8 into r9
    inc r9 ; and increased r9 to make j = i + 1

inner_loop:
    cmp r9, rdx
    jae next_outer

    mov eax, [rcx + r8*4]; arr[i]
    mov edi, [rcx + r9*4]; arr[j]
    cmp eax, edi
    jne no_match

    inc r10 ; counter++
    

no_match:
    inc r9
    jmp inner_loop

next_outer:
    inc r8
    jmp outer_loop

end_function:
    mov eax, r10d ; return counter
    pop rdi
    ret