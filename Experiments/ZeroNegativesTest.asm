SECTION .text
    GLOBAL ZeroNegatives

; void ZeroNegatives(int *arr, size_t size)
; RCX = int *arr             ; Pointer to the integer array
; RDX = size_t size          ; Number of elements in the array
; This function modifies the input array in-place by setting all negative numbers to zero.
; There is no return value.

ZeroNegatives:
    XOR R9, R9                ; R9 = loop index, initialized to 0
    CMP RDX, 0                ; If size == 0
    JE end_ZeroNegatives      ; Exit early if array size is zero
    MOV R10, 1000             ; R10 = safety loop limit (max iterations)

loop_ZeroNegatives:
    CMP R9, RDX               ; Check if we've reached the end of the array
    JAE end_ZeroNegatives     ; If index >= size, exit loop

    CMP R9, R10               ; Compare index to safety cap
    JAE end_ZeroNegatives     ; Exit if index >= 1000 (prevent infinite loops)

    MOV EAX, [RCX + R9*4]     ; Load arr[index] into EAX
    TEST EAX, EAX             ; Check if arr[index] is negative
    JS set_zero               ; If sign bit is set (value < 0), jump to set_zero

    INC R9                    ; Move to next index
    JMP loop_ZeroNegatives    ; Repeat the loop

set_zero:
    MOV DWORD [RCX + R9*4], 0 ; Set arr[index] = 0
    INC R9                    ; Move to next index
    JMP loop_ZeroNegatives    ; Repeat the loop

end_ZeroNegatives:
    RET                       ; Return (void)
