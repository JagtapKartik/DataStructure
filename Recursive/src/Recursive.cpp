//============================================================================
// Name        : Recursive.cpp
// Author      : Kartik Jagtap
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void recursive_fucntion_print_before(int n)
{
	if(n>0)
	{
		printf("[%d]\n", n);
		recursive_fucntion_print_before(n-1) ;
	}
}

void recursive_fucntion_print_after(int n)
{
	if(n>0)
	{
		recursive_fucntion_print_after(n-1) ;
		printf("[%d]\n", n);
	}
}



#if 0
int s[5] = {1,2,1,3,2};

int birthday(int s_count, int* s, int d, int m)
{
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
#endif

int main() {
	int n = 5;
	recursive_fucntion_print_before(n);
	recursive_fucntion_print_after(n);
	return 0;
}
