#include "list.h"

int main()
{
        struct node *head = NULL;
        int arr[] = { 5, 7, 8, 10 };
        int n = sizeof(arr) / sizeof(arr[0]);

        head = atolink(arr, n);
        prtlist(head);
        printf("\n");

        head = delete(head, 7);
        prtlist(head);
        printf("\n");

        head = delete(head, 8);
        prtlist(head);
        printf("\n");

        head = delete(head, 10);
        prtlist(head);
        printf("\n");

        head = delete(head, 5);
        prtlist(head);
        printf("\n");
        return 0;
}