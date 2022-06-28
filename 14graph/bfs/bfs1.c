#include <stdio.h>
#include <stdlib.h>

int empty(void);
void enqueue(int);
int dequeue(void);

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

void bfs(struct node **g, int n, int u)
{
        struct node *node;
	int visited[n] = {};
	
        visited[u] = 1;
	enqueue(u);
        while (!empty()) {
		u = dequeue();
		printf("vertex %d\n", u);
		for (node = g[u]; node; node = node->next) 
			if (!visited[node->dest]) {
				visited[node->dest] = 1;
				enqueue(node->dest);
			}		
	}
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
