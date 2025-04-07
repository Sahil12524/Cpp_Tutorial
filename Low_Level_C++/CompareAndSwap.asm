SECTION .text
    GLOBAL CompareAndSwap

; bool CompareAndSwap(int *ptr, int expected, int newVal)
CompareAndSwap:
    ; RCX = ptr
    ; RDX = expected
    ; R8 = newVal

    MOV EAX, EDX            ; EAX = expected
    LOCK CMPXCHG [RCX], R8D ; if (*ptr == EAX) then *ptr = newVal

    ;CMPXCHG sets ZF (zero flag) if the swap happened

    SETZ AL                  ; AL = 1 if swap happened, 0 otherwise
    MOVZX EAX, AL            ; Zero-extend AL to EAX
    RET