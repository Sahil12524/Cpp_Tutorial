section .text
    global traverse_array

; Func Sig: int traverse_array(int* arr, size_t size, size_t index)
traverse_array:
    cmp r8, rdx             ; Compare index (index >= size)
    jae traverse_end         ; If index >= size, jump to end and return -1

    mov eax, dword [rcx + r8 * 4] ; Load the element from the array into eax
    ret

traverse_end:
    mov eax, -1              ; Return -1 if index is out of range
    ret
