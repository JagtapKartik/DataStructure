/*
 * main.c
 *
 *  Created on: 13-Apr-2020
 *      Author: Kartik
 */


#include<stdio.h>

int treeRecursion(int n){
	if(n > 0){
		printf("%d",n);
		treeRecursion(n-1);
		treeRecursion(n-1);
	}
	return 0;
}

int main(void){
	int n = 3;
	treeRecursion(n);
	return 0;
}

