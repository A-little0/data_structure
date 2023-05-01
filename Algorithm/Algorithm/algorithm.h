#ifndef __ALGORITHM_H
#define __ALGORITHM_H
#include "main.h"

//插入排序
void StraightInsertionSort(int* target_arr, int length,int choice);//要排序数组，数组长度，choice==0:从小到大 ，choice==1:从大到小
//折半插入排序
void BinaryInsertionSort(int* target_arr, int length,int choice);// 要排序数组，数组长度
//希尔排序
void DiminishingIncrementSort(int* target_arr, int length, int choice, int dx, int d_dx);//要排序的数组，数组长度，（choice==0：从小到大choice==1:从大到小），增量，增量的增量

//void DiminishingIncrementSort(int* target_arr, int length, int choice, int dx, int d_dx)
//{
//	while (dx >= 1)
//	{
//
//		for (int i = 0; i + dx <= length - 1; i++)
//		{
//			//if (target_arr[i] >= target_arr[i + dx])
//			//{
//			//	int temp = target_arr[i];
//			//	target_arr[i] = target_arr[i + dx];
//			//	target_arr[i + dx] = temp;
//			//}
//
//
//
//		}
//		dx -= d_dx;
//
//
//		for (int i = 0; i < length; i++)
//		{
//			printf("arr[%d]=%d\r\n", i, target_arr[i]);
//		}
//		printf("----------------------------------------------------------\r\n");
//	}
//
//	//for (int i = 0; i < length; i++)
//	//{
//	//	printf("arr[%d]=%d\r\n", i, target_arr[i]);
//	//}
//}
#endif