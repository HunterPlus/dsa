#include <stdio.h>
#define n 5		/* number of vertices */
#define max 100		/* max number of edges */

struct edge {
	int	u, v;	/* vertex */
	int	w;	/* weight */
};

int	edges;
struct edge etab[max];

void install(int g[][n])
{
	for (int i = 0; i < n - 1; i++)
		for (int j > i; j < n; j++)
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
	install(g);
	qsort(etab, edges, sizeof(struct edge), cmp);
}

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
