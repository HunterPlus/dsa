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

void prtrecord(struct record *rec)
{
	printf("%2d  ", rec->key);
}

int main()
{
	struct record *rec;
	int a[] = { 3, 15, 11, 7, 21, 19, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	
	for (int i = 0; i < n; i++) {
		rec = newrecord(a[i]);
		put2(rec->key, sizeof(rec->key), rec);
	}
	
	return 0;
}
