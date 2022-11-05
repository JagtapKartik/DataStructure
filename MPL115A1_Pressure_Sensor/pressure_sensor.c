//******************************************************************************
// Filename: pressure_sensor.c
// Brief Description: This file contains implementation of pressure sensor driver
//                    for MPL115A1 IC.
//
// Detailed description:
//  >Function Are Wrapper Function for pressure sensor driver Module Function's.
//  >Function to initialize, read coefficient values,
//   read raw pressure and temperature and calculate the absolute pressure value.
//******************************************************************************

#include "pressure_sensor.h"

//******************************************************************************
// Name:         pressure_Sensor_ReadRaw_Pressure_Temprature
// Description:  This function read the raw pressure and temperature values.
// Parameters:   pstPressureSensorInst: @ref TPressure_Sensor_object
//				 pstRead: @ref TPressure_Sensor_Read
// Returns:      @ref TPressure_sensor_ret
//******************************************************************************
TPressure_sensor_ret pressure_Sensor_ReadRaw_Pressure_Temprature( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead )
{
	TPressure_sensor_ret ret = ePRESSURE_SENSOR_SUCCESS;
	uint8_t readBuffer [ PRESSURE_TEMP_BUFFER_SIZE ] = { 0 };
	uint8_t startConversion [ START_CONV_BUFFER_SIZE ] = { eSTART_CONVERSION, eDUMMY_BYTE };
	uint8_t readLocation[ PRESSURE_TEMP_BUFFER_SIZE ]= { eREAD_PRESSURE_MSB, eDUMMY_BYTE, eREAD_PRESSURE_LSB, eDUMMY_BYTE, eREAD_TEMPERATURE_MSB,
			                                             eDUMMY_BYTE, eREAD_TEMPERATURE_LSB, eDUMMY_BYTE, eDUMMY_BYTE };

	if( NULL == pstPressureSensorInst || NULL == pstRead )
	{
		ret = ePRESSURE_SENSOR_FAILURE;
	}
	else
	{
		pstRead->pressure.MSB = 0x0;
		pstRead->pressure.LSB = 0x0;
		pstRead->temperature.MSB = 0x0;
		pstRead->temperature.LSB = 0x0;
		//Send Start Conversion Command
		pressure_Sensor_Enable( &(pstPressureSensorInst->hwInteface) );

		for( int i=0; i<START_CONV_BUFFER_SIZE; i++)
		{
			pressure_Sensor_TransmitReceive( &(pstPressureSensorInst->hwInteface ), &startConversion[ i ], &readBuffer[ i ]);
			//LOG_INFO( "Pressure Sensor%d  %X\r\n",i, readBuffer[i] );
		}
		pressure_Sensor_Disable( &(pstPressureSensorInst->hwInteface) );
#ifdef ON_STM32
		HAL_Delay ( 3 );
#endif
		//Read Raw Pressure and temperature values
		pressure_Sensor_Enable( &(pstPressureSensorInst->hwInteface) );

		for( int i=0; i<PRESSURE_TEMP_BUFFER_SIZE; i++)
		{
			pressure_Sensor_TransmitReceive( &(pstPressureSensorInst->hwInteface ), &readLocation[ i ], &readBuffer[ i ]);
			//LOG_INFO( "Pressure Sensor%d  %X\r\n",i, readBuffer[i] );
		}
		pressure_Sensor_Disable( &(pstPressureSensorInst->hwInteface) );
		//Raw Pressure calculation
		pstRead->pressure.MSB = readBuffer [ ePRESSURE_MSB ];
		pstRead->pressure.LSB = readBuffer [ ePRESSURE_LSB ];
		pstRead->pressure.instValue = ((pstRead->pressure.MSB * 256) + pstRead->pressure.LSB)/64;

		//Raw Temperature calculation
		pstRead->temperature.MSB = readBuffer [ eTEMPERATURE_MSB ];
		pstRead->temperature.LSB = readBuffer [ eTEMPERATURE_LSB ];
		pstRead->temperature.instValue = ((pstRead->temperature.MSB * 256) + pstRead->temperature.LSB)/64;
	}

	return ret;
}

