#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
        int     id;
        char    name[20];
        double  score;
} stutab[] = {
        1, "Cherry",    88,
        2, "William",   90,
        3, "Mary",      82.5,
        4, "Kyla",      76.5,
        5, "Steven",    95 
};

/* scmp: string compare of *p1 and *p2 */
int scmp(const void *p1, const void *p2)
{
        const struct student *s1, *s2;

        s1 = p1;
        s2 = p2;
        return strcmp(s1->name, s2->name);
}

/* dcmp: double compare of *p1 and *p2 */
int dcmp(const void *p1, const void *p2)
{
        const struct student *s1, *s2;

        s1 = p1;
        s2 = p2;
        if (s1->score < s2->score)
                return -1;
        else if (s1->score > s2->score)
                return 1;
        return 0;
}
void prtstu(struct student *stu)
{
        printf("%d  %5s\t%.2f\n", stu->id, stu->name, stu->score);
}

int main()
{
        int     n, size;        
        size = sizeof stutab[0];
        n = sizeof(stutab) / size;

        qsort(stutab, n, size, dcmp);
        for (int i = 0; i < n; i++)
                prtstu(stutab + i);
        printf("\n");

        qsort(stutab, n, size, scmp);
        for (int i = 0; i < n; i++)
                prtstu(stutab + i);
        return 0;
}