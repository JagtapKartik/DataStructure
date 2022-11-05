//******************************************************************************
// Filename: opb_IR_Sensor.h
// Brief Description: This file contain variables, function prototypes used in
// opb_IR_Sensor.c
//
// Detailed description:
//  >Included required header files
//  >Enum for driver return value, sensor status
//  >Function prototypes
//  >structure definition for IR sensor object
//******************************************************************************

#ifndef PERIPHERALS_DRIVERS_OPB732VACMSTNSENSOR_OPB_IR_SENSOR_H_
#define PERIPHERALS_DRIVERS_OPB732VACMSTNSENSOR_OPB_IR_SENSOR_H_

#ifdef ON_STM32
#include "gpio_if.h"
#include "stm32f4xx_hal.h"
#endif

#include <stdio.h>


typedef void ( *TcbIRSensor_t )( void );

/* Enum for opb ir Sensor status */
typedef enum
{
	eOPB_ACTIVATED, 	/* opb ir Sensor status activated */
	eOPB_DEACTIVATED	/* opb ir Sensor status deactivated */
}TOpb_Status;

/* Enum for opb ir Sensor control pin status */
typedef enum
{
	eOPB_ENABLED,      	/* opb ir Sensor control pin status enabled */
	eOPB_DISABLED		/* opb ir Sensor control pin status disabled */
}TOpb_CtrStatus;

/* Enum for opb ir Sensor module return values */
typedef enum
{
	eOPB_SUCCESS,  		/* opb ir Sensor module return Success */
	eOPB_FAILURE		/* opb ir Sensor module return Failure */
}TOpb_ret;

/* Structure for opb ir Sensor object */
typedef struct
{
	TOpb_Status EStatus;  	//opb ir Sensor status
#ifdef ON_STM32
	TGpio  ioCntrl;			//opb ir Sensor contorl IO
	TGpio  ioOutput;		//opb ir Sensor output IO
#endif
	TcbIRSensor_t irCb;		//opb ir Sensor callback
}Topb_IR_object;

/* Function prototypes */
TOpb_ret opb_EnableIRSensor( Topb_IR_object *pstIRSensorInstance );

TOpb_ret opb_DisableIRSensor( Topb_IR_object *pstIRSensorInstance );

TOpb_ret readStatus_OPB_IRSensor(Topb_IR_object *pstIRSensorInstance, TOpb_Status *pEstatus );

TOpb_ret register_IRSensorCallback( Topb_IR_object *pstIRSensorInstance, TcbIRSensor_t cb );

#endif /* PERIPHERALS_DRIVERS_OPB732VACMSTNSENSOR_OPB_IR_SENSOR_H_ */
