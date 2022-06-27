#include <stdio.h>

int empty();
void push(int);
int pop();

void dfs(int *g, int n, int start)
{
        int     visited[n];
        int     u, v;           /* vertext */

        for (int i = 0; i < n; i++)
                visited[i] = 0;
        push(start);
        visited[start] = 1;
        while (!empty()) {
                u = pop();
                printf("vertex %d\n", u);
                for (int i = 0; i < n; i++)
                        if (!visited[i] && g[u * n + i]) {
                                visited[i] = 1;
                                push(i);
                        }

        }
}

int main()
{
        int graph[5][5] = { { 0, 1, 1, 1, 0 },
                            { 1, 0, 1, 0, 0 },
                            { 1, 1, 0, 0, 1 },
                            { 1, 0, 0, 0, 0 },
                            { 0, 0, 1, 0, 0 } };
        dfs((int *)graph, 5, 0);
        return 0;        
}