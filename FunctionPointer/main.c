/*
 * main.c
 *
 *  Created on: 02-Aug-2021
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdint.h>

typedef void ( *function_ptr ) ( void );

function_ptr fptr[5];

void function_0( void )
{
	printf("Calling from Function ptr 0\n");
}

void function_1( void )
{
	printf("Calling from Function ptr 1\n");
}

void function_2( void )
{
	printf("Calling from Function ptr 2\n");
}

void function_3( void )
{
	printf("Calling from Function ptr 3\n");
}

void function_4( void )
{
	printf("Calling from Function ptr 4\n");
}

void fun(int arr[])
{
	int i;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printf("arr_size %d\n ", arr_size);
	for (i = 0; i < arr_size; i++)
		printf("%d \n", arr[i]);
}

void swap(int *px, int *py)
{
	*px = *px - *py;
	*py = *px + *py;
	*px = *py - *px;
	printf("%d %d\n", *px,*py);
}

int f(int x, int *py, int **ppz)
{
	//	Here int x is treat as local variable of the function
	//	no issue
	int y, z;
	**ppz += 1;
	z  = **ppz;
	printf("z %d\n",z);
	printf("**ppz %d\n",**ppz);
	printf("x %d\n",x);

	*py += 2;
	y = *py;
	printf("y %d\n",y);
	x += 3;
	printf("x %d\n",x);
	return x + y + z;
}

int main( void )
{
#if 0
	uint64_t *u64ptr;
	uint32_t *u32ptr;
	uint16_t *u16ptr;
	uint8_t *u8ptr;
	char *cptr;
	int *ptr;

	printf("First \n[%p]\n [%p]\n [%p]\n [%p]\n [%p]\n ", u64ptr, u32ptr, u16ptr, u8ptr, cptr, ptr);
	u64ptr++; u32ptr++; u16ptr++; u8ptr++; cptr++; ptr++;
	printf("Second \n[%p]\n [%p]\n [%p]\n [%p]\n [%p]\n ", u64ptr, u32ptr, u16ptr, u8ptr, cptr, ptr);
#endif

#if 0
	int arr[4] = {10, 20 ,30, 40};
	fun(arr);
#endif

#if 0
	float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
	float *ptr1 = &arr[0];
	float *ptr2;
	ptr2 = ptr1;
	*ptr2 = 2;


	printf("%f\n ", *ptr1);
	//    printf("%d\n", ptr2 - ptr1);
	//    printf("%p %p\n", ptr1, ptr2);
	//    printf("%p %p\n", arr, arr + 3);
	//    printf("%p %p\n", ptr1, ptr1 + 3);
	//    printf("%d %d\n", ptr1, ptr1 + 3);
	//    printf("%f %d\n", *ptr1,  ptr1 + 3 );
#endif

#if 0
	int a = 6;
	int b = 5;
	swap(&a,&b);
#endif


#if 0
	int arr[] = {10, 20, 30, 40, 50, 60};
	int *ptr1 = arr;
	int *ptr2 = arr + 5;
	printf("Number of elements between two pointer are: %d.",
			(ptr2 - ptr1));
	printf("Number of bytes between two pointers are: %d",
			(char*)ptr2 - (char*) ptr1);
#endif

#if 0
	int c, *b, **a;
	c = 4;
	b = &c;
	a = &b;
	printf("%d ", f(c, b, a));
#endif

#if 0
//	We can can not de-reference void pointer
	int a = 12;
	void *ptr = (int *)&a;
	printf("%d", *ptr);
#endif

#if 1
	int amount  = 8000;
	int ret = 0;
	for( int i=0;i<30;i++)
	{
		ret = amount / 100;
		ret = ret * 5;
		amount += ret;
	}
	printf("Amount %d\n", amount );
#endif

	return 0;
}



