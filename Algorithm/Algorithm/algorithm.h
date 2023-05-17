#ifndef __ALGORITHM_H
#define __ALGORITHM_H
#include "main.h"

//插入排序
void StraightInsertionSort(int* target_arr, int length,int choice);//要排序数组，数组长度，choice==0:从小到大 ，choice==1:从大到小
//折半插入排序
void BinaryInsertionSort(int* target_arr, int length,int choice);// 要排序数组，数组长度
//希尔排序
void DiminishingIncrementSort(int* target_arr, int length, int choice, int dx, int d_dx);
//快速排序
void QuickSort(int* target_arr, int length,int choice);
//简单选择排序
void SimpleSelectionSort(int* target_arr, int length,int choice);
//树形选择排序
void TreeSelectionSort(int* target_arr, int length);
#endif