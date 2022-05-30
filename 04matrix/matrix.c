#include <stdio.h>

void mtx_print(void *a, int m, int n)
{
  	int 	i, j;
	double	*p;
	
  	p = a;
  	for (i = 0; i < m; i++)
      		for (j = 0; j < n; j++)
     			printf("%.4f %c", p[i*n + j], (j == n-1)? '\n' : ' ');
}
void *mtx_add(void *a, void *b, void *c, int m, int n)
{
	int	i, j;
	double	*pa, *pb, *pc;
	
	pa = a;
	pb = b;
	pc = c;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			pc[i*n + j] = pa[i*n + j] + pb[i*n + j];
	return pc;
}

void *mtx_bias(double bias, void *a, int m, int n)
{
	int	i, j;
	double	*p;
	
	p = a;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			p[i*n + j] += bias;
	return p;
}

void *mtx_scale(double scale, void *a, int m, int n)
{
	int	i, j;
	double	*p;
	
	p = a;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			p[i*n + j] *= scale;
	return p;
}

int main()
{
 	double arr1[2][3] = { 11, 12, 13, 21, 22, 23 };
	double arr2[2][3] = {1, 2, 3, 4, 5, 6 };
	double arr3[2][3];
	
	mtx_add(arr1, arr2, arr3, 2, 3);
  	mtx_print(arr3, 2, 3);
	
	mtx_bias(0.1, arr3, 2, 3);
	mtx_print(arr3, 2, 3);
	
	mtx_print(mtx_scale(0.1, arr3, 2, 3), 2, 3);
  	return 0;
}
