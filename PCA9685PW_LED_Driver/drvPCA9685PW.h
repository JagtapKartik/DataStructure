//******************************************************************************
// Filename: drvPCA9685PW.h
// Brief Description: This file contain variables, macros and function prototypes
// used in drvPCA9685PW.c
//
// Detailed description:
//  >Included required header files
//  >macros for register addresses, values used in c file
//  >structure definition for led driver object
//  >Enum for return values
//  >Function prototypes
//******************************************************************************
#ifndef DRVPCA9685PW_H
#define DRVPCA9685PW_H

#include "drvPCA9685PW_if.h"
#include "stdbool.h"
#include <stdint.h>

//Register addresses
#define REG_MODE1            0x00       //Mode1 register
#define REG_MODE2            0x01       //Mode2 register

#define REG_SUBADR1          0x02       //I2C-bus subaddress 1 register
#define REG_SUBADR2          0x03       //I2C-bus subaddress 2 register
#define REG_SUBADR3          0x04       //I2C-bus subaddress 3 register
#define REG_ALLCALLADR       0x05       //LED All Call I2C-bus address

#define REG_LED0             0x06		//LED0 start register
#define REG_LED0_ON_L        0x06		//LED0 output and brightness control byte 0
#define REG_LED0_ON_H        0x07		//LED0 output and brightness control byte 1
#define REG_LED0_OFF_L       0x08		//LED0 output and brightness control byte 2
#define REG_LED0_OFF_H       0x09		//LED0 output and brightness control byte 3
#define REG_ALLLED_ON_L      0xFA       //load all the LEDn_ON registers, byte 0 (turn 0-7 channels on)
#define REG_ALLLED_ON_H      0xFB	    //load all the LEDn_ON registers, byte 1 (turn 8-15 channels on)
#define REG_ALLLED_OFF_L     0xFC	    //load all the LEDn_OFF registers, byte 0 (turn 0-7 channels off)
#define REG_ALLLED_OFF_H     0xFD	    //load all the LEDn_OFF registers, byte 1 (turn 8-15 channels off)
#define PRE_SCALE            0xFE		//prescaler for output frequency

#define LED_MULTIPLYER      4	        // For the other 15 channels

// software reset
#define SWRST_CMD    0x06               // software reset command value/software reset data byte1 value
#define SWRST_ADD    0x00               // SOftware reset address/General call address

// MODE1 register bits
#define MODE1_RESTART  0x80             // restart logic
#define MODE1_EXTCLK   0x40             // external clock
#define MODE1_AI       0x20             // auto-increment mode
#define MODE1_SLEEP    0x10             // oscillator off
#define MODE1_SUB1     0x08             // sub address 1 enable
#define MODE1_SUB2     0x04             // sub address 2 enable
#define MODE1_SUB3     0x02             // sub address 3 enable
#define MODE1_ALLCALL  0x01             // all-call enable

// Mode 2 register bits
#define MODE2_INVRT    0x10             // inverted bit
#define MODE2_OCH      0x08             // output change
#define MODE2_OUTDRV   0x04             // LED output configuration
#define MODE2_OUTNE    0x03             // outne bits

// LEDOUTn states
#define LEDOUT_OFF     0x00             // driver is off
#define LEDOUT_ON      0x01             // fully on

// Max and Min (range) of PWM step count
#define PWM_MAX_STEP_COUNT   4095       // maximum step counts
#define PWM_MIN_STEP_COUNT    0         // minimum/start step count

/* Enum for led driver Module Return values */
typedef enum
{
	eLEDDRV_SUCCESS,  	                 /* Success Return */
	eLEDDRV_FAILURE	                    /* Failure Return */
}TLedDrv_ret;

/* Structure for LED object*/
typedef struct
{
	Tpca9685pw_if_Hw hwInterface;        //hardware interface for i2c Handle
	uint8_t uiSlaveAddress;              //Slave Address
}TPca9685_object;

/* Function prototypes */
TLedDrv_ret drvpca9685_InitStatusLed( TPca9685_object *pstLedInstance );

TLedDrv_ret drvpca9685_SoftwareReset( TPca9685_object *pstLedInstance );

TLedDrv_ret drvpca9685_StatusLedOff( TPca9685_object *pstLedInstance );

void drvpca9685_setSingleLed( TPca9685_object *pstLedInstance, uint8_t ledNum, uint16_t val, bool invert );

TLedDrv_ret drvpca9685_SetSingleLedOnOff( TPca9685_object *pstLedInstance, uint8_t ledNum, uint16_t on_value, uint16_t off_value );

TLedDrv_ret drvpca9685_GetSingleLedPin( TPca9685_object *pstLedInstance, uint8_t ledNum, uint8_t *pData );

TLedDrv_ret drvpca9685_StatusLed_AllON( TPca9685_object *pstLedInstance );

TLedDrv_ret drvpca9685_StatusLed_AllOff( TPca9685_object *pstLedInstance );

#endif //DRVPCA9685PW_H
