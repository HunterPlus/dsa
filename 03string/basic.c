
/* stringlen - strlen - calculate the length of a string
int stringlen(const char *s)
{
	char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}

/* stringchr - strchr - locate character in string */
char *stringchr (const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return s;
}

/* stringcpy - strcpy - copy a string */
char *stringcpy (char *dest, const char *src)
{
	char *t = dest;

	while ((*dest++ = *src++) != '\0') 
		/* nothing */;	
	return t;
}

/* stringncpy - strncpy - most n bytes of src are copied */
char *stringncpy(char *dest, const char *src, size_t n)
{
	char	*t = dest;
	
	while (n) {
		if ((*t = *src) != '\0')
			src++;
		t++;
		n--;
	}
	return dest;
}
