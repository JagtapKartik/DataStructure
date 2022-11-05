//****************************************************************************
// Filename: tsd305_i2c_if.h
// Brief Description: 	This header file includes macros, typedefs and function declarations
//						for interface file for thermopile driver.
//
//****************************************************************************

#ifndef PERIPHERALDRIVERS_TSD305TEMPERARTURESENSOR_TSD305_I2C_IF_H_
#define PERIPHERALDRIVERS_TSD305TEMPERARTURESENSOR_TSD305_I2C_IF_H_

#ifdef ON_STM32
#include "stm32f4xx_hal.h"
#endif

#include <stdio.h>
#include <stdint.h>

#define I2C_TIMEOUT 	( 100 )

typedef enum
{
	eTSD305_I2C_FAILURE,
	eTSD305_I2C_SUCCESS
}TTsd305i2c_ret;

TTsd305i2c_ret tsd305_i2c_read( void *i2cBus, uint8_t uiSlave_Address, uint16_t uiMemaddr, uint16_t uiMemaddrsize, uint8_t *puiRxBuffer, uint8_t uiSize);
void tsd305_delay( uint16_t uiDelay );

#endif /* PERIPHERALDRIVERS_TSD305TEMPERARTURESENSOR_TSD305_I2C_IF_H_ */
