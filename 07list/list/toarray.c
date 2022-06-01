#include "list.h"

int main()
{
        struct node *head = NULL;
        int     n, *p;

        push(&head, 10);
        push(&head, 12);
        push(&head, 14);
        push(&head, 15);
        prtlist(head);

        n = listlen(head);
        p = toarray(head);
        for (int i = 0; i < n; i++)
                printf("%2d  ", p[i]);
        free(p);
        return 0;
}