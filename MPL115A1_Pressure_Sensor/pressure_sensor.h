//******************************************************************************
// Filename: pressure_sensor.h
// Brief Description: This file contain variables, macros, function prototypes used in
// pressure_sensor.c
//
// Detailed description:
//  >Included required header files
//  >Macros and enums to configure pressure sensor IC MPL115A1
//  >Function prototypes for driver functions
//  >structure definition for driver object
//******************************************************************************

#ifndef PERIPHERAL_DRIVER_PRESSURE_SENSOR_H_
#define PERIPHERAL_DRIVER_PRESSURE_SENSOR_H_

#ifdef ON_STM32
#include "stm32f4xx_hal.h"
#include "gpio_if.h"
#endif
#include "pressure_sensor_if.h"

#ifdef ON_STM32
#define PRESSURE_SENSOR_SPI_HANDLE  ( hspi3 )
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_CS_Pin GPIO_PIN_1
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_CS_GPIO_Port GPIOD
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_SCK_Pin GPIO_PIN_10
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_SCK_GPIO_Port GPIOC
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_MISO_Pin GPIO_PIN_11
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_MISO_GPIO_Port GPIOC
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_MOSI_Pin GPIO_PIN_12
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_MOSI_GPIO_Port GPIOC
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_SHDN_Pin GPIO_PIN_2
#define VACUUM_SEPRATOR_PRESSURE_SENSOR_SHDN_GPIO_Port GPIOD
#endif

/* Pressure sensor Range values */
#define PRESSURE_SENSOR_MIN_RANGE_VALUE ( 50.0000 )
#define PRESSURE_SENSOR_MAX_RANGE_VALUE ( 115.0000)
#define PRESSURE_SENSOR_ADC_RESOLUTION  ( 1023.0000 )
#define PRESSURE_SENSOR_CONST_VALUE     ( 0.06353861192 )

/* Macro for Buffer size */
#define COEFF_BUFFER_SIZE ( 17 )
#define START_CONV_BUFFER_SIZE ( 2 )
#define PRESSURE_TEMP_BUFFER_SIZE ( 9 )

typedef void ( *TcbPressureSensor_t )( void );

/* Enum for pressure Sensor status */
typedef enum
{
	ePRESSURE_SENSOR_ACTIVATED, 	/* pressure Sensor status activated */
	ePRESSURE_SENSOR_DEACTIVATED	/* pressure Sensor status deactivated */
}TPressure_sensor_Status;

/* Enum for pressure Sensor module return values */
typedef enum
{
	ePRESSURE_SENSOR_SUCCESS,  		/* pressure Sensor module return Success */
	ePRESSURE_SENSOR_FAILURE		/* pressure Sensor module return Failure */
}TPressure_sensor_ret;

/* Enum for pressure Sensor coefficient's */
typedef enum
{
	ea0COEFFICIENT_MSB = 1,					     //Read a0 MSB Coefficient
	ea0COEFFICIENT_LSB = 3,					     //Read a0 LSB Coefficient
	eb1COEFFICIENT_MSB = 5,					     //Read b1 MSB Coefficient
	eb1COEFFICIENT_LSB = 7,					     //Read b1 LSB Coefficient
	eb2COEFFICIENT_MSB = 9,					     //Read b2 MSB Coefficient
	eb2COEFFICIENT_LSB = 11,					 //Read b2 LSB Coefficient
	ec12COEFFICIENT_MSB = 13,					 //Read c12 MSB Coefficient
	ec12COEFFICIENT_LSB = 15					 //Read c12 LSBCoefficient
}TPressure_sensor_coeff;

/* Enum for pressure Sensor Pressure and temperature coefficient's */
typedef enum
{
	ePRESSURE_MSB = 1,					     //Read pressure Coefficient
	ePRESSURE_LSB = 3,					     //Read pressure Coefficient
	eTEMPERATURE_MSB = 5,					 //Read temperature Coefficient
	eTEMPERATURE_LSB = 7,					 //Read temperature Coefficient
}TPressure_sensor_PresTemp;

/* Enum for Pressure Sensor Read */
typedef enum
{
	ePRESSURE,                       //Read pressure
	eTEMPERATURE,					 //Read pressure
	ea0COEFFICIENT,					 //Read a0 Coefficient
	eb1COEFFICIENT,					 //Read b1 Coefficient
	eb2COEFFICIENT,					 //Read b2 Coefficient
	ec12COEFFICIENT					 //Read c12 Coefficient
}TPressure_sensor_read;

/* Structure for Read Bytes */
typedef struct
{
	uint8_t LSB;                    //Store LSB of Data
	uint8_t MSB;					//Store MSB of Data
	uint16_t total;					//Store total value without decimal value of Data
	float instValue;				//Store total value with decimal value of Data
}TPressure_Sensor_Read_Bytes;

/* Structure for Read */
typedef struct
{
	TPressure_Sensor_Read_Bytes pressure;              //Read pressure
	TPressure_Sensor_Read_Bytes temperature;           //Read temperature
	TPressure_Sensor_Read_Bytes a0_Coeff;              //Read a0 Coefficient
	TPressure_Sensor_Read_Bytes b1_Coeff;              //Read b1 Coefficient
	TPressure_Sensor_Read_Bytes b2_Coeff;              //Read b2 Coefficient
	TPressure_Sensor_Read_Bytes c12_Coeff;             //Read c12 Coefficient
}TPressure_Sensor_Read;

/* Structure for pressure Sensor object */
typedef struct
{
	TPressure_sensor_if_Hw hwInteface;          //hardware interface for pressure sensor
	float uiAbsPressure;                        //Absolute pressure value
	TPressure_sensor_Status EStatus;  	        //pressure Sensor status
	TcbPressureSensor_t psCb;		            //pressure Sensor callback
}TPressure_Sensor_object;

/* Function prototypes */
TPressure_sensor_ret pressure_Sensor_Init( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead );

TPressure_sensor_ret pressure_Sensor_ReadRaw_Pressure_Temprature( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead );

TPressure_sensor_ret pressure_Sensor_Read_Coeff( TPressure_Sensor_object * pstPressureSensorInst, TPressure_Sensor_Read *pstRead );

TPressure_sensor_ret pressure_Sensor_CalcAbsPressure( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead );

TPressure_sensor_ret register_PressureSensorCallback( TPressure_Sensor_object *pstPressureSensorInst, TcbPressureSensor_t cb );

#endif /* PERIPHERAL_DRIVER_PRESSURE_SENSOR_H_ */
