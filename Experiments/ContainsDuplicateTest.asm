SECTION .text
    GLOBAL ContainsDuplicate

; int ContainsDuplicate(const int* arr, size_t size)
; RCX = const int* arr
; RDX = size_t size
; Returns:
; EAX = 1 if duplicate found, else 0

ContainsDuplicate:
    PUSH RDI
    PUSH RSI
    XOR RAX, RAX
    XOR R8, R8

outer_loop:
    CMP R8, RDX
    JAE end_function ; if i >= size, end

    MOV R9, R8
    INC R9 ; inner loop index j = i + 1

inner_loop:
    CMP R9, RDX
    JAE next_outer ; if j >= size, go to next outer iteration

    MOV ESI, [RCX + R8*4]
    MOV EDI, [RCX + R9*4]

    CMP ESI, EDI
    JE found_duplicate

    INC R9
    JMP inner_loop

next_outer:
    INC R8
    JMP outer_loop

found_duplicate:
    MOV EAX, 1

end_function:
    POP RSI
    POP RDI
    RET