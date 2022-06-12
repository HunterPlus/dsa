#include <stdio.h>
#define HSIZE 26

int	hashtab[HSIZE];
int hash(int c)
{
	return c - 'a';
}

void countch(char *txt)
{
	char	*s;
	int	i, c;
	
	for (s = txt; *s != '\0'; s++)
		if ((c = *s) >= 'a' && c <= 'z')
			hashtab[hash(c)] += 1;
}

int main()
{
	char *txt = "The c argument is an int, the value of which the"
		" application  shall ensure is a character representable as an"
		" unsigned char or equal to the value of the macro EOF."
		" If the argument has any other value, the behavior is undefined.";
	countch(txt);
	for (int i = 0; i < HSIZE; i++)
		printf("%c: %2d\t", (i + 'a'), hashtab[i]);
	return 0;
}
