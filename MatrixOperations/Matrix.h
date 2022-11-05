/*
 * Matrix.h
 *
 *  Created on: 23-Apr-2020
 *      Author: Kartik
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix();
	virtual void set(int i,int j,int x) = 0;
	virtual int get(int i,int j) = 0;
	virtual void Display() = 0;
	virtual ~Matrix();
};

#endif /* MATRIX_H_ */
