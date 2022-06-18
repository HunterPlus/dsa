#include "tree.h"

int main()
{
        struct node *root;

        root = newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);

        printf("inorder traversal:\n");
        inorder(root);
        printf("\npreorder traversal:\n");
        preorder(root);
        printf("\npostorder traversal:\n");
        postorder(root);

        return 0;
}