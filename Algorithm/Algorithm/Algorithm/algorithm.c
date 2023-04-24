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

void BinaryInsertionSort(int* target_arr, int length, int choice)// 要排序数组，数组长度
{
	target_arr[0] = 1;
	int temp = 0;
	for (int i = 2; i <= length; i++)
	{
		temp = target_arr[0];
		target_arr[0] = target_arr[i];
		if (choice == 0)
		{
			int j = temp;
			int first = 1;
			int end = temp;
			while (end != first)
			{
				int mid = (end + first) / 2;
				int midvalue = 0;

				if (mid * 2 != end + first)
				{
					midvalue = (float)(target_arr[mid] + target_arr[mid + 1]) / 2;
				}
				else
				{
					midvalue = target_arr[mid];
				}
				if (target_arr[0] >= midvalue)
				{
					j = mid;
					break;
				}
				else
				{
					first = 1;
					end = mid;
				}
			}
			if (target_arr[end] >= target_arr[0]) { j = 0; }
			for (int k = i, m = 0; m < i - j; m++)
			{
				target_arr[k] = target_arr[k - 1];
				k--;
			}
			target_arr[j + 1] = target_arr[0];
		}
		else if (choice == 1)
		{
			int j = temp;
			int first = 1;
			int end = temp;
			while (end != first+1)
			{
				int mid = (end + first) / 2;
				float midvalue = 0;

				if (mid * 2 != end + first)
				{
					midvalue = (float)(target_arr[mid] + target_arr[mid + 1]) / 2;
				}
				else
				{
					midvalue = target_arr[mid];
				}
				if (target_arr[0] >= midvalue)
				{
					j = mid;
					break;
				}
				else
				{
					first = mid;
				}
			}
			if (target_arr[end] <= target_arr[0]) { j = i; }
			for (int k = i, m = 0; m < i - j; m++)
			{
				target_arr[k] = target_arr[k - 1];
				k--;
			}
			target_arr[j + 1] = target_arr[0];
		}
		temp++;
		target_arr[0] = temp;
	}
	for (int i = 1; i <= length; i++)
	{
		printf("arr[%d]=%d\r\n", i, target_arr[i]);
	}
}
