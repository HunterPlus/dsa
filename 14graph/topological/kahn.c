#include "kahn.h"


int main()
{
	struct node **g;
	
	g = creategraph(6);
	addedge(g, 5, 2);
	addedge(g, 5, 0);
	addedge(g, 4, 0);
	addedge(g, 4, 1);
	addedge(g, 2, 3);
	addedge(g, 3, 1);	
}
