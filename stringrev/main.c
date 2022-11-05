/*
 * main.c
 *
 *  Created on: 10-Apr-2020
 *      Author: Kartik
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_string(char *actual){
	int len = 0;
	len = strlen(actual);
	int  j = len -1;
	char holdc = 0;
	for(int i =0;i<len /2;i++,j--){
		holdc = actual[i];
		actual[i] = actual[j];
		actual[j] = holdc;
	}
}

int beautifulDays(int i, int j, int k) {
	char HoldStringOfNum[7];
	int BeautifulDayCount = 0;
	int iterator = (j- i);
	for(int f = 0;f<= iterator;f++){
		sprintf(HoldStringOfNum,"%d",i);
		reverse_string(HoldStringOfNum);
		int ReverseNum = atoi(HoldStringOfNum);
		float Divident = (i - ReverseNum);
		if(Divident < 0){
			Divident *= -1;
		}
		float Result  = Divident / k;
		int Resulti = Result;
		printf("Resultf %f\t",Result);
		printf("Resulti %d\n",Resulti);
		if(Resulti == Result){
			BeautifulDayCount += 1;
		}
		i++;
		printf("f %d\n",f);
	}
	return BeautifulDayCount;
}


int main(void){
	printf("%d\n",beautifulDays(1,2000000,1000000000));
	return 0;
}


