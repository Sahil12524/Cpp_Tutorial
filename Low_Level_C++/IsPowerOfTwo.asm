; IsPowerOfTwo.asm
; ----------------
; Checks whether a number is a power of two using bitwise AND.
; Expects the number in ECX.
; Prints "Yes" if it is, otherwise prints "No".
; Uses puts for output and follows Windows x64 calling convention.

section .data
    yesMsg db "Yes", 0     ; Null-terminated "Yes" string
    noMsg db "No", 0       ; Null-terminated "No" string

section .text
    global IsPowerOfTwo    ; Make this function visible to the linker
    extern puts            ; Declare the external C function 'puts'

IsPowerOfTwo:
    sub rsp, 40            ; Allocate 32 bytes shadow space + 8 bytes for alignment (Windows x64 ABI)

    test ecx, ecx          ; Check if the input is 0
    jz .no                 ; If input is 0, it's not a power of two → jump to .no

    mov r8d, ecx           ; Copy the input number to r8d (temporary register)
    dec r8d                ; Compute (n - 1)

    test ecx, r8d          ; Bitwise AND: n & (n - 1)
                           ; If result is 0, then n is a power of two
    jz .yes                ; Jump to .yes if the result is zero

.no:
    lea rcx, [rel noMsg]   ; Load address of "No" message into RCX (first argument to puts)
    xor rax, rax           ; Clear RAX as a Windows ABI safety for variadic functions
    call puts              ; Call puts("No")
    jmp .done              ; Jump to .done to clean up and return

.yes:
    lea rcx, [rel yesMsg]  ; Load address of "Yes" message into RCX
    xor rax, rax           ; Clear RAX (again for ABI safety)
    call puts              ; Call puts("Yes")

.done:
    add rsp, 40            ; Restore the stack (undo sub rsp, 40)
    ret                    ; Return to the caller
