#include "tree.h"
#include <string.h>

int path(struct node *node, void *p[], int key)
{
        if (node == NULL)
                return 0;
        if (node->key == key) {
                *p = node;
                return 1;
        }
        if (node->left && path(node->left, p+1, key)) {
                *p = node;
                return 1;
        } else if (node->right && path(node->right, p+1, key)) {
                *p = node;
                return 1;
        }
        return 0;
}

void lca(struct node *root, int k1, int k2)
{
        int h = height(root);
        void *p1[h], *p2[h];
        
        memset(p1, 0, sizeof p1);
        memset(p2, 0, sizeof p2);
        if (!path(root, p1, k1) || !path(root, p2, k2)) {
                printf("warning: at least one of the key is not present!\n");
                return ;
        }

        int i;
        for (i = 0; i < h; i++)
                if (p1[i] != p2[i])
                        break;
        printf("The LCA(%d, %d) is at level: %d\n", k1, k2, --i);
        printf ("The LCA(%d, %d) key is: %d\n", k1, k2, ((struct node *) p1[i])->key);
}

int main()
{
        struct node *root;

        root = newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);
        root->right->left = newnode(6);
        root->right->right = newnode(7);

        lca(root, 4, 5);
        lca(root, 4, 6);
        lca(root, 3, 4);
        lca(root, 2, 4);
        return 0;
}