#include <stdio.h>
#include <stdlib.h>

/* icmp: integer compare of *p1 and *p2	*/
int icmp(const void *p1, const void *p2)
{
	int	v1, v2;
	
	v1 = *(int *)p1;
	v2 = *(int *)p2;
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	return 0;
}

int main()
{
	int arr[] = { 12, 3, 8, 17, 26, 5 };
        int n = sizeof(arr) / sizeof(arr[0]);
	
	qsort(arr, n, sizeof(arr[0]), icmp);
        for (int i = 0; i < n; i++)
                printf("%3d  ", arr[i]);
        return 0;
}