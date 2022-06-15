#include "hash.h"

struct record {
	int	key;
	/* other data */
};

struct record *newrecord(int key)
{
	struct reccord *rec;
	
	rec = malloc(struct record);
	if (rec == NULL) {
		fprintf(stderr, "newrecord error");
		exit(1);
	}
	rec->key = key;
}
