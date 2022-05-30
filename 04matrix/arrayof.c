#include <string.h>
#include <stdlib.h>

int scmp(const void *p1, const void *p2)
{
    	const char *s1, *s2;
    
    	s1 = *(char **)p1;
    	s2 = *(char **)p2;
    	return strcmp(s1, s2);
}

int main()
{
    	char *name[] = {"Thompson", "Ritchie", "Pike", "Johnson"};
    	int     n = sizeof(name) / sizeof(name[0]);
    	
    	for (int i = 0; i < n; i++)
    	   	printf("%s\n", name[i]);
        	printf("\n");
        	qsort(name, n, sizeof name[0], scmp);
    	for (int i = 0; i < n; i++)
    	   	printf("%s\n", name[i]);        
    	return 0;
}
