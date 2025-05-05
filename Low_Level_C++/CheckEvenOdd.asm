; CheckEvenOdd.asm
; ----------------
; Checks whether a number is even or odd using bitwise AND.
; Expects the number in RCX (Windows x64 calling convention)

section .text
    global CheckEvenOdd
    extern puts

CheckEvenOdd:
    sub rsp, 40             ; Allocate shadow space + alignment

    test ecx, 1             ; Test LSB
    jz .even                ; Jump if even

    lea rcx, [rel OddMsg]   ; First parameter = address of OddMsg
    call puts
    jmp .done

.even:
    lea rcx, [rel EvenMsg]  ; First parameter = address of EvenMsg
    call puts

.done:
    add rsp, 40             ; Restore stack
    ret

section .data
    EvenMsg db "Even", 0     ; String for even
    OddMsg db "Odd", 0       ; String for odd