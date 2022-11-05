/*
 * main.cpp
 *
 *  Created on: 02-May-2020
 *      Author: Kartik
 */

#include "Polynimial.h"
#include "math.h"



/*
 * polynimial 3x^5+2x^4+5x^2+2x+7
 */

int SumOfPolynomial(){
	Polynimial poly;
	cout <<"Enter no of non zero element"<<endl;
	cin >>poly.n;
	poly.term = new term_t[poly.n];
	cout<<"Enter Polynomial Term"<<endl;
	for(int i=0;i<poly.n;i++){
		cout<<"Enter Coeffient"<<i+1<<endl;
		cin>>poly.term[i].coef;
		cout<<"Enter Polynomial"<<i+1<<endl;
		cin>>poly.term[i].exponent;
	}
	int x = 5;
	int sum = 0;
	for(int i=0;i<poly.n;i++){
		sum += poly.term[i].coef * pow(x,poly.term[i].exponent);
	}
	cout<<"Sum"<<sum;
	return sum;
}

int main(void){

	int SumOfFirstPoly = 0;
	int SumOfSecondPoly = 0;

	cout<<"Enter First Polynomial"<<endl;
	SumOfFirstPoly = SumOfPolynomial();
	cout<<"Enter Second Polynomial"<<endl;
	SumOfSecondPoly = SumOfPolynomial();

	cout<<"Result"<<SumOfFirstPoly + SumOfSecondPoly;

	return 0;
}


