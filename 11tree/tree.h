#include <stdio.h>
#include <stdlib.h>

struct node {
	int	key;
	struct node *left;
	struct node *right;
};

struct node *newnode(int);
int height(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);