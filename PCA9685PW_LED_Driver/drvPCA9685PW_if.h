//******************************************************************************
// Filename: drvPCA9685PW_if.h
// Brief Description: This file contain variables, macros and function prototypes
// used in drvPCA9685PW_if.c
//
// Detailed description:
//  >Included required header files
//  >Define macros for I2C read/write operation
//  >structure for led hardware interface
//  >function prototypes
//******************************************************************************
#ifndef DRVPCA9685PW_IF_H
#define DRVPCA9685PW_IF_H

#ifdef ON_STM32
#include "gpio_if.h"
#endif

#include <stdio.h>
#include <stdint.h>

/* Macro for Memory Read_write size and  i2c communication timeout */
#define MEM_READ_WRITE_SIZE 	( 1 )
#define I2C_COMM_TIMEOUT 		( 100 )

/* Enum for LED driver I2C Interface Module Return values */
typedef enum
{
	eI2C_LED_SUCCESS, 	          /* Success Return  */
	eI2C_LED_FAILURE 	         /* Failure Return  */
}TLedI2c_if_ret;

#ifdef ON_STM32
/* Structure for status led Interface Module */
typedef struct
{
	  *i2cHandle; 	//i2c Handle
}Tpca9685pw_if_Hw;
#endif

typedef int I2C_HandleTypeDef; // must be replace as per platform

typedef struct
{
	I2C_HandleTypeDef *i2cHandle; 	//i2c Handle
}Tpca9685pw_if_Hw;

/* Function prototypes */
TLedI2c_if_ret drvpca9685_if_I2cWrite( I2C_HandleTypeDef *pstI2cHandle, uint16_t uiSlaveAddress, uint16_t uiCommandByte, uint8_t *pData, uint16_t uiSize );

TLedI2c_if_ret drvpca9685_if_I2cRead( I2C_HandleTypeDef *pstI2cHandle, uint16_t uiSlaveAddress, uint16_t uiCommandByte, uint8_t *pData, uint16_t uiSize );

#endif  //DRVPCA9685PW_IF_H
