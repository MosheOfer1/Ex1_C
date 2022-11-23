#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n) {
	return isPalindrome_rec(n, 0, count_digits(n) - 1);
}

int isPalindrome_rec(int n, int i, int j) {
	if (j <= i)
	{
		return True;
	}

	if ( (n/(int)(pow(DECIMAL_BASE,i))%DECIMAL_BASE) != (n / (int)(pow(DECIMAL_BASE, j)) % DECIMAL_BASE) )
	{
		return False;
	}
	return isPalindrome_rec(n, i + 1, j - 1);
}

int isArmstrong(int n) {
	if(isArmstrong_rec(n,count_digits(n)) == n)
		return True;
	return False;
}

int isArmstrong_rec(int n,int dig) {
	if(n>0) 
		return (isArmstrong_rec(n/DECIMAL_BASE,dig) + pow(n%DECIMAL_BASE,dig));
	return False;
}

int count_digits(int n){
	int x = n;
	int count_dig = 0;
	while (x > 0)
	{
		count_dig++;
		x /= DECIMAL_BASE;
	}
	return count_dig;
}
