#include "driver.h"

void Delay(unsigned int nCount)
{
	for(; nCount != 0; nCount--);
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}

void Set_Alarm_actuator(int i)
{
  if (i)
  {
    RESET_BIT(GPIOA_ODR, 13);
  }
  else
  {
    SET_BIT(GPIOA_ODR, 13);
  }
}

int getPressureVal(void)
{
  return (GPIOA_IDR & 0xFF);
}
