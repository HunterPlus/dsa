#include <stdio.h>
#include <stdlib.h>

struct node {
        int     data;
        struct node *next;
};

struct node *newnode(int);

void push(struct node **, int);
struct node *push1(struct node *, int);
void insert(struct node *, int);
void append(struct node **, int);
void delete(struct node **, int);
struct node *del(struct node *, int);
void *toarray(struct node *);
int listlen(struct node *);
struct node *atolink(int *, int);
void prtlist(struct node *);