/*
 * Pressure_Sensor.h
 *
 *  Created on: Apr 4, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"
#include "driver.h"


void PressureSensor_Init(void);


/* State pointer to functions */
extern void (*PS_STATE) ();

STATE_DEFINE(PS_READING);


#endif /* PRESSURE_SENSOR_H_ */
