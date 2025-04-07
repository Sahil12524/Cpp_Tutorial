SECTION .text
    GLOBAL ReadValue

ReadValue:
    MOV RAX, [RCX] ; RCX holds the address of X, [RCX] dereference it
    RET