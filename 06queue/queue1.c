#include <stdio.h>
#include <limits.h>
#include "queue.h"

static int buf[BUFSIZ];
static int front, rear, size;

int size()
{
	return size;
}

int empty()
{
	return size == 0;
}
