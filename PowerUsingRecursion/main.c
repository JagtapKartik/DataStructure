/*
 * main.c
 *
 *  Created on: 14-Apr-2020
 *      Author: Kartik
 */

#include<stdio.h>

int power(int m,int n){
	if(n == 0){
		return 1;
	}
	if(n %2 == 0){
		return power( m * m, n / 2);
	}else{
		return m * power(m * m,(n-1) /2);
	}
}

int main(void){
	printf("%d\n",power(2,9));
	return 0;
}




