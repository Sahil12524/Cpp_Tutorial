; ClampShiftedSigned.asm
; ----------------------
; Problem: Perform arithmetic right shift (SAR) on a signed integer and clamp the result between min and max bounds.
; Input:
;   ECX = signed integer value
;   EDX = shift amount
;   R8D = min clamp value
;   R9D = max clamp value
; Output:
;   EAX = SAR(ECX, EDX), clamped to [R8D, R9D]
;
; Logic:
;   - Perform SAR (signed arithmetic right shift) on the input value
;   - Compare result with min and max bounds
;   - If result < min_val, return min_val
;   - If result > max_val, return max_val
;   - Else, return the result itself
;
; Windows x64 calling convention.

section .text
    global ClampShiftedSigned

ClampShiftedSigned:
    mov r10d, ecx
    mov cl, dl
    sar r10d, cl

    cmp r10d, r8d
    jl .lesser

    cmp r10d, r9d
    jg .greater

    jmp .default


.greater:
    mov eax, r9d
    jmp .done

.lesser:
    mov eax, r8d
    jmp .done

.default:
    mov eax, r10d

.done:
    ret