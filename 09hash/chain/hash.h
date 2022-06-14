#include <stdio.h>
#include <stdlib.h>
#define HSIZE 7

struct record {
	int	key;
	/* other data */
	struct record *next;
};

struct record *newrecord(int key);
void put(struct record *rec);
struct record *get(int key);
void delete(int key);
void display();
