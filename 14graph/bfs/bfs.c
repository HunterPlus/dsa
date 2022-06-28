#include <stdio.h>

int empty(void);
void enqueue(int);
int dequeue(void);

int bfs(int *g, int n, int start)
{
        int     visited[n];
        int     u, v;           /* vertex */
        
        for (int i = 0; i < n; i++)
                visited[i] = 0;
        enqueue(start);
        visited[start] = 1;
        while (!empty()) {
                u = dequeue();
                printf("vertex %d\n", u);
                for (int i = 0; i < n; i++) 
                        if (!visited[i] && g[u * n + i]) {
                                visited[i] = 1;
                                enqueue(i);
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
        bfs((int *)graph, 5, 0);
        return 0;         
}
