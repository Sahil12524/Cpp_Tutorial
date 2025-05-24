; ClampAfterLeftShift.asm
; -----------------------
; Problem: Multiply a signed integer by 2^k using SAL (Shift Arithmetic Left),
;          then clamp the result between min and max bounds.
;
; Input:
;   ECX = signed integer value (num)
;   EDX = shift amount (k)
;   R8D = min clamp value
;   R9D = max clamp value
;
; Output:
;   EAX = result of SAL(ECX, EDX), clamped to [R8D, R9D]
;
; Logic:
;   - Perform SAL (signed arithmetic left shift) on the input
;   - Clamp the shifted result:
;       If result < min_val → return min_val
;       If result > max_val → return max_val
;       Otherwise           → return the result
;
; Windows x64 calling convention

section .text
    global ClampAfterLeftShift

ClampAfterLeftShift:
    mov eax, ecx
    mov cl, dl
    sal eax, cl

    cmp eax, r8d
    jl .clamp_to_min

    cmp eax, r9d
    jg .clamp_to_max

    jmp .return

.clamp_to_min:
    mov eax, r8d
    jmp .return

.clamp_to_max:
    mov eax, r9d

.return:
    ret