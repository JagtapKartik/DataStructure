//******************************************************************************
// Filename: pressure_sensor_if.h
// Brief Description: This file contain variables, macros, function prototypes used in
// pressure_sensor_if.c
//
// Detailed description:
//  >Included required header files
//  >Macros and enums to configure/return value pressure sensor IC MPL115A1
//  >Function prototypes for driver functions
//  >Structure definition for driver object
//  >Macros for memory read/write size, spi communication timeout
//******************************************************************************

#ifndef PERIPHERAL_DRIVER_PRESSURE_SENSOR_IF_H_
#define PERIPHERAL_DRIVER_PRESSURE_SENSOR_IF_H_

#ifdef ON_STM32
#include "stm32f4xx_hal.h"
#include "gpio_if.h"
#include "main.h"
#endif

#include <stdio.h>
#include <stdint.h>


#define PRESSURE_SENSOR_RXTX_SIZE 		( 1 )
#define PRESSURE_SENSOR_RXTX_TIMEOUT 	( 100 )

#ifdef ON_STM32
extern SPI_HandleTypeDef hspi3;
#endif
#define PRESSURE_SENSOR_SPI_HANDLE  ( hspi3 )

/* Enum for pressure sensor module return values */
typedef enum
{
	ePRESSURE_SENSOR_IF_SUCCESS,  		/* pressure Sensor module return Success */
	ePRESSURE_SENSOR_IF_FAILURE		    /* pressure Sensor module return Failure */
}TPressure_sensor_if_ret;

/* Enum for Pressure Sensor Command */
typedef enum
{
	eSTART_CONVERSION = 0x24,        //Wake main circuit and start A to D conversion
	eREAD_PRESSURE_MSB = 0x80,       //Read location of pressure MSB
	eREAD_PRESSURE_LSB = 0x82,       //Read location of pressure LSB
	eREAD_TEMPERATURE_MSB = 0x84,    //Read location of temperature MSB
	eREAD_TEMPERATURE_LSB = 0x86,    //Read location of temperature LSB
	eREAD_a0_COEFF_MSB = 0x88,       //Read location of a0 coefficient MSB
	eREAD_a0_COEFF_LSB = 0x8A,       //Read location of a0 coefficient LSB
	eREAD_b1_COEFF_MSB = 0x8C,       //Read location of b1 coefficient MSB
	eREAD_b1_COEFF_LSB = 0x8E,       //Read location of b1 coefficient LSB
	eREAD_b2_COEFF_MSB = 0x90,       //Read location of b2 coefficient MSB
	eREAD_b2_COEFF_LSB = 0x92,       //Read location of b2 coefficient LSB
	eREAD_c12_COEFF_MSB = 0x94,      //Read location of c12 coefficient MSB
	eREAD_c12_COEFF_LSB = 0x96,      //Read location of c12 coefficient LSB
	eDUMMY_BYTE = 0x0
}TPressure_Sensor_Command;

/* Structure for pressure sensor module */
typedef struct
{
#ifdef ON_STM32
	SPI_HandleTypeDef *spiHandle; 	            //SPI Handle
	TGpio  CS;			                        //pressure Sensor chip select IO
	TGpio  ioDataIn;		                    //pressure Sensor DOUT pin connected to MISO IO
	TGpio  ioDataOut;		                    //pressure Sensor DIN pin connected to MOSI IO
	TGpio  SCLK;                                //pressure Sensor Clock
	TGpio  SHDN;                                //pressure Sensor Shut Down
#endif
}TPressure_sensor_if_Hw;

/* Function prototypes */
TPressure_sensor_if_ret pressure_Sensor_Shutdown( TPressure_sensor_if_Hw *pstHwInterfaceInst );

TPressure_sensor_if_ret pressure_Sensor_On( TPressure_sensor_if_Hw *pstHwInterfaceInst );

TPressure_sensor_if_ret pressure_Sensor_Enable( TPressure_sensor_if_Hw *pstHwInterfaceInst );

TPressure_sensor_if_ret pressure_Sensor_Disable( TPressure_sensor_if_Hw *pstHwInterfaceInst );

TPressure_sensor_if_ret pressure_Sensor_TransmitReceive ( TPressure_sensor_if_Hw *pstHwInterfaceInst, uint8_t* pTxBuffer, uint8_t *pRxBuffer );

#endif /* PERIPHERAL_DRIVER_PRESSURE_SENSOR_IF_H_ */
