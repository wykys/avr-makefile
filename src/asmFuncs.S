; Set offset for control register addresses (NEEDED)
#define __SFR_OFFSET 0

;Defines I/O port aliases
#include <avr/io.h>


;----------------------------------------------------------------------
; Load input vector elements and store them to output vector
; param r25:r24 - Pointer to input vector
; param r23:r22 - Pointer to output vector
; param r20 - Vectors' length
; return None
;----------------------------------------------------------------------
    .global asm_copy
    .func asm_copy
asm_copy:
    push r31            ; Backup all registers going to use
    push r30
    push r29
    push r28
    push r16
    push r17
    push r18
    movw r30, r24       ; Copy input pointer to Z (r31:r30) vstupní pole
    movw r28, r22       ; Copy output pointer to Y (r29:r28) vystupni pole
    ldi r18, 0
load:
    ld r16, Z+          ; Load one vector element
    mov r18, r17
    mov r17, r16
    add r16, r18
    st Y+, r16          ; Store one vector element
    dec r20             ; Decrement vectors' length
    brne load           ; If not zero go back
    pop r18
    pop r17
    pop r16             ; Reload all used registers
    pop r28
    pop r29
    pop r30
    pop r31
    ret                 ; Return from function
    .endfunc
