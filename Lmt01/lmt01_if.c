//****************************************************************************
// Filename: lmt01_if.h
// Brief Description: 	This is the source file for LMT01 temperature sensor driver.
//						Contains function definitions for controlling and processing LMT01
//						IO interrupt interface.
//
//****************************************************************************

#include "lmt01_if.h"

#ifdef ON_STM32
//******************************************************************************
// Name:        lmt01_If_EnableInterrupt
// Description: Enables the interrupt on Pin specified in the params
// Parameters:  gpioIntPin @ref TInterruptIo - Gpio Interrupt Pin
// Returns:     @ref TLmt_if_Ret
//******************************************************************************
TLmt_if_Ret lmt01_If_EnableInterrupt(  TInterruptIo gpioIntPin )
{
	TLmt_if_Ret ERet = eLMT01_IF_SUCCESS;

	HAL_NVIC_EnableIRQ( gpioIntPin );

	return ERet;
}

//******************************************************************************
// Name:        lmt01_If_DisableInterrupt
// Description: Disables the interrupt on Pin specified in the params
// Parameters:  gpioIntPin @ref TInterruptIo - Gpio Interrupt Pin
// Returns:     @ref TLmt_if_Ret
//******************************************************************************
TLmt_if_Ret lmt01_If_DisableInterrupt(  TInterruptIo gpioIntPin )
{
	TLmt_if_Ret ERet = eLMT01_IF_SUCCESS;

	HAL_NVIC_DisableIRQ( gpioIntPin );

	return ERet;
}
#endif

/*************************************END OF FILE******************************************/
