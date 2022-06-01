#include "list.h"

int main()
{
        struct node *head = NULL;

        push(&head, 7);
        push(&head, 1);
        push(&head, 3);
        push(&head, 2);

        prtlist(head);
        printf("\n");
        delete(&head, 1);
        delete(&head, 2);
        prtlist(head);
        return 0;
}