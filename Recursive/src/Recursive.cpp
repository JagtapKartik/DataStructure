//============================================================================
// Name        : Recursive.cpp
// Author      : Kartik Jagtap
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int recursive_fucntion(int n){
	if(n>0){
		return recursive_fucntion(n-1) + n;
	}
	return 0;
}




int s[5] = {1,2,1,3,2};

int birthday(int s_count, int* s, int d, int m) {
    int count = 0;
    int sum = 0;
    int count_ret = 0;
    for(int i = 0;i<s_count;i++){
        for(int j = 0;j<m;j++){
            sum += s[count + j];
            if(sum == d && j == m-1){
                count_ret += 1;
                printf("count %d %d\n",count,j);
            }
        }sum = 0; count += 1;
    }
    return count_ret;
}

int main() {
//	int n = 5;
//	printf("%d\n",recursive_fucntion(n));

	/*int a = 10;
	printf("%d\n",a);
	printf("%d\n",a++);
	printf("%d\n",++a);
	printf("%d %d %d\n",a,a++,++a);
	*/
	printf("%d\n",birthday(5,s,3,2));

	return 0;
}
