
//****************************************************************************
// Filename: lmt01_if.h
// Brief Description: 	This header file includes macros, typedefs and function declarations
//						for interface file for LMT01 driver
//
//****************************************************************************/*

#ifndef LMT01_LMT01_IF_H_
#define LMT01_LMT01_IF_H_

#ifdef ON_STM32
#include "stm32f4xx_hal.h"
#endif

/*Return type for LMT01 interface function*/
typedef enum
{
	eLMT01_IF_FAILURE,
	eLMT01_IF_SUCCESS
}TLmt_if_Ret;

#ifdef ON_STM32
/*User type for hiding STM32 HAL layer IRQ type*/
typedef IRQn_Type TInterruptIo;

TLmt_if_Ret lmt01_If_EnableInterrupt( TInterruptIo pstGpioIntPin );
TLmt_if_Ret lmt01_If_DisableInterrupt(  TInterruptIo pstGpioIntPin );
#endif

#endif /* LMT01_LMT01_IF_H_ */

/*************************************END OF FILE******************************************/
