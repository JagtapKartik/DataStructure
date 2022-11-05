/*
 * DiagonalMatrix.h
 *
 *  Created on: 23-Apr-2020
 *      Author: Kartik
 */

#ifndef DIAGONALMATRIX_H_
#define DIAGONALMATRIX_H_

#include "Matrix.h"

class DiagonalMatrix: public Matrix {
private:
	int size;
	int *array;
public:
	DiagonalMatrix(int sz);
	void set(int i,int j,int x);
	int get(int i,int j);
	void Display();
	virtual ~DiagonalMatrix();
};

#endif /* DIAGONALMATRIX_H_ */
