#include "main.h"
#include "algorithm.h"

void test01()
{
	int arr[10 + 1] = { 0,3,2,1,4,5,8,9,6,7,10 };
	StraightInsertionSort(arr, 10,1);
}

void test02()
{
	int arr[10 + 1] = { 0,3,2,1,4,5,8,9,6,7,10 };
	BinaryInsertionSort(arr, 10,0);

}

void test03()
{
	int arr[10 + 1] = {0,3,2,1,4,5,8,9,6,7,10 };
	DiminishingIncrementSort(arr, 10, 1, 5, 2);
}

void test04()
{
	int arr[10 + 1] = { 0,3,2,1,4,5,8,9,6,7,10 };
	QuickSort(arr, 11,1);
	
	for (int i = 0; i < 11; i++)
	{
		printf("arr[%d]=%d\r\n", i, arr[i]);
	}
	printf("-------------------------------------------------------\r\n");
}

void test05()
{
	int arr[10 + 1] = { 0,3,2,1,4,5,8,9,6,7,10 };
	SimpleSelectionSort(arr,11,1);
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();



	system("pause");
	return 0;
}