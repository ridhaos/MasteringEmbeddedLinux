.section ".text.boot"
.global _start
_start:
    ldr x0, =_stack_top
    mov sp, x0
    bl  main
1:  b   1b

.section .bss
.align 11
_stack:
    .skip 8192
_stack_top:
