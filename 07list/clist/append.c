#include "list.h"

int main()
{
        int arr[] = { 1, 2, 3, 4, 5, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);
        struct node *head = NULL;

        for (int i = 0; i < n; i++)
                head = append(head, arr[i]);
        prtlist(head);
        freelist(head);

        head = NULL;
        head = atolink(arr, n);
        prtlist(head);
        freelist(head);
        return 0;
}