#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct edge {
	int	src;
	int	dest;
	int	weight;
};

struct graph {
	int	vertices;
	int	edges;
	struct edge *edge;
};

struct graph *creategraph(int v, int e)
{
	struct graph *g;
	
	if ((g = malloc(sizeof(struct graph))) == NULL) {
		fprintf(stderr, "creategraph error");
		exit(1);
	}
	g->vertices = v;
	g->edges = e;
	g->edge = malloc(e * sizeof(struct edge));
	if (g->edge == NULL) {
		fprintf(stderr, "creategraph edge error");
		free(g);
		exit(1);
	}
	return g;
}

void bellman(struct graph *g, int src)
{
	int 	vertices = g->vertices;
	int 	edges = g->edges;
	int	dist[vertices], u, v, weight;
	
	for (int i = 0; i < vertices; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	
	for (int i = 0; i < vertices-1; i++) 		/* counter, loop vertices-1 times */
		for (int j = 0; j < edges; j++) {
			u = g->edge[j].src;
			v = g->edge[j].dest;
			weight = g->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	
	/* detects negative weight cycle */
	for (int i = 0; i < edges; i++) {
		u = g->edge[i].src;
		v = g->edge[i].dest;
		weight = g->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			printf("graph contains negative weight circle\n");
	}
	
	printf("vertex\tdistance from %d\n", src);
	for (int i = 0; i < vertices; i++)
		printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    	int V = 5; 		/* Number of vertices in graph */
    	int E = 8; 		/* Number of edges in graph */
    	struct graph* graph = creategraph(V, E);
 
    	/* add edge 0-1 (or A-B) */
    	graph->edge[0].src = 0;
    	graph->edge[0].dest = 1;
    	graph->edge[0].weight = -1;
 
    	/* add edge 0-2 (or A-C) */
    	graph->edge[1].src = 0;
    	graph->edge[1].dest = 2;
    	graph->edge[1].weight = 4;
 
    	/* add edge 1-2 (or B-C) */
    	graph->edge[2].src = 1;
    	graph->edge[2].dest = 2;
    	graph->edge[2].weight = 3;
 
    	/* add edge 1-3 (or B-D) */
    	graph->edge[3].src = 1;
    	graph->edge[3].dest = 3;
    	graph->edge[3].weight = 2;
 
    	/* add edge 1-4 (or B-E) */
    	graph->edge[4].src = 1;
    	graph->edge[4].dest = 4;
    	graph->edge[4].weight = 2;
 
    	/* add edge 3-2 (or D-C) */
    	graph->edge[5].src = 3;
    	graph->edge[5].dest = 2;
    	graph->edge[5].weight = 5;
 
    	/* add edge 3-1 (or D-B) */
    	graph->edge[6].src = 3;
    	graph->edge[6].dest = 1;
    	graph->edge[6].weight = 1;
 
    	/* add edge 4-3 (or E-D) */
    	graph->edge[7].src = 4;
    	graph->edge[7].dest = 3;
    	graph->edge[7].weight = -3;
 	
	bellman(graph, 0);
	return 0;
}
	
