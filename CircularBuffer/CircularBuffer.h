/*
 * CircularBuffer.h
 *
 *  Created on: 30-Nov-2020
 *      Author: Kartik
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

class CircularBuffer {
private:
	const int size = 5;
	int *circularBuffer;
	static int latestIndex;
public:
	CircularBuffer();
	virtual ~CircularBuffer();
	void AddDataToCircularBuffer(int data);
	void PrintData( void );
};

#endif /* CIRCULARBUFFER_H_ */
