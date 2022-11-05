/*
 * main.c
 *
 *  Created on: 16-Jun-2020
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "file_transfer.h"

static TPacketStruct_t txPacket; //packet to send over usb
static uint8_t ft_buffer[MAX_PACKET_SIZE];

static uint16_t FileTransfer_CalculateCRC(const uint8_t *data,uint16_t len)
{
	uint16_t crc = 0xFFFF;
	int i;
	if (len){
		do {
			crc ^= *data++;
			for (i=0; i<8; i++) {
				if (crc& 1) crc = (crc>> 1) ^ 0x8408;
				else crc>>= 1;
			}
		}while (-- len);
		return (~crc);
	}
	return 0;
}

static void FileTransfer_CreateDataFrame()
{
	memset(&txPacket,0,sizeof(txPacket));
	memset(&ft_buffer,0,MAX_PACKET_SIZE);

//	fileblockNo ++;
	txPacket.type = eCOMMAND;
	txPacket.payload[PACKET_SUB_COMMAND_FIELD_POSITION] = FILE_DATA;
	txPacket.payload[PACKET_HST_TMOUT_FIELD_POSITION] = HOST_TIMEOUT;
	txPacket.payload[PACKET_BLOCK_NO_FIELD_POSITION] = 1;
//	txPacket.length = FileTransfer_ReadFile(txPacket.payload + PACKET_DATA_FIELD_POSITION, &file_discriptor, MAX_PAYLOAD_LENGHT - SIZE_OF_COMMAND_FIELD + SIZE_OF_SUBCMD_FIELD + SIZE_OF_HST_TMOUT_FIELD + SIZE_OF_BLOCK_NO);
	ft_buffer[PACKET_COMMAND_FIELD_POSITION] =	txPacket.payload[PACKET_COMMAND_FIELD_POSITION];
	ft_buffer[PACKET_SUB_COMMAND_FIELD_POSITION] =txPacket.payload[PACKET_SUB_COMMAND_FIELD_POSITION];
	ft_buffer[PACKET_HST_TMOUT_FIELD_POSITION] = txPacket.payload[PACKET_HST_TMOUT_FIELD_POSITION];
	ft_buffer[PACKET_BLOCK_NO_FIELD_POSITION] = txPacket.payload[PACKET_BLOCK_NO_FIELD_POSITION];
	memcpy(ft_buffer + PACKET_DATA_FIELD_POSITION,txPacket.payload + PACKET_DATA_FIELD_POSITION,txPacket.length);
	txPacket.length =  SIZE_OF_COMMAND_FIELD + SIZE_OF_SUBCMD_FIELD + SIZE_OF_HST_TMOUT_FIELD + SIZE_OF_BLOCK_NO;
	txPacket.crc16 = FileTransfer_CalculateCRC(ft_buffer, txPacket.length);
	txPacket.length = txPacket.length + sizeof(txPacket.crc16);
}

static void FileTransfer_CreateErrorFrame(uint8_t error_no)
{
	memset(&txPacket,0,sizeof(txPacket));
	memset(&ft_buffer,0,sizeof(ft_buffer));

	txPacket.type = eNACK;
	txPacket.length = sizeof(error_no) + sizeof(txPacket.crc16);
	txPacket.payload[0] = error_no;
	ft_buffer[PACKET_TYPE_FIELD_POSITION] = txPacket.type;
	ft_buffer[PACKET_LENGTH_MSB_FIELD_POSITION] = ((txPacket.length & 0xFF00) >> 8);
	ft_buffer[PACKET_LENGTH_LSB_FIELD_POSITION] = (txPacket.length & 0x00FF);
	ft_buffer[PACKET_PAYLOAD_FIELD_POSITION] = error_no;
	txPacket.crc16 = FileTransfer_CalculateCRC(ft_buffer, txPacket.length + FIXED_HEADER_LENGTH - sizeof(txPacket.crc16));
}

static void FileTransfer_CreateAckFrame(uint8_t blockNo,const uint8_t *payload,uint8_t payloadLen)
{
	memset(&txPacket,0,sizeof(txPacket));
	memset(&ft_buffer,0,sizeof(ft_buffer));

	for(int i = 0;i<payloadLen;i++)
	{
		printf("%c",payload[i]);
	}printf("\n");

	txPacket.type = eACK;
	if(blockNo != 0)
	{
		txPacket.length = sizeof(blockNo) + sizeof(txPacket.crc16);
		txPacket.payload[0] = blockNo;
		ft_buffer[PACKET_TYPE_FIELD_POSITION] = txPacket.type;
		ft_buffer[PACKET_LENGTH_MSB_FIELD_POSITION] = ((txPacket.length & 0xFF00) >> 8);
		ft_buffer[PACKET_LENGTH_LSB_FIELD_POSITION] = (txPacket.length & 0x00FF);
		ft_buffer[PACKET_PAYLOAD_FIELD_POSITION] = blockNo;
		txPacket.crc16 = FileTransfer_CalculateCRC(ft_buffer, txPacket.length + FIXED_HEADER_LENGTH - sizeof(txPacket.crc16));
	}else if(payloadLen != 0)
	{
		txPacket.length = payloadLen + sizeof(txPacket.crc16);
		memcpy(txPacket.payload,payload,payloadLen);
		ft_buffer[PACKET_TYPE_FIELD_POSITION] = txPacket.type;
		ft_buffer[PACKET_LENGTH_MSB_FIELD_POSITION] = ((txPacket.length & 0xFF00) >> 8);
		ft_buffer[PACKET_LENGTH_LSB_FIELD_POSITION] = (txPacket.length & 0x00FF);
		memcpy(ft_buffer + PACKET_PAYLOAD_FIELD_POSITION,payload,payloadLen);
		txPacket.crc16 = FileTransfer_CalculateCRC(ft_buffer,txPacket.length + FIXED_HEADER_LENGTH - sizeof(txPacket.crc16));
	}
}

unsigned short crc16(data_p, length)
char *data_p;
unsigned short length;
{
       unsigned char i;
       unsigned int data;
       unsigned int crc;

       crc = 0xffff;

       if (length == 0)
              return (~crc);

       do {
              for (i = 0,data = (unsigned int)0xff & *data_p++; i < 8; i++, data >>= 1) {
                    if ((crc & 0x0001) ^ (data & 0x0001))
                           crc = (crc >> 1) ^  0x8408;
                    else
                           crc >>= 1;
              }
       } while (--length);

       crc = ~crc;

       data = crc;
//       crc = (crc << 8) | (data >> 8 & 0xFF);

       return (crc);
}

int main()
{
	uint8_t payload[500];
	payload[0] = 0x01;
	payload[1] = 0x00;
	payload[2] = 0x03;
	payload[3] = 0x01;
//	strcpy(payload+3,"1");

	uint8_t data[] = "The Shawshank Redemption is a 1994 American drama film written and directed by Frank Darabont, based on the 1982 Stephen King novella Rita Hayworth and Shawshank Redemption. It tells the story of banker Andy Dufresne (Tim Robbins), who is sentenced to life in Shawshank State Penitentiary for the murders of his wife and her lover, despite his claims of innocence. Over the following two decades, he befriends a fellow prisoner, contraband smuggler Ellis Red Redding (Morgan Freeman) 11111111111.";
	printf("len %d\n",strlen(data));
	uint16_t result = FileTransfer_CalculateCRC(payload,4);
	printf("Result [%x]\n",result);

	strcpy(payload,"812FirmwareLog");
	FileTransfer_CreateErrorFrame(1);

	printf("\n");
	printf("type [%x]\n",txPacket.type);
	printf("length [%x]\n",txPacket.length);
	printf("Payload ");
	for(int i = 0;i<14;i++)
	{
		printf("%x",txPacket.payload[i]);
	}printf("\n");
	printf("crc [%x]",txPacket.crc16);
}
