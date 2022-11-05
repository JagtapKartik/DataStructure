/*
 * DiagonalMatrix.cpp
 *
 *  Created on: 23-Apr-2020
 *      Author: Kartik
 */

#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(int sz){
	// TODO Auto-generated constructor stub
	size = sz;
	array = new int[size];
}

DiagonalMatrix::~DiagonalMatrix() {
	// TODO Auto-generated destructor stub
	delete []array;
}

void DiagonalMatrix::set(int i,int j,int x){
	if( i==j){
		array[i-1] = x;
	}
}

int DiagonalMatrix::get(int i,int j){
	if(i == j) {
		return array[i - 1];
	}
	return 0;
}

void DiagonalMatrix::Display(){
	int i,j;
	for(i= 0;i<size;i++){
		for(j=0;j<size;j++){
			if(i==j){
			cout << array[i];
			}else{
				cout << 0;
			}
			cout<<"\t";
		}cout<<endl;
	}
}

int main(void)
{
	DiagonalMatrix diagonal_matrix(5);
	diagonal_matrix.set(1,1,1);
	diagonal_matrix.set(2,2,2);
	diagonal_matrix.set(3,3,3);
	diagonal_matrix.set(4,4,4);
	diagonal_matrix.set(5,5,5);
	diagonal_matrix.Display();
	cout<<diagonal_matrix.get(2,2);
	return 0;
}
