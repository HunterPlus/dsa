#include <stdio.h>
#include <stdlib.h>

int icmp(const void *x, const void *y)
{
        int     *ix, *iy;

        ix = (int *) x;
        iy = (int *) y;
        return *ix - *iy;
}

int main()
{
        int arr[] = { 2, 8, 10, 13, 21, 26, 35 };
        int n, key, *pkey;

        n = sizeof(arr) / sizeof(arr[0]);
        key = 21;
        pkey = bsearch(&key, arr, n, sizeof arr[0], icmp);
        printf ("key: %d\n", (pkey == NULL) ? 0 : *pkey);
}