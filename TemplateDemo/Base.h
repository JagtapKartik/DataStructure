/*
 * Base.h
 *
 *  Created on: 08-Nov-2021
 *      Author: Kartik
 */

#ifndef BASE_H_
#define BASE_H_

class Base {
public:
	Base();
	template <typename x> void testfunction( x data );
	virtual ~Base();
};

#endif /* BASE_H_ */
