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
	for (rec = hastab[i]; rec != NULL; rec = rec->next)
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
	
