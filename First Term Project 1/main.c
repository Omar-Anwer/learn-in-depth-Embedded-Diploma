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
#include "App.h"


int main(void)
{
  GPIO_INITIALIZATION();

  PressureSensor_Init();
  Alarm_Init();

  ALARM_STATE = STATE(ALARM_WAITING);
  PS_STATE = STATE(PS_READING);
  PRESSURE_DETECTION_STATE = STATE(PRESSURE_DETECTION);

  while (1)
  {
    PS_STATE();
    PRESSURE_DETECTION_STATE();
    ALARM_STATE();
  }

  return 0;

}
