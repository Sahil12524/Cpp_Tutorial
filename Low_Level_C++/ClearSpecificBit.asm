 ; ClearSpecificBit.asm
 ; --------------
 ; Problem: Clear (set to 0) the k-th bit (0-indexed) of a number.
 ; Input:
 ;   ECX = number
 ;   EDX = bit position k (0 = LSB)
 ; Output:
 ;   EAX = number with k-th bit cleared (0)
 ; Logic:
 ;   Create a mask with a 0 at the k-th position.
 ;   Use AND operation to clear the k-th bit.
 ; Windows x64 calling convention.

section .text
    global ClearSpecificBit

ClearSpecificBit:
    xor rax, rax    ; rax is cleared
    mov r9d, ecx    ; moved ecx into r9d (r9d now has number)

    mov cl, dl      ; 8 bit operation (moved the index from dl to cl) 

    xor r8d, r8d    ; r8d = 0
    inc r8d         ; r8d = 1

    shl r8d, cl     ; masking
    not r8d         ; flipping the mask
    and r9d, r8d    ; anded number with mask
    mov eax, r9d    ; moved the result into eax and returned

.done:
    ret             ; clean exit