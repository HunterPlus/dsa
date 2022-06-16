
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
