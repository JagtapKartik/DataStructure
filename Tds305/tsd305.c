//****************************************************************************
// Filename: tsd305.c
// Brief Description: 	This is the source file for TSD305 temperature sensor driver.
//						Contains function definitions for thermopile.
//
//****************************************************************************

#include "tsd305.h"

//******************************************************************************
// Name:        read_EEPROM_UInt
// Description: Reads the tsd305 EEPROM coefficient stored at address provided.
// Parameters:  pstTsd305Instance @ref TTSd305Object - Pointer to pstTsd305Instance instance
//   			uCommand @ uint16_t - eeprom address to read coefficients
// 				*puiCoefficient @ref uint16_t - Store coefficient
// Returns:     TTSd305RetType
//******************************************************************************


TTSd305RetType read_EEPROM_UInt( TTSd305Object *pstTsd305Instance, uint16_t uCommand, uint16_t *puiCoefficient )
{
	TTsd305i2c_ret ETsd305_i2c_ret_val = eTSD305_I2C_SUCCESS;
	TTSd305RetType ERetVal = eTSD305_SUCCESS;
	uint8_t auiBuffer[3];
	uint8_t uiStatus_byte = 0;

	if(( NULL == pstTsd305Instance ) || ( NULL == puiCoefficient ))
	{
		ERetVal = eTSD305_FAILURE;
	}

	else
	{
		/* Read Slave Data */
		ETsd305_i2c_ret_val = tsd305_i2c_read( pstTsd305Instance->i2cBus, TSD305_ADDR, uCommand, 1,\
											   auiBuffer, 3 );

		tsd305_delay( 1 );
		if( ETsd305_i2c_ret_val != eTSD305_I2C_SUCCESS )
		{
			ERetVal = eTSD305_FAILURE;
		}
		else
		{
			uiStatus_byte = auiBuffer[0];
			if ( uiStatus_byte & TSD305_STATUS_BUSY_MASK )
			{
				ERetVal = eTSD305_STATUS_BUSY;
			}

			if ( uiStatus_byte & TSD305_STATUS_MEMORY_ERROR_MASK )
			{
				ERetVal = eTSD305_STATUS_MEMORY_ERROR;
			}
			else
			{
				*puiCoefficient = ( auiBuffer[1] << 8 ) | auiBuffer[2];
			}
		}
	}

	return ERetVal;
}

//******************************************************************************
// Name:        read_EEPROM_Float
// Description: Reads the tsd305 floating point EEPROM coefficient stored at address provided.
// Parameters: 	uCommand @ uint16_t - eeprom address to read coefficients
// 				*pfValue @ref float - Store coefficient
// Returns:     @ref TTSd305RetType
//******************************************************************************

TTSd305RetType read_EEPROM_Float( TTSd305Object *pstTsd305Instance, uint16_t uCommand, float *pfValue )
{
	uint8_t auiBuffer[3];

	TTsd305i2c_ret ETsd305_i2c_ret_val = eTSD305_I2C_SUCCESS;
	TTSd305RetType ERetVal = eTSD305_SUCCESS;

	if(( NULL == pstTsd305Instance ) || ( NULL == pfValue ))
	{
			ERetVal = eTSD305_FAILURE;
	}

	else
	{
		ETsd305_i2c_ret_val = tsd305_i2c_read( pstTsd305Instance->i2cBus, TSD305_ADDR, uCommand, 1,\
												   auiBuffer, 3 );

		tsd305_delay( 1 );

		if (ETsd305_i2c_ret_val != eTSD305_I2C_SUCCESS)
		{
			ERetVal = eTSD305_FAILURE;
		}
		else
		{
			TTsd305UintFloat uEepromVal;
			uint16_t uiHword = 0;
			uint16_t uiLword = 0;
			uint32_t uiWord = 0;

			uiHword = ( auiBuffer[1] << 8 ) | auiBuffer[2];

			ETsd305_i2c_ret_val = tsd305_i2c_read( pstTsd305Instance->i2cBus, TSD305_ADDR, uCommand+1, 1,\
														   auiBuffer, 3 );
			tsd305_delay( 1 );
			if (ETsd305_i2c_ret_val != eTSD305_I2C_SUCCESS)
			{
				ERetVal = eTSD305_FAILURE;
			}
			else
			{
				uiLword = ( auiBuffer[1] << 8 ) | auiBuffer[2];
				uiWord = ( uint32_t )((uiHword << 16) | uiLword);
				uEepromVal.uiInt = uiWord;
				*pfValue = uEepromVal.fFloat;
			}

		}
	}

	return ERetVal;
}

//******************************************************************************
// Name:        read_ADC_Values
// Description: Reads the tsd305 floating point EEPROM coefficient stored at address provided.
// Parameters: 	pstTsd305Instance @ref TTSd305Object - Pointer to pstTsd305Instance instance
//				*puiAdc_object @ int32_t - Pointer to get ADC_object value
//				*puiAdc_sensor @ int32_t - Pointer to get ADC_sensor value
// Returns:     @ref TTSd305RetType
//******************************************************************************


