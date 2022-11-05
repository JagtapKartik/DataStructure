/*
 * main.c
 *
 *  Created on: 18-Apr-2020
 *      Author: Kartik
 */

#include<stdio.h>
#define LENGHT 6

int arr[LENGHT] = {3,4,5,6,1,2};
int barr[LENGHT] = {10,11,12,13,14,15};

int LinearSearch(int key){
	for(int i=0;i<LENGHT;i++){
		if(key == arr[i]){
			return i;
		}
	}
	return -1;
}

int BinarySearch(int key,int low,int high){
	int mid;
	while(low <= high){
		mid = (high + low) / 2;
		if(barr[mid] == key){
			return mid;
		}else if(barr[mid] < key){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return -1;
}

int RecursiveBinarySearch(int key,int low,int high){
	int mid;
	if(low <= high){
		mid = (high + low) / 2;
		if(barr[mid] == key){
			return mid;
		}else if(barr[mid] < key){
			RecursiveBinarySearch(11,mid + 1,high);
		}else{
			RecursiveBinarySearch(11,low,mid - 1);
		}
	}
	return -1;
}

int main(void){
	printf("Linear Search [%d]\n",LinearSearch(2));
	printf("Binary Search [%d]\n",BinarySearch(11,0,5));
	printf("Recursive Binary Search [%d]\n",BinarySearch(14,0,5));
	return 0;
}


