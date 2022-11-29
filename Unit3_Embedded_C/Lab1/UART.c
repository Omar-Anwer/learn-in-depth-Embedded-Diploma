#include "UART.h"

/* UART Registers */
#define UART0DR (*(volatile unsigned int*)	0x101f1000)

/* UART Functions */
void UART_Send_String(const char* pStr)
{
	while(*pStr != '\0')
	{
		UART0DR = *pStr;
		pStr++;
	}
}
