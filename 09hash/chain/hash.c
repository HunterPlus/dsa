#include "hash.h"

struct record *hashtab[HSIZE];

static int hash(int x)
{
	return x % HSIZE;
}

struct record *get(int key)
{
	int	i;
	struct record *rec;
	
	i = hash(key);
	for (rec = hashtab[i]; rec != NULL; rec = rec->next)
		if (rec->key == key)
			break;
	return rec;	
}

void put(struct record *rec)
{
	int	i;
	
	if (get(rec->key) != NULL)
		return;
	i = hash(rec->key);
	rec->next = hashtab[i];
	hashtab[i] = rec;
}

void delete(int key)
{
	int	i;
	struct record *p, *q;
	
	i = hash(key);
	for (p = hashtab[i]; p != NULL; p = p->next) {
		if (p->key == key) {			
			if (p == hashtab[i])
				hashtab[i] = p->next;
			else
				q->next = p->next;
			free(p);
			return;
		}
		q = p;
	}
}

void display()
{
	int 	i;
	struct record *p;
	
	for (i = 0; i < HSIZE; i++) {
		printf("%d: ", i);
		for (p = hashtab[i]; p; p = p->next)
			printf("%2d\t", p->key);
		printf("\n");
	}
}

struct record *newrecord(int key)
{
	struct record *rec;

	rec = malloc(sizeof(struct record));
	if (rec == NULL) {
		fprintf(stderr, "newrecord error");
		exit(1);
	}
	rec->key = key;
	rec->next = NULL;
	return rec;
}