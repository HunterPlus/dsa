#include "tree.h"

struct node *lca(struct node *node , int k1, int k2, int *found)
{
        struct node *ln, *rn;

        if (node == NULL)
                return NULL;
        ln = lca(node->left, k1, k2, found);
        rn = lca(node->right, k1, k2, found);
        if (ln && rn) {
                *found = 1;
                return node;
        } else if ((node->key == k1 || node->key == k2) && (ln || rn)) {
                *found = 1;
                return node;
        } else if (node->key == k1 || node->key == k2)
                return node;
        
        return ln ? ln : rn;
}

int main()
{
        int found;
        struct node *root, *node;

        root = newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);
        root->right->left = newnode(6);
        root->right->right = newnode(7); 

        found = 0;
        node = lca(root, 4, 5, &found);
        if (found && node)
                printf("lca(4, 5) is: %d\n", node->key);
        found = 0;
        node = lca(root, 4, 6, &found);
        if (found && node)
                printf("lca(4, 6) is: %d\n", node->key);
        found = 0;
        node = lca(root, 3, 4, &found);
        if (found && node)
                printf("lca(3, 4) is: %d\n", node->key);
        found = 0;
        node = lca(root, 2, 4, &found);
        if (found && node)
                printf("lca(2, 4) is: %d\n", node->key);

        found = 0;
        node = lca(root, 2, 8, &found);
        if (found && node)
                printf("lca(2, 8) is: %d\n", node->key);
        else if (node)
                printf("only found key: %d\n", node->key);

        return 0;       
}