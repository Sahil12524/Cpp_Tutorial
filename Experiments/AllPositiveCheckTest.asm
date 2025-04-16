SECTION .text
    GLOBAL AllPositiveCheck

; int AllPositiveCheck(const int* arr, size_t size)
; RCX = const int* arr       ; pointer to array
; RDX = size_t size          ; number of elements
; Returns:
; EAX = 1 if all elements > 0, else 0

AllPositiveCheck:
    XOR RAX, RAX
    XOR R9, R9
    CMP RDX, 0
    JE end_AllPositiveCheck
    MOV EAX, 1

loop_AllPositiveCheck:
    CMP R9, RDX
    JAE end_AllPositiveCheck

    MOV ESI, [RCX + R9*4]
    CMP ESI, 0
    JLE force_Termination
    INC R9
    JMP loop_AllPositiveCheck

force_Termination:
    MOV EAX, 0
    RET

end_AllPositiveCheck:
    RET