#include <stdint.h>

/*#define stack_top	0x20001000*/

extern int main(void);

/*locating 1024B in .bss through uninitialized static array of 4B*256=1024*/
static uint32_t stack_top[256]; 

extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void Reset_Handler(void)
{
	/* copy .data section byte by byte from FLASH to SRAM */
	uint8_t* pSrc = (uint8_t*)(&_E_text);
	uint8_t* pDst = (uint8_t*)(&_S_data);
	uint32_t DATA_SIZE = (uint8_t*)(&_E_data) - (uint8_t*)(&_S_data);
	
	uint32_t i;
	for(i = 0; i < DATA_SIZE; ++i)
	{
		*pDst = *pSrc;
		pSrc++;
		pDst++;
	}
	
	/* initialize .data section in SRAM */
	pDst = (uint8_t*)(&_S_bss);
	uint32_t BSS_SIZE = (uint8_t*)(&_E_bss) - (uint8_t*)(&_S_bss);

	for(i = 0; i < BSS_SIZE; ++i)
	{
		*pDst = 0;
		pDst++;
	}
	
	/* jump to main() */
	main();
}

/* initialize vectors */
void Default_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler(void)			__attribute__(( weak, alias("Default_Handler") ));
void H_fault_Handler(void)		__attribute__(( weak, alias("Default_Handler") ));
void MM_fault_Handler(void)		__attribute__(( weak, alias("Default_Handler") ));
void Bus_fault_Handler(void)	__attribute__(( weak, alias("Default_Handler") ));
void Usage_fault_Handler(void)	__attribute__(( weak, alias("Default_Handler") ));


void (* const vectors[])(void)  __attribute__((section(".vectors"))) = {
	(void (*) ()) ((uint32_t)stack_top + sizeof(stack_top) ),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_fault_Handler,
	&Bus_fault_Handler,
	&Usage_fault_Handler
};