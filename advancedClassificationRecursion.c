#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n) {
	return isPalindrome_rec(n, 0, count_digits(n) - 1);
}

int isPalindrome_rec(int n, int i, int j) {
	if (j <= i)
	{
		return 1;
	}

	if ( (n/(int)(pow(10,i))%10) != (n / (int)(pow(10, j)) % 10) )
	{
		return 0;
	}
	return isPalindrome_rec(n, i + 1, j - 1);
}

int isArmstrong(int n) {
	if(isArmstrong_rec(n,count_digits(n)) == n)
		return 1;
	return 0;
}

int isArmstrong_rec(int n,int dig) {
	if(n>0) 
		return (isArmstrong_rec(n/10,dig) + pow(n%10,dig));
	return 0;
}

int count_digits(int n){
	int x = n;
	int count_dig = 0;
	while (x > 0)
	{
		count_dig++;
		x /= 10;
	}
	return count_dig;
}