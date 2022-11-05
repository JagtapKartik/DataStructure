//******************************************************************************
// Filename: drvPCA9685PW_if.c
// Brief Description: This file provides micro-controller interface functions for
// LED driver for PCA9685PW
//
// Detailed description:
//  >Functions to Read/Write data from/to LED driver IC
//******************************************************************************

#include "drvPCA9685PW_if.h"

//******************************************************************************
// Name:        drvpca9685_if_I2cWrite
// Description: This function Writes data to the LED driver
// Parameters:  pstI2cHandle: @ref I2C_HandleTypeDef
//              uiSlaveAddress: I2C slave address for LED driver IC
//              uiCommandByte: LED driver Register Address
//              pData: data buffer for writing data to LED Register Address
//              uiSize: data buffer size
// Returns:     @ref TLedI2c_if_ret
//******************************************************************************
TLedI2c_if_ret drvpca9685_if_I2cWrite( I2C_HandleTypeDef *pstI2cHandle, uint16_t uiSlaveAddress, uint16_t uiCommandByte, uint8_t *pData, uint16_t uiSize )
{
	TLedI2c_if_ret ret = eI2C_LED_SUCCESS;

	/* Check it pstI2cHandle is NULL or pointer to pData is NULL */
	if( NULL == pstI2cHandle || NULL == pData )
	{
		ret = eI2C_LED_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		/*i2c Memory Write*/
		if( HAL_OK != HAL_I2C_Mem_Write( pstI2cHandle, uiSlaveAddress, uiCommandByte, MEM_READ_WRITE_SIZE, pData, uiSize, I2C_COMM_TIMEOUT ) )
		{
			ret = eI2C_LED_FAILURE;
		}
		else
		{
			/* Do nothing */
		}
#endif
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_if_I2cRead
// Description: This function Reads data from LED driver IC
// Parameters:  pstI2cHandle: @ref I2C_HandleTypeDef
//              uiSlaveAddress: I2C slave address for LED driver IC
//              uiCommandByte: LED driver Register Address
//              pData: pointer to store read data from the LED driver
//              uiSize: Data buffer size
// Returns:     @ref TLedI2c_if_ret
//******************************************************************************
TLedI2c_if_ret drvpca9685_if_I2cRead( I2C_HandleTypeDef *pstI2cHandle, uint16_t uiSlaveAddress, uint16_t uiCommandByte, uint8_t *pData, uint16_t uiSize )
{
	TLedI2c_if_ret ret = eI2C_LED_SUCCESS;

	/* Check it pstI2cHandle is NULL or pointer to pData is NULL */
	if( NULL == pstI2cHandle || NULL == pData )
	{
		ret = eI2C_LED_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		/*i2c Memory Read*/
		if( HAL_OK != HAL_I2C_Mem_Read( pstI2cHandle, uiSlaveAddress, uiCommandByte, MEM_READ_WRITE_SIZE, pData, uiSize, I2C_COMM_TIMEOUT ) )
		{
			ret = eI2C_LED_FAILURE;
		}
		else
		{
			/* Do nothing */
		}
#endif
	}

	return ret;
}
