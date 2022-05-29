#include <stdio.h>

void swap(int *x, int *y)
{
        int tmp;

        tmp = *x;
        *x = *y;
        *y = tmp;
}

void quicksort(int a[], int n)
{
        int     i, j;

        if (n <= 1)
                return;
        i = 0;
        j = n;
        for (;;) {
                do {
                        i++;
                } while (i < n && a[i] < a[0]);
                do {
                        j--;
                } while (a[j] > a[0]);
                if (j < i)
                        break;
                swap(&a[i], &a[j]);     
        }
        swap(&a[0], &a[j]);
        quicksort(a, j);
        quicksort(a + j + 1, n - j - 1);
}

int main()
{
        int arr[] = { 23, 19, 2, 26, 7, 15 };
        int n = sizeof(arr) / sizeof(arr[0]);

        quicksort(arr, n);
        for (int i = 0; i < n; i++)
                printf("%3d  ", arr[i]);
        return 0;
}