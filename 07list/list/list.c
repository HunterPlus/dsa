#include "list.h"

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

void push(struct node **headref, int data)
{
        struct node *n;

        n = newnode(data);
        n->next = *headref;
        *headref = n;
}

struct node *push1(struct node *head, int data)
{
        struct node *n;

        n = newnode(data);
        n->next = head;
        return n;
}

void insert(struct node *node, int data)
{
        struct node *n;

        n = newnode(data);
        n->next = node->next;           /* not check node is NULL */
        node->next = n;
        return;
}

void append(struct node **headref, int data)
{
        struct node *n, *p;

        n = newnode(data);
        if ((p = *headref) == NULL) 
                *headref = n;
        else {
                while (p->next != NULL)
                        p = p->next;
                p->next = n;
        }
        return;        
}

void delete(struct node **headref, int key)
{
        struct node *p, *q;

        if ((p = *headref) != NULL && p->data == key) {
                *headref = p->next;     /* change head */
                free(p);
                return;
        }
        while (p != NULL && p->data != key) {
                q = p;
                p = p->next;
        }
        if (p == NULL)          /* key not found */
                return;
        q->next = p->next;
        free(p);
}

void delete1(struct node **headref, int key)
{
        struct node *p, **nref;
        
        nref = headref;
        for(p = *nref; p; nref = &p->next, p = p->next) 
                if (p->data == key) {
                        *nref = p->next;
                        free(p);
                        break;
                }
}

void freelist(struct node *head)
{
        struct node *p;

        for (p = head; head != NULL; head = p) {
                p = head->next;
                free(head);
        }
}

/* recursion delete node */
struct node *del(struct node *node, int key)
{
        struct node *p;

        if ((p = node) == NULL)
                return node;
        if (p->data == key) {
                node = p->next;
                free(p);
        } else
                node->next = del(p->next, key);
        return node;
}

void *toarray(struct node *head)
{
        int     len, i, *p;


        if ((len = listlen(head)) == 0)
                return NULL;
        p = malloc(len * sizeof(*p));           /* not check NULL */
        for (i = 0; head; head = head->next)
                p[i++] = head->data;
        return p;
}

int listlen(struct node *head)
{
        int     len;

        len = 0;
        while (head != NULL) {
                len++;
                head = head->next;
        }
        return len;
}

struct node *atolink(int a[], int n)		/* convert array to link list */
{
    	struct node head = {}, *cur;
    
    	cur = &head;
    	for (int i = 0; i < n; i++)
        	cur = cur->next = newnode(a[i]);    
    	return head.next;
}

void prtlist(struct node * node)
{
        for (; node; node = node->next)
                printf("%2d  ", node->data);
        printf("\n");
}
