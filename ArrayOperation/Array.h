/*
 * Array.h
 *
 *  Created on: 20-Apr-2020
 *      Author: Kartik
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

using namespace std;

template <class T>
class  Array {
	T *array;
	int size;
	int length;
	void swap(int index1,int index2);
public:
	Array(int sz);
	void AddElement(T element);
	void InsertElement(int index,T element);
	void ShifNegativeNumberOfLeftSide();
	void SortArray();
	void Display();
	void ArrayMerge();
	virtual ~Array();
};

#endif /* ARRAY_H_ */
