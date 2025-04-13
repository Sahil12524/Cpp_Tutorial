SECTION .text
    GLOBAL ProductOfEvens

; int ProductOfEvens(const int* arr, size_t size)
; RCX = const int* arr       ; pointer to the array
; RDX = size_t size          ; number of elements in the array
; Returns:
; EAX = product of even numbers (excluding zero)

ProductOfEvens:
    XOR     R9, R9            ; R9 = index = 0
    MOV     EAX, 1            ; EAX = result = 1 (product starts at 1)

    CMP     RDX, 0            ; if size == 0
    JE      end_ProductOfEvens ; return 1

    MOV     R10, 1000         ; R10 = max limit to prevent infinite loop

loop_ProductOfEvens:
    CMP     R9, RDX           ; if index >= size
    JAE     end_ProductOfEvens

    CMP     R9, R10           ; if index >= 1000
    JAE     end_ProductOfEvens

    MOV     ESI, [RCX + R9*4] ; ESI = arr[index]

    TEST    ESI, 1            ; check if number is odd (LSB = 1)
    JNZ     skip              ; skip if odd

    CMP     ESI, 0
    JE      skip              ; skip if zero

    IMUL    EAX, ESI          ; EAX *= ESI (32-bit signed multiply)

skip:
    INC     R9
    JMP     loop_ProductOfEvens

end_ProductOfEvens:
    RET                       ; return result in EAX
