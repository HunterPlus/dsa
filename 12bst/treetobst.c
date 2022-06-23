#include "tree.h"

int cmp(const void *a, const void *b)
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

void convert(struct node *node, int a[])
{
        static int i;

        if (node == NULL)
                return;
        convert(node->left, a);
        node->key = a[i++];
        convert(node->right, a);
}

void treetobst(struct node *root)
{
        int     n, *a;

        n = count(root);
        if ((a = malloc(n * sizeof(int))) == NULL) {
                fprintf(stderr, "treetobst error");
                exit(1);
        }
        store(root, a);
        qsort(a, n, sizeof(int), cmp);
        convert(root, a);
        free(a);
}

int main()
{
        struct node *root;

        root = newnode(10);
        root->left = newnode(30);
        root->right = newnode(15);
        root->left->left = newnode(20);
        root->right->right = newnode(5);

        treetobst(root);
        inorder(root);
        return 0;
}