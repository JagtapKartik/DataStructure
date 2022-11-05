//******************************************************************************
// Filename: pressure_sensor_if.c
// Brief Description: This file provides micro-controller interface functions for
// pressure sensor driver for MPL115A1
//
// Detailed description:
//  >Functions to Shutdown and On the pressure sensor IC
//  >Functions to Enable and Disable the pressure sensor IC
//  >Functions to Read/Write data from/to pressure sensor IC
//******************************************************************************

#include "pressure_sensor_if.h"

//******************************************************************************
// Name:        pressure_Sensor_Shutdown
// Description: This function shutdown the MPL115A1 pressure sensor
// Parameters:  pstHwInterfaceInst: @ref TPressure_sensor_if_Hw
// Returns:     @ref TPressure_sensor_if_ret
//******************************************************************************
TPressure_sensor_if_ret pressure_Sensor_Shutdown( TPressure_sensor_if_Hw *pstHwInterfaceInst )
{
	TPressure_sensor_if_ret ret = ePRESSURE_SENSOR_IF_SUCCESS;

	if( NULL == pstHwInterfaceInst )
	{
		ret = ePRESSURE_SENSOR_IF_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		gpio_if_clearIO( &( pstHwInterfaceInst->SHDN ) );
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        pressure_Sensor_On
// Description: This function turns on MPL115A1 pressure sensor
// Parameters:  pstHwInterfaceInst: @ref TPressure_sensor_if_Hw
// Returns:     @ref TPressure_sensor_if_ret
//******************************************************************************
TPressure_sensor_if_ret pressure_Sensor_On( TPressure_sensor_if_Hw *pstHwInterfaceInst )
{
	TPressure_sensor_if_ret ret = ePRESSURE_SENSOR_IF_SUCCESS;

	if( NULL == pstHwInterfaceInst )
	{
		ret = ePRESSURE_SENSOR_IF_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		gpio_if_setIO( &( pstHwInterfaceInst->SHDN ) );
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        pressure_Sensor_Enable
// Description: This function enables the MPL115A1 pressure sensor
// Parameters:  pstHwInterfaceInst: @ref TPressure_sensor_if_Hw
// Returns:     @ref TPressure_sensor_if_ret
//******************************************************************************
TPressure_sensor_if_ret pressure_Sensor_Enable( TPressure_sensor_if_Hw *pstHwInterfaceInst )
{
	TPressure_sensor_if_ret ret = ePRESSURE_SENSOR_IF_SUCCESS;

	if( NULL == pstHwInterfaceInst )
	{
		ret = ePRESSURE_SENSOR_IF_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		gpio_if_clearIO( &( pstHwInterfaceInst->CS ) );
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        pressure_Sensor_Disable
// Description: This function disables the MPL115A1 pressure sensor
// Parameters:  pstHwInterfaceInst: @ref TPressure_sensor_if_hw
// Returns:     @ref TPressure_sensor_if_ret
//******************************************************************************
TPressure_sensor_if_ret pressure_Sensor_Disable( TPressure_sensor_if_Hw *pstHwInterfaceInst )
{
	TPressure_sensor_if_ret ret = ePRESSURE_SENSOR_IF_SUCCESS;

	if( NULL == pstHwInterfaceInst )
	{
		ret = ePRESSURE_SENSOR_IF_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		gpio_if_setIO( &( pstHwInterfaceInst->CS ) );
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        pressure_Sensor_TransmitReceive
// Description: This function reads and writes from and to the MPL115A1 IC
//              Given pressure sensor Memory Address
// Parameters:  pstHwInterfaceInst: @ref TPressure_sensor_if_Hw
//              pTxBuffer: Pointer to Transmitting Buffer
//              pRxBuffer: Pointer to Receiving Buffer
// Returns:     @ref TPressure_sensor_if_ret
//******************************************************************************
TPressure_sensor_if_ret pressure_Sensor_TransmitReceive( TPressure_sensor_if_Hw *pstHwInterfaceInst ,uint8_t* pTxBuffer, uint8_t *pRxBuffer )
{
	TPressure_sensor_if_ret ret = ePRESSURE_SENSOR_IF_SUCCESS;

	if( ( NULL == pstHwInterfaceInst ) || ( NULL == pRxBuffer ) || ( NULL == pTxBuffer ) )
	{
		ret = ePRESSURE_SENSOR_IF_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		HAL_SPI_TransmitReceive( ( pstHwInterfaceInst->spiHandle ), pTxBuffer, pRxBuffer, PRESSURE_SENSOR_RXTX_SIZE, PRESSURE_SENSOR_RXTX_TIMEOUT );
#endif
	}

	return ret;
}
