#include "avl.h"

int main() 
{
        struct node *root = NULL;

        root = insert(root, 9);
        root = insert(root, 5);
        root = insert(root, 10);
        root = insert(root, 0);
        root = insert(root, 6);
        root = insert(root, 11);
        root = insert(root, -1);
        root = insert(root, 1);
        root = insert(root, 2);     

        inorder(root);
        printf("\n");

        root = delete(root, 10);
        inorder(root);
        printf("\n");
        return 0;   
}