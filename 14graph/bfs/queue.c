#include <stdio.h>
#include <limits.h>

static int buf[BUFSIZ];
static int _front, _rear, _size;

int empty()
{
	return _size == 0;
}

void enqueue(int data)
{
	if (_size == BUFSIZ)
		return;
	buf[_rear] = data;
	_rear = (_rear + 1) % BUFSIZ;
	_size++;
}

int dequeue()
{
	int	item;
	
	if (_size == 0)
		return INT_MIN;
	item = buf[_front];
	_front = (_front + 1) % BUFSIZ;
	_size--;
	return item;
}
