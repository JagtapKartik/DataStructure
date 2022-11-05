
#include <stdio.h>
#include <stdint.h>

#define SETBIT( VARIABLE, POSITION ) ( VARIABLE |= ( 1 << POSITION ) )
#define CLEARBIT( VARIABLE, POSITION ) ( VARIABLE &= ~( 1 << POSITION ) )
#define S(X) ( X * X)

typedef struct{
	int a;
	union temp{
		int b;
		uint8_t arr[4];
	};
}test;

void convert( int *a )
{
	uint8_t b[4] = {0};
	b[0] = (uint8_t) *a;
	b[1] = (uint8_t) ( *a >> 8 );
	b[2] = (uint8_t) ( *a >> 16 );
	b[3] = (uint8_t) ( *a >> 24 );
	*a = ( uint32_t ) ( b[0] << 24 );
	*a |= ( uint32_t ) ( b[1] << 16);
	*a |= ( uint32_t ) ( b[2] << 8 );
	*a |= ( uint32_t ) ( b[3] << 0 );
}

#if 0
int main( void ){
	//		test test_t;
	//		test_t.a = 40;
	//		test_t.b = 30;
	//		printf("[%d]\n",test_t.a);
	//		printf("[%x]\n", test_t.arr[0]);
	//		printf("[%x]\n", test_t.arr[1]);
	//		printf("[%x]\n", test_t.arr[2]);
	//		printf("[%x]\n", test_t.arr[3]);
	//		const int *ptr = &test_t.a;
	//		test_t.a = 60;
	//		ptr = &test_t.b;
	//		printf("[%d]\n", *ptr);
	//
	//		int *const ptr_1 = &test_t.a;
	//		printf("[%d]\n", *ptr_1);
	//	//	ptr_1 = &test_t.b;
	//		printf("[%d]\n", *ptr_1);
	//
	//		const int var_3= 51;
	//		ptr = &var_3;
	//		printf("[%d]\n", *ptr);
	//		*ptr = 61;
	//		printf("[%d]\n", *ptr);
	//		while(1);
	int a = 0xAABBCCDD;
	printf("big Endien[%x]\n",a);
	convert(&a);
	printf("little Endien[%x]\n",a);

	int temp = 0;
	SETBIT(temp, 2);
	printf("set [%x]\n",temp);
	CLEARBIT(temp, 2);
	printf("clear [%x]\n",temp);
	return 0;
}
#endif

int main()
{
//    int a[5] = {1,2,3,4,5};
//    int *ptr = (int*)(&a+1);
//    printf("%d %d\n", *(a+1), *(ptr-1));
//    int b[3] = {1,2,3};
//    int *ptr1 = (int*)(&b+1);
//    printf("%d %d\n", *(b+1), *(ptr1-1));
//
//    char c[3] = {'a','b','c'};
//    char *ptr2 = (char*)(&c+1);
//    printf("%c %c", *(c+1), *(ptr2-1));


    char *str = "abc";
    printf("[%x]\n", str);
    printf("[%x]\n", *(str + 1 ) );
//    *(str + 1 ) = 'n';
//    printf("[%s]\n", str);
    int a, b=8;
    a= b+NULL;
    printf("[%d]", a);

    volatile int c= 60;
    const int d = c;
    printf("[%d]", d);

    printf("[%d]\n", S(2+3));

    unsigned int e = 3427;
    int *p;
    p =&e;
    printf("[%u]\n", &e);
    printf("%u %u\n", &*p, *&p);

    int i;
    do
    {
    	for( i=0;i<7;i++)
    	{
    		printf("FOR\n");
    		break;
    	}
    	printf("WHILE\n");
    }while(i);
    return 0;
}
