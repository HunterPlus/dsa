#include <stdio.h>
#include <stdlib.h>

struct node {
        int     dest;
        struct node *next;
};

struct node **creategraph(int n);
void addedge(struct node **graph, int src, int dest);