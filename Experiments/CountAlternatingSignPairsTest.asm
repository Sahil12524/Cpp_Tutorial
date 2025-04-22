; CountAlternatingSignPairsTest.asm
; ----------------------
; void CountAlternatingSignPairs(const int* input, int* output, size_t size)
;
; This function counts how many adjacent elements in the input array have opposite signs.
; It checks if the signs of consecutive elements are different (one positive, the other negative).
;
; Parameters:
;   RCX = pointer to input array
;   RDX = pointer to output array
;   R8  = size of the array
;
; Output:
;   output[0] = total number of adjacent pairs with opposite signs
;
; --- Implementation to be done by you ---
; Tip: You can compare the sign of consecutive elements and count how many have opposite signs.
; Multiply both the values and check the product, if its negative meaning both are different sign.

section .text
    global CountAlternatingSignPairs

CountAlternatingSignPairs:
    push rsi        ; input[i]
    push rdi        ; input[i+1]
    push r12        ; product

    xor r9, r9      ; i = 0
    xor r10, r10    
    xor eax, eax    ; count = 0

    mov r10, r8
    dec r10         ; size - 1

.loop_start:
    cmp r9, r10
    jae .done

    mov esi, [rcx + r9 * 4]         ; input[i]
    mov edi, [rcx + (r9 + 1) * 4]   ; input[i+1]
    mov r12d, esi
    imul r12d, edi  ;  input[i] * input[i + 1]
    js .found       ; if SF = 1 (negative product)

    jmp .next

.found:
    inc eax     ; count++

    .next:
    inc r9      ; ++i
    jmp .loop_start

.done:
    mov [rdx], eax  ; arr[0] = count
    pop r12
    pop rdi
    pop rsi
    ret