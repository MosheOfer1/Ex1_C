#include <stdio.h>
#include <math.h>
#include "NumClass.h"


int main() {
	int a, b;
	scanf("%d%d", &a,&b);
	printf("The Armstrong numbers are:");
	for (int i = a; i <= b; i++)
	{
		if (isArmstrong(i) == 1)
		{
			printf(" %d", i);
		}
	}


	printf("\nThe Palindromes are:");
	for (int i = a; i <= b; i++)
	{
		if (isPalindrome(i) == 1)
		{
			printf(" %d", i);
		}
	}

	printf("\nThe Prime numbers are:");
	for (int i = a; i <= b; i++)
	{
		if (isPrime(i) == 1)
		{
			printf(" %d", i);
		}
	}

	printf("\nThe Strong numbers are:");
	for (int i = a; i <= b; i++)
	{
		if (isStrong(i) == 1)
		{
			printf(" %d", i);
		}
	}
	printf("\n");
}
