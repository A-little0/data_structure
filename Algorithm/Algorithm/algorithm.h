#ifndef __ALGORITHM_H
#define __ALGORITHM_H
#include "main.h"

//��������
void StraightInsertionSort(int* target_arr, int length,int choice);//Ҫ�������飬���鳤�ȣ�choice==0:��С���� ��choice==1:�Ӵ�С
//�۰��������
void BinaryInsertionSort(int* target_arr, int length,int choice);// Ҫ�������飬���鳤��
//ϣ������
void DiminishingIncrementSort(int* target_arr, int length, int choice, int dx, int d_dx);
//��������
void QuickSort(int* target_arr, int length,int choice);
//��ѡ������
void SimpleSelectionSort(int* target_arr, int length,int choice);
//����ѡ������
void TreeSelectionSort(int* target_arr, int length);
#endif