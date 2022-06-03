#include <stdio.h>
#include <stdlib.h>

struct node {
        int     data;
        struct node *prev;
        struct node *next;
};

struct node *newnode(int);
struct node *push(struct node *, int);
struct node *append(struct node *, int);
void insert(struct nodde *, int);