#include "tree.h"

int cmp(void *a, void *b)
{
        return *(int *)a - *(int *)b;
}

void store(struct node *node, int a[])
{
        static int i;

        if (node == NULL)
                return;
        store(node->left, a);
        a[i++] = node->key;
        store(node->right, a);
}

