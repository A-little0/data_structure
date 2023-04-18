#include "main.h"
#include "algorithm.h"

void test01()
{
	int arr[10 + 1] = { 0,3,2,1,4,5,8,9,6,7,10 };
	StraightInsertionSort(arr, 10,1);
	
}


int main() {
	test01();
	system("pause");
	return 0;
}