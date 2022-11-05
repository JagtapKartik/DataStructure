/*
 * main.c
 *
 *  Created on: 13-Apr-2020
 *      Author: Kartik
 */


#include <stdio.h>

int recursiveWithStaticVariable(int n){
	static int x = 0;
	if(n>0){
		return recursiveWithStaticVariable(n - 1) + x;
	}
	return 0;
}

int main(void){
	int n = 3;
	printf("%d\n",recursiveWithStaticVariable(n));
	return 0;
}

