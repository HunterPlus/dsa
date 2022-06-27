#include <stdio.h>
#define n 5

int visited[n] = {};
void dfs(int g[][n], int u)
{
        visited[u] = 1;
        printf("vertex %d\n", u);
        for (int i = 0; i < n; i++)
                if (!visited[i] && g[u][i])
                        dfs(g, i);
}

int main()
{
        int graph[n][n] = { { 0, 1, 1, 1, 0 },
                            { 1, 0, 1, 0, 0 },
                            { 1, 1, 0, 0, 1 },
                            { 1, 0, 0, 0, 0 },
                            { 0, 0, 1, 0, 0 } };
        dfs(graph, 0);
        return 0;         
}