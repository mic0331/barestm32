/*Entry Point*/
ENTRY(Reset_Handler)

/*specify Memory Map*/
MEMORY
{
    flash0 (rx) : org = 0x08000000, len = 512k
    ram0   (wx) : org = 0x20000000, len = 96k   /* SRAM */
}

_estack = ORIGIN(ram0) + LENGTH(ram0);

/*Define Sections*/
SECTIONS
{
    .isr_vector : 
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } >flash0

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
    } >flash0

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >ram0 AT> flash0

    _sidata = LOADADDR(.data);

    .bss :
    {
        _sbss = .;
        __bsstart__  = _sbss;
        *(.bss)
        *(.bss*)
        *(COMMON)

        _ebss = .;
        __bss_end__ = _ebss;
    } >ram0
}