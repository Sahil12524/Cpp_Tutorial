; IsolateRightmostSetBit.asm
; --------------------------
; Given a number in ECX, isolate its rightmost set bit (e.g., turn 10100 → 00100).
; Output that value in EAX.
; Uses: x86_64 Assembly, Windows calling convention.
; Logic: result = n & -n
; Why: In two's complement, -n flips all bits and adds 1,
;      which preserves only the lowest set bit when ANDed with n.

section .text
    global IsolateRightmostSetBit

IsolateRightmostSetBit:
    mov eax, ecx        ; Copy input to EAX
    neg eax             ; Compute -n using two's complement (~n + 1)
    and eax, ecx        ; n & -n isolates the rightmost set bit
    ret