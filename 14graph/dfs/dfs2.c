#include "dfs2.h"
#define n 5

int visited[n] = {};
void dfs(struct node **g, int u)
{
        struct node *node;

        visited[u] = 1;
        printf("vertex %d\n", u);
        for (node = g[u]; node; node = node->next)
                if (!visited[node->dest])
                        dfs(g, node->dest);

}

int main()
{
        struct node **g;

        g = creategraph(n);
        addedge(g, 0, 1);
        addedge(g, 0, 2);
        addedge(g, 0, 3);
        addedge(g, 1, 2);
        addedge(g, 2, 4);

        dfs(g, 0);
        return 0;
}