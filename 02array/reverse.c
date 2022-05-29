#include <stdio.h>

void reverse(int a[], int n)
{
	int	i, j, tmp;
	
	for (i = 0, j = n-1; i < j; i++, j--) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	reverse(arr, n);
	for (int i = 0; i < n; i++)
		printf("%3d  ", arr[i]);
	return 0;
}
