#include <stdio.h>
#include <string.h>

void swap(int *x, int *y)
{
        int     tmp;

        tmp = *x;
        *x = *y;
        *y = tmp;
}

void isort(int a[], int n)
{
        int     i, j;

        for (i = 1; i < n; i++)
                for (j = i; j > 0 && a[j-1] > a[j]; j--)
                        swap(&a[j], &a[j-1]);
}

int ksmall(int k, int a[], int n)
{
        int temp[n];

        memcpy(temp, a, n * sizeof(int));
        isort(temp, n);
        return temp[k-1];
}

int main()
{
        int arr[] = { 3, 8, 2, 9, 12 };
        int n = sizeof(arr) / sizeof(arr[0]);

        isort(arr, n);
        for (int i = 0; i < n; i++)
                printf("%2d ", arr[i]);
        return 0;
}