
/*SYSCTL*/
#define SYSCTL_RCGC2_R		(*(volatile unsigned long*) 0x400FE108)

/*GPIO-F*/
#define GPIO_PORTF_DIR_R	(*(volatile unsigned long*) 0x40025400)
#define GPIO_PORTF_DEN_R	(*(volatile unsigned long*) 0x4002551C)
#define GPIO_PORTF_DATA_R	(*(volatile unsigned long*) 0x400253FC)


int main(void)
{
	SYSCTL_RCGC2_R = 0x20;
	
	volatile unsigned long delay_cnt;
	for(delay_cnt = 0; delay_cnt < 200; delay_cnt++); /*delay to make setup GPIO*/
	
	GPIO_PORTF_DIR_R |= 1<<3;	/* Dir: output */
	GPIO_PORTF_DEN_R |= 1<<3;	/* enable */
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_cnt = 0; delay_cnt < 200000; delay_cnt++); /*delay*/		
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_cnt = 0; delay_cnt < 200000; delay_cnt++); /*delay*/
	}
	
	
	return 0;
}




