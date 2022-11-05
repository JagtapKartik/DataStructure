/*
 * main.c
 *
 *  Created on: 18-Apr-2020
 *      Author: Kartik
 */
#include<stdio.h>
#define SIZE 7

void ReverseArray(int *arr,int length){
	int j = length - 1,i;
	int temp;
	length = length / 2;
	for(i=0;i<length;i++,j--){
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void LeftShiftArray(int *arr,int length){
	for(int i=0;i<length;i++){
		arr[i] = arr[i+1];
	}
}

void RotateLeft(int *arr,int length){
	int temp;
	temp = arr[0];
	for(int i=0;i<length-2;i++){
		arr[i] = arr[i+1];
	}
	arr[length - 1] = temp;
}

void RightShiftArray(int *arr,int length){
	for(int i=length;i>=0;i--){
		arr[i + 1] = arr[i];
	}
}

void RotateRight(int *arr,int length){
	int temp;
	temp = arr[length - 1];
	for(int i=length - 2;i>=0;i--){
		arr[i+1] = arr[i];
	}
	arr[0] = temp;
}


int main(void){
	int arr[SIZE] = {10,11,13,14,16,18,19};

//	ReverseArray(arr,SIZE);
//	LeftShiftArray(arr,SIZE);
//	RotateLeft(arr,SIZE);
//	RightShiftArray(arr,SIZE);
	RotateRight(arr,SIZE);
	printf("\n[");
	for(int i = 0;i<SIZE;i++){
		printf("%d\t",arr[i]);
	}printf("]\n");
	return 0;
}



