/*
 * Array.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: Kartik
 */

#include "Array.h"

template <class T>Array<T>::Array(int sz) {
	// TODO Auto-generated constructor stub
	size = sz;
	array = new T[size];
	length = 0;
}

template <class T> void Array<T>::AddElement(T element){
	array[length ++] = element;
}

template <class T> void Array<T>::InsertElement(int index,T element){
	for(int i = size - 1;i >= index; i--){
		array[i] = array[i - 1];
	}cout<<endl;
	length ++;
	array[index] = element;
}

template <class T> void Array<T>::Display(){
	for(int i = 0;i<size;i++){
		cout << array[i] << "\t";
	}cout <<endl;
}

template <typename T> void Array<T>::ShifNegativeNumberOfLeftSide(){
	int i = 0;
	int j = length - 1;
	while(i<j){
		while(array[i]<0){i++;}
		while(array[j]>=0){j++;}
		if(i<j){
		T temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		}
	}
}

template <class T>Array<T>::~Array() {
	// TODO Auto-generated destructor stub
}

template <class T> void Array<T>::swap(int index1,int index2){
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;

}

template <class T> void Array<T>::SortArray(){
	for(int i =0;i<length - 1;i++){
		if(array[i] > array[i+1]){
//			printf("%d %d\n",array[i],array[i+1]);
			swap(i,i+1);
		}
	}
}

template <class T> void Array<T>::ArrayMerge(){
	int array_one[10] = {1,3,2,4,6,5,7,9,8,0};
	int array_two[10] = {10,12,11,13,15,16,14,20,45,88};
}

int main(void){
	Array<int> temp_array(11);
	temp_array.AddElement(-1);
	temp_array.AddElement(15);
	temp_array.AddElement(11);
	temp_array.AddElement(-3);
	temp_array.AddElement(5);
	temp_array.AddElement(-9);
	temp_array.AddElement(6);
	temp_array.AddElement(-6);
	temp_array.AddElement(9);
	temp_array.AddElement(-5);
//	temp_array.InsertElement(1,4);
//	temp_array.ShifNegativeNumberOfLeftSide();
//	temp_array.SortArray();
	temp_array.ArrayMerge();
//	temp_array.Display();
	return 0;
}
