#include "list.h"
#define N 4

int main()
{
        int a1[N] = { 1, 2, 3, 4 };
        int a2[N] = { 5, 6, 7, 8 };
        int a3[N] = { 9, 10, 11, 12 };
        int a4[N] = { 13, 14, 15, 16 };
        struct node *linktab[N] = {}, **p;

        p = linktab;
        p[0] = atolink(a1, N);
        p[1] = atolink(a2, N);
        p[2] = atolink(a3, N);
        p[3] = atolink(a4, N);

        for (int i = 0; i < N; i++)
                prtlist(p[i]);
        return 0;
}