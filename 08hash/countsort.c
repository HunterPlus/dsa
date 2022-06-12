#include <stdio.h>
#define MAX 10

void countsort(int a[], int n)
{
	int	out[10], count[MAX], i;
	
	for (i = 0; i < MAX; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[a[i]]++;
	for (i = 1; i < MAX; i++)
		count[i] += count[i-1];
	for (i = 0; i < n; i++) {
		out[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}
	for (i = 0; i < n; i++)
		a[i] = out[i];
}
void prtarray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

int main()
{
	int arr[] = {4, 2, 2, 8, 3, 3, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	countsort(arr, n);
	prtarray(arr, n);
}
