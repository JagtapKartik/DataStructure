/*
 * main.c
 *
 *  Created on: 14-Apr-2020
 *      Author: Kartik
 */


#include<stdio.h>

int factorial(int n){
	if(n == 0){
		return 1;
	}
	return factorial(n -1) * n;
}

int main(void){
	printf("%d\n",factorial(5));
	return 0;
}

