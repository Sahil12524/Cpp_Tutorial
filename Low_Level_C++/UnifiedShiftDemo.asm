; UnifiedShiftDemo.asm
; --------------------
; Problem: Perform one of the four shifts (SAR, SAL, SHL, SHR) on a 32-bit signed integer.
;
; Inputs:
;   ECX = integer value
;   EDX = shift amount
;   R8D = operation code:
;         0 = SAR (signed right)
;         1 = SAL (signed left)
;         2 = SHL (logical left)
;         3 = SHR (logical right)
;
; Output:
;   EAX = result of the shift
;
; Logic:
;   - Copy ECX to EAX
;   - Based on opcode in R8D, perform the appropriate shift
;   - Use CL as shift count (from DL)
;
; Windows x64 calling convention
section .rdata
    align 8    ; Align jump table to 8-byte boundary (64-bit pointers)
    
.jump_table:
    dq .SAR    ; Address of SAR handler (opcode 0)
    dq .SAL    ; Address of SAL handler (opcode 1)
    dq .SHL    ; Address of SHL handler (opcode 2)
    dq .SHR    ; Address of SHR handler (opcode 3)

section .text
    global UnifiedShiftDemo

UnifiedShiftDemo:
    ; Initialize
    mov     eax, ecx        ; Copy input value to EAX (where result will be stored)
    movzx   ecx, dl         ; Zero-extend shift count from DL to CL (avoiding partial register stalls)
    
    ; Validate opcode range (0-3)
    mov     r10d, r8d       ; Copy opcode to temporary register
    and     r10d, ~3        ; Mask all bits except 0-1 (if result !=0, opcode is invalid)
    jnz     .default_case   ; Jump to error handler if opcode >3
    
    ; Jump table dispatch
    lea     r11, [rel .jump_table]  ; Load RIP-relative address of jump table
    jmp     [r11 + r8*8]    ; Jump to handler based on opcode (scale by 8 for 64-bit pointers)

; ----- Shift Operations -----
.SAR:
    sar     eax, cl         ; Signed Arithmetic Right Shift (preserves sign bit)
    ret

.SAL:
    sal     eax, cl         ; Signed Arithmetic Left Shift (same as SHL)
    ret

.SHL:
    shl     eax, cl         ; Logical Left Shift (identical to SAL)
    ret

.SHR:
    shr     eax, cl         ; Logical Right Shift (fills with zeros)
    ret

; ----- Error Handling -----
.default_case:
    xor     eax, eax        ; Return 0 for invalid opcodes
    ret