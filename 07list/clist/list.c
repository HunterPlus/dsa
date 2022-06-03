#include "list.h"

struct node *newnode(int data)
{
        struct node *n;

        if ((n = malloc(sizeof(*n))) == NULL) {
                fprintf(stderr, "newnode: malloc error");
                exit(1);
        }
        n->data = data;
        n->next = n;
        return n;
}

struct node *append(struct node *head, int data)
{
        struct node *n;

        n = newnode(data);        
        if(head) {
                n->next = head->next;
                head->next = n;
        }        
        return n;
}

struct node *atolink(int a[], int n)
{
        struct node head = {}, *cur;

        cur = &head;
        for (int i = 0; i < n; i++)
                cur = cur->next = newnode(a[i]);
        cur->next = head.next;
        return cur;
}

struct node *delete(struct node *head, int key)
{
        struct node *p, *q;
        int found = 0;

        if ((p = head) == NULL)
                return head;
        q = NULL;
        do {
                if (p->data == key) {
                        found = 1;
                        break;
                }
                q = p;
        } while ((p = p->next) != head);
        if (!found)
                return head;
        /* found key */
        if (p == head && p->next == head)       /* only one node */                
                head = NULL;                    /* update head */
        else if (p == head) {                 
                for (q = p->next; q->next != p; q = q->next)
                        ;
                q->next = p->next;
                head = q;                       /* update head */                               
        } else 
                q->next = p->next;                
        free(p);       
        return head;            
}

int listlen(struct node *head)
{
        int     n = 0;

        if (head) {
                struct node *p = head;
                do {
                        n++;
                } while ((p = p->next) != head);                
        }
        return n;
}

int circle(struct node *head)
{
        struct node *slow, *fast;

        slow = fast = head;
        while (slow && fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast)
                        return 1;
        }
        return 0;
}

void freelist(struct node *head)
{
        struct node *p, *q;

        if ((q = head) == NULL)
                return;
        p = q->next;
        q->next = NULL;
        for (; p; p = q) {
                q = p->next;
                free(p);
        }
}

void prtlist(struct node *head)
{
        struct node *p;

        if (head == NULL)
                return ;
        for (p = head->next; p != head; p = p->next)
                printf("%2d  ", p->data);
        printf("%2d\n", head->data);
}

void prtlist1(struct node *head)
{
        struct node *p;

        if ((p = head) == NULL)
                return;
        do {
                printf("%2d  ", p->data);
                p = p->next;
        } while (p != head);
}