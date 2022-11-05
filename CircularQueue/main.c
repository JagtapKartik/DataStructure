

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE   								 ( 10 )

typedef struct
{
	int head;
	int tail;
	int size;
	int sizeOfEachElement;
	int *holdingBuffer;
}CircularBuffer;

typedef enum
{
	eCB_SUCCESS,
	eCB_FAILED
}eCircularBufferRet;

typedef enum
{
	ADD = 1,
	DELETE,
	DISPLAY
}eMenu;

int dataBuffer[SIZE];

eCircularBufferRet initCircularBuffer( CircularBuffer *cbQueue, int *buffer, int size, int sizeofelements )
{
	eCircularBufferRet ret = eCB_SUCCESS;

	if( NULL == buffer || 0 == size )
	{
		ret = eCB_FAILED;
	}
	else
	{
		cbQueue->size = size;
		cbQueue->sizeOfEachElement = sizeofelements;
		cbQueue->head = cbQueue->tail = 0;
		cbQueue->holdingBuffer = buffer;
	}
	return ret;
}

eCircularBufferRet checkBufferEmpty( CircularBuffer *cbQueue )
{
	eCircularBufferRet ret = eCB_SUCCESS;

	if( NULL == cbQueue )
	{
		ret = eCB_FAILED;
	}
	else
	{
		if( cbQueue->head == cbQueue->tail )
		{
			ret = eCB_FAILED;
		}
		else
		{
			/*Do Nothing*/
		}
	}
	return ret;
}

eCircularBufferRet checkBufferFull( CircularBuffer *cbQueue )
{
	eCircularBufferRet ret = eCB_SUCCESS;
	int temp = 0;

	if( NULL == cbQueue )
	{
		ret = eCB_FAILED;
	}
	else
	{
		printf("Head[%d]\n", cbQueue->head );
		temp = ( cbQueue->head + 1 ) % cbQueue->size;
		if( temp == cbQueue->tail )
		{
			ret = eCB_FAILED;
		}
		else
		{
			/*Do Nothing*/
		}
	}
	return ret;
}

eCircularBufferRet AddElement( CircularBuffer *cbQueue, int *element )
{
	eCircularBufferRet ret = eCB_SUCCESS;
	int temp = 0;
	int *ptr = NULL;

	if( NULL == cbQueue )
	{
		ret = eCB_FAILED;
	}
	else
	{
		if( eCB_FAILED == checkBufferFull( cbQueue ) )
		{
			ret = eCB_FAILED;
		}
		else
		{
			cbQueue->head = cbQueue->head % cbQueue->size;
			ptr = cbQueue->holdingBuffer + ( cbQueue->head * cbQueue->sizeOfEachElement );
			memcpy( ptr, element, cbQueue->sizeOfEachElement );
			temp = ( cbQueue->head + 1 ) % cbQueue->size;
			if( temp != cbQueue->tail )
			{
				cbQueue->head = ( cbQueue->head + 1 ) % cbQueue->size;
			}
			else
			{
				/*Do Nothing*/
			}
		}
	}
	return ret;
}

eCircularBufferRet RemoveElement( CircularBuffer *cbQueue , int *element )
{
	eCircularBufferRet ret = eCB_SUCCESS;
	int *ptr;

	if( NULL == cbQueue )
	{
		ret = eCB_FAILED;
	}
	else
	{
		if( eCB_FAILED == checkBufferEmpty( cbQueue ))
		{
			ret = eCB_FAILED;
		}
		else
		{
			ptr = cbQueue->holdingBuffer + ( cbQueue->tail * cbQueue->sizeOfEachElement );
			memcpy( element, ptr, cbQueue->sizeOfEachElement );
			memcpy( ptr,"\0", cbQueue->sizeOfEachElement );
			cbQueue->tail = ( cbQueue->tail + 1 ) % cbQueue->size;
		}
	}
	return ret;
}

void DisplayMenu( void )
{
	printf("Select Choice\n");
	printf("1.Add element to circular queue\n");
	printf("2.Delete element from circular quque\n");
	printf("3.Display queue\n");
}

void DisplayQueue( CircularBuffer *cbQueue )
{
	for( int i = 0;i< cbQueue->size; i++)
	{
		printf("[%d]\t", cbQueue->holdingBuffer[i]);
	}printf("\n");
}

int main( void )
{
	CircularBuffer cbQueue;
	eCircularBufferRet ret = eCB_SUCCESS;
	int input = 0;
	int element = 0;

	ret = initCircularBuffer( &cbQueue, dataBuffer, SIZE, sizeof( char ) );
	if( eCB_SUCCESS == ret )
	{
		while( 1 )
		{
			DisplayMenu();
			scanf("%d",&input);
			switch( input )
			{
			case ADD:
			{
				printf("Please Enter Element\n");
				scanf("%d", &element);
				ret = AddElement( &cbQueue, &element );
				if( eCB_SUCCESS == ret )
				{

				}
				else
				{
					printf("List is full\n");
				}
			}
			break;
			case DELETE:
			{
				ret = RemoveElement( &cbQueue, &element );
				if( eCB_SUCCESS == ret )
				{
					printf("[%d]\n",element);
				}
				else
				{
					printf("List is empty\n");
				}
			}
			break;
			case DISPLAY:
			{
				DisplayQueue( &cbQueue );
			}
			break;

			default:
			{
				/*Do Nothing*/
			}
			break;
			}
		}
	}
	else
	{
		printf("Failed to Initialized circular buffer\r\n");
	}
	return 0;
}


