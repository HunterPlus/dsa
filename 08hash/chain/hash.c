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
	for (q = p = hashtab[i]; p != NULL; p = p->next) {
		if (p->key == key) {
			q = p->next;
			if (p == hashtab[i])
				hashtab[i] = q;
			free(p);
			return;
		}
		q = p;
	}
}
