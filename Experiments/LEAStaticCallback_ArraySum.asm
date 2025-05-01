; LEAStaticCallback_ArraySum.asm
; ------------------------------
; void LEAStaticCallback_ArraySum(void (*cb)(int*, int*, int*));
;
; Windows x64 calling convention:
;   RCX = pointer to callback function
;
; Behavior:
;   - Defines an array of 3 integers: arr = {4, 5, 6}
;   - Also defines: count = 3, total = 0
;   - Uses LEA to pass:
;       - &arr[0]     (pointer to start of array)
;       - &count      (number of elements)
;       - &total      (where result will be stored)
;   - Calls cb(&arr[0], &count, &total)
;
; Notes:
;   - Array is static in .data
;   - Stack alignment still required
;   - No indexing done in ASM; logic stays in callback

section .data
    arr:        dd        4, 5, 6
    count:      dd        3
    total:      dd        0

section .text
    global LEAStaticCallback_ArraySum

LEAStaticCallback_ArraySum:
    push        rsi

    mov         rsi,        rcx

    sub         rsp,        32
    and         rsp,        -16
    
    lea         rcx,        [rel arr]
    lea         rdx,        [rel count]
    lea         r8,         [rel total]

    call        rsi

.done:
    add         rsp,        32
    pop         rsi
    ret