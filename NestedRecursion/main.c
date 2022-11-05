/*
 * main.c
 *
 *  Created on: 13-Apr-2020
 *      Author: Kartik
 */



#include<stdio.h>

int nestedRecursion(int n){
	if(n > 0){
		printf("%d\n",n);
		return nestedRecursion(nestedRecursion(n - 1));
	}
	return 0;
}

void Something()
{
	int *ptr;
	char a = 'K';
	ptr = (int *)&a;
	printf("[%c]\n",*ptr);

}

int main(void){
	int n = 3;
	nestedRecursion(n);
	Something();
	return 0;
}
