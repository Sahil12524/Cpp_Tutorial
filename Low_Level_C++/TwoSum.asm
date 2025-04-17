SECTION .text
    GLOBAL TwoSum

; int TwoSum(const int* arr, size_t size, int target)
; RCX = arr
; RDX = size
; R8D = target
; Return: EAX = 1 if found, 0 if not

TwoSum:
    PUSH RDI
    PUSH RSI

    XOR EAX, EAX
    XOR R9, R9

outer_loop:
    CMP R9, RDX
    JAE end_func

    MOV R10, R9
    INC R10

inner_loop:
    CMP R10, RDX
    JAE next_outer

    MOV ESI, [RCX + R9*4]
    MOV EDI, [RCX + R10*4]
    ADD ESI, EDI

    CMP ESI, R8D
    JE found

    INC R10
    JMP inner_loop

next_outer:
    INC R9
    JMP outer_loop

found:
    MOV EAX, 1

end_func:
    POP RSI
    POP RDI
    RET