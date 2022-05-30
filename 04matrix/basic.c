#include <stdio.h>

void math()
{
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
	int b[2][3] = { 7, 8, 9, 10, 11, 12 };
	int c[2][3];
	
	/* add - add two matrix */
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
	/* bias */
	int bias = 3;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] += bias;
	/* scale */
	int scale = 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] *= scale;	
}
void mul()
{
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
	int b[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int c[2][4] = {0};
	int i, j, k;
	
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 3; k++)
				c[i][j] += a[i][k] * b[k][j];
				
	
}
int main()
{
	int arr[2][3] = { 11, 12, 13, 21, 22, 23 };
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			printf("%3d  ", arr[i][j]);
		printf("\n");
	}
	return 0;
}
