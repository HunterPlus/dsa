#include "hash.h"

static int used;
static struct entry *hashtab[HSIZE];

static int hash(char *s, int len)
{
}

static int match(struct entry *ent, char *key, int len)
{
	return ent->key && ent->key != TOMBSTONE &&
		ent->len == len && memcmp(ent->key, key, len) == 0;
}

static struct entry *get_entry(char *key, int len)
{
	struct entry *ent;
	int 	h;
	
	h = hash(key, len);	
	for (int i = 0; i < HSIZE; i++) {
		ent = hashtab + (h + i) % HSIZE;
		if (match(ent, key, len))
			return ent;
		if (ent->key == NULL)
			return NULL;
	}
	assert(0);
}

static struct entry *put_entry(char *key, int len)
{
	struct entry *ent;
	int	h;
	
	h = hash(key, len);
	for (int i = 0; i < HSIZE; i++) {
		ent = hashtab + (h + i) % HSIZE;
		if (match(ent, key, len))
			return ent;
		if (ent->key == TOMBSTONE) {
			ent->key = key;
			ent->len = len;
			return ent;
		}
		if (ent->key == NULL) {
			ent->key = key;
			ent->len = len;
			used++;
			return ent;
		}
	}
	assert(0);
}

void *get(char *key)
{
	return get2(key, strlen(key));
}

void *get2(char *key, int len)
{
	struct entry *ent = get_entry(key, len);
	return ent ? ent->rec : NULL;
}

void put(char *key, void *rec)
{
	put2(key, strlen(key), rec);
}

void put2(char *key, int len, void *rec)
{
	struct entry *ent = put_entry(char *key, int len);
	ent->rec = rec;
}

void delete(char *key)
{
	delete2(key, strlen(key));
}

void delete2(char *key, int len)
{
	struct entry *ent = get_entry(key, len);
	if(ent)			/* we should free this deleted record */
		ent->key = TOMBSTONE;
}
