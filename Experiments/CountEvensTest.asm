SECTION .text
    GLOBAL CountEvens

; int CountEvens(const int *arr, const size_t size)
; RCX = const int *arr
; RDX = const size_t size
; RAX = total even counts

CountEvens:
    XOR RAX, RAX    ; Clear RAX (will hold the number of even counts)
    XOR R9, R9      ; R9 = index = 0

loop_CountEvens:
    CMP R9, RDX
    JAE end_CountEvens
    MOV ESI, [RCX + R9*4] ; load array element into ESI
    TEST ESI, 1 ; check if even (last bit is 0)
    JZ count_even ; if not even, skip incrementing RAX
    INC R9
    JMP loop_CountEvens

count_even:
    INC RAX
    INC R9 ; count even number
    JMP loop_CountEvens

end_CountEvens:
    RET