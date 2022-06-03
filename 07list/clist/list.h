#include <stdio.h>
#include <stdlib.h>

struct node {
        int     data;
        struct node *next;
};

struct node *newnode(int);
struct node *append(struct node *, int);
struct node *atolink(int *, int);
struct node *delete(struct node *, int);
int listlen(struct node *);
int circle(struct node *);
void freelist(struct node *);
void prtlist(struct node *);