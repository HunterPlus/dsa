#include <stdio.h>
#include "queue.h"

void visit(int d)
{
	printf("%d\n", d);
}

void dfsvisit(int d)
{
	if (d == 0)
		return;
	dfsvisit(d - 1);
	visit(d);
}

/* visit data using DFS */
void visitarray1(int a[], int n)
{
	for (int i = 0; i < n; i++)
		dfsvisit(a[i]);
	return;
}

/* visit data using BFS */
void visitarray2(int a[], int n)
{
	int	d;
	
	for (int i = 0; i < n; i++)
		enqueue(a[i]);
	while (!empty()) {
		d = dequeue();
		visit(d);
		if (d > 1)
			enqueue(d - 1);
	}
}

int main()
{
	int arr[] = { 4, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	visitarray1(arr, n);
	visitarray2(arr, n);
	return 0;
}
