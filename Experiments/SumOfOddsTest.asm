SECTION .text
    GLOBAL SumOfOdds

; int SumOfOdds(const int *arr, size_t size)
; RCX = const int *arr
; RDX = size_t size
; Return value (RAX) = sum of odd numbers

SumOfOdds:
    XOR RAX, RAX            ; RAX will store the sum
    XOR R9, R9              ; R9 = loop index (i = 0)
    CMP RDX, 0              ; If size is 0, skip loop
    JE end_sumOfOdds

    MOV R10, 1000           ; Safety loop limit

loop_SumOfOdds:
    CMP R9, RDX
    JAE end_sumOfOdds

    CMP R9, R10
    JAE end_sumOfOdds

    MOV ESI, [RCX + R9*4]   ; Load arr[i]
    TEST ESI, 1             ; Check if it's odd (LSB == 1)
    JZ skip_sum             ; If even, skip

    ADD EAX, ESI            ; Add to sum if odd

skip_sum:
    INC R9
    JMP loop_SumOfOdds

end_sumOfOdds:
    RET
