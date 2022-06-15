#include "hash.h"

static struct entry *hashtab[HSIZE];

static int hash(char *s, int len)
{
}

static int match(struct entry *ent, char *key, int len)
{
	return ent->key && ent->key != TOMBSTONE &&
		ent->len == len && memcmp(ent->key, key, len) == 0;
}
