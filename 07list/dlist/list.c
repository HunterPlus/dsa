#include "list.h"

struct node *newnode(int data)
{
        struct node *n;

        if ((n = malloc(sizeof(*n))) == NULL) {
                fprintf(stderr, "newnode: malloc error");
                exit(1);
        }
        n->data = data;
        n->prev = n->next = NULL;
        return n;        
}

struct node *push(struct node *head, int data)
{
        struct node *n;

        n = newnode(data);
        n->next = head;
        if (head)
                head->prev = n;
        return n;
}

struct node *append(struct node *head, int data)
{
        struct node *n, *p;

        n = newnode(data);
        if ((p = head) == NULL)
                return n;
        while (p->next)
                p = p->next;
        p->next = n;
        n->prev = p;
}

void insert(struct node *node, int data)
{
        struct node *n;

        n = newnode(data);
        n->next = node->next;           /* not check node is NULL */
        node->next = n;
        n->prev = node;
        if (n->next != NULL)
                n->next->prev = n;
}