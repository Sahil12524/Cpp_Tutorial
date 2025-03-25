SECTION .text
    GLOBAL Swap

Swap:
    MOV EAX, DWORD [RCX]  ; Load *a (4 bytes) into EAX
    XCHG EAX, DWORD [RDX] ; Swap EAX with *b (4 bytes)
    MOV DWORD [RCX], EAX  ; Store swapped value back to *a

    RET
