#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int n) {
	double d = sqrt(n);
	for (int i = 2; i <= d ;i++) {
		if (n%i == 0)
		{
			return False;
		}
	}
	return True;
}

int isStrong(int n) {
	int x = n;
	int sum_factorial = 0;
	int temp_sum_f = 1;
	while (x>0 && n >= sum_factorial)
	{
		for (int i = 1; i <= (x%DECIMAL_BASE ); i++)
		{
			temp_sum_f *= i;
		}
		sum_factorial += temp_sum_f;
		temp_sum_f = 1;
		x /= DECIMAL_BASE;
	}
	if (n == sum_factorial) {
		return True;
	}
	return False;
}


