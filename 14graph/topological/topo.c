#include <stdio.h>
#include <stdlib.h>

int empty(void);
void push(int);
int pop(void);

struct edge {
        int     src;
        int     dest;
};

struct edge *creategraph(int edges)
{
        struct edge *edge;

        if ((edge = malloc(edges * sizeof(struct edge))) == NULL) {
                fprintf(stderr, "creategraph error");
                exit(1);
        }
        return edge;
}

void dosort(struct edge *edge, int edges, int u, int visited[])
{
        visited[u] = 1;         /* mark visited */
        for (int i = 0; i < edges; i++)
                if (edge[i].src == u && !visited[edge[i].dest])
                        dosort(edge, edges, edge[i].dest, visited);
        push(u);
}

void topo(struct edge *edge, int edges, int vertices)
{
        int visited[vertices], i;

        for (i = 0; i < vertices; i++)
                visited[i] = 0;
        for (i = 0; i < vertices; i++)
                if (visited[i] == 0)
                        dosort(edge, edges, i, visited);
        while (!empty())
                printf("%2d  ", pop());
        printf("\n");
}


int main()
{
        int     n = 6;
        struct edge *edge;

        edge = creategraph(n);
        edge[0].src = 5;
        edge[0].dest = 2;
        edge[1].src = 5;
        edge[1].dest = 0;
        edge[2].src = 4;
        edge[2].dest = 0;
        edge[3].src = 4;
        edge[3].dest = 1;
        edge[4].src = 2;
        edge[4].dest = 3;
        edge[5].src = 3;
        edge[5].dest = 1;

        topo(edge, n, n);
        return 0;                
}