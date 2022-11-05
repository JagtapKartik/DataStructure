//******************************************************************************
// Filename: photoMicroSensor.c
// Brief Description: This file contains implementation of photo micro sensor driver.
//
// Detailed description:
//  >Function to read the status of sensor
//  >Function to register application callback when the sensor activated
//******************************************************************************

#include "photoMicroSensor.h"

//******************************************************************************
// Name:        readStatus_HomePosition_Sensor
// Description: This function reads the status of home position Sensor
// Parameters:  pstHomePosSensorInstance: @ref THomePos_Sensor_object
//              pEstatus: @ref THomePos_Sensor_Status
// Returns:     @ref THomePos_Sensor_ret
//******************************************************************************
THomePos_Sensor_ret readStatus_HomePosition_Sensor( THomePos_Sensor_object *pstHomePosSensorInstance, THomePos_Sensor_Status *pEstatus )
{
	THomePos_Sensor_ret ret = eHOMEPOSITION_SUCCESS;
	/*Check if home position sensor instance is null or pEstatus pointer is null*/
	if( NULL == pstHomePosSensorInstance || NULL == pEstatus )
	{
		ret = eHOMEPOSITION_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		TGpio_if_ret EgpioRet = eGPIO_IF_SUCCESS;
		GPIO_PinState EgpioStatus = GPIO_PIN_RESET;
		/*Read the status of home position sensor output gpio port pin*/
		EgpioRet = gpio_if_readStatusIO( &( pstHomePosSensorInstance->ioOutput ), &EgpioStatus );
		/*Check if EgpioRet is failed*/
		if( eGPIO_IF_FAILURE == EgpioRet )
		{
			ret = eHOMEPOSITION_FAILURE;
		}
		else
		{
			/*Update the pEstatus pointer to deactivated or activated based on the gpio status*/
			*pEstatus  = ( ( GPIO_PIN_SET == EgpioStatus )? eHOMEPOSITION_DEACTIVATED : eHOMEPOSITION_ACTIVATED );
		}
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        register_HomePositionSensor_Callback
// Description: This function register the Home position sensor callback
// Parameters:  pstHomePosSensorInstance: @ref THomePos_Sensor_object
//              cb: @ref TCbHomePositionSensor
// Returns:     @ref THomePos_Sensor_ret
//******************************************************************************
THomePos_Sensor_ret register_HomePositionSensor_Callback( THomePos_Sensor_object *pstHomePosSensorInstance, TCbHomePositionSensor cb )
{
	THomePos_Sensor_ret ret = eHOMEPOSITION_SUCCESS;
	/*Check if home position sensor instance is null*/
	if( NULL == pstHomePosSensorInstance )
	{
		ret = eHOMEPOSITION_FAILURE;
	}
	else
	{
		/*Assign user Callback to the home position sensor callback*/
		( pstHomePosSensorInstance->homePosSensorcb ) = cb;
	}

	return ret;
}


int main( void )
{
	return 0;
}
