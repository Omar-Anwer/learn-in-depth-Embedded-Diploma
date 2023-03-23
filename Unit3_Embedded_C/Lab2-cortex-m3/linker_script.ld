/*
	Linker script Cortex-M3
	By Eng.Omar
*/

MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K

}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}>FLASH
	
	.data :
	{
		_S_data = .;
		*(.data)
		. = ALIGN(4);
		_E_data = .;
	}>SRAM AT>FLASH
	
	.bss :
	{
		_S_bss = .;
		*(.bss*)
		_E_bss = .;
		. = ALIGN(4);
		. = . + 0x1000; 
		_stack_top = .;		/*stack top after 4 KB*/
	}>SRAM
}