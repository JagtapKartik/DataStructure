//******************************************************************************
// Filename: drvPCA9685PW.c
// Brief Description: This file is used to drive status led indication.
//
// Detailed description:
//  >Initialize/configure led driver IC
//  >Set initial value of status LEDs
//  >Function to control status led indication
//	>Function to Set Single Led Pin On/off
//	>Function to Get Single Led Pin On/off status etc.
//******************************************************************************
#include "drvPCA9685PW.h"
#include <stdio.h>

#ifdef ON_STM32
#include "cmsis_os.h"
#endif

/* macro to find smallest value */
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

//******************************************************************************
// Name:        drvpca9685_InitStatusLed
// Description: This function initializes the led driver
// Parameters:  pstLedInstance: @ref TPca9685_object
// Returns:     @ref TLedDrv_ret
//******************************************************************************
TLedDrv_ret drvpca9685_InitStatusLed( TPca9685_object *pstLedInstance )
{
	TLedDrv_ret ret = eLEDDRV_SUCCESS;
	/* Check pstLedInstance if its null */
	if( NULL == pstLedInstance )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
#define PCA9685_MODE1 ( 0x00 )
		uint8_t initStruct[2];
		uint8_t prescale = 3; // hardcoded value
#ifdef ON_STM32
		osDelay(1);
		initStruct[0] = PCA9685_MODE1;
		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, REG_MODE1, &initStruct[0] , 1 ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
#endif
		uint8_t newmode = ((PCA9685_MODE1 & 0x7F) | 0x10);
		initStruct[0] = PCA9685_MODE1;
		initStruct[1] = newmode;

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, REG_MODE1, initStruct, 2 ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		initStruct[1] = prescale;
		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, REG_MODE1, initStruct, 2 ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		initStruct[1] = PCA9685_MODE1;
		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, REG_MODE1, initStruct, 2 ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
#ifdef ON_STM32
		HAL_Delay(5);
#endif

		initStruct[1] = ( PCA9685_MODE1 | 0xA1 );
		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, REG_MODE1, initStruct, 2 ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_StatusLedOff
// Description: This function is used off all the led connected to the led outputs
// Parameters:  pstLedInstance: @ref TPca9685_object
// Returns:     NA
//******************************************************************************
TLedDrv_ret drvpca9685_StatusLedOff( TPca9685_object *pstLedInstance )
{
	uint8_t aucTxBuffer[2] = { 0, 0 };  /*Transmit data Buffer*/
	uint16_t regAddress = REG_ALLLED_ON_L;
	TLedDrv_ret ret = eLEDDRV_SUCCESS;

	if( NULL == pstLedInstance )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
		aucTxBuffer[0] = LEDOUT_OFF;
		for ( int i=0; i<4; i++ )
		{
			/* Turn Off the led */
			if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
			{
				ret = eLEDDRV_FAILURE;
			}
			else
			{
				/* Do  nothing */
			}
			regAddress = regAddress + 1;  // next byte register address pointer
		}
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_StatusLed_AllON
// Description: This function is used ON all the led connected to the led outputs
// Parameters:  pstLedInstance: @ref TPca9685_object
// Returns:    @ref TLedDrv_ret
//******************************************************************************
TLedDrv_ret drvpca9685_StatusLed_AllON( TPca9685_object *pstLedInstance )
{
	uint8_t aucTxBuffer[2] = { 0, 0 };  /*Transmit data Buffer*/
	uint16_t regAddress = REG_ALLLED_ON_L;
	TLedDrv_ret ret = eLEDDRV_SUCCESS;

	if( NULL == pstLedInstance )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
		/* write led_on low byte */
		aucTxBuffer[0] = LEDOUT_OFF;
		regAddress = REG_ALLLED_ON_L;

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		/* write led_on high byte */
		aucTxBuffer[0] = LEDOUT_OFF;
		regAddress = REG_ALLLED_ON_H;

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_StatusLed_AllOff
// Description: This function is used Off all the led connected to the led outputs
// Parameters:  pstLedInstance: @ref TPca9685_object
// Returns:    @ref TLedDrv_ret
//******************************************************************************
TLedDrv_ret drvpca9685_StatusLed_AllOff( TPca9685_object *pstLedInstance )
{
	uint8_t aucTxBuffer[2] = { 0, 0 };  /*Transmit data Buffer*/
	uint16_t regAddress = REG_ALLLED_OFF_L;
	TLedDrv_ret ret = eLEDDRV_SUCCESS;

	if( NULL == pstLedInstance )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
		/* write led_off low byte */
		aucTxBuffer[0] = LEDOUT_OFF;
		regAddress = REG_ALLLED_OFF_L;

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		/* write led_off high byte */
		aucTxBuffer[0] = LEDOUT_OFF;
		regAddress = REG_ALLLED_OFF_H;

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_setSingleLed
// Description: Function to set single pin PWM output. Sets pin without having to deal with
//              on/off tick placement and properly handles a zero value as completely off and
//              4095 as completely on. Optional invert parameter supports inverting the
//              pulse for sinking to ground.
// Parameters:  pstLedInstance: @ref TPca9685_object led object pointer
//              ledNum: @ref uint8_t One of the PWM output pins, from 1 to 16
//              val: @ref uint16_t The number of ticks out of 4096 to be active,
//                                 should be a value from 0 to 4095 inclusive.
//              invert: @ref bool If true, inverts the output, defaults to 'false'
// Returns:     void
//******************************************************************************
void drvpca9685_setSingleLed( TPca9685_object *pstLedInstance, uint8_t ledNum, uint16_t val, bool invert )
{
	// Clamp value between 0 and 4095 inclusive.
	val = MIN(val, (uint16_t)PWM_MAX_STEP_COUNT);

	if (invert)
	{
		if ( PWM_MIN_STEP_COUNT == val )
		{
			// Special value for signal fully on.
			drvpca9685_SetSingleLedOnOff(pstLedInstance, ledNum, PWM_MAX_STEP_COUNT+1, PWM_MIN_STEP_COUNT );
		}
		else if ( PWM_MAX_STEP_COUNT == val )
		{
			// Special value for signal fully off.
			drvpca9685_SetSingleLedOnOff(pstLedInstance, ledNum, PWM_MIN_STEP_COUNT, PWM_MAX_STEP_COUNT+1 );
		}
		else
		{
			drvpca9685_SetSingleLedOnOff(pstLedInstance, ledNum, PWM_MIN_STEP_COUNT, PWM_MAX_STEP_COUNT - val);
		}
	}
	else
	{
		if ( PWM_MAX_STEP_COUNT == val )
		{
			// Special value for signal fully on.
			drvpca9685_SetSingleLedOnOff(pstLedInstance, ledNum, PWM_MAX_STEP_COUNT+1, PWM_MIN_STEP_COUNT);
		}
		else if ( PWM_MIN_STEP_COUNT == val )
		{
			// Special value for signal fully off.
			drvpca9685_SetSingleLedOnOff(pstLedInstance, ledNum, PWM_MIN_STEP_COUNT, PWM_MAX_STEP_COUNT+1 );
		}
		else
		{
			drvpca9685_SetSingleLedOnOff(pstLedInstance, ledNum, PWM_MIN_STEP_COUNT, val);
		}
	}
}

//******************************************************************************
// Name:        drvpca9685_SetSingleLedOnOff
// Description: Function to set single pin PWM output. Sets pin with on/off value.
// Parameters:  pstLedInstance: @ref TPca9685_object led object pointer
//              ledNum: @ref uint8_t One of the PWM output pins, from 1 to 16
//              on_value: @ref uint16_t led on value to be set
//              off_value: @ref uint16_t led off value to be set
// Returns:     @ref: TLedDrv_ret
//******************************************************************************
TLedDrv_ret drvpca9685_SetSingleLedOnOff( TPca9685_object *pstLedInstance, uint8_t ledNum, uint16_t on_value, uint16_t off_value )
{
	TLedDrv_ret ret = eLEDDRV_SUCCESS;
	uint8_t aucTxBuffer[2] = { 0, 0 };  /*Transmit data Buffer*/
	uint16_t regAddress = 0;

	if( NULL == pstLedInstance )
	{
		ret = eLEDDRV_FAILURE;
	}
	else if( ( 1 > ledNum ) || ( 16 < ledNum ) )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
		/* write led_on low byte */
		aucTxBuffer[0] = on_value & 0xFF;
		regAddress = REG_LED0_ON_L + LED_MULTIPLYER * (ledNum - 1);

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		/* write led_on high byte */
		aucTxBuffer[0] = on_value >> 8;
		regAddress = REG_LED0_ON_H + LED_MULTIPLYER * (ledNum - 1);

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		/* write led_off low byte */
		aucTxBuffer[0] = off_value & 0xFF;
		regAddress = REG_LED0_OFF_L + LED_MULTIPLYER * (ledNum - 1);

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		/* write led_on high byte */
		aucTxBuffer[0] = off_value >> 8;
		regAddress = REG_LED0_OFF_H + LED_MULTIPLYER * (ledNum - 1);

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, aucTxBuffer, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_GetSingleLedPin
// Description: Function to get current PWM value of the single pin.
// Parameters:  pstLedInstance: @ref TPca9685_object led object pointer
//              ledNum: @ref uint8_t One of the PWM output pins, from 1 to 16
//              pData: @ref uint8_t buffer pointer to store read value
// Returns:     @ref: TLedDrv_ret
//******************************************************************************
TLedDrv_ret drvpca9685_GetSingleLedPin( TPca9685_object *pstLedInstance, uint8_t ledNum, uint8_t *pData )
{
	TLedDrv_ret ret = eLEDDRV_SUCCESS;
	uint16_t regAddress = 0;

	if( ( NULL == pstLedInstance ) || ( NULL == pData ) )
	{
		ret = eLEDDRV_FAILURE;
	}
	else if( ( 1 > ledNum ) || ( 16 < ledNum ) )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
		/* read led pin high byte */
		regAddress = REG_LED0_OFF_H + LED_MULTIPLYER * (ledNum - 1);

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cRead(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, pData, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}

		/* read led pin low byte */
		regAddress = REG_LED0_OFF_L + LED_MULTIPLYER * (ledNum - 1);

		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, regAddress, ++pData, sizeof(uint8_t) ) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
	}

	return ret;
}

//******************************************************************************
// Name:        drvpca9685_SoftwareReset
// Description: This function is used to reset driver IC from software
// Parameters:  pstLedInstance: @ref TPca9685_object
// Returns:     @ref TLedDrv_ret
//******************************************************************************
TLedDrv_ret drvpca9685_SoftwareReset( TPca9685_object *pstLedInstance )
{
	TLedDrv_ret ret = eLEDDRV_SUCCESS;

	if( NULL == pstLedInstance )
	{
		ret = eLEDDRV_FAILURE;
	}
	else
	{
		if( eI2C_LED_SUCCESS != drvpca9685_if_I2cWrite(pstLedInstance->hwInterface.i2cHandle, pstLedInstance->uiSlaveAddress, SWRST_ADD, (uint8_t *)SWRST_CMD, 1) )
		{
			ret = eLEDDRV_FAILURE;
		}
		else
		{
			/* Do  nothing */
		}
	}

	return ret;
}


int main( void )
{
	return 0;
}
