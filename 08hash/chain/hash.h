#include <stdio.h>
#define HSIZE 7

struct record {
	int	key;
	/* other data */
	struct record *next;
};

void put(struct record *rec);
struct record *get(int key);
void delete(int key);
void display();
