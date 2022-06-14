#include "hash.h"

struct record *hashtab[HSIZE];

static int hash(int x)
{
	return x % HSIZE;
}
