/*
 * main.c
 *
 *  Created on: 11-Apr-2020
 *      Author: Kartik
 */

#include<stdio.h>

int resultIndex = 0;
int *cutTheSticks(int arr_count,int* arr,int* result_count){
	int noOfSticks = arr_count;
	int loopflag = 1;
	int *result = (int *) malloc(arr_count);

	while(loopflag){
		int min = 0;
		int deleteCount = 0;
		int loopCount = 0;
		if(noOfSticks == 1){
			result[resultIndex] = noOfSticks;
			loopflag = 0;
		}else{
			min = arr[0];
			for(int i = 0;i< noOfSticks;i++){
				result[resultIndex] = noOfSticks;
				if(min > arr[i]){
					min = arr[i];
				}
			}
			resultIndex++;
			printf("%d\n",resultIndex);
			for(int i=0;i<noOfSticks;i++){
				if(min == arr[i]){
					deleteCount += 1;
					loopCount = (noOfSticks - 1) - i;
					for(int j =0;j<loopCount;j++){
						arr[i] = arr[i+1];
					}
				}else if(min < arr[i]){
					arr[i - deleteCount] = arr[i] - min;
				}
			}
			noOfSticks = noOfSticks - deleteCount;
		}
	}
	*result_count = resultIndex;
	return result;
}

int main(void){
	int resultCount;
	int count = 8;
	int array[8] = {1,13,3,8,14,9,4,4};
	int *result = cutTheSticks(count,array,&resultCount);
	printf("result %d\n",*result);
	for(int i=0;i<= resultCount;i++){
		printf("Result %d\n",result[i]);
	}
	return 0;
}





