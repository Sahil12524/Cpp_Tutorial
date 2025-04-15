SECTION .text
    GLOBAL CountRangeMatches

; int CountRangeMatches(const int* arr, size_t size, int min, int max)
; RCX = const int* arr       ; pointer to the array
; RDX = size_t size          ; number of elements in the array
; R8D = int min              ; lower bound (inclusive)
; R9D = int max              ; upper bound (inclusive)
; Returns:
; EAX = count of elements where min <= element <= max

CountRangeMatches:
    XOR R10, R10
    XOR RAX, RAX

    CMP RDX, 0
    JE end_CountRangeMatches

loop_CountRangeMatches:
    CMP R10, RDX
    JAE end_CountRangeMatches

    MOV ESI, [RCX + R10*4]
    CMP ESI, R8D
    JL skip
    CMP ESI, R9D
    JG skip
    INC EAX
    INC R10
    JMP loop_CountRangeMatches

skip:
    INC R10
    JMP loop_CountRangeMatches

end_CountRangeMatches:
    RET