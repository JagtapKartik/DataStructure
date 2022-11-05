//****************************************************************************
// Filename: tsd305.h
// Brief Description: 	This header file includes macros, typedefs and function declarations
//						for thermopile driver.
//
//****************************************************************************

#ifndef PERIPHERALDRIVERS_TSD305TEMPERARTURESENSOR_TSD305_H_
#define PERIPHERALDRIVERS_TSD305TEMPERARTURESENSOR_TSD305_H_


#include "tsd305_i2c_if.h"


// TSD305 device address
#define TSD305_ADDR 					( 0x00 )
#define TSD305_STATUS_BUSY_MASK 		( 0x20 )
#define TSD305_STATUS_MEMORY_ERROR_MASK ( 0x04 )
#define TSD305_ADC_COMMAND				( 0xaf )

/*Sensor object*/
typedef struct
{
	void *i2cBus;
	float fTemperature;

}TTSd305Object;

/*Needed for Float to uint32 or vice-a-versa typecast*/
typedef union
{
       float fFloat;
       unsigned int uiInt;
}TTsd305UintFloat;

/*Return type for driver functions*/
typedef enum
{
	eTSD305_FAILURE,
	eTSD305_SUCCESS,
	eTSD305_STATUS_BUSY,
	eTSD305_STATUS_MEMORY_ERROR,
}TTSd305RetType;

TTSd305RetType read_EEPROM_UInt( TTSd305Object *pstTsd305Instance, uint16_t uCommand, uint16_t *puiCoefficient );
TTSd305RetType read_EEPROM_Float( TTSd305Object *pstTsd305Instance, uint16_t uCommand, float *pfValue );
TTSd305RetType read_ADC_Values( TTSd305Object *pstTsd305Instance,int32_t *puiAdc_object,int32_t *puiAdc_sensor );
TTSd305RetType TSD_Determinate_Temperature( TTSd305Object *pstTsd305Instance );

#endif /* PERIPHERALDRIVERS_TSD305TEMPERARTURESENSOR_TSD305_H_ */
