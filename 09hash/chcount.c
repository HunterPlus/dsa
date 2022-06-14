#include <stdio.h>
#define HSIZE 26

int     hashtab[HSIZE];

int hash(int c)
{
        return c - 'a';
}

void chcount(char *txt)
{
        char    *s;
        int     i, c;

        for (s = txt; *s != '\0'; s++) {
                c = *s;
                if (c >= 'a' && c <= 'z') {
                        i = hash(c);
                        hashtab[i] += 1;
                }
        }
}

int main()
{
        char *txt = "The c argument is an int, the value of which the"
        " application  shall ensure is a character representable as an"
        " unsigned char or equal to the value of the macro EOF."
        " If the argument has any other value, the behavior is undefined.";

        chcount(txt);
        for (int i = 0; i < HSIZE; i++)
                printf("%c: %d  ", (i + 'a'), hashtab[i]);
        return 0;
}