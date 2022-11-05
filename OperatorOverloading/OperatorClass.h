/*
 * OperatorClass.h
 *
 *  Created on: 02-Nov-2021
 *      Author: Kartik
 */

#ifndef OPERATORCLASS_H_
#define OPERATORCLASS_H_

class OperatorClass {
private:
	int longitude;
	int latitude;
public:
	OperatorClass();
	OperatorClass( int lon, int lat );
	OperatorClass operator+( OperatorClass obj );
	OperatorClass operator-( OperatorClass obj );
	OperatorClass operator*( OperatorClass obj );
	void show( void );
	virtual ~OperatorClass();
};

#endif /* OPERATORCLASS_H_ */
