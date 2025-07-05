ENTRY(main)

SECTIONS
{
    . = 0x00200000;          /* Pi 4 loader destination */
    .text :  { 
        *(.text.main) 
        *(.text*) 
    }
    .rodata :{ *(.rodata*) }
    .data :  { *(.data*) }
    .bss  :  { *(.bss*)  }
}