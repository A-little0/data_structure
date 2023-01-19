#include "main.h"
#include "myqueue.h"


void test01()
{
	Queue* myqueue = QueueInit();
	if (QueueEmpty(myqueue))
	{
		printf("queue init and funtion QueueEmpty success\r\n");
	}
	else
	{
		printf("queue init and funtion QueueEmpty fail\r\n");
	}
	EnQueue(10, myqueue);
	if (QueueEmpty(myqueue))
	{
		printf("Enqueue fail\r\n");
	}
	else
	{
		if (myqueue->dataarr[0]==10&&myqueue->rear==1)
		{
			printf("enqueue success\r\n");
		}
		else
		{
			printf("enqueue fail\r\n");
		}
	}
	int value = DeQueue(myqueue);
	if (value == 10)
	{
		if (QueueEmpty(myqueue))
		{
			printf("DeQueue success\r\n");
		}
		else
		{
			printf("DeQueue fail\r\n");
		}
	}
	else
	{
		printf("return value error\r\n");
	}
}

void test02()
{
	Queue* myqueue = QueueInit();
	if (QueueEmpty(myqueue))
	{
		printf("queue init and funtion QueueEmpty success\r\n");
	}
	else
	{
		printf("queue init and funtion QueueEmpty fail\r\n");
	}
	for (int i = 0; i < 10; i++)
	{
		EnQueue(10+i, myqueue);
	}
	//EnQueue(10, myqueue);
	int length = QueueLength(myqueue);
	printf("length:%d\r\n", length);
	//for (int j = 0; j < 10; j++)
	//{
	//	int temp = DeQueue(myqueue);
	//	printf("the %d yuanshu:\r\n", temp);
	//}
	//QueueTraverse(myqueue);
	DeQueue(myqueue);
	//QueueTraverse(myqueue);
	ClearQueue(myqueue);
	QueueTraverse(myqueue);

}


int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}