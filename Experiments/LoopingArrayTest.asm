SECTION .text
    GLOBAL ReadArray, DoubleElements

ReadArray: ; ReadArray(const int *arr, size_t size, size_t index)

    ; RCX = *ptr
    ; RDX = size
    ; R8 = index

    CMP R8, RDX ; Compare size of array with index (index >= size)
    JAE Index_error ; Jump if above or equal, to Read_end to terminate. (index >= size then jump to end and return -1)
    MOV RAX, [RCX + R8 * 4] ; Load the element from array into RAX
    RET

DoubleElements: ; DoubleElements(const int *arr, const size_t size)
    
    ; RCX = *ptr (Base pointer of arr)
    ; RDX = size of arr
    ; R9 = iterator (counter)

    XOR R9, R9 ; Ensure 0 index start (R9 is also used for counter like an iterator)

loop_DoubleElements:
    CMP R9, RDX
    JAE end_loop_DoubleElements ; If R9 == RDX then jump to end_loop_DoubleElements

    MOV EAX, [RCX + R9 * 4] ; Load the element from array into EAX
    IMUL EAX, 2 ; Signed multiplication (multiplying 2 with EAX)
    MOV [RCX + R9 * 4], EAX ; Load the multiplied element back into array
    INC R9 ; Increase counter by 1 (i++)
    JMP loop_DoubleElements ; Repeat :P

end_loop_DoubleElements: ; Clean exit
    RET

Index_error:
    MOV RAX, -1 ; Return -1 if index is out of range
    RET