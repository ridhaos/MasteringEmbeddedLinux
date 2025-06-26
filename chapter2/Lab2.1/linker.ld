SECTIONS
{
    . = 0x80000;          /* Pi 4 loader destination */
    .text :  { *(.text.boot) }
    .text :  { *(.text*) }
    .rodata :{ *(.rodata*) }
    .data :  { *(.data*) }
    .bss  :  { *(.bss*)  }
}