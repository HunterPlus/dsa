#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *lps(char *s)
{
        int     i, j, len, *p;

        len = strlen(s);
        if ((p = malloc(len * sizeof(int))) == NULL) {
                fprintf(stderr, "lps error");
                exit(1);
        }
        p[0] = 0;
        j = 0;
        for (i = 1; i < len; i++) {
                while (j > 0 && s[i] != s[j])
                        j = p[j - 1];
                if (s[i] == s[j])
                        j++;
                p[i] = j;
        }
        return p;
}

void kmp(char *txt, char *s)
{
        int     i, j, m, *p;

        m = strlen(s);
        p = lps(s);
        j = 0;
        for (i = 0; txt[i] != '\0'; i++) {
                while (j > 0 && txt[i] != s[j])
                        j = p[j - 1];
                if (txt[i] == s[j])
                        j++;
                if (j == m) {
                        printf("pattern found at index: %d\n", i - j + 1);
                        j = p[j - 1];
                }
        }
}

int main()
{
        char *txt = "AABAACAADAABAABA";
        char *s = "AABA";

        kmp(txt, s);
        return 0;
}