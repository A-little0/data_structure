#ifndef __ALGORITHM_H
#define __ALGORITHM_H
#include "main.h"

//��������
void StraightInsertionSort(int* target_arr, int length,int choice);//Ҫ�������飬���鳤�ȣ�choice==0:��С���� ��choice==1:�Ӵ�С
//�۰��������
void BinaryInsertionSort(int* target_arr, int length,int choice);// Ҫ�������飬���鳤��
//ϣ������
void DiminishingIncrementSort(int* target_arr, int length, int choice, int dx, int d_dx);//Ҫ��������飬���鳤�ȣ���choice==0����С����choice==1:�Ӵ�С��������������������

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