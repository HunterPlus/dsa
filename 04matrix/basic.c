#include <stdio.h>

void add()
{
	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
	int b[2][3] = { 7, 8, 9, 10, 11, 12 };
	int c[2][3];
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
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
