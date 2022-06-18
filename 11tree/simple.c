#include "tree.h"

int main()
{
	struct node *root;
	
	root = newnode(1);
	root->left =newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	return 0;
}
