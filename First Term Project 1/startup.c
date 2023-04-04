#include <stdint.h>

/*#define stack_top	0x20001000*/

extern int main(void);

extern uint32_t _stack_top;
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

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault_Handler,
	(uint32_t) &Usage_fault_Handler,
};