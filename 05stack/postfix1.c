#include <stdio.h>
#include <string.h>
#include "stack.h"
	
int postfix(char *exp)
{
	char	*p;
	int	op2;
	
	p = exp;
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
			op22 = pop();		
			push(pop() - op2);			
		} else if (*p = '*') {
			op2 = pop();
			push(pop() * op2);
		} else if (*p = '/') {
			if ((op2 = pop()) == 0) {
				fprintf("error: zero divisor\n");
				exit(1);
			}
			push(pop() / op2);
		} else {
			fprintf(stderr, "unsupport operator");
			exit(1);
		}
	}
	return pop();
}

int main()
{
	char *exp = "3 4 5 + *";
	
	printf("%d\n", postfix(exp));
	return 0;
}
