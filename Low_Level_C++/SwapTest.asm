SECTION .text
    GLOBAL SwapAtomic

SwapAtomic:
    LOCK XCHG DWORD [RCX], EDX
    MOV EAX, EDX
    RET