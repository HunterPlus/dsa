#include "tree.h"

struct node *newnode(int data)
{
	struct node *node;
	
	if ((node = malloc(struct node)) == NULL) {
		fprintf(stderr, "newnode: error");
		exit(1);
	}
	node->data = data;
	node->left = node->left = NULL;
	return node;
}
