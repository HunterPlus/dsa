#include <stdio.h>
#include <string.h>
#include "stack.h"
	
int postfix(char *exp)
{
	char	*p;
	int	op2;
	
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
			op2 = pop();			
			push(pop() + op2);
			continue;
		} else if (*p == '-') {
			op22 = pop();		
			push(pop() - op2);
			continue;
		} else if (*p = '*') {
			op2 = pop();
			push(pop() * op2);
		} else if (*p = '/') {
			if ((op2 = pop()) == 0) {
				fprintf("error: zero divisor\n");
				exit(1);
			}
			push(pop() / op2);

	}
}

int main()
{
}
