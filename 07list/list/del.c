#include "list.h"

int main()
{
        struct node *head = NULL;

        push(&head, 10);
        push(&head, 12);
        push(&head, 14);
        push(&head, 15);
        prtlist(head);

        head = del(head, 20);
        prtlist(head);

        head = del(head, 10);
        prtlist(head);

        head = del(head, 14);
        prtlist(head);

        return 0;
}