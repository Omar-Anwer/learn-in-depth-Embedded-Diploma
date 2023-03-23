/*
	Linker script for Cortex-M3
	By Eng.Omar
*/

/* Entry Point */
ENTRY(_reset)


/* Memories definition */
MEMORY
{
	FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 512M
	SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 512M
}

/* Sections */
SECTIONS
{
	/* 
	.startup :
	{
		startup.o(.text)
		. = ALIGN(4);
	}>FLASH
	*/
	.text :
	{
		. = ALIGN(4);
		*(.vectors*)
		*(.text*)
		. = ALIGN(4);
		_E_text = .;
	}>FLASH
	
	
	/* Constant data into "FLASH" Rom type memory */
	.rodata:
	{
		*(.rodata)      /* .rodata sections (constants, strings, etc.) */
	}>FLASH
	
	
	/* Initialized data sections into "RAM" Ram type memory */
	.data :
	{
		_S_data = .;
		*(.data)
		. = ALIGN(4);
		_E_data = .;
	}>SRAM AT>FLASH
	
	/* Uninitialized data section into "RAM" Ram type memory */
	.bss :
	{
		_S_bss = .;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = .;
	}>SRAM
}