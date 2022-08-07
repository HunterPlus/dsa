#include <stdio.h>
#include <string.h>

void jose(int m, int start, int njump)
{
	int	buf[m], *circle, killed;
	
	for (int i = 0; i < m; i++)
		buf[i] = i+1;
	circle = buf;
	while (m > 1) {
		killed = (start + njump + 1) % m;
		printf("killed ... %d\n", circle[killed]);
		if (killed == 0) {
			circle++;
			start = 0;
		}
		else if (killed == m - 1)
			start = 0;
		else {
			start = killed;
			memmove(circle + killed, circle + killed + 1, (m - killed - 1) * sizeof(int));
		}
		m--;
	}	
	printf("survivor: %d\n", circle[0]);
}

int main()
{
	int	m, start, njump;
	
	m = 5;
	start = 0;
	njump = 2;
	jose(m, start, njump);
	return 0;
}
