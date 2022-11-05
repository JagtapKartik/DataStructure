//****************************************************************************
// Filename: lmt01.h
// Brief Description: 	This header file includes macros, typedefs and function declarations
//						for LMT01 thermal diode driver.
//
//****************************************************************************

#ifndef LMT01_LMT01_H_
#define LMT01_LMT01_H_

#ifdef ON_STM32
#include "lmt01_if.h"
#endif
#include <stdio.h>
#include <stdint.h>
#include "stdbool.h"

/*Double buffer implementation for counts to ignore the first one and use the second one for calculation*/
#define LMT_MAX_PULSE_COUNT_BUFFER_LEN	( 2 )

/*Return type for LMT01*/
typedef enum
{
	eLMT01_FAILURE,
	eLMT01_SUCCESS,
}TLmt01_Ret;

/*Sensor Object*/
typedef struct
{
	uint8_t uiPulseCountBufferIndex;
	bool bIsBufferReadyForCalc;
	uint16_t pulseCounts[ LMT_MAX_PULSE_COUNT_BUFFER_LEN ];
	float fTemperature;
	uint8_t ucNoPulseDetectionTimeout;
#ifdef ON_STM32
	TInterruptIo stGpioInthandler;
#endif
}TLmt01_Object;

TLmt01_Ret lmt01_Init( TLmt01_Object *pstInstance );
TLmt01_Ret lmt01_EnableSensing( TLmt01_Object *pstInstance );
TLmt01_Ret lmt01_GetTemperatureValue( TLmt01_Object *pstInstance );
TLmt01_Ret lmt01_DisableSensing( TLmt01_Object *pstInstance );

#endif /* LMT01_LMT01_H_ */

/*************************************END OF FILE******************************************/
