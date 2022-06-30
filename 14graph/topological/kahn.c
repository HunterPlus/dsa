#include "kahn.h"

void kahn(struct node **g, int n)
{
	struct node *node;
	int indegree[n], order[n], i, cnt;
	
	for (i = 0; i < n; i++)
		indegree[i] = 0;
	
	for (i = 0; i < n; i++)
		for (node = g[i]; node; node = node->next)
			indegree[node->dest]++;
	for (i = 0; i < n; i++)
		if (indegree[i] == 0)
			enqueue(i);
	
	cnt = 0;
	while (!empty()) {
		order[cnt++] = i = dequeue();
		for (node = g[i]; node; node = node->next)
			if (--indegree[node->dest] == 0)
				enqueue(node->dest);
	}
	if (cnt != n) {
		printf("warning: has an cycle\n");
		return;
	}
	for (i = 0; i < n; i++)
		printf("%2d  ", order[i]);
	printf("\n");
}

int main()
{
	struct node **g;
	
	g = creategraph(6);
	addedge(g, 5, 2);
	addedge(g, 5, 0);
	addedge(g, 4, 0);
	addedge(g, 4, 1);
	addedge(g, 2, 3);
	addedge(g, 3, 1);
	
	kahn(g, 6);
	return 0;
}
