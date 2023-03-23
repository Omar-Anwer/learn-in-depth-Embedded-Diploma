typedef volatile unsigned int vuint32_t;
#include <stdint.h>

/*RCC*/
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		(*(volatile uint32_t*)(RCC_BASE + 0x18))
#define RCC_IOPAEN		(1<<2)

/*GPIO*/
#define GPIO_BASE		0x40010800
#define GPIO_CRH		(*(volatile uint32_t*)(GPIO_BASE + 0x04))
#define GPIO_ODR		(*(volatile uint32_t*)(GPIO_BASE + 0x0C))
#define GPIO_A13		(1UL<<13)

typedef union
{
	vuint32_t all_fields;
	
	struct
	{
		vuint32_t reserved: 13;
		vuint32_t P13:		1;
	}Pin;
	
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_BASE + 0x0C);
unsigned char g_variables[3] = {1, 2, 3};
unsigned char const const_variables[3] = {1, 2, 3};

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIO_CRH	&= 0xFF0FFFFF;
	GPIO_CRH	|= 0x00200000;
	
	while(1)
	{
		R_ODR->Pin.P13 = 1;
		
		int i;
		for(i = 0; i < 5000; i++);
		
		R_ODR->Pin.P13 = 0;
		
		for(i = 0; i < 5000; i++);
	}
	
	return 0;
}




