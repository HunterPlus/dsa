#include "hash.h"

struct record {
	int	key;
	/* other data */
};

struct record *newrecord(int key)
{
	struct record *rec;
	
	rec = malloc(sizeof(struct record));
	if (rec == NULL) {
		fprintf(stderr, "newrecord error");
		exit(1);
	}
	rec->key = key;
	return rec;
}

void prtrecord(void *rec)
{
	printf("%d", ((struct record *)rec)->key);
}

int main()
{
	struct record *rec;
	int a[] = { 3, 15, 11, 7, 21, 19, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	
	for (int i = 0; i < n; i++) {
		rec = newrecord(a[i]);
		put2((char *)&rec->key, sizeof(rec->key), rec);
	}
	display(prtrecord);
	
	int key = 11;
	delete2((char *)&key, sizeof(key));
	display(prtrecord);
	
	return 0;
}
