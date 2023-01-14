#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


/*GPIO*/
#define GPIOA_BASE		0x40010800
#define GPIOA_CRL		(*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_CRH		(*(volatile uint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR		(*(volatile uint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA13			(1U << 13)

/*RCC*/
#define RCC_BASE		0x40021000
#define RCC_CFGR		(*(volatile uint32_t*)(RCC_BASE + 0x04))
#define RCC_APB2ENR		(*(volatile uint32_t*)(RCC_BASE + 0x18))
#define RCC_APB1ENR		(*(volatile uint32_t*)(RCC_BASE + 0x1C))
#define RCC_AFIOEN		(1U << 0)
#define RCC_IOPAEN		(1U << 2)


/*EXTI*/
#define EXTI_BASE		0x40010400
#define EXTI_IMR		(*(volatile uint32_t*)(EXTI_BASE + 0x00))
#define EXTI_EMR		(*(volatile uint32_t*)(EXTI_BASE + 0x04))
#define EXTI_RTSR		(*(volatile uint32_t*)(EXTI_BASE + 0x08))
#define EXTI_PR			(*(volatile uint32_t*)(EXTI_BASE + 0x14))

/*AFIO*/
#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1	(*(volatile uint32_t*)(AFIO_BASE + 0x08))

/*NVIC*/
#define NVIC_EXTIE0		(*(volatile uint32_t*)(0xE000E100))


void clock_init(void)
{
	/*Enable GPIOA Clock*/
	RCC_APB2ENR |= RCC_IOPAEN;

	/*Enable GPIOA Clock*/
	RCC_APB2ENR |= RCC_AFIOEN;
}

void GPIO_init(void)
{
	/*Pin A13 is output*/
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	/*Pin A0 is input floating*/
	GPIOA_CRL |= (1U << 2);
}


int main(void)
{
	clock_init();
	GPIO_init();

	/**/
	AFIO_EXTICR1 = 0;

	/*Enable EXTI Line 0 (Mask 1)*/
	EXTI_IMR |= (1 << 0);

	/*Enable Rising Trigger*/
	EXTI_RTSR |= (1 << 0);

	/* NVIC IRQ6 at EXTI0*/
	NVIC_EXTIE0 |= (1U << 6);

	while(1);

	return 0;
}

void EXTI0_IRQHandler(void)
{
	/*IRQ is happened at EXTI0 at PORTA Pin0 RISING EDGE*/
	/*Toggle LED  Pin A13*/
	GPIOA_ODR ^= GPIOA13;

	/*Clean Pending request for Line 0*/
	EXTI_PR |= (1 << 0);
}




