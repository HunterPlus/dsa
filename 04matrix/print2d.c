#include <stdio.h>

void print2d(void *a, int m, int n)
{
  	int i, j, *p;
	
  	p = a;
  	for (i = 0; i < m; i++)
      		for (j = 0; j < n; j++)
     			printf("%3d %c", p[i*n + j], (j == n-1)? '\n' : ' ');
}

int main()
{
 	int arr[2][3] = { 11, 12, 13, 21, 22, 23 };
	
  	print2d(arr, 2, 3);
  	return 0;
}
