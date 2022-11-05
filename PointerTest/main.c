/*
 * main.c
 *
 *  Created on: 26-Jan-2021
 *      Author: Kartik
 */


int main( void )
{
	int *pp, *p;

	pp = 0;
	p = 0;

	printf("PP[%p]\n",pp);
	printf("P[%p]\n",p);

	pp ++;
	p ++;

	printf("PP[%p]\n",pp);
	printf("P[%p]\n",p);

	return 0;
}

