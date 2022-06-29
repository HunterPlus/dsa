#include <stdio.h>
#include <limits.h>
#define n 9

/* mindistance: get shortest path vertex index */
int mindistance(int dist[], int spt[])
{
	int	min, index;
	
	min = INT_MAX;
	for (int i = 0; i < n; i++) 
		if (!spt[i] && dist[i] <= min) {
			min = dist[i];
			index = i;
		}
	return index;
}

void dijkstra(int g[][n], int start)
{
	int	dist[n], spt[n] = {};		/* spt[]: sortest path tree set */
	
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[start] = 0;
	for (int count = 0; count < n-1; count++) {	/* count: vertices counter */
		int u = mindistance(dist, spt);
		
		spt[u] = 1;
		for (int v = 0; v < n; v++)
			if (!spt[v] && g[u][v] && dist[u] != INT_MAX && dist[u] + g[u][v] < dist[v])
				dist[v] = dist[u] + g[u][v];
	}
	printf("vertex\t\tdistance from %d", start);
	for (int i = 0; i < n; i++)
		printf("%d\t\t%d\n", i, dist[i]);
}

int main()
{
    	int graph[n][n] = { 	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } 	};
  
    	dijkstra(graph, 0);

    	return 0;
}
