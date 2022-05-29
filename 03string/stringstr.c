#include <stdio.h>
#include <string.h>

/* stringstr - strstr - Find the first substring in a NULL terminated string */
char *stringstr(const char *s1, const char *s2)
{
	size_t l1, l2;

        l1 = strlen(s1);
	l2 = strlen(s2);
	if (l2 == 0)
		return (char *) s1;
	for (; l1 >= l2; l1--, s1++)
                if (strncmp(s1, s2, l2) == 0)
                        return (char *) s1;	
	return NULL;
}

int main()
{
        char *text = "my name is Tom, and is seventeen years old.";
        char *found, *str = "yearss";

        found = stringstr(text, str);
        printf("%s\n", (found == NULL) ? "not found" : found);
        return 0;
}