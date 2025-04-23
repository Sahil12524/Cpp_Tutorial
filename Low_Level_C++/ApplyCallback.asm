; ApplyCallback.asm
; -----------------
; void ApplyCallback(int* arr, size_t size, void (*cb)(int*))
;
; RCX = arr
; RDX = size
; R8  = callback pointer
;
; Walk through array and call cb(&arr[i]).
; Return: void
; ----------------------------------------

section .text
    global ApplyCallback

ApplyCallback:
    push rsi
    push rbx

    mov rsi, rcx    ; rsi = base pointer (arr)
    xor rbx, rbx      ; rbx = index i = 0

.loop_start:
    cmp rbx, rdx
    jae .done

    ; Compute &arr[i] in RCX (first parameter for callback)
    lea rcx, [rsi + rbx * 4]

    ; ---- Indirect call ----
    call r8 ; call cb(int* value)

    inc rbx
    jmp .loop_start

.done:
    pop rbx
    pop rsi
    ret