; SumCallback.asm
; ----------------
; int ApplyAndSum(const int* arr, size_t size, int (*cb)(int))
;
; Purpose
; --------
; Walk through an integer array, call a user‑supplied callback on each element,
; add all callback return values together, and return the final sum.
;
; Calling Convention  (Windows x64)
; ---------------------------------
;   RCX : const int*  arr   → base address of array
;   RDX : size_t      size  → number of elements
;   R8  : int (*cb)(int)    → pointer to callback
;
; Callback contract
;   • Accepts one int value in RCX
;   • Returns its result in EAX
;
; High‑Level Algorithm
; --------------------
;   total = 0
;   for (i = 0; i < size; ++i) {
;       total += cb(arr[i]);
;   }
;   return total;
;
; Register Usage
;   RSI : immutable base pointer to arr
;   RBX : loop index  i
;   R9D : running sum  (32‑bit is fine for int)
;   RCX : reused each iteration to pass arr[i] to callback
;   RAX : holds each callback return → final result when function returns
;
; Non‑volatile registers modified:  RSI, RBX
; → Save / restore with push/pop.
;
; --------------------------------------------

section .text
    global ApplyAndSum

ApplyAndSum:
    ; Preserve non‑volatile registers we modify
    push rsi
    push rbx

    ; Set up loop state
    xor  rbx, rbx          ; i = 0
    xor  r9d, r9d          ; total = 0
    mov  rsi, rcx          ; RSI = base pointer (arr)

.loop_start:
    cmp  rbx, rdx          ; reached size?
    jae  .done

    ; RCX = arr[i]  (value, not address)
    mov  ecx, [rsi + rbx * 4]

    ; Call the callback: int cb(int value)
    call r8                ; EAX <- cb(arr[i])

    ; Accumulate
    add  r9d, eax          ; total += EAX

    inc  rbx               ; ++i
    jmp  .loop_start

.done:
    mov  eax, r9d          ; return total in EAX

    ; Restore non‑volatile registers and return
    pop  rbx
    pop  rsi
    ret
