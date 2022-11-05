//
//
//#include <stdio.h>
//
//#define MAX_SIZE  500
//
//
//static FILE fileptr = NULL;
//
//FILE *OpenFileForRead(uint8_t *filename)
//{
//	fileptr = fopen(filename,"r");
//	if(fileptr != NULL){
//		return fileptr;
//	}
//	return 0;
//}
//
//
//void TransferFileDataToHost(uint8_t *payload)
//{
//	static uint8_t block_number = 0;
//	uint8_t host_timeout = payload[2];
//	uint16_t payload_index = 0;
////		payload[payload_index ++] = (uint8_t)FILE_TRANSFER;
////		payload[payload_index ++] = (uint8_t)FILE_DATA;
//	 payload[payload_index ++] = host_timeout;
//	 payload[payload_index ++] = block_number + 1;
//	 fgets(payload + payload_index, MAX_SIZE - payload_index,fileptr);
//}
///*
//static void handleFileTransferCommands( const uint8_t sub_command, const uint8_t *payload, const uint16_t payloadLen )
//{
//	switch(sub_command)
//	{
//		case FILE_READ_REQUEST:
//		{
//			if(strcmp(payload + 3,filename) == 0)
//			{
//				fileptr = OpenFileForRead(payload + 3);
//	 	 	 	if(fileptr != 0)
//	 	 	 	{
//	 	 	 		TransferFileDataToHost(uint8_t &payload)
//					enqueueCmdResponse( FILE_TRANSFER, sub_command, eACK, &payload, sizeof( payload ) );
//	 	 	 	}
//			}else{
//				 uint8_t errorCode = ( uint8_t )eFILE_NOT_FOUND;
//				 enqueueCmdResponse( 0, 0, eNACK, &errorCode, 1 );
//			}
//		}
//		break;
//
//		case FILE_WRITE_REQUEST:
//		{
//				if(strcmp(payload[3],filename) == 0)
//			{
//				enqueueCmdResponse( FILE_TRANSFER, sub_command, eACK, &payload, sizeof( payload ) );
//			}else{
//				 uint8_t errorCode = ( uint8_t )eFILE_NOT_FOUND;
//				 enqueueCmdResponse( 0, 0, eNACK, &errorCode, 1 );
//			}
//
//		}
//		break;
//
//		case FILE_DATA:
//		{
//			TransferFileDataToHost(payload);
//		}
//		break;
//
//		case FILE_LAST_DATA:
//		{
//
//		}
//		break;
//
//		default:
//		{
//
//		}
//		break;
//	}
//}
//*/
