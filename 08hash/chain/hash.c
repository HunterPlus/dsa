#include "hash.h"

struct record *hashtab[HSIZE];

static int hash(int x)
{
	return x % HSIZE;
}

void put(struct record *rec)
{
	int	i;
	
	i = hash(rec->key);
	rec->next = hashtab[i];
	hashtab[i] = rec;
}
	
