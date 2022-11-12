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
		x /= 10;
	}
	//checking
	int mid = (int) pow(10, dig_counter / 2);
	int j = (int) pow(10, dig_counter - 1);
	for (int i = 1; i <= mid; i *= 10,j /= 10)
	{
		if ((n/i)%10 != (n/j)%10)
		{
			return 0;
		}
	}
	return 1;
}
int isArmstrong(int n) {
	int x = n;
	int dig_counter = 0;
	while (x > 0)
	{
		dig_counter++;
		x /= 10;
	}

	x = n;
	int arm_sum = 0;
	while (x > 0 && arm_sum <= n)
	{
		int temp_pow = (int)pow(x%10,dig_counter);
		arm_sum += temp_pow;
		x /= 10;
	}
	if (arm_sum == n)
	{
		return 1;
	}
	return 0;
}