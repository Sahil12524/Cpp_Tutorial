 ; SetSpecificBit.asm
 ; --------------
 ; Problem: Set the k-th bit (0-indexed) of a number to 1.
 ; Input:
 ;   ECX = number
 ;   EDX = bit position k (0 = LSB)
 ; Output:
 ;   EAX = number with k-th bit set to 1
 ; Logic:
 ;   Create a mask with a 1 at the k-th position.
 ;   Use OR operation to set the k-th bit to 1.
 ; Windows x64 calling convention.

section .text
    global SetSpecificBit

SetSpecificBit:
    xor rax, rax
    mov r9d, ecx
    mov cl, dl

    xor r8, r8
    inc r8

    shl r8, cl

    or r9d, r8d
    mov eax, r9d

.done:
    ret