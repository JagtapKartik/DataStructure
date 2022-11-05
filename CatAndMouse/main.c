/*
 * main.c
 *
 *  Created on: 26-Apr-2020
 *      Author: Kartik
 */
#include<stdio.h>

char* catAndMouse(int x, int y, int z) {
	int A = z - x;
	int B = z - y;
	char *ret;
	if(A < 0){
		A *= -1;
	}
	if(B<0){
		B *= -1;
	}

	if(A==B){
		ret = "Mouse C";
		return ret;
	}

	if(A<B){
		ret = "CAT A";
		return ret;
	}else{
		ret = "CAT B";
		return ret;
	}
}

int main(void){
	int x = 1,y=3,z=2;
	printf("%s\n",catAndMouse(x,y,z));
	return 0;
}



