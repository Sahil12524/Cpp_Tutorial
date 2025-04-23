; FindPointerToMaxElementTest.asm
; ----------------------
; void* FindPointerToMaxElement(const int* input, size_t size)
;
; This function returns a pointer to the maximum element in the array.
;
; Parameters:
;   RCX = pointer to input array
;   RDX = size of the array
;
; Returns:
;   RAX = pointer to the maximum element
;
; --- Implementation to be done by you ---
; Tip: Use RSI to store current maximum address, and compare each element to update it.

section .text
    global FindPointerToMaxElement

FindPointerToMaxElement:
    cmp rdx, 0
    je .return_null

    push rsi
    push rdi

    mov rsi, rcx            ; rsi = input pointer (current max pointer)
    xor r8, r8              ; i = 0
    inc r8                  ; start from i = 1

.loop_start:
    cmp r8, rdx
    jae .done               ; if i >= size, exit

    mov edi, [rcx + r8*4]   ; edi = input[i]
    mov eax, [rsi]          ; eax = *max

    cmp edi, eax
    jle .next               ; if input[i] <= max, skip update

    lea rsi, [rcx + r8*4]   ; rsi = &input[i]

.next:
    inc r8
    jmp .loop_start

.done:
    mov rax, rsi            ; return pointer to max
    pop rdi
    pop rsi
    ret

.return_null:
    xor rax, rax
    ret