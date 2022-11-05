//****************************************************************************
// Filename: lmt01.h
// Brief Description: 	This is the source file for LMT01 temperature sensor driver.
//						Contains function definitions for controlling and processing LMT01.
//
//****************************************************************************

#include "lmt01.h"

//******************************************************************************
// Name:        lmt01_Init
// Description: Initialises the members of the instances and disables the interrupts on them by default
// Parameters:  pstInstance @ref TLmt01_Object - Pointer to the LMT01 sensor instance
// Returns:     @ref TLmt_if_Ret
//******************************************************************************
TLmt01_Ret lmt01_Init( TLmt01_Object *pstInstance )
{
	TLmt01_Ret ERet = eLMT01_SUCCESS;

	if( NULL == pstInstance )
	{
		ERet = eLMT01_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		if( eLMT01_IF_SUCCESS != lmt01_If_DisableInterrupt( pstInstance->stGpioInthandler ) )
		{
			ERet = eLMT01_FAILURE;
		}
#endif
		pstInstance->pulseCounts[0] = 0;		/*Count buffer 1 cleared*/
		pstInstance->pulseCounts[1] = 0;		/*Count buffer 2 cleared*/
		pstInstance->uiPulseCountBufferIndex = 0;	/*Count Buffer index set to 0*/
		pstInstance->fTemperature = 0.0;			/*Default*/
		pstInstance->bIsBufferReadyForCalc = false;	/*Ready flag cleared*/
		pstInstance->ucNoPulseDetectionTimeout = 0;		/*No Pulse Detection timeout count cleared*/
	}

	return ERet;
}


//******************************************************************************
// Name:        lmt01_EnableSensing
// Description: Enables sensing on the given sensor instance enabling the interrupts
// Parameters:  pstInstance @ref TLmt01_Object - Pointer to the LMT01 sensor instance
// Returns:     @ref TLmt01_Ret
//******************************************************************************
TLmt01_Ret lmt01_EnableSensing( TLmt01_Object *pstInstance )
{
	TLmt01_Ret ERet = eLMT01_SUCCESS;

	if( NULL == pstInstance )
	{
		ERet = eLMT01_FAILURE;
	}
	else
	{
		/*Set all the members to defaults before enabling interrupt IO interface*/
		pstInstance->uiPulseCountBufferIndex = 0;
		pstInstance->pulseCounts[0] = 0;
		pstInstance->pulseCounts[1] = 0;
		pstInstance->bIsBufferReadyForCalc = false;
		pstInstance->ucNoPulseDetectionTimeout = 0;
#ifdef ON_STM32
		if( eLMT01_IF_SUCCESS != lmt01_If_EnableInterrupt( pstInstance->stGpioInthandler ) )
		{
			ERet = eLMT01_FAILURE;
		}
#endif
	}

	return ERet;
}

//******************************************************************************
// Name:        lmt01_GetTemperatureValue
// Description: Measures the temperature for the given sensor instance and stores the result in the member fTemperature
// Parameters:  pstInstance @ref TLmt01_Object - Pointer to the LMT01 sensor instance
// Returns:     @ref TLmt01_Ret
//******************************************************************************
TLmt01_Ret lmt01_GetTemperatureValue( TLmt01_Object *pstInstance )
{
	TLmt01_Ret ERet = eLMT01_SUCCESS;

	if( NULL == pstInstance )
	{
		ERet = eLMT01_FAILURE;
	}
	else
	{
		float fResult = 0.0;
		/*Refer Datasheet for calculations*/
		fResult = ( ( pstInstance->pulseCounts[1] * 256.0 / 4096.0 ) - 50.0 );
		pstInstance->fTemperature = fResult;
	}

	return ERet;
}

//******************************************************************************
// Name:        lmt01_DisableSensing
// Description: Disabes the sensor by disabling the interrupt on the input pin
// Parameters:  pstInstance @ref TLmt01_Object - Pointer to the LMT01 sensor instance
// Returns:     @ref TLmt01_Ret
//******************************************************************************
TLmt01_Ret lmt01_DisableSensing( TLmt01_Object *pstInstance )
{
	TLmt01_Ret ERet = eLMT01_SUCCESS;

	if( NULL == pstInstance )
	{
		ERet = eLMT01_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		if( eLMT01_IF_SUCCESS != lmt01_If_DisableInterrupt( pstInstance->stGpioInthandler ) )
		{
			ERet = eLMT01_FAILURE;
		}
#endif
	}

	return ERet;
}

#ifdef INTERRUPT_ROUTINE_SNIPPET
/*Example snippet to be used in Pin interrupt Routine*/
extern TLmt01_Object stTempSensor;
stTempSensor.pulseCounts[0]++;
stTempSensor.ucNoPulseDetectionTimeout = 3;

/*Example snippet to be used in Window detection timer interrupt Routine*/
extern TLmt01_Object stTempSensor;
if( stTempSensor.ucNoPulseDetectionTimeout != 0 )
{
	stTempSensor.ucNoPulseDetectionTimeout--;
	if( 0 == stTempSensor.ucNoPulseDetectionTimeout )
	{
		lmt01_DisableSensing();
		stTempSensor.bIsBufferReadyForCalc = true;
	}
}

/*Called once during Initialisation*/
lmt01_EnableSensing( TLmt01_Object *pstInstance );

/*Call in main while*/
if( stTempSensor.bIsBufferReadyForCalc )
{
  lmt01_GetTemperatureValue();
  stTempSensor.bIsBufferReadyForCalc = 0;
  lmt01_EnableSensing();
}
#endif

/*************************************END OF FILE******************************************/
