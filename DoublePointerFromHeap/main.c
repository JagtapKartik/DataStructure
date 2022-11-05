/*
 * main.c
 *
 *  Created on: 17-Apr-2020
 *      Author: Kartik
 */



#include<stdio.h>
#include<stdlib.h>


int main(void){
	int **heap_ptr = (int **) malloc(3 * sizeof(int));
	int a[3] = {1,2,3};
	int b[3] = {4,5,6};
	int c[3] = {7,8,9};

	heap_ptr[0] = a;
	heap_ptr[1] = b;
	heap_ptr[2] = c;

	for(int i =0;i<3;i++){
		for(int j =0;j<3;j++){
			printf("%d",heap_ptr[i][j]);
		}printf("\n");
	}
}
