#include <stdio.h>
#include "stack.h"

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0; i < n; i++)
		push(arr[i]);
	while (!empty())
		printf("%d\t", pop());
	return 0;
}
