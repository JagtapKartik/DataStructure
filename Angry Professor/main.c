/*
 * main.c
 *
 *  Created on: 26-Apr-2020
 *      Author: Kartik
 */

#include <stdio.h>

void AngryProfessor(int n,int k,int *arr){
	int count = 0;
	for(int i =0;i<n;i++){
		if(arr[i]<= 0){
			count ++;
		}
	}
	if(count == k){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
}


int main(void){
	int n = 10, k=10;
	int arr[10] = {23 ,-35, -2, 58, -67, -56, -42, -73, -19, 37};
	AngryProfessor(n,k,arr);
	return 0;
}
