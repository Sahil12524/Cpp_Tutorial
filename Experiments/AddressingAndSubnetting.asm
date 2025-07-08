; File: AddressingAndSubnetting.asm
;
; Purpose:
;     Computes both the network and broadcast address of an IPv4 address using SSE2 instructions.
;     This is achieved by performing vectorized bitwise AND and OR operations on 4 integers (16 bytes).
;
; Function Signature (Windows x64 ABI):
;     void AddressingAndSubnetting(int* ipAddress, int* networkMask, int* resultNetwork, int* resultBroadcast)
;
; Parameters:
;     RCX -> ipAddress[4]        ; Input IPv4 address (4 x 32-bit ints)
;     RDX -> networkMask[4]      ; Input subnet mask (4 x 32-bit ints)
;     R8  -> resultNetwork[4]    ; Output: network address
;     R9  -> resultBroadcast[4]  ; Output: broadcast address
;
; Return:
;     None (results are written directly to memory via pointers)
;
; Notes:
;     - Uses movdqu and pand/por/pxor SSE2 instructions for parallel computation.
;     - Broadcast is computed as (ip | ~mask), then masked to retain only the lowest 8 bits per octet.
;     - An aligned 128-bit mask is used from .rodata for the 0xFF clamp.
;
; Example Computation:
;     Network   = ip[i] & mask[i]
;     Broadcast = (ip[i] | (~mask[i])) & 0xFF
;

section .text
    global AddressingAndSubnetting

AddressingAndSubnetting:
    ; Load all values as bytes
    movdqu xmm0, [rcx]      ; Load IP address (4 ints)
    movdqu xmm1, [rdx]      ; Load network mask (4 ints)
    
    ; Calculate network address (IP & mask)
    pand xmm0, xmm1
    movdqu [r8], xmm0       ; Store network address

    ; Calculate broadcast address (IP | ~mask)
    pcmpeqd xmm3, xmm3      ; xmm3 = 0xFFFFFFFF
    pxor xmm1, xmm3         ; xmm1 = ~mask
    movdqu xmm2, [rcx]      ; Reload original IP
    por xmm2, xmm1          ; xmm2 = IP | ~mask
    
    ; Mask to keep only low 8 bits of each component
    movdqa xmm4, [rel mask_8bits]  ; Use RIP-relative addressing
    pand xmm2, xmm4         ; Keep only low 8 bits
    movdqu [r9], xmm2       ; Store broadcast address

    ret

section .rodata
align 16
mask_8bits: dd 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF