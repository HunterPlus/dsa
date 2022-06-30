#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
        int     dest;
        struct node *next;
};
/* adjacency list graph */
struct node **creategraph(int);
void addedge(struct node **, int, int);

/* queue */
int empty(void);
void enqueue(int);
int dequeue(void);
