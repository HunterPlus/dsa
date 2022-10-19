#include <stdio.h>
#define CAPACITY 10

int find(int key, int a[], int n)
{
    	int i;
    
    	for (i = 0; i < n; i++)
        	if (a[i] == key)
            		return i;
    	return -1;
}

int insert(int key, int a[], int *pn)            /* sorted array */
{
        int     i;

        for (i = *pn-1; a[i] > key; i--)         /* not check array capacity */
                a[i+1] = a[i];
        a[++i] = key;
        ++*pn;                                  /* update nelems */
        return i;                               /* index where inserted */
}

int extract(int idx, int a[], int *pn)
{
        int     elem, i;

        if (idx < 0 || idx >= *pn)
                return -1;
        elem = a[idx];
        for (i = idx+1; i < *pn; i++)
                a[i-1] = a[i];
        --*pn;                            /* update nelems */
        return elem;
}

int main()
{
        int     arr[CAPACITY] = { 10, 20, 30, 40, 50};
        int     n = 5, idx, e;

        insert(15, arr, &n);
        idx = find(30, arr, n);
        e = extract(idx, arr, &n);
        printf("e: %d\n", e);
        for (int i = 0; i < n; i++)
                printf("%2d ", arr[i]);
        return 0;
}