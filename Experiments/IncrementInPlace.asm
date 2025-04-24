; IncrementInPlace.asm
; --------------------
; void IncrementInPlace(int* value, void (*cb)(int*))
;
; Windows x64 registers on entry:
;   RCX = pointer to int  (value)
;   RDX = callback pointer (void (*cb)(int*))
;
; Behavior:
;   Call the callback once, forwarding the same pointer.
;   No return value (void).
;
; Sequence:
;   ; RCX already holds first argument for callback
;   ; RDX holds function pointer
;   call RDX
;   ret
;
; No non‑volatile registers are modified, so no push/pop needed.

section .text
    global IncrementInPlace:

IncrementInPlace:
    call rdx
.done:
    ret