//******************************************************************************
// Name:         pressure_Sensor_Read_Coeff
// Description:  This function read the coefficient values.
// Parameters:   pstPressureSensorInst: @ref TPressure_Sensor_object
//				 pstRead: @ref TPressure_Sensor_Read
// Returns:      @ref TPressure_sensor_ret
//******************************************************************************
TPressure_sensor_ret pressure_Sensor_Read_Coeff( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead )
{
	TPressure_sensor_ret ret = ePRESSURE_SENSOR_SUCCESS;
	uint8_t readBuffer [ COEFF_BUFFER_SIZE ] = { 0 };
	uint8_t readLocation[ COEFF_BUFFER_SIZE ]= { eREAD_a0_COEFF_MSB, eDUMMY_BYTE, eREAD_a0_COEFF_LSB, eDUMMY_BYTE, eREAD_b1_COEFF_MSB, eDUMMY_BYTE,
			                                     eREAD_b1_COEFF_LSB, eDUMMY_BYTE, eREAD_b2_COEFF_MSB, eDUMMY_BYTE, eREAD_b2_COEFF_LSB, eDUMMY_BYTE,
												 eREAD_c12_COEFF_MSB, eDUMMY_BYTE, eREAD_c12_COEFF_LSB,eDUMMY_BYTE, eDUMMY_BYTE };

	if( NULL == pstPressureSensorInst || NULL == pstRead )
	{
		ret = ePRESSURE_SENSOR_FAILURE;
	}
	else
	{
		pressure_Sensor_Enable( &(pstPressureSensorInst->hwInteface) );
		for ( int i=0; i<COEFF_BUFFER_SIZE; i++)
		{
			pressure_Sensor_TransmitReceive( &(pstPressureSensorInst->hwInteface ), &readLocation[ i ], &readBuffer[ i ]);
			//LOG_INFO( "Pressure Sensor%d  %X\r\n",i, readBuffer[i] );
		}
		pressure_Sensor_Disable( &(pstPressureSensorInst->hwInteface) );

		//Coefficient a0 calculation
		pstRead->a0_Coeff.MSB = readBuffer [ 1 ];
		pstRead->a0_Coeff.LSB = readBuffer [ 3 ];
		pstRead->a0_Coeff.instValue = ((pstRead->a0_Coeff.MSB) << 5) + ((pstRead->a0_Coeff.LSB) >> 3) + ((pstRead->a0_Coeff.LSB) & 0x07) / 8.0;
		//LOG_INFO( "a0_Coeff  %d\r\n", pstRead->a0_Coeff.instValue );

		//Coefficient b1 calculation
		pstRead->b1_Coeff.MSB = readBuffer [ eb1COEFFICIENT_MSB ];
		pstRead->b1_Coeff.LSB = readBuffer [ eb1COEFFICIENT_LSB ];
		pstRead->b1_Coeff.instValue = ( ( ( (pstRead->b1_Coeff.MSB & 0x1F) * 0x100) + pstRead->b1_Coeff.LSB) / 8192.0) - 3 ;
		//LOG_INFO( "b1_Coeff  %f\r\n", pstRead->b1_Coeff.instValue );

		//Coefficient b2 calculation
		pstRead->b2_Coeff.MSB = readBuffer [ eb2COEFFICIENT_MSB ];
		pstRead->b2_Coeff.LSB = readBuffer [ eb2COEFFICIENT_LSB ];
		pstRead->b2_Coeff.instValue = ( ( ( (pstRead->b2_Coeff.MSB - 0x80) << 8) + pstRead->b2_Coeff.LSB ) / 16384.0 ) - 2 ;
		//LOG_INFO( "b2_Coeff  %f\r\n", pstRead->b2_Coeff.instValue );

		//Coefficient c12 calculation
		pstRead->c12_Coeff.MSB = readBuffer [ ec12COEFFICIENT_MSB ];
		pstRead->c12_Coeff.LSB = readBuffer [ ec12COEFFICIENT_LSB ];
		pstRead->c12_Coeff.instValue = ( ( ( pstRead->c12_Coeff.MSB * 0x100 ) + pstRead->c12_Coeff.LSB) / 16777216.0 )  ;
		//LOG_INFO( "c12_Coeff  %f\r\n", pstRead->c12_Coeff.instValue );
	}

	return ret;
}

