
void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
void heapify(int a[], int n, int i)
{
	int	min, l, r;
	
	min = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && a[l] < a[min])
		min = l;
	if (r < n && a[r] < a[min])
		min = r;
	if (min != i) {
		swap(a + i, a + min);
		heapify(a, n, min);
	}
}

void insert(int a[], int *pn, int key)
{
	int	j;
	
	j = *pn;
	a[j] = key;
	++*pn;
	while (j > 0 && a[j] < a[(j-1)/2]) {
		swap(a + j; a + (j-1)/2);
		j = (j-1) / 2;
	}
}

int extract(int a[], int *pn)
{
	int	n;
	
	if ((n = --*pn) == 0)
		return a[0];
	swap(a, a + n);
	heapify(a, n, 0);
	return a[n];
}
