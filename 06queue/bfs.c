#include <stdio.h>
#include "queue.h"

void visit(int d)
{
	printf("%d\n", d);
}

/* visit data using BFS with queue */
void bfs(int a[], int n)
{
	int	d;
	
	for (int i = 0; i < n; i++)
		enqueue(a[i]);
	while (!empty()) {
		if ((d = dequeue()) > 1)
			enqueue(d - 1);
		visit(d);
	}
}

int main()
{
	int arr[] = { 4, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	bfs(arr, n);
	return 0;
}
