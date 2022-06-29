#include <stdio.h>
#define INF 99999
#define n 4


void floyd(int g[][n])
{
	int	i, j, k, d;
	int	dist[n][n];
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dist[i][j] = g[i][j];
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) 
				if ((d = dist[i][k] + dist[k][j]) < dist[i][j])
					dist[i][j] = d;
	/* print dist matrix */
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
			if (dist[i][j] = INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		printf("\n");
	}
}

/* 
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           	*/
int main()
{
    	int graph[n][n] = { 	{0,   5,  INF, 10},
                        	{INF, 0,   3, INF},
                        	{INF, INF, 0,   1},
                        	{INF, INF, INF, 0}	};
     
	floyd(graph);
    	return 0;
}