TTSd305RetType read_ADC_Values( TTSd305Object *pstTsd305Instance,int32_t *puiAdc_object,\
								int32_t *puiAdc_sensor )
{
	TTSd305RetType ERetVal = eTSD305_SUCCESS;
	TTsd305i2c_ret ETsd305_i2c_ret_val = eTSD305_I2C_SUCCESS;
	uint8_t auiBuffer[7];
	uint8_t uiStatus_byte = 0;

	if(( NULL == pstTsd305Instance ) || ( NULL == puiAdc_object ) || ( NULL == puiAdc_sensor ))
	{
		ERetVal = eTSD305_FAILURE;
	}
	else
	{
		ETsd305_i2c_ret_val = tsd305_i2c_read( pstTsd305Instance->i2cBus, TSD305_ADDR, TSD305_ADC_COMMAND, 1,\
												   auiBuffer, 7 );

		if( ETsd305_i2c_ret_val != eTSD305_I2C_SUCCESS )
		{
			ERetVal = eTSD305_FAILURE;
		}
		else
		{
			uiStatus_byte = auiBuffer[0];
				if ( uiStatus_byte & TSD305_STATUS_MEMORY_ERROR_MASK )
				{
					ERetVal = eTSD305_STATUS_MEMORY_ERROR;
				}
				else
				{
					*puiAdc_object =  ((uint32_t)auiBuffer[1] << 16) | ((uint32_t)auiBuffer[2] << 8) | \
								  (uint32_t)auiBuffer[3];

					*puiAdc_sensor = ((uint32_t)auiBuffer[4] << 16) | ((uint32_t)auiBuffer[5] << 8) | \
								  (uint32_t)auiBuffer[6];
			}
		}
	}

	return ERetVal;
}

//******************************************************************************
// Name:        TSD_Determinate_Temperature
// Description: This function is meant to illustrate the procedure to determinate
//				the measured sensor and object temperatures with respect to TSD305
// Parameters: 	pstTsd305Instance @ref TTSd305Object - Pointer to pstTsd305Instance instance
//
// Returns:     @ref TTSd305RetType
//******************************************************************************

TTSd305RetType TSD_Determinate_Temperature( TTSd305Object *pstTsd305Instance )
{

	signed int siMinSenTemp = 0;
	signed int siMaxSenTemp = 0;
	float fTC = 0.0;
	float fTref = 0.0;
	float fK4com = 0.0;
	float fK3com = 0.0;
	float fK2com = 0.0;
	float fK1com = 0.0;
	float fK0com = 0.0;
	float fK4obj = 0.0;
	float fK3obj = 0.0;
	float fK2obj = 0.0;
	float fK1obj = 0.0;
	float fK0obj = 0.0;
	float fTsen = 0.0;
	float fTobj = 0.0;
	float fTCF = 0.0;
	float fOffset = 0.0;
	float fADCcomp = 0.0;
	int32_t slADC_Object = 0;
	int32_t slADC_Sensor = 0;

	TTSd305RetType ERetVal = eTSD305_SUCCESS;
	int iLoopIndex = 0;
	int iArrayIndex = 0;
	float fTemp[14];
	uint16_t  uiTemp[6];

	if(( NULL == pstTsd305Instance ))
	{
		ERetVal = eTSD305_FAILURE;
	}
	else
	{

	  // Read Temperature Range Minimum & Maximum
	  for( iLoopIndex = 25; iLoopIndex <= 30; iLoopIndex++  )
	  {
		  read_EEPROM_UInt( pstTsd305Instance, iLoopIndex,  &( uiTemp[iArrayIndex] ) );

		  iArrayIndex++;
	  }

	  // Read all necessary coefficients from the memory, float type
	  iArrayIndex = 0;
	  for( iLoopIndex = 31; iLoopIndex < 56; iLoopIndex += 2  )
	  {
		  if( iLoopIndex == 45 )
		  {
			  continue;
		  }

		  read_EEPROM_Float( pstTsd305Instance, iLoopIndex,  &( fTemp[iArrayIndex] ) );
		  iArrayIndex++;
	 }

	// Save all gathered coefficients from array to specific variables
	siMinSenTemp = ( int16_t )uiTemp[2];
	siMaxSenTemp = ( int16_t )uiTemp[3];
	fTC = fTemp[0];
	fTref = fTemp[1];
	fK4com = fTemp[2];
	fK3com = fTemp[3];
	fK2com = fTemp[4];
	fK1com = fTemp[5];
	fK0com = fTemp[6];
	fK4obj = fTemp[7];
	fK3obj = fTemp[8];
	fK2obj = fTemp[9];
	fK1obj = fTemp[10];
	fK0obj = fTemp[11];

	// Read ADC Values for Object Temperature & Sensor Temperature
	read_ADC_Values( pstTsd305Instance, &slADC_Object, &slADC_Sensor );
	tsd305_delay(100);
	read_ADC_Values( pstTsd305Instance, &slADC_Object, &slADC_Sensor );

	fTsen = (float)slADC_Sensor / 16777216.0 * ( siMaxSenTemp - siMinSenTemp ) + siMinSenTemp;

	// Calculate TC Correction Factor
	fTCF = 1.0 + ((fTsen - fTref) * fTC);

	// Calculate Offset Value
	fOffset = fOffset + fK4com * fTsen * fTsen * fTsen * fTsen;
	fOffset = fOffset + fK3com * fTsen * fTsen * fTsen;
	fOffset = fOffset + fK2com * fTsen * fTsen;
	fOffset = fOffset + fK1com * fTsen;
	fOffset = fOffset + fK0com;
	fOffset = fOffset * fTCF;

	// Align ADC Value for Object Temperature
	slADC_Object = slADC_Object - 8388608;

	// Calculate Object Temperature
	fADCcomp = (float)slADC_Object + fOffset;
	fADCcomp = fADCcomp / fTCF;

	fTobj = fTobj + fK4obj * fADCcomp * fADCcomp * fADCcomp * fADCcomp;
	fTobj = fTobj + fK3obj * fADCcomp * fADCcomp * fADCcomp;
	fTobj = fTobj + fK2obj * fADCcomp * fADCcomp;
	fTobj = fTobj + fK1obj * fADCcomp;
	fTobj = fTobj + fK0obj;

	pstTsd305Instance->fTemperature = fTobj;
	}
	return ERetVal;
}
