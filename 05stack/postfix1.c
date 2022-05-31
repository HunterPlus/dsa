#include <stdio.h>
#include <string.h>
#include "stack.h"
	
int postfix(char *exp)
{
	char	*p;
	int	c;
	
	p = exp;
	while (*p != '\0') {
		if (*p == ' ' || *p == '\t')
			p++;
		if (*p >= '0' && *p <= '9') {
			push(*p - '0');
			p++;
			continue;
		}
		switch (*p) {
		case '+': push(pop() + pop()); continue;
				
		}
	}
}

int main()
{
}
