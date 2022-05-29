
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
