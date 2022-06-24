#include "avl.h"

static int max(int a, int b)
{
        return (a > b) ? a : b;
}

static int height(struct node *node)
{
        if (node == NULL)
                return 0;
        return node->height;
}

struct node *newnode(int key)
{
        struct node *node;

        if ((node = malloc(sizeof(struct node))) == NULL) {
                fprintf(stderr, "newnode error");
                exit(1);
        }
        node->key = key;
        node->height = 1;
        node->left = node->right = NULL;
        return node;
}

/*
            y                               x
           / \     Right Rotation          /  \
          x   T3   – - – - – - – >        T1   y
         / \       < - - - - - - -            / \
        T1  T2     Left Rotation            T2  T3
*/
/* right rotate */
struct node *rrotate(struct node *y)
{
        struct node *x, *T2;

        x = y->left;
        T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
}

/* left rotate */
struct node *lrotate(struct node *x)
{
        struct node *y, *T2;

        y = x->right;
        T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
}

int getbalance(struct node *node)
{
        if (node == NULL)
                return 0;
        return height(node->left) - height(node->right);
}

struct node *insert(struct node *node, int key)
{
        if (node == NULL)
                return newnode(key);
        if (key == node->key)
                return node;

        if (key < node->key)
                node->left = insert(node->left, key);
        else
                node->right = insert(node->right, key);
        
        int balance = getbalance(node);

        /* left left case */
        if (balance > 1 && key < node->left->key)
                return rrotate(node);
        /* right right case */
        if (balance < -1 && key > node->right->key)
                return lrotate(node);
        /* left right case */
        if (balance > 1 && key > node->left->key) {
                node->left = lrotate(node->left);
                return rrotate(node);
        }
        /* right left case */
        if (balance < -1 && key < node->right->key) {
                node->right = rrotate(node->right);
                return lrotate(node);
        }

        /* update height and return the unchanged node */
        node->height = 1 + max(height(node->left), height(node->right));
        return node;
}

static struct node *successor(struct node *node)
{
	struct node *cur = node;

	while (cur && cur->left != NULL)
		cur = cur->left;
	return cur;
}

