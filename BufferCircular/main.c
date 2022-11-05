/*
 * main.c
 *
 *  Created on: 21-Aug-2021
 *      Author: Kartik
 */


#include <stdio.h>
#include <stdint.h>

#define SIZE 					10

uint8_t cbuffer[SIZE];

typedef struct
{
	uint8_t head;
	uint8_t tail;
	uint8_t *buffer_ptr;
}circularBuffer;

void initialize_circular_buffer( circularBuffer *buffer, uint8_t *buffer_cir )
{
	buffer->head = 0;
	buffer->tail = 0;
	buffer->buffer_ptr = buffer_cir;
}

int check_buffer_full( circularBuffer *buffer )
{
	int ret = 0;
	int temp = 0;
	if( NULL == buffer )
	{
		ret = 1;
	}
	else
	{
		printf("Head[%d]\n",buffer->head);
		temp =  ( buffer->head + 1 ) % ( SIZE + 1 );
		if( buffer->tail == temp )
		{
			ret = 1;
		}
	}
	return ret;
}

int check_buffer_empty( circularBuffer *buffer )
{
	int ret = 0;
	int temp = 0;
	if( NULL == buffer )
	{
		ret = 1;
	}
	else
	{
		temp = (buffer->tail + 1) % SIZE;
		if( buffer->head == 0 && temp == 0 )
		{
			ret = 1;
		}
	}
	return ret;
}

void add_datatocircularbuffer( uint8_t data, circularBuffer *buffer )
{
	if( check_buffer_full(buffer) == 1 )
	{
		printf("buffer full\n");
	}
	else
	{
		buffer->head = (buffer->head) % SIZE;
		buffer->buffer_ptr[buffer->head] = data;
		buffer->head++;
//		if( temp != buffer->tail )
//		{
//			buffer->head = (buffer->head + 1) % SIZE;
//		}
	}
}

void delete_datafrombuffer( circularBuffer *buffer )
{
	int temp = 0;
	if( check_buffer_empty(buffer) == 1 )
	{
		printf("Buffer empty\n");
	}
	else
	{
		buffer->tail = buffer->tail % SIZE;
		buffer->buffer_ptr[buffer->tail] = 0;
		temp = (buffer->tail + 1) % SIZE;
		if( temp != 0 )
		{
			buffer->tail = (buffer->tail + 1) % SIZE;
		}
	}
}

void display_buffer( circularBuffer *buffer )
{
	for( int i=0;i<SIZE;i++)
	{
		printf("[%d]", buffer->buffer_ptr[i]);
	}
}

int main( void )
{
	int choice = 0;
	circularBuffer buffer;
	initialize_circular_buffer( &buffer, cbuffer);
	while(1)
	{
		printf("select choice\n");
		scanf( "%d", &choice);
		switch(choice)
		{
		case 1:
		{
			scanf("%d", &choice );
			add_datatocircularbuffer(choice ,&buffer);
			choice = 0;
		}
		break;
		case 2:
		{
			delete_datafrombuffer(&buffer);
			choice =0;
		}
		break;
		case 3:
		{
			display_buffer(&buffer);
			choice =0;
		}
		break;
		}
	}
	return 0;
}

