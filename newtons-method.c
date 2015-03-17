#include <stdio.h>
#include <math.h>

//using function: 
//	f(x)	= x^3 + M_PI*(x^2) - e^x
//	f'(x)	= 3x^2 + 2*M_PI*x - e^x
//	f''(x)	= 6x + 2*M_PI - e^x

float f(float x)
{
	return (float) pow((double)x, 3.0) + (M_PI * pow((double)x, 2.0)) - pow(M_E, (double)x);
}

float deriv(float x)
{
	return (float) 3*pow((double)x, 2.0) + 2*M_PI*pow((double)x, 2.0) - pow(M_E, (double)x);
}

void newton(float startPoint)
{
	float next;
	float previous = startPoint;
	int i;
	//running for 20 iterations no matter what
	for (i = 0; i < 20; i++)
	{
		next = previous - (f(previous) / deriv(previous));
	}
	
	printf("Setting x0 = %f\n", startPoint);
	printf("After 20 iterations, we estimate the root is: %e\n", next);
	//claiming root = -0.481885
	double root = -0.481885;
	double trueError = fabs(root - next);
	printf("True error: %e\n", trueError);
	double relativeError = fabs(f(next) / deriv(next));
	printf("Relative error: %e\n", relativeError);
}


int main()
{
	newton(-0.5);
	return 0;
}
