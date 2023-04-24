#ifndef __ALGORITHM_H
#define __ALGORITHM_H
#include "main.h"

//插入排序
void StraightInsertionSort(int* target_arr, int length,int choice);//要排序数组，数组长度，choice==0:从小到大 ，choice==1:从大到小
//折半插入排序
void BinaryInsertionSort(int* target_arr, int length,int choice);// 要排序数组，数组长度
#endif