//******************************************************************************
// Name:         pressure_Sensor_Init
// Description:  This function initializes the pressure sensor( MPL115A1 ).
// Parameters:   pstPressureSensorInst: @ref TPressure_Sensor_object
//				 pstRead: @ref TPressure_Sensor_Read
// Returns:      @ref TPressure_sensor_ret
//******************************************************************************
TPressure_sensor_ret pressure_Sensor_Init( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead )
{
	TPressure_sensor_ret ret = ePRESSURE_SENSOR_SUCCESS;

	/* Check for null condition of pointer's */
	if( NULL == pstPressureSensorInst || NULL == pstRead )
	{
		ret = ePRESSURE_SENSOR_FAILURE;
	}
	else
	{
#ifdef ON_STM32
		/* Initialize Pressure sensor Structure */
		pstPressureSensorInst->hwInteface.spiHandle = &PRESSURE_SENSOR_SPI_HANDLE;
		pstPressureSensorInst->hwInteface.CS.uiPort = VACUUM_SEPRATOR_PRESSURE_SENSOR_CS_GPIO_Port;
		pstPressureSensorInst->hwInteface.CS.uiPin = VACUUM_SEPRATOR_PRESSURE_SENSOR_CS_Pin;
		pstPressureSensorInst->hwInteface.SCLK.uiPort = VACUUM_SEPRATOR_PRESSURE_SENSOR_SCK_GPIO_Port;
		pstPressureSensorInst->hwInteface.SCLK.uiPin = VACUUM_SEPRATOR_PRESSURE_SENSOR_SCK_Pin;
		pstPressureSensorInst->hwInteface.ioDataIn.uiPort = VACUUM_SEPRATOR_PRESSURE_SENSOR_MISO_GPIO_Port;
		pstPressureSensorInst->hwInteface.ioDataIn.uiPin = VACUUM_SEPRATOR_PRESSURE_SENSOR_MISO_Pin;
		pstPressureSensorInst->hwInteface.ioDataOut.uiPort = VACUUM_SEPRATOR_PRESSURE_SENSOR_MOSI_GPIO_Port;
		pstPressureSensorInst->hwInteface.ioDataOut.uiPin = VACUUM_SEPRATOR_PRESSURE_SENSOR_MOSI_Pin;
		pstPressureSensorInst->hwInteface.SHDN.uiPort = VACUUM_SEPRATOR_PRESSURE_SENSOR_SHDN_GPIO_Port;
		pstPressureSensorInst->hwInteface.SHDN.uiPin = VACUUM_SEPRATOR_PRESSURE_SENSOR_SHDN_Pin;
#endif
		pressure_Sensor_On( &(pstPressureSensorInst->hwInteface) );
#ifdef ON_STM32
		HAL_Delay( 5 );
#endif
		pressure_Sensor_Disable(&(pstPressureSensorInst->hwInteface));
#ifdef ON_STM32
		HAL_Delay( 3 );
#endif

		pstRead->a0_Coeff.MSB = 0x0;
		pstRead->a0_Coeff.LSB = 0x0;
		pstRead->b1_Coeff.MSB = 0x0;
		pstRead->b1_Coeff.LSB = 0x0;
		pstRead->b2_Coeff.MSB = 0x0;
		pstRead->b2_Coeff.LSB = 0x0;
		pstRead->c12_Coeff.MSB = 0x0;
		pstRead->c12_Coeff.LSB = 0x0;

		/* Read the coefficient from Pressure sensor */
		ret = pressure_Sensor_Read_Coeff(pstPressureSensorInst, pstRead);
	}

	return ret;
}

//******************************************************************************
// Name:         pressure_Sensor_CalcAbsPressure
// Description:  This function calculates the absolute pressure value.
// Parameters:   pstPressureSensorInst: @ref TPressure_Sensor_object
//				 pstRead: @ref TPressure_Sensor_Read
// Returns:      @ref TPressure_sensor_ret
//******************************************************************************
TPressure_sensor_ret pressure_Sensor_CalcAbsPressure( TPressure_Sensor_object *pstPressureSensorInst, TPressure_Sensor_Read *pstRead )
{
	TPressure_sensor_ret ret = ePRESSURE_SENSOR_SUCCESS;

	if( NULL == pstPressureSensorInst || NULL == pstRead )
	{
		ret = ePRESSURE_SENSOR_FAILURE;
	}
	else
	{
		/* Read Raw Pressure Temperature Values */
		if( ePRESSURE_SENSOR_FAILURE == pressure_Sensor_ReadRaw_Pressure_Temprature( pstPressureSensorInst, pstRead ) )
		{
			ret = ePRESSURE_SENSOR_FAILURE ;
		}
		else
		{
			pstPressureSensorInst->uiAbsPressure = ( pstRead->a0_Coeff.instValue + (pstRead->b1_Coeff.instValue + \
					                                 pstRead->c12_Coeff.instValue * pstRead->temperature.instValue) * pstRead->pressure.instValue + \
												     pstRead->b2_Coeff.instValue * pstRead->temperature.instValue );
			pstPressureSensorInst->uiAbsPressure = ( pstPressureSensorInst->uiAbsPressure * PRESSURE_SENSOR_CONST_VALUE ) + PRESSURE_SENSOR_MIN_RANGE_VALUE;
		}
	}

	return ret;
}


int main( void )
{
	return 0;
}
