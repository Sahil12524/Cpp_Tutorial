; NegateWithContext.asm
; ---------------------
; void NegateWithContext(int*  arr,
;                        size_t n,
;                        void (*cb)(int*, void*),
;                        void*  ctx);
;
; Windows x64 parameter registers
;   RCX = arr        (base pointer to int array)
;   RDX = n          (element count)
;   R8  = cb         (callback pointer)
;   R9  = ctx        (context pointer)
;
; Callback contract
;   RCX = pointer to element (int*)
;   RDX = context pointer    (void*)
;   Returns: void   (no need to look at RAX)
;
; Algorithm
;   for (i = 0; i < n; ++i)
;       cb(&arr[i], ctx);
;   // done
;
; Non‑volatile registers we’ll modify:
;   RSI  : copy of base pointer (arr)
;   RBX  : loop index i
;   (We preserve them with push/pop.)

section .text
    global NegateWithContext

NegateWithContext:
    ; Preserve non-volatile registers
    push rsi
    push rbx

    ; Copy arr (RCX) into rsi for loop processing
    mov rsi, rcx

    ; Initialize loop index i = 0
    xor rbx, rbx

.loop_start:
    ; Compare i (rbx) with n (rdx), if i >= n, exit loop
    cmp rbx, rdx
    jae .done

    ; Load address of arr[i] into rcx
    lea rcx, [rsi + rbx * 4]

    ; Preserve rdx before calling the callback
    mov  r10, rdx          ; --- save element count ---
    sub  rsp, 8               ; keep RSP 16‑byte aligned
    ;push rdx
    mov rdx, r9        ; rdx = ctx (context pointer)
    call r8            ; call the callback (cb(&arr[i], ctx))
    ;pop rdx            ; Restore rdx
    add  rsp, 8               ; restore alignment
    mov  rdx, r10          ; --- restore element count ---

    ; Increment loop index i
    inc rbx

    ; Jump back to loop start
    jmp .loop_start

.done:
    ; Restore preserved registers
    pop rbx
    pop rsi

    ; Return from the function
    ret