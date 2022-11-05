//******************************************************************************
// Filename: photoMicroSensor.h
// Brief Description: This file contain variables, function prototypes used in
// photoMicroSensor.c
//
// Detailed description:
//  >Included required header files
//  >Enum for driver return value, sensor status
//  >Function prototypes
//  >Structure definition for sensor object
//******************************************************************************

#ifndef PERIPHERALS_DRIVERS_PHOTOMICROSENSOR_PHOTOMICROSENSOR_H_
#define PERIPHERALS_DRIVERS_PHOTOMICROSENSOR_PHOTOMICROSENSOR_H_

#ifdef ON_STM32
#include "gpio_if.h"
#include "stm32f4xx_hal.h"
#endif

#include <stdio.h>

typedef void ( *TCbHomePositionSensor )( void );

/* Enum for home position Sensor status */
typedef enum
{
	eHOMEPOSITION_ACTIVATED,	/* Home position sensor status activated */
	eHOMEPOSITION_DEACTIVATED   /* Home position sensor status deactivated */
}THomePos_Sensor_Status;

/* Enum for home position Sensor module return values */
typedef enum
{
	eHOMEPOSITION_SUCCESS, 		/* home position Sensor module return Success */
	eHOMEPOSITION_FAILURE		/* home position Sensor module return Failure */
}THomePos_Sensor_ret;

/* Structure for home position sensor object */
typedef struct
{
	THomePos_Sensor_Status EStatus;   		//status of the home position sensor
#ifdef ON_STM32
	TGpio  ioOutput;						//home position sensor output IO
#endif
	TCbHomePositionSensor homePosSensorcb;  //home position callback
}THomePos_Sensor_object;

/* Function prototypes */
THomePos_Sensor_ret readStatus_HomePosition_Sensor( THomePos_Sensor_object *pstHomePosSensorInstance, THomePos_Sensor_Status *pEstatus );

THomePos_Sensor_ret register_HomePositionSensor_Callback( THomePos_Sensor_object *pstHomePosSensorInstance, TCbHomePositionSensor cb );

#endif /* PERIPHERALS_DRIVERS_PHOTOMICROSENSOR_PHOTOMICROSENSOR_H_ */
