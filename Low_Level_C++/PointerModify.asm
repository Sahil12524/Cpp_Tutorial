SECTION .text
    GLOBAL ModifyValue

ModifyValue:
    ; RCX holds the pointer to the int

    MOV DWORD [RCX], 99
    RET