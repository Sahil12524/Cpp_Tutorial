SECTION .text
    GLOBAL CountAboveThreshold

; int CountAboveThreshold(const int* arr, size_t size, int threshold)
; RCX = const int* arr       ; pointer to the array
; RDX = size_t size          ; number of elements in the array
; R8D = int threshold        ; threshold value
; Returns:
; EAX = count of elements strictly greater than threshold

CountAboveThreshold:
    XOR RAX, RAX
    XOR R9, R9

    CMP RDX, 0
    JE end_CountAboveThreshold

    MOV R10, 1000


loop_CountAboveThreshold:
    CMP R9, RDX
    JAE end_CountAboveThreshold

    CMP R9, R10
    JAE end_CountAboveThreshold
    
    MOV ESI, [RCX + R9*4]
    CMP ESI, R8D
    JLE skip
    INC RAX

skip:
    INC R9
    JMP loop_CountAboveThreshold

end_CountAboveThreshold:
    RET