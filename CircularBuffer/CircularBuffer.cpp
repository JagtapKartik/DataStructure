/*
 * CircularBuffer.cpp
 *
 *  Created on: 30-Nov-2020
 *      Author: Kartik
 */

#include "CircularBuffer.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
int CircularBuffer::latestIndex = 0;

CircularBuffer::CircularBuffer() {
	// TODO Auto-generated constructor stub
	circularBuffer = new int[size];
	memset( circularBuffer, 0, size);
}

CircularBuffer::~CircularBuffer() {
	// TODO Auto-generated destructor stub
}

void CircularBuffer::AddDataToCircularBuffer( int idata )
{
	circularBuffer[latestIndex] = idata;
	if( 4 == latestIndex )
	{
		latestIndex = 0;
	}
	else
	{
		latestIndex++;
	}
}

void CircularBuffer::PrintData( void )
{
	for(int i = 0;i<size;i++)
	{
		cout << "[" << circularBuffer[i]<<"]";
	}cout<<endl;
}

int main( void )
{
	CircularBuffer cb;
	int data = 0;
	while( 1 )
	{
		cout<<"Enter Data"<<endl;
		cin>> data ;
		cb.AddDataToCircularBuffer(data);
		cb.PrintData();
	}
	return 0;
}
