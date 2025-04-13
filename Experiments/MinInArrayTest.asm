SECTION .text
    GLOBAL MinInArray

; int MinInArray(const int* arr, size_t size)
; RCX = const int* arr       ; pointer to the array
; RDX = size_t size          ; number of elements in the array
; Returns:
; EAX = minimum value in the array

MinInArray:
    XOR R9, R9

    CMP RDX, 0
    JE end_MinInArray

    MOV ESI, [RCX + R9*4]
    INC R9

loop_MinInArray:
    CMP R9, RDX
    JAE end_MinInArray

    MOV EAX, [RCX + R9*4]
    CMP ESI, EAX 
    JLE skip
    MOV ESI, EAX

skip:
    INC R9
    JMP loop_MinInArray

end_MinInArray:
    MOV EAX, ESI
    RET