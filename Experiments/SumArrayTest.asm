SECTION .text
    GLOBAL SumArray

; int SumArray(const int *arr, size_t size)
; Parameters:
; RCX = const int* arr
; RDX = size_t size
; Return:
; RAX = total sum

SumArray:
    ; Setup
    XOR     RAX, RAX        ; Clear RAX (will hold the sum)
    XOR     R9, R9          ; R9 = index = 0

.loop:
    CMP     R9, RDX         ; if (index >= size)
    JAE     .end            ;     jump to end

    MOV     ESI, [RCX + R9*4]   ; Load arr[index] into ESI
    ADD     EAX, ESI            ; Add it to total in EAX
    INC     R9                  ; index++

    JMP     .loop

.end:
    RET
