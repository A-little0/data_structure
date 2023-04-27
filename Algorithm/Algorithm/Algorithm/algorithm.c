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

		int begin = 1;
		int end = temp;
		int j = 0;
		while (begin + 1 != end)
		{
			if (begin == end) { break; }
			int mid_sub = (begin + end) / 2;
			int mid_value = 0;
			if (mid_sub * 2 == begin + end) { (target_arr[begin] + target_arr[end]) / 2; }
			else { mid_value = target_arr[mid_sub]; }

			if (target_arr[0] >= mid_value)
			{
				end = mid_sub;
			}
			else if (target_arr[0] < mid_value)
			{
				begin = mid_sub;
			}
			
		
		}
		if (target_arr[0] > target_arr[end] && target_arr[0] < target_arr[begin])
		{
			j = begin;
		}
		else if (target_arr[0] >= target_arr[begin])
		{
			j = begin - 1;
		}
		else if (target_arr[0] > target_arr[end] && target_arr[0] < target_arr[begin])
		{
			j = end;
		}
		else if (target_arr[0] < target_arr[end])
		{
			j = end;//这里注意
		}


		for (int k = i; k >= j + 2;)//int k = i, m = 0; m < i - j; m++  int k = i; k >= j + 2;
		{
			target_arr[k] = target_arr[k - 1];
			k--;
		}
		target_arr[j + 1] = target_arr[0];

		temp++;
		target_arr[0] = temp;
		//for (int i = 1; i <= length; i++)
		//{
		//	printf("arr[%d]=%d\r\n", i, target_arr[i]);
		//}
		//printf("-------------------------------------------------------------\r\n");
	}
	for (int i = 1; i <= length; i++)
	{
		printf("arr[%d]=%d\r\n", i, target_arr[i]);
	}
}
