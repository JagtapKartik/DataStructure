/*
 * main.c
 *
 *  Created on: 29-May-2020
 *      Author: Kartik
 */




#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define MAX_PAYLOAD_LENGHT 500

typedef struct
{
  uint16_t length;                      //2B
  uint16_t crc16;                         //2B
  uint8_t payload[MAX_PAYLOAD_LENGHT];  //3B
  uint8_t type;                   //1B
}TPacketStruct_t;



int main(void){

//	char name[] = "FirmwareLog";
//	char payload[MAX_PAYLOAD_LENGHT] = {1,2} ;
//	for(int i = 2,j = 0;name[i] != '\0';i++,j++){
//		payload[i] = name[j];
//	}
//
//	printf("payload name %s\n",payload + 2);
//
//	if(strcmp(payload + 2,"FirmwareL") == 0)
//	{
//		printf("Equal\n");
//	}
//
//	printf("Size of %d",sizeof(TPacketStruct_t));
	uint32_t DATA;
	uint8_t demo[10] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A };
	DATA =  ( demo[0] << 0);
	DATA |= ( demo[1] << 8);
	DATA |= ( demo[2] << 16);
	DATA |= ( demo[3] << 24);
	printf("%x\n",DATA);

	uint8_t buffer[4];
	DATA = 0xABCD;

	buffer[0] = 0xFF & (DATA << 0);
	buffer[1] = 0xFF & (DATA << 8);
	buffer[2] = 0xFF & (DATA << 16);
	buffer[3] = 0xFF & (DATA << 24);

	for(int i= 0;i<4;i++)
	{
		printf("%x\n",buffer[i]);
	}

//	demo + 4;
//	DATA = ( demo[4] << 0);
//	DATA |= ( demo[5] << 8);
//	DATA |= ( demo[6] << 16);
//	DATA |= ( demo[7] << 24);
//	printf("%x",DATA);
	return 0;
}
