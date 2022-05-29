#include <stdio.h>

/*  
 * toh(n, x, y, z): Tower of Hanoi
 * move n disks from x to z using y
 */
 
void toh (int n, int x, int y, int z) 
{
    	static int count = 0;
    
    	if (n > 0) {
        	toh(n-1, x, z, y);          /* move n-1 disks from x to y using z */
        
        	printf("No.%2d:\tMoving #%d from %c to %c\n", ++count, n, x, z);
        
        	toh(n-1, y, x, z);          /* move n-1 disks from y to z using x */
    	}
}

int main()
{
    	toh(3, 'A', 'B', 'C');
    	return 0;
}

