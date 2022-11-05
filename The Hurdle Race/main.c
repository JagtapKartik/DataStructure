/*
 * main.c
 *
 *  Created on: 26-Apr-2020
 *      Author: Kartik
 */

#include<stdio.h>

int hurdleRace(int k, int height_count, int* height) {
	int count  = 0;
	int max = 0;
	max = height[0];
	for(int i =0;i<height_count;i++){
		if(height[i] > max){
			max=height[i];
		}
	}
	if(k<max){
		count = max-k;
	}
	return count;
}

int main(void){
	int n = 5,k=4;
	int height[5]={1,6,3,5,2};
	printf("%d\n",hurdleRace(k,n,height));
	return 0;
}



