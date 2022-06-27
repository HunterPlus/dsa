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

void print(struct node **g, int n)
{
        struct node *node;

        for (int i = 0; i < n; i++) {
                printf("head %d ", i);
                for (node = g[i]; node; node = node->next)
                        printf(" -> %d", node->dest);
                printf("\n");
        }
}

int main()
{
        int     n = 4;
        struct node **g;

        g = creategraph(n);
        addedge(g, 0, 1);
        addedge(g, 0, 2);
        addedge(g, 0, 3);
        addedge(g, 1, 2);

        print(g, n);
        return 0;        
}