//******************************************************************************
// Filename: file_transfer.c
// Brief Description: This file implements functionality of processing of
//                    file transfer.
//
// Detailed description:
//  >Functions to processes various messages received from host application
//
// 3M (c) Copyright 2019
//******************************************************************************

#include <stdint.h>
#include <stdio.h>
#include <string.h>
//#include "packet_handler.h"
//#include "flashstorage.h"


#define MAX_PACKET_SIZE 		500
#define MAX_FILE_NAME_SIZE 		20

/*Field Positions in a Packet*/
#define PACKET_COMMAND_FIELD_POSITION		(0)
#define PACKET_SUB_COMMAND_FIELD_POSITION	(1)
#define PACKET_HST_TMOUT_FIELD_POSITION		(2)
#define PACKET_BLOCK_NO_FIELD_POSITION		(3)
#define PACKET_DATA_FIELD_POSITION			(4)
#define PACKET_ACK_FIELD_DATA_POSITION		(0)

/*Field Positions in a Packet*/
#define   PACKET_TYPE_FIELD_POSITION            ( 0 )
#define   PACKET_LENGTH_MSB_FIELD_POSITION      ( 1 )
#define   PACKET_LENGTH_LSB_FIELD_POSITION      ( 2 )
#define   PACKET_PAYLOAD_FIELD_POSITION         ( 3 )

#define   FIXED_HEADER_LENGTH    ( 1 + 2 )

/*Host time out required for data frame*/
#define HOST_TIMEOUT		(2)

/*Size of fields */
#define SIZE_OF_HST_TMOUT_FIELD			(1)
#define SIZE_OF_BLOCK_NO				(1)

#define SIZE_OF_SUBCMD_FIELD	( 1 )
#define SIZE_OF_COMMAND_FIELD	( 1 )

typedef uint16_t TCrc_t;

typedef enum
{
  eCOMMAND = 1,
  eACK,
  eNACK,
  eEVENT
}EPacketType_t;

typedef struct
{
  uint16_t length;                      //2B
  TCrc_t crc16;                         //2B
  uint8_t payload[MAX_PACKET_SIZE];  //3B
  EPacketType_t type;                   //1B
}TPacketStruct_t;

typedef enum
{
	FILE_DATA = 3,
	FILE_LAST_DATA
}FILEMODE;

typedef enum
{
	RETURN_OK,
	RETURN_ERROR
}FT_RETURN;




uint8_t  FileTransfer_HandleWrq( const uint8_t *payload, const uint16_t payloadLen);

uint8_t  FileTransfer_HandleRrq( const uint8_t *payload, const uint16_t payloadLen);

//uint16_t FileTransfer_HandleIncomingData(const TPacketStruct_t *rxPacket);

//uint8_t  FileTransfer_HandleIncomingAck(const TPacketStruct_t *rxPacket);

//uint8_t FileTransfer_HandleIncomingNack(const TPacketStruct_t *rxPacket);

FT_RETURN FileTransfer_SendAck(uint8_t blockNo,const uint8_t *payload,uint8_t payloadLen);

FT_RETURN FileTransfer_SendError(uint8_t error_no);

FT_RETURN FileTransfer_SendData();

FT_RETURN FileTransfer_TimeoutCB();

//FT_RETURN FileTransfer_OpenFile(uint8_t *filename,Flash_FileDescriptor *pFile_descriptor);

//FT_RETURN FileTransfer_CloseFile(Flash_FileDescriptor *pFile_descriptor);

