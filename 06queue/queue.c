#include <stdio.h>
#include <limits.h>
#include "queue.h"

static int buf[BUFSIZ];
static int _front, _rear, _size;

int size()
{
	return _size;
}

int full()
{
	return _size == BUFSIZ;
}

int empty()
{
	return _size == 0;
}

void enqueue(int data)
{
	if (full())
		return;
	buf[_rear] = data;
	_rear = (_rear + 1) % BUFSIZ;
	_size++;
}

int dequeue()
{
	int	item;
	
	if (empty())
		return INT_MIN;
	item = buf[_front];
	_front = (_front + 1) % BUFSIZ;
	_size--;
	return item;
}

int front()
{
	if (empty())
		return INT_MIN;
	return buf[_front];
}

int rear()
{
	if (empty())
		return INT_MIN;
	return buf[_rear];
}
	
