#include <stdio.h>
#include <stdlib.h>

struct node {
        int     dest;
        struct node *next;
};
struct node *newnode(int v)
{
        struct node *node;

        if ((node = malloc(sizeof(struct node))) == NULL) {
                fprintf(stderr, "newnode error");
                exit(1);
        }
        node->dest = v;
        node->next = NULL;
        return node;
}

struct node **creategraph(int n)
{
        struct node **g;

        g = (struct node **) malloc(n * sizeof(*g));
        if (g == NULL) {
                fprintf(stderr, "creategraph error");
                exit(1);
        }
        for (int i = 0; i < n; i++)
                g[i] = NULL;
        return g;
}

void addedge(struct node **graph, int src, int dest)
{
        struct node *node;

        node = newnode(dest);
        node->next = graph[src];
        graph[src] = node;

        node = newnode(src);
        node->next = graph[dest];
        graph[dest] = node;
}
