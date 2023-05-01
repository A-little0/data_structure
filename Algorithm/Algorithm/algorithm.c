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
	if (choice == 1)
	{
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
	}
	else if (choice == 0)
	{
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

				if (target_arr[0] > mid_value)
				{
					begin = mid_sub;
				}
				else if (target_arr[0] <= mid_value)
				{
					end = mid_sub;
				}


			}
			if (target_arr[0] < target_arr[end] && target_arr[0] >target_arr[begin])
			{
				j = begin;
			}
			else if (target_arr[0] <= target_arr[begin])
			{
				j = begin - 1;
			}
			//else if (target_arr[0] > target_arr[end] && target_arr[0] < target_arr[begin])
			//{
			//	j = end;
			//}
			else if (target_arr[0] > target_arr[end])
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
	}
	for (int i = 1; i <= length; i++)
	{
		printf("arr[%d]=%d\r\n", i, target_arr[i]);
	}
}

void DiminishingIncrementSort(int* target_arr, int length, int choice, int dx, int d_dx)
{
	while (dx >= 1)
	{
		int arr_nub_sum = 0;
		for (int m = 0, sonarr_length = length / dx;arr_nub_sum<=length; m++)
		{
			for (int i = m, compare = i + dx; compare<=(i+ (sonarr_length-1)*dx); compare += dx)
			{
				int tempcompare = target_arr[compare];
				int find_insertsub = 0;
				for (int j = compare - dx; j >= i; j -= dx)
				{
					if (tempcompare <= target_arr[j])
					{
						continue;
					}
					else if (tempcompare >target_arr[j])
					{
						find_insertsub = j;
						break;
					}
				}  

				for (int k = compare,i=0; i< (compare - find_insertsub) / dx - 1;i++)//int k = i, m = 0; m < i - j; m++  int k = i; k >= j + 2;
				{
					target_arr[k] = target_arr[k - dx];
					k-=dx;
				}
				target_arr[find_insertsub + dx] = tempcompare;
			}
			arr_nub_sum += sonarr_length + 1;
			sonarr_length = (length - arr_nub_sum) / dx;
		}
		dx -=d_dx;
		//for (int i = 1; i < length; i++)
		//{
		//	printf("arr[%d]=%d\r\n", i, target_arr[i]);
		//}
		//printf("----------------------------------------------------------\r\n");
	}

	for (int i = 1; i < length; i++)
	{
		printf("arr[%d]=%d\r\n", i, target_arr[i]);
	}
}
