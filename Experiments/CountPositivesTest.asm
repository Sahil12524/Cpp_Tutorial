SECTION .text
    GLOBAL CountPositives

; int CountPositives(const int *arr, const size_t size)
; Parameters:
; RCX = pointer to the array
; RDX = size of the array
; Return value:
; RAX = number of positive integers in the array

CountPositives:
    XOR RAX, RAX        ; Clear RAX, will store the count of positive numbers
    XOR R9, R9          ; R9 = loop index (i = 0)
    CMP RDX, 0          ; Check if array size is zero
    JE end_CountPositives ; If size is zero, skip loop and return 0
    MOV R10, 1000       ; Safety limit: prevent infinite loop by hard-capping iterations

loop_CountPositives:
    CMP R9, RDX         ; Check if we've reached the end of the array
    JAE end_CountPositives ; Exit if index >= size

    CMP R9, R10         ; Additional safety: ensure index < 1000
    JAE end_CountPositives ; Exit if index exceeds limit

    MOV ESI, [RCX + R9*4] ; Load current element (arr[i]) into ESI
    TEST ESI, ESI       ; Test if the value is zero or negative (sign bit set)
    JS skip_count  ; If negative, skip incrementing count (jump to skip_count)
    
    INC R9              ; Move to next element
    INC RAX             ; Increment count (value is positive)
    JMP loop_CountPositives ; Repeat the loop

skip_count:
    ; Negative or zero number encountered, don't count
    INC R9              ; Move to next element
    JMP loop_CountPositives ; Repeat the loop

end_CountPositives:
    RET                 ; Return the count in RAX