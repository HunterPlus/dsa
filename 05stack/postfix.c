#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
	
int postfix(char *expr)
{
	char	*p;
	int	op2;
	
	p = expr;
	while (*p != '\0') {
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p >= '0' && *p <= '9') {
			push(*p - '0');
			p++;
			continue;
		}
		
		if (*p == '+') {
			op2 = pop();			
			push(pop() + op2);			
		} else if (*p == '-') {
			op2 = pop();		
			push(pop() - op2);			
		} else if (*p == '*') {
			op2 = pop();
			push(pop() * op2);
		} else if (*p == '/') {
			if ((op2 = pop()) == 0) {
				fprintf(stderr, "error: zero divisor\n");
				exit(1);
			}
			push(pop() / op2);
		} else {
			fprintf(stderr, "error: unsupport operator:\n%s", p);
			exit(1);
		}
		p++;
	}
	return pop();
}

int main()
{
	char *expr = "3 4 5 + *";
	
	printf("%d\n", postfix(expr));
	return 0;
}
