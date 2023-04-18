#include "algorithm.h"

void StraightInsertionSort(int* target_arr, int length,int choice)
{
	target_arr[0] = 1;
	int temp = 0;
	for (int i = 2; i <= length; i++)
	{
		temp = target_arr[0];
		target_arr[0] = target_arr[i];
		for (int j = temp; j >=0; j--)
		{
			if (choice == 0)
			{
				if (target_arr[0] >= target_arr[j])
				{
					for (int k = i, m = 0; m < i - j; m++)
					{
						target_arr[k] = target_arr[k - 1];
						k--;
					}
					target_arr[j + 1] = target_arr[0];
					break;
				}
				else if (target_arr[0] < target_arr[j])
				{
					continue;
				}
			}
			else if (choice == 1)
			{
				if (target_arr[0] <= target_arr[j])
				{
					for (int k = i, m = 0; m < i - j; m++)
					{
						target_arr[k] = target_arr[k - 1];
						k--;
					}
					target_arr[j + 1] = target_arr[0];
					break;
				}
				else if (target_arr[0] > target_arr[j])
				{
					continue;
				}
			}
		}
		temp++;
		target_arr[0] = temp;
	}
	for (int i = 1; i <= length; i++)
	{
		printf("arr[%d]=%d\r\n", i, target_arr[i]);
	}
}