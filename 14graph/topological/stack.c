#include <stdio.h>
#include <limits.h>

static int buf[BUFSIZ];		/* buffer of stack */
static int sp = 0;		/* stack pointer, next free position */

int empty()			/* if stack is empty return 1, otherwise 0 */
{
	return sp == 0;
}

void push(int data)
{
	if (sp >= BUFSIZ)
		printf("push: stack is overflow");
	else
		buf[sp++] = data;
}

int pop()
{
	return (sp > 0) ? buf[--sp] : INT_MIN;
}