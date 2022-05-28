#include <stdio.h>

void mergeprt(int a[], int low, int high)
{
        int     mid;

        if (low > high)
                return;
        if (low == high) {
                printf("%3d", a[low]);
                return;
        }

        printf("pre split:\t");
        for (int i = low; i <= high; i++)
                printf("%3d  ", a[i]);
        printf("\n");

        mid = (low + high) / 2;
        mergeprt(a, low, mid);
        printf("\n");
        mergeprt(a, mid+1, high);
        printf("\n");

        printf("post merge:\t");
        for (int i = low; i <= high; i++)
                printf("%3d  ", a[i]);
        printf("\n");
}

int main()
{
        int arr[] = { 15, 12, 13, 7, 24, 18, 11, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        mergeprt(arr, 0, n-1);
        return 0;
}