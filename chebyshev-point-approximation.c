#include <math.h>
#include <stdio.h>

//choosing n for n-polynomial approximation of f(x) = cos(2piX), x = [0, 1]
//such that the error in the approximation is <= 10^(-8). Using Chebyshev points 

int factorial(int n)
{
	int i;
	int retVal = 1;
	for (i = 1; i <= n; i++)
		retVal = retVal * i;
	return retVal;
}

float f(int n)
{
	float term1 = (float) pow(2*M_PI, n) / factorial(n+1);
	float term2 = (float) 1.0 / pow(2, (double) (2*n)+1);
	return term1 * term2;
}
	
int main()
{
	int n = 1;
	float limit = (float) pow(10.0, -8.0);
	while (f(n) >= limit)
		n++;
	printf("%e, %e,  %d\n", f(n-1), f(n), n);
	return 0;
}
