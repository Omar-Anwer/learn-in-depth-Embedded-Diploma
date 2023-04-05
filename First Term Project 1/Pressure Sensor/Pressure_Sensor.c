/*
 * Pressure_Sensor.c
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "Pressure_Sensor.h"

extern int g_pressureVal;

void PressureSensor_Init(void)
{
 /* Sensor Driver Init */
}

/* state ptr to function*/
void (*PS_STATE) (void);

/* define states */
enum
{
  PS_READING,
}PS_STATE_ID;

STATE_DEFINE(PS_READING)
{
  PS_STATE_ID = PS_READING;
  g_pressureVal = getPressureVal();
}

