SECTION .text
    GLOBAL ReadValue, ModifyValue

ReadValue: ; ReadValue(int *ptr)
    ; RCX = *ptr
    MOV RAX, [RCX]
    RET

ModifyValue: ; ModifyValue(int *ptr, int val)
    ; RCX = *ptr
    ; RDX = val
    MOV [RCX], RDX
    RET