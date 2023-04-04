/*
 * main.c
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */

#include "driver.h"
#include "Alarm.h"
#include "Pressure_Sensor.h"


extern int g_pressureVal;


int main(void)
{
  GPIO_INITIALIZATION();
  PressureSensor_Init();
  Alarm_Init();


  while (1)
  {
    /* getPressureVal */
    getPressureVal();

    /* storePressureVal (optional) */

    /* Monitor Alarm */
    if(g_pressureVal > PRESSURE_THRESHOLD)
    {
      StartAlarm();
      Delay(ALARM_TIME_PERIOD);
      StopAlarm();
    }
    else
    {
      /**/
    }
  }

  return 0;

}
