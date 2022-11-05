//****************************************************************************
// Filename: tsd305_i2c_if.c
// Brief Description: 	This is the source file for TSD305 temperature sensor interface.
//						Contains function definitions of i2c interface function for thermopile.
//
//****************************************************************************

#include "tsd305_i2c_if.h"

//******************************************************************************
// Name:        tsd305_i2c_read
// Description: This function is used to read value from tsd305 sensor
// Parameters:  i2cBus @ref void - Pointer to I2CHandler
//				uiSlave_Address @ref uint8_t - Target device address
// 				uiMemaddr @ uint16_t - Internal memory address
//				uiMemaddrsize @ uint16_t - Size of internal memory address
//				*puiRxBuffer @ uint8_t - Pointer to data buffer
//				 uiSize @ uint8_t - Amount of data to be Read
// Returns:     TTsd305i2c_ret
//				0 - Failure
//				1 - Success
//******************************************************************************

TTsd305i2c_ret tsd305_i2c_read( void *i2cBus, uint8_t uiSlave_Address, uint16_t uiMemaddr, uint16_t uiMemaddrsize, uint8_t *puiRxBuffer, uint8_t uiSize)
{
#ifdef ON_STM32
	I2C_HandleTypeDef *I2CHandle = i2cBus;
#endif
	TTsd305i2c_ret ERet = eTSD305_I2C_SUCCESS;

	if ( NULL == puiRxBuffer )
	{
		ERet = eTSD305_I2C_FAILURE;
	}

	else
	{
#ifdef ON_STM32
		if ( HAL_I2C_Mem_Read(I2CHandle, uiSlave_Address<<1, uiMemaddr, I2C_MEMADD_SIZE_8BIT, puiRxBuffer, uiSize, I2C_TIMEOUT ) != HAL_OK )
		{
			ERet = eTSD305_I2C_FAILURE;
		}
#endif
	}

	return ERet ;
}

//******************************************************************************
// Name:        tsd305_delay
// Description: This function is used to used to set delay in ms
// Parameters:  uDelay @ uint16_t - required delay to be write
// Returns:     void
//******************************************************************************

void tsd305_delay( uint16_t uiDelay )
{
#ifdef ON_STM32
	HAL_Delay( uiDelay );
#endif
}
