#include <stdio.h>
#include <string.h>

char *reverse(char *s)
{
	int	len, c;
	char	*s1, *s2;
	
	len = strlen(s);
	for (s1 = s, s2 = s+len-1; s1 < s2; s1++, s2--) {
		c = *s1;
		*s1 = *s2;
		*s2 = c;
	}
}

int main()
{
	char str[] = "I am a student";
	
	reverse(str);
	printf("%s\n", str);
	return 0;
}
