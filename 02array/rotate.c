#include <stdio.h>
#include <string.h>

void rotate(int off, int a[], int n)
{
        int tmp, i, j;

        off %= n;
        for (i = 0; i < off; i++) {
                tmp = a[0];
                for (j = 1; j < n; j++)
                        a[j-1] = a[j];
                a[j-1] = tmp;
        }
}

void blkrotate(int off, int a[], int n)
{
        int    buf[off%n];

        off %= n;
        memcpy(buf, a, sizeof buf);
        memmove(a, &a[off], (n-off) * sizeof (int));
        memcpy(&a[n - off], buf,  sizeof buf);
}

/* memorycpy - memcpy - copy memory area */
void *memorycpy(void *dest, const void *src, size_t n)
{
	char *tmp = dest;
	const char *s = src;

	while (n--)
		*tmp++ = *s++;
	return dest;
}

void printarray(int a[], int n);
int main()
{
        int arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
        int arr2[] = { 1, 2, 3, 4, 5, 6, 7 };
        int n = sizeof(arr1)/sizeof(arr1[0]);

        rotate(2, arr1, n);
        printarray(arr1, n);

        blkrotate(2, arr2, n);
        printarray(arr2, n);
}

void printarray(int a[], int n)
{
        for (int i = 0; i < n; i++)
                printf("%2d%c", a[i], (i%n == 9 || i == n-1) ? '\n' : ' ');
}
