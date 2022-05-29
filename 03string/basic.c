
/* stringlen - strlen - calculate the length of a string */
int stringlen(const char *s)
{
	char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}

/* stringchr - strchr - locate character in string */
char *stringchr(const char *s, int c)
{
	for (; *s != (char)c; ++s)
		if (*s == '\0')
			return NULL;
	return (char *)s;
}

/* stringcpy - strcpy - copy a string */
char *stringcpy (char *dest, const char *src)
{
	char *tmp = dest;

	while ((*dest++ = *src++) != '\0') 
		/* nothing */;	
	return tmp;
}

/* stringncpy - strncpy - most n bytes of src are copied */
char *stringncpy(char *dest, const char *src, size_t n)
{
	char	*tmp = dest;
	
	while (n) {
		if ((*tmp = *src) != '\0')
			src++;
		tmp++;
		n--;
	}
	return dest;
}

/* stringcat - strcat - concatenate two strings */
char *stringcat(char *dest, const char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0')
		;
	return tmp;
}

/* stringcmp - strcmp - compare two strings */
int stringcmp(const char *cs, const char *ct)
{
	unsigned char c1, c2;

	while (1) {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if (!c1)	/* c1 = c2 = '\0' */
			break;
	}
	return 0;
}

/* stringncmp - strncmp - compare two length-limited strings */
int stringncmp(const char *cs, const char *ct, size_t n)
{
	unsigned char c1, c2;

	while (n) {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			return c1 < c2 ? -1 : 1;
		if (!c1)	/* c1 = c2 = '\0' */
			break;
		n--;
	}
	return 0;
}

/* memoryset - memset - fill memory with a constant byte */
void *memoryset(void *s, int c, size_t count)
{
	char *xs = s;

	while (count--)
		*xs++ = c;
	return s;
}
