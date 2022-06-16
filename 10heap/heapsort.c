#include <stdio.h>

void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }

void heapify(int a[], int n, int i)
{
        int max, l, r;

        max = i;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < n && a[l] > a[max])
                max = l;
        if (r < n && a[r] > a[max])
                max = r;
        if (max != i) {
                swap(a + i, a + max);
                heapify(a, n, max);
        }
}

void heapsort(int a[], int n)
{
        int     i;

        for (i = n/2 - 1; i >= 0; i--)
                heapify(a, n, i);
        for (i = n-1; i > 0; i--) {
                swap(a, a + i);
                heapify(a, i, 0);
        }
}

void print(int a[], int n)
{
        for (int i = 0; i < n; i++)
                printf("%2d  ", a[i]);
        printf("\n");
}

int main()
{
        int arr[] = {12, 11, 13, 5, 6, 7, 9, 18};
        int n = sizeof(arr) / sizeof(arr[0]);

        heapsort(arr, n);
        print(arr, n);
        return 0;
}