#include "tree.h"

struct node *newnode(int key)
{
	struct node *node;
	
	if ((node = malloc(sizeof(struct node))) == NULL) {
		fprintf(stderr, "newnode: error");
		exit(1);
	}
	node->key = key;
	node->left = node->left = NULL;
	return node;
}

int height(struct node *node)
{
	int	lh, rh;

	if (node == NULL)
		return 0;
	lh = height(node->left);
	rh = height(node->right);
	if (lh > rh)
		return 1 + lh;
	else
		return 1 + rh;
}

void inorder(struct node *node)
{
	if (node == NULL)
		return;
	inorder(node->left);		/* visit left */
	printf("%d ", node->key);	/* visit this node */
	inorder(node->right);		/* visit right */
}

void preorder(struct node *node)
{
	if (node == NULL)
		return;
	printf("%d ", node->key);	/* visit this node */
	preorder(node->left);		/* visit left */
	preorder(node->right);		/* visit right */
}

void postorder(struct node *node)
{
	if (node == NULL)
		return;
	postorder(node->left);		/* visit left */
	postorder(node->right);		/* visit right */
	printf("%d ", node->key);	/* visit this node */
}