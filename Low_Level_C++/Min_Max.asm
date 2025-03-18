section .text
    global minmax

minmax:
    ; rdx = size of array
    ; rcx = pointer to array

    mov r8, rdx              ; Copy size to r8 for looping
    mov eax, dword [rcx]      ; Load first element of array as max (in eax)
    mov edx, dword [rcx]      ; Load first element of array as min (in edx)
    
    add rcx, 4                ; Move pointer to the next element (4 bytes ahead)
    dec r8                    ; Decrease size count, as we already processed the first element

minmax_loop:
    test r8, r8               ; Check if size is zero
    je minmax_end             ; If yes, jump to end

    mov r9d, dword [rcx]      ; Load current element into r9d (32-bit register)
    
    ; Compare with current max value
    cmp r9d, eax
    jle .check_min            ; If r9d <= rax, jump to check min
    mov eax, r9d              ; Otherwise, update max

.check_min:
    ; Compare with current min value
    cmp r9d, edx
    jge .next_element         ; If r9d >= rdx, move to next element
    mov edx, r9d              ; Otherwise, update min

.next_element:
    add rcx, 4                ; Move to the next element (4 bytes)
    dec r8                    ; Decrease counter
    jmp minmax_loop           ; Repeat loop

minmax_end:
    ret