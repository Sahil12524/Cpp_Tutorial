 ; ToggleSpecificBit.asm
 ; ----------------
 ; Problem: Toggle (flip) the k-th bit (0-indexed) of a number.
 ; Input:
 ;   ECX = number
 ;   EDX = bit position k (0 = LSB)
 ; Output:
 ;   EAX = number with k-th bit flipped
 ; Logic:
 ;   Create a mask with a 1 at the k-th position.
 ;   Use XOR operation to toggle the k-th bit.
 ; Windows x64 calling convention.

section .text
    global ToggleSpecificBit

ToggleSpecificBit:
    xor rax, rax    ; Clear rax
    mov r9d, ecx    ; Shifted number to r9d

    mov cl, dl      ; 8bit operation for shifting

    xor r8d, r8d    ; Zeroing r8d
    inc r8d         ; r8d is now r8d++ (r8d = 1)
    shl r8d, cl     ; Masking


    xor r9d, r8d    ; Xoring number with the mask
    mov eax, r9d    ; Shifted the result from r9d to eax

.done:
    ret             ; Clean exit