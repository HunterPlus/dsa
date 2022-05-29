/*
 * p(): power function - p(x, n) - x^n
 * f(): factorial function - f(n) - n!
 * e(): taylor series - e^x =  e(x, n) = 1 + x + x^2/2! + x^3/3! ... + x^n/n!
 * Horner's rules: e(x, n) = 1 + x/1 * (1 + x/2 * (1 + x/3 * (1 + ... (1 + x/n * 1)...)
 */
 
#include <stdio.h>

double p(double x, int n) 
{
  	if (n == 0)
    		return 1;
   	return x * p(x, n-1);
}
double f(int n)
{
    	if (n == 0)
        	return 1.0;
    	return n * f(n-1);
}
double e(double x, int n)
{
    	if (n == 0)
        	return 1.0;
    	return p(x, n)/f(n) + e(x, n-1);
}

double e1(double x, int n)
{
    	double p, f, s;
	
    	p = f = s = 1.0;
    	for (int i = 1; i <= n; i++) {
        	p = x * p;
        	f = i * f;
        	s = s + p / f;
    	}
    	return s;
}

double e2(double x, int n)      /* Horner’s Rule */
{
    	double s = 1.0;
	
    	for (; n > 0; n--)
        	s = 1 + x/n * s;
    	return s;
}

int main()
{
    	int x, n;
	
    	x = 2;
    	n = 30;
    	printf("%f\n", e(x, n));
	
    	return 0;
}
