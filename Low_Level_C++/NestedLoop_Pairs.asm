SECTION .text
    GLOBAL CountMatchingPairs
; int CountMatchingPairs(const int* arr, size_t size)
; RCX = arr
; RDX = size
; Return: EAX = count of (i,j) pairs with i < j and arr[i] == arr[j]

CountMatchingPairs:
    PUSH RDI
    PUSH RSI

    XOR EAX, EAX ; Total count = 0
    XOR R8, R8 ; i = 0

outer_loop:
    CMP R8, RDX
    JGE end_function

    MOV R9, R8
    INC R9 ; j = i + 1

inner_loop:
    CMP R9, RDX
    JGE next_outer

    MOV ESI, [RCX + R8*4]
    MOV EDI, [RCX + R9*4]
    CMP ESI, EDI
    JNE not_equal

    INC EAX ; Found a matching pair

not_equal:
    INC R9
    JMP inner_loop

next_outer:
    INC R8
    JMP outer_loop

end_function:
    POP RSI
    POP RDI
    RET