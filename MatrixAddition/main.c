
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void print_matrix( int matrix[2][2],int row,int column )
{
	for( int matrow = 0; matrow < row; matrow++)
	{
		for( int matcolumn = 0; matcolumn < column; matcolumn++)
		{
			printf("[%d]\t",matrix[matrow][matcolumn]);
		}printf("\n");
	}
}

void add_matrix_with_same_size( int mat1[2][2], int mat1row, int mat1column, int mat2[2][2], int mat2row, int mat2column ,int resultMatrix[2][2] )
{
	int row = 0, column  = 0;
	for( row = 0; row < mat1row; row ++ )
	{
		for( column = 0; column<mat1column; column ++ )
		{
			resultMatrix[row][column] = mat1[row][column] + mat2[row][column];
		}
	}
	print_matrix( resultMatrix , mat1row, mat1column );
}

int main(void)
{

	int matrix1[2][2] = {{2,4},{6,8}};
	int matrix2[2][2] = {{3,6},{9,12}};
	int resultMatrix[2][2];
	add_matrix_with_same_size( matrix1, 2, 2, matrix2, 2, 2, resultMatrix );
	getch();
	return 0;
}



