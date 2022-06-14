#include "hash.h"

int main()
{
        int a[] = { 15, 11, 27, 8, 12 };
        int n = sizeof(a) / sizeof(a[0]);

        for (int i = 0; i < n; i++)
                put(newrecord(a[i]));
        delete(12);
        display();
}