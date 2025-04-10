SECTION .text
    GLOBAL MaxInArray

; int MaxInArray(const int *arr, const size_t size)
; Parameters:
; RCX = const int *arr      ; pointer to the array
; RDX = const size_t size   ; number of elements
; ESI = max number while scanning the array
; EAX = final return value
; Returns:
; RAX = max number found in the array

MaxInArray:
    XOR R9, R9              ; R9 = index = 0
    CMP RDX, 0              ; Check if size == 0
    JE end_MaxInArray       ; If array is empty, just return 0

    MOV ESI, [RCX + R9*4]   ; ESI = arr[0] (initialize max with first element)
    INC R9                  ; i = 1 (start from second element)

    MOV R10, 1000           ; R10 = safety limit to prevent infinite loops

loop_MaxInArray:
    CMP R9, RDX             ; if i >= size, we're done
    JAE end_MaxInArray

    CMP R9, R10             ; if i >= safety limit, break out (likely infinite loop)
    JAE end_MaxInArray

    MOV EAX, [RCX + R9*4]   ; EAX = arr[i]
    CMP ESI, EAX            ; if current max < arr[i]
    JG skip_update
    MOV ESI, EAX            ; update max

skip_update:
    INC R9                  ; i++
    JMP loop_MaxInArray

end_MaxInArray:
    MOV EAX, ESI            ; return value = max
    RET