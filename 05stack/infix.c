#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int priority(int op)
{
	switch (op) {
	case '(':
		return 10;
	case '+':
	case '-':
		return 20;
	case '*':
	case '/':
		return 30;
	default:
		fprintf(stderr, "error: unsurpport op: %c\n", op);
		exit(1);
	}
}

void topostfix(char *inexpr, char *postexpr)
{
	char	*p, *q;
	int	c;

	p = inexpr;
	q = postexpr;
	while (*p != '\0') {
		while (isspace(*p))
			p++;
		if (isdigit(*p)) {
			while (isdigit(*p))
				*q++ = *p++;
			*q++ = ' ';
			continue;
		}

		if (*p == '(')
			push(*p++);
		else if (*p == ')') {
			while (!empty() && (c = pop()) != '(')
				*q++ = c;
			p++;
		} else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
			while (!empty() && priority(top()) >= priority(*p))
				*q++ = pop();
			push(*p++);
		} 
	}
	while (!empty())
		*q++ = pop();
	*q = '\0';
}

int postfix(char *expr)
{
	char	*p;
	int	op2;
	
	p = expr;
	while (*p != '\0') {
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p >= '0' && *p <= '9') {
			op2 = strtoul(p, &p, 10);
			push(op2);
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
	char *expr = "13 + 4 * (12 + 3) - 32";
	char postexpr[50];

	topostfix(expr, postexpr);
	printf("%s\n", postexpr);
	
	printf("%d\n", postfix(postexpr));
	return 0;
}
