/*
 * Pressure_Sensor.c
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "driver.h"
#include "Pressure_Sensor.h"

int g_pressureVal;

void PressureSensor_Init(void)
{
  g_pressureVal = 0;
}


void getPressureVal(void)
{
  g_pressureVal  = (GPIOA_IDR & 0xFF);
}
