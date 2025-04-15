SECTION .text
    GLOBAL FindIndexOfFirstZero

; int FFindIndexOfFirstZero(const int* arr, size_t size)
; RCX = const int* arr       ; pointer to the array
; RDX = size_t size          ; number of elements in the array
; Returns:
; EAX = index of the first zero (or -1 if not found)

FindIndexOfFirstZero:
    XOR RAX, RAX
    XOR R9, R9

    CMP RDX, 0
    JE end_FindIndexOfFirstZero

    MOV R10, 100

loop_FindIndexOfFirstZero:
    CMP R9, RDX
    JAE end_FindIndexOfFirstZero

    CMP R9, R10
    JAE end_FindIndexOfFirstZero

    MOV ESI, [RCX + R9*4]
    CMP ESI, 0
    JNE skip
    MOV EAX, R9D
    JMP end_FindIndexOfFirstZero

skip:
    INC R9
    CMP R9, RDX
    JAE zero_Notfound
    JMP loop_FindIndexOfFirstZero

zero_Notfound:
    MOV EAX, -1

end_FindIndexOfFirstZero:
    RET