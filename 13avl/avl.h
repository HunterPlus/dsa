#include <stdio.h>
#include <stdlib.h>

struct node {
        int     key;
        int     height;
        struct node *left;
        struct node *right;        
};

struct node *newnode(int);
