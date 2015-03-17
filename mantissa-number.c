#include<stdio.h>
#include<math.h>

int main()
{
	int k = 1;
	float current = 0;
	float previous = -1;

	while(previous != current && current != 1.0)
	{
		previous = current;
		current = 1.0 + (float) pow(2.0, (double) -k);
		k++;
	}

	printf("We have found a mantissa number! It is %d\n", k);
	printf("This means the unit roundoff, 2^-(n-1), is %e\n", pow(2, (double) -(k - 1)));
	return 0;
}
