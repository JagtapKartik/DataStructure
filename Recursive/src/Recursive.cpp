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

int recursive_with_static_var(int n)
{
	static int x = 0;

	if(n > 0)
	{
		x++;
		return recursive_with_static_var(n-1) + x;
	}
	return 0;
}

void tree_recursion(int n)
{
	if(n>0)
	{
		printf("[%d]\n",n);
		tree_recursion(n-1);
		tree_recursion(n-1);
	}
}

void indirect_recursion_2(int n);

void indirect_recursion_1(int n)
{
	if(n>0)
	{
		printf("[%d]",n);
		indirect_recursion_2(n-1);
	}
}

void indirect_recursion_2(int n)
{
	if(n>1)
	{
		printf("[%d]",n);
		indirect_recursion_1(n/2);
	}
}


int nested_recursion(int n)
{
	if(n>100)
	{
		return n-10;
	}
	else
	{
		return nested_recursion(nested_recursion(n+11));
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
	int n = 3;
	recursive_fucntion_print_before(n);
	recursive_fucntion_print_after(n);
	printf("recursive with static [%d]\n",recursive_with_static_var(n));
	tree_recursion(3);
	indirect_recursion_1(20);
	printf("\n[%d]",nested_recursion(95));
	return 0;
}
