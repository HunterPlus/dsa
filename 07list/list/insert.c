#include "list.h"

int main()
{
        struct node *head = NULL;

        append(&head, 6);
        push(&head, 7);
        head = push1(head, 1);
        append(&head, 4);
        insert(head->next, 8);

        for (struct node *p = head; p; p = p->next)
                printf("%2d  ", p->data);
        return 0;
}