; FindIndexOfLastNegativeTest.asm
; ----------------------
; int FindIndexOfLastNegative(const int* input, size_t size)
;
; This function returns the index of the last negative number in the array.
; If no negative exists, return -1.
;
; Parameters:
;   RCX = pointer to input array
;   RDX = size of the array
;
; Returns:
;   RAX = index of last negative number, or -1 if none found
;
; --- Implementation to be done by you ---
; Tip: Traverse the array forward, update RAX whenever a negative number is found.

section .text
    global FindIndexOfLastNegative

FindIndexOfLastNegative:
    cmp rdx, 0
    je .done

    push rsi
    xor r8, r8
    mov eax, -1
    
.loop_start:
    cmp r8, rdx
    jae .done

    mov esi, [rcx + r8 * 4]
    test esi, esi
    jns .next

    mov eax, r8d

.next:
    inc r8
    jmp .loop_start

.done:
    pop rsi
    ret