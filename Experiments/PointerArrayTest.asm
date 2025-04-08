SECTION .text
    GLOBAL ReadArray, ModifyArrayElement, ZeroFillArray

ReadArray: ; ReadArray(const int *arr, size_t size, size_t index)

    ; RCX = *ptr
    ; RDX = size
    ; R8 = index

    CMP R8, RDX ; Compare size of array with index (index >= size)
    JAE Index_error ; Jump if above or equal, to Read_end to terminate. (index >= size then jump to end and return -1)
    MOV RAX, [RCX + R8 * 4] ; Load the element from array into RAX
    RET

ModifyArrayElement: ; ModifyArrayElement(const int *arr, size_t size, size_t index, int value)
    
    ; RCX = *ptr
    ; RDX = size
    ; R8 = index
    ; R9 = value

    CMP R8, RDX ; Compare size of array with index (index >= size)
    JAE Index_error ; Jump if above or equal, to Read_end to terminate. (index >= size then jump to end and return -1)
    MOV [RCX + R8 * 4], R9D ; Put custom value into the specified index
    RET

ZeroFillArray:
    CMP R8, RDX ; Compare size of array with index (index >= size)
    JAE Index_error ; Jump if above or equal, to Read_end to terminate. (index >= size then jump to end and return -1)
    MOV EAX, 0
    MOV [RCX + R8 * 4], EAX ; Put 0 into the array (write only 4 bytes!)
    RET

Index_error:
    MOV RAX, -1 ; Return -1 if index is out of range
    RET