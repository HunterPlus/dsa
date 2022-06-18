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

        printf("inorder traversal:\n");
        inorder(root);

        printf("\ndelete 20:\n");
        root = delete(root, 20);
        inorder(root);
        printf("\ndelete 30:\n");
        root = delete(root, 30);
        inorder(root);
        printf("\ndelete 50:\n");
        root = delete(root, 50);
        inorder(root); 

        return 0;       
}