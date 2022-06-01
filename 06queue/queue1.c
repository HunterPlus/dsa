#include <stdio.h>
#include <limits.h>
#include "queue.h"

static int buf[BUFSIZ];
static int front, rear, size;

int size()
{
	return size;
}

int full()
{
	return size = BUFSIZ;
}

int empty()
{
	return size == 0;
}

void enqueue(int data)
{
	if (full())
		return;
	buf[rear] = data;
	rear = (rear + 1) / BUFSIZ;
	size++;
}

int dequeue()
{
	int	item;
	
	if (empty())
		return INT_MIN;
	item = buf[front];
	front = (front + 1)/ BUFSIZ;
	size--;
	return item;
}
	
