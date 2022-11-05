//******************************************************************************
// Filename: opb_IR_Sensor.c
// Brief Description: This file contains implementation of IR sensor driver.
//
// Detailed description:
//  >Function to activate and deactivate IR sensor
//  >Function to read the status of IR sensor
//  >Function to register application callback when the sensor activated/interrupt
//  >Occurs
//******************************************************************************

#include "opb_IR_Sensor.h"

//******************************************************************************
// Name:        opb_EnableIRSensor
// Description: This function activate the OPB IR Sensor
// Parameters:  pstIRSensorInstance: @ref Topb_IR_object
// Returns:     @ref TOpb_ret
//******************************************************************************
TOpb_ret opb_EnableIRSensor( Topb_IR_object *pstIRSensorInstance )
{
	TOpb_ret ret = eOPB_SUCCESS;
	/*Check if IR Sensor instance is null*/
	if( NULL == pstIRSensorInstance )
	{
		ret = eOPB_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		/*Set the IR Sensor control gpio pin for enabling the Sensor*/
		if( eGPIO_IF_FAILURE == gpio_if_setIO( &( pstIRSensorInstance->ioCntrl ) ) )
		{
			ret = eOPB_FAILURE;    /*Set IR Sensor control gpio pin failed*/
		}
		else
		{
			( pstIRSensorInstance->EStatus ) = eOPB_ENABLED;
		}
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        opb_DisableIRSensor
// Description: This function deactivate the OPB IR Sensor
// Parameters:  pstIRSensorInstance: @ref Topb_IR_object
// Returns:     @ref TOpb_ret
//******************************************************************************
TOpb_ret opb_DisableIRSensor( Topb_IR_object *pstIRSensorInstance )
{
	TOpb_ret ret = eOPB_SUCCESS;
	/*Check if IR Sensor instance is null*/
	if(  NULL == pstIRSensorInstance )
	{
		ret = eOPB_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		/*Clear the IR Sensor control gpio pin for disabling the Sensor*/
		if( eGPIO_IF_FAILURE == gpio_if_clearIO( &( pstIRSensorInstance->ioCntrl ) ) )
		{
			ret = eOPB_FAILURE; /*Clear IR Sensor control gpio pin failed*/
		}
		else
		{
			( pstIRSensorInstance->EStatus ) = eOPB_DISABLED;
		}
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        readStatus_OPB_IRSensor
// Description: This function reads the status of OPB IR Sensor
// Parameters:  pstIRSensorInstance: @ref Topb_IR_object
//              pEstatus: @ref TOpb_Status
// Returns:     @ref TOpb_ret
//******************************************************************************
TOpb_ret readStatus_OPB_IRSensor(Topb_IR_object *pstIRSensorInstance, TOpb_Status *pEstatus )
{
	TOpb_ret ret = eOPB_SUCCESS;
	/*Check if IR Sensor instance is null or pEstatus pointer is null */
	if( NULL == pstIRSensorInstance || NULL == pEstatus )
	{
		ret = eOPB_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		TGpio_if_ret EgpioRet = eGPIO_IF_SUCCESS;
		GPIO_PinState gpioStatus = GPIO_PIN_RESET;
		/*Read the Status of IR Sensor output gpio pin */
		EgpioRet = gpio_if_readStatusIO( &( pstIRSensorInstance->ioOutput ), &gpioStatus );

		if( eGPIO_IF_FAILURE == EgpioRet )
		{
			ret = eOPB_FAILURE; /*Read the Status of IR Sensor output gpio pin failed*/
		}
		else
		{
			/*Update the pEstatus pointer to activated or deactivated depends on gpio pin status*/
			*pEstatus  = ( ( GPIO_PIN_SET == gpioStatus ) ? eOPB_ACTIVATED : eOPB_DEACTIVATED );
		}
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        register_IRSensorCallback
// Description: This function registers application callback function, to be called
//              whenever interrupt occurs
// Parameters:  pstIRSensorInstance: @ref Topb_IR_object
//              cb: callback function
// Returns:     @ref TOpb_ret
//******************************************************************************
TOpb_ret register_IRSensorCallback( Topb_IR_object *pstIRSensorInstance, TcbIRSensor_t cb )
{
	TOpb_ret ret = eOPB_SUCCESS;
	/*Check if IR Sensor instance is null or call back is null */
	if( NULL == pstIRSensorInstance || NULL == cb  )
	{
		ret = eOPB_FAILURE;
	}
	else
	{
		( pstIRSensorInstance->irCb ) = cb; /*Initialize the callback to the IR Sensor callback*/
	}

	return ret;
}

int main( void )
{
	return 0;
}
