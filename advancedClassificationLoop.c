#include <stdio.h>
#include <math.h>
#include "NumClass.h"


int isPalindrome(int n) {
	int x = n;
	//counting th digits
	int dig_counter = 0;
	while (x>0)
	{
		dig_counter++;
		x /= DECIMAL_BASE;
	}
	//checking
	int mid = (int) pow(DECIMAL_BASE, dig_counter / 2);
	int j = (int) pow(DECIMAL_BASE, dig_counter - 1);
	for (int i = 1; i <= mid; i *= DECIMAL_BASE,j /= DECIMAL_BASE)
	{
		if ((n/i)%DECIMAL_BASE != (n/j)%DECIMAL_BASE)
		{
			return False;
		}
	}
	return True;
}
int isArmstrong(int n) {
	int x = n;
	int dig_counter = 0;
	while (x > 0)
	{
		dig_counter++;
		x /= DECIMAL_BASE;
	}

	x = n;
	int arm_sum = 0;
	while (x > 0 && arm_sum <= n)
	{
		int temp_pow = (int)pow(x%DECIMAL_BASE,dig_counter);
		arm_sum += temp_pow;
		x /= DECIMAL_BASE;
	}
	if (arm_sum == n)
	{
		return True;
	}
	return False;
}
