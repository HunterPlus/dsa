#include <stdio.h>
#define n 5		/* number of vertices */
#define max 100		/* max number of edges */

struct edge {
	int	u, v;	/* vertex */
	int	w;	/* weight */
};

struct edge etab[max];


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
