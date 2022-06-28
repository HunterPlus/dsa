#include <stdio.h>
#include <stdlib.h>
#define n 5		/* number of vertices */
#define max 100		/* max number of edges */

struct edge {
	int	u, v;	/* vertex */
	int	w;	/* weight */
};

int	edges;
struct edge etab[max];

int find(int parent[], int i)
{
	if (parent[i] != i)
		find(parent, parent[i]);
	return parent[i];
}

void Union(int parent[], int x, int y)
{
	parent[x] = y;
}
	
void install(int g[][n])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (g[i][j] > 0) {
				etab[edges].u = i;
				etab[edges].v = j;
				etab[edges].w = g[i][j];
				edges++;
			}
	if (edges > max)
		fprintf(stderr, "install error");
}
int cmp(const void *x, const void *y)
{
	return ((struct edge *) x)->w - ((struct edge *) y)->w;
}
void kruskal(int g[][n])
{
	int parent[n], result[n];
	int	u, v;
	
	for (int i = 0; i < n; i++)
		parent[i] = i;
	install(g);
	qsort(etab, edges, sizeof(struct edge), cmp);
	
	for (int i = 0, j = 0; i < edges && j < n-1; i++) {
		u = find(parent, etab[i].u);
		v = find(parent, etab[i].v);
		if (u != v) {
			result[j++] = i;
			Union(parent, u, v);
		}
	}
	
	printf("kruskal's mst:\n");
	int cost = 0;
	struct edge *e;
	for (int i = 0; i < n-1; i++) {
		e = etab + result[i];
		printf("%d - %d => %d\n", e->u, e->v, e->w);
		cost += e->w;
	}
	printf("Kruskal's minimum spanning tree cost: %d\n", cost);
}

/* 
            2    3
    	(0)--(1)--(2)
    	|    / \   |
       6| 8/    \5 |7
    	| /      \ |
    	(3)-------(4)
              9         
*/
int main()
{
  	int graph[n][n] = { 	{ 0, 2, 0, 6, 0 },
                      		{ 2, 0, 3, 8, 5 },
                      		{ 0, 3, 0, 0, 7 },
                      		{ 6, 8, 0, 0, 9 },
                      		{ 0, 5, 7, 9, 0 } 	};
	kruskal(graph);
	return 0;
}
