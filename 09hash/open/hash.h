#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HSIZE	16
#define TOMBSTONE	((void *) -1)	/* represents a deleted hash entry */

struct entry {
	char	*key;
	int	len;	/* key length */
	void	*rec;
};

void *get(char *key);
void *get2(char *key, int len);
void put(char *key, void *rec);
void put2(char *key, int len, void *rec);
void delete(char *key);
void delete2(char *key, int len);


