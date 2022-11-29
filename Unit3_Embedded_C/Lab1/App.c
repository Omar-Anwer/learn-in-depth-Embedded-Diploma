#include "UART.h"

const unsigned char buffer[100] = "learn-in-depth:Omar";
void main(void)
{
	UART_Send_String(buffer);
}