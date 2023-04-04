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

#define PRESSURE_THRESHOLD      (20U)   /* 20 bar*/


void PressureSensor_Init(void);
void getPressureVal(void);


#endif /* PRESSURE_SENSOR_H_ */
