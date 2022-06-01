#include <stdio.h>
#include "stack.h"

void visit(int d)
{
	printf("%d\n", d);
}

void rvisit(int d)
{
	if (d == 0)
		return;
	rvisit(d - 1);
	visit(d);
}

/* visit data using DFS with recursion call */
void recursion(int a[], int n)
{
	for (int i = 0; i < n; i++)
		rvisit(a[i]);
	return;
}

/* visit data using DFS with stack */
void dfs(int a[], int n)
{
	int	d;
	
	for (int i = 0; i < n; i++){
		for (d = a[i]; d > 0; d--)
			push(d);
		while (!empty())
			visit(pop());
	}
}

int main()
{
	int arr[] = { 4, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	recursion(arr, n);
	printf("\n\n");
	dfs(arr, n);
	return 0;
}
