#include <stdio.h>
#include <string.h>
#include "stack.h"
	
int postfix(char *exp)
{
	char	*p;
	int	v1, v2;
	
	p = exp;
	while (*p != '\0') {
		if (*p == ' ' || *p == '\t')
			p++;
		if (*p >= '0' && *p <= '9') {
			push(*p - '0');
			p++;
			continue;
		}
		if (*p == '+') {
			v2 = pop();
			v1 = pop();

	}
}

int main()
{
}
