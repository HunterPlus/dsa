#include "tree.h"

void enqueue(void *);
void *dequeue();

void levelorder(struct node *root)
{
        struct node *node;

        if ((node = root) == NULL)
                return;
        while(node) {
                printf("%d ", node->key);
                if (node->left)
                        enqueue(node->left);
                if (node->right)
                        enqueue(node->right);
                node = dequeue();
        }
}

int main()
{
        struct node *root;

        root = newnode(1);
        root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(4);
        root->left->right = newnode(5);

        printf("level order traversal:\n");
        levelorder(root);
        printf("\n");
        return 0;
}