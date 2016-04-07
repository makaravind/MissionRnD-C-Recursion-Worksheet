/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#include<malloc.h>
void spiralPrint(int m, int n, int **a,int *result,int *rptr);
int *spiral(int rows, int columns, int **input_array)
{
	if (rows<=0||columns<=0||input_array==NULL) 
		return NULL;

	int *result = (int*)malloc(sizeof(int)*( (rows - 1)*(columns - 1) ));
	int index = 0;
	int x1 = 0;
	int y1 = 0;
	spiralPrint(rows, columns, input_array, result, &index);
	return result;
}
void spiralPrint(int m, int n, int **a, int *result, int *rptr)
{
	int i, k = 0, l = 0;

	while (k < m && l < n)
	{
		/* Print the first row from the remaining rows */
		for (i = l; i < n; ++i)
		{
			result[*rptr] = a[k][i];
			*rptr = *rptr + 1;
		}
		k++;

		/* Print the last column from the remaining columns */
		for (i = k; i < m; ++i)
		{
			result[*rptr] = a[i][n - 1];
			*rptr = *rptr + 1;
		}
		n--;

		/* Print the last row from the remaining rows */
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				result[*rptr] = a[m - 1][i];
				*rptr = *rptr + 1;
			}
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				result[*rptr] = a[i][l];
			}
			l++;
		}
	}
}