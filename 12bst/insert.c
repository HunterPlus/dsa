#include "tree.h"

int main()
{
        struct node *root;

        root = insert(NULL, 50);
        insert(root, 30);
        insert(root, 20);
        insert(root, 40);
        insert(root, 70);
        insert(root, 60);
        insert(root, 80);

        inorder(root);
        return 0;
}