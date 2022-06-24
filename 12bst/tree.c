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

int count(struct node *node)
{
	if (node == NULL)
		return 0;
	return 1 + count(node->left) + count(node->right);
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


struct node *search(struct node *node, int key)
{
	if (node == NULL || node->key == key)
		return node;
	if (node->key < key)
		return search(node->right, key);
	return search(node->left, key);
}

struct node *insert(struct node *node, int key)
{
	if (node == NULL)
		return newnode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

static struct node *successor(struct node *node)
{
	struct node *cur = node;

	while (cur && cur->left != NULL)
		cur = cur->left;
	return cur;
}

struct node *delete(struct node *node, int key)
{
	if (node == NULL)
		return NULL;
	if (key < node->key)
		node->left = delete(node->left, key);
	else if (key > node->key)
		node->right = delete(node->right, key);
	else {
		struct node *temp;
		if (node->left == NULL) {
			temp = node->right;
			free(node);
			return temp;
		} else if (node->right == NULL) {
			temp = node->left;
			free(node);
			return temp;
		}
		temp = successor(node->right);
		node->key = temp->key;
		node->right = delete(node->right, temp->key);
	}
	return node;
}