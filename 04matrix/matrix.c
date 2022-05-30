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

/* mtx_mul: a = m x dim, b = dim x n; c = m x n */
void *mtx_mul(void *a, void *b, void *c, int m, int dim, int n)
{
	int	i, j, k;
	double	*pa, *pb, *pc, e;
	
	pa = a;
	pb = b;
	pc = c;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			e = 0.0;
			for (k = 0; k < dim; k++)
				e += pa[i*dim + k] * pb[k*n + j];
			pc[i*n + j] = e;			
		}
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
	
	
	double a[2][3] = { 1, 2, 3, 4, 5, 6 };
	double b[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	double c[2][4];
	
	mtx_print(mtx_mul(a, b, c, 2, 3, 4), 2, 4);
  	return 0;
}
