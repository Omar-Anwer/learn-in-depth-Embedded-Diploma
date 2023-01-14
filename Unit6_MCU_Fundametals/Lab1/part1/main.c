typedef volatile unsigned int vuint32_t;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


/*GPIO*/
#define GPIOA_BASE		0x40010800
#define GPIOA_CRH		(*(volatile uint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR		(*(volatile uint32_t*)(GPIOA_BASE + 0x0C))

/*RCC*/
#define RCC_BASE		0x40021000
#define RCC_CFGR		(*(volatile uint32_t*)(RCC_BASE + 0x04))
#define RCC_APB2ENR		(*(volatile uint32_t*)(RCC_BASE + 0x18))
#define RCC_APB1ENR		(*(volatile uint32_t*)(RCC_BASE + 0x1C))


int main(void)
{
	RCC_CFGR	|= (0b100 << 8);		/*PRE1*/
	/*
	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
	*/
	
	RCC_CFGR	|= (0b101 << 11);		/*PRE2*/
	/*
	its 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
	*/
	
	RCC_APB2ENR |= (1U << 2);
	
	GPIOA_CRH	&= 0xFF0FFFFF;
	GPIOA_CRH	|= 0x00200000;
	
	while(1)
	{
		GPIOA_ODR |= (1U << 13);
		
		int i;
		for(i = 0; i < 5000; i++);
		
		GPIOA_ODR &= ~(1U << 13);
		
		for(i = 0; i < 5000; i++);
	}
	
	return 0;
}




