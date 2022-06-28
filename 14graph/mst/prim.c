#include <stdio.h>
#include <limits.h>
#include <string.h>

#define n 5		/* number of vertices */

void prim(int g[][n], int start)
{
	int	selected[n];
	int	x, y, min;	
	
	memset(selected, 0, sizeof(selected));	
	selected[start] = 1;
	printf("edge : weight\n");
	for (int edges = 1; edges < n; edges++) {	/* minimum spanning tree has n-1 edges */
		x = y = 0;		/* x: from vertex, y: to vertex, form a edge */
		min = INT_MAX;		/* hold the minimum weight */
		
		for (int i = 0; i < n; i++) 	/* traversal the selected array */
			if (selected[i])
				for (int j = 0; j < n; j++) 
					if (!selected[j] && g[i][j]) 		/* select an edge */
						if (g[i][j] < min) {
							min = g[i][j];
							x = i;
							y = j;
						}
		printf("%d - %d : %d\n", x, y, g[x][y]);
		selected[y] = 1;
	}
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
	prim(graph, 0);
	return 0;
}
