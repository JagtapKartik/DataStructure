/*
 * Polynimial.h
 *
 *  Created on: 02-May-2020
 *      Author: Kartik
 */

#ifndef POLYNIMIAL_H_
#define POLYNIMIAL_H_

#include <iostream>

using namespace std;

typedef struct{
	int coef;
	int exponent;
}term_t;

class Polynimial {
private:
public:
	int n;
	term_t *term;
	Polynimial();
	virtual ~Polynimial();
};

#endif /* POLYNIMIAL_H_ */
