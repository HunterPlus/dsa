#include <stdio.h>
#include <limits.h>

void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
void heapify(int a[], int n, int i)
{
	int	min, l, r;
	
	min = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && a[l] < a[min])
		min = l;
	if (r < n && a[r] < a[min])
		min = r;
	if (min != i) {
		swap(a + i, a + min);
		heapify(a, n, min);
	}
}

void insert(int a[], int *pn, int key)
{
	int	j;
	
	j = *pn;
	a[j] = key;
	++*pn;
	while (j > 0 && a[j] < a[(j-1)/2]) {
		swap(a + j; a + (j-1)/2);
		j = (j-1) / 2;
	}
}

int extract(int a[], int *pn)
{
	int	n;
	
	if ((n = --*pn) == 0)
		return a[0];
	swap(a, a + n);
	heapify(a, n, 0);
	return a[n];
}

void decrease(int a[], int i, int val)
{
	a[i] = val;
	while( i > 0 && a[i] < a[(i-1) / 2]) {
		swap(a + i; a + (i-1)/2);
		i = (i-1) / 2;
	}
}

int delete(int a[], int *pn, int i)
{
	int 	x;
	
	x = a[i];
	decrease(a, i, INT_MIN);
	extract(a, pn);
	return x;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%2d  ", a[i]);
    printf("\n");
}
int main()
{
	int arr[7] = {10, 28, 6, 9, 26, 13, 21};
	int heap[7], n = 0;
	
	for (int i = 0; i < 7; i++)
		insert(heap, &n);
	print(heap, n);
}
