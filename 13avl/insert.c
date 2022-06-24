#include "avl.h"

int main()
{
        struct node *root = NULL;

        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 30);
        root = insert(root, 40);
        root = insert(root, 50);
        root = insert(root, 25);

        inorder(root);
        return 0;
}