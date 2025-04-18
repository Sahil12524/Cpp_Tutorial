section .text
    global BubbleSort

BubbleSort:
    push rdi
    push rsi

    xor r8, r8              ; r8 = i (outer loop index)

outer_loop:
    mov r10, rdx            ; r10 = size
    sub r10, r8             ; r10 = size - i
    dec r10                 ; r10 = size - i - 1
    cmp r10, 0
    jl end_function         ; if r10 < 0, we're done

    xor r9, r9              ; r9 = j (inner loop index)

inner_loop:
    cmp r9, r10
    jg next_outer

    mov esi, [rcx + r9*4]           ; arr[j]
    mov edi, [rcx + r9*4 + 4]       ; arr[j + 1]
    cmp esi, edi
    jle skip_swap                   ; if arr[j] <= arr[j+1], no need to swap

    ; swap arr[j] and arr[j + 1]
    mov eax, esi                    ; eax = arr[j]
    mov [rcx + r9*4], edi           ; arr[j] = arr[j+1]
    mov [rcx + r9*4 + 4], eax       ; arr[j+1] = eax

skip_swap:
    inc r9
    jmp inner_loop

next_outer:
    inc r8
    jmp outer_loop

end_function:
    pop rsi
    pop rdi
    ret