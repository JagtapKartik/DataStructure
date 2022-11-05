/*
 * main.c
 *
 *  Created on: 08-Apr-2020
 *      Author: Kartik
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int return_max(int *arr,int arr_count){
    int max = arr[0];
    for(int i = 0;i<arr_count;i++){
        if(arr[i] > max ){
            max = arr[i];
        }
    }
    return max;
}

// Complete the sockMerchant function below.
int sockMerchant(int n, int ar_count, int* ar) {
	int max = return_max(ar,n);
	int sock_count = 0;
	max++;
	printf("Max Return [%d]\n",max);
	int *new_array = (int *)calloc(max,sizeof(int));
//	memset(ar,0,sizeof(int) * max);
	for(int i = 0;i<n;i++){
		new_array[ar[i]]++;
	}
	for(int i = 0;i<max;i++){
//		printf("%d %d\n",new_array[i],i);
		if(new_array[i] > 1){
			if((new_array[i] & 1) == 0){
				printf("even %d",i);
				sock_count += new_array[i] /2;
			}else{
				printf("odd %d",i);
				sock_count += (new_array[i] - 1)/2;
			}
		}
	}
	printf("sock_count [%d]",sock_count);
	return sock_count;
}

int main(void){

	int total_count = 9;
	int arr[9] = {10,20,20,10,10,30,50,10,20};
	sockMerchant(total_count,total_count,arr);
	return 0;
}
