#include <stdio.h>
#include <stdlib.h>

struct node {
        int     data;
        struct node *next;
};

struct node *newnode(int data)
{
        struct node *n;

        if ((n = malloc(sizeof(*n))) == NULL) {
                fprintf(stderr, "newnode: malloc error");
                exit(1);
        }
        n->data = data;
        n->next = NULL;
        return n;
}

int main()
{
        struct node *head, *second, *third;

        head = second = third = NULL;
        head = newnode(1);
        second = newnode(2);
        third = newnode(3);

        head->next = second;
        second->next = third;

        /* linked list traversal */
        for (struct node *p = head; p != NULL; p = p->next)
                printf("%2d  ", p->data);

        return 0;
